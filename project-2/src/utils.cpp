#include <utils.h>
#include <iostream>
#include <cmath>

using namespace std;

int MAX_ITERATIONS = 50;
double EPSILON = numeric_limits<float>::epsilon();

void printVector(vector<double> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
}

void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void printMatrix(matrix matrix)
{
    cout << endl;
    for (int i = 0; i < matrix.matrix.size(); i++)
    {
        for (int j = 0; j < matrix.matrix[i].size(); j++)
        {
            cout << matrix.matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

matrix calculateCoeffecients(matrix mat)
{
    matrix coefficients;

    for (int i = 0; i < mat.matrix.size(); i++)
    {
        vector<double> row;
        for (int j = 0; j < mat.matrix[i].size(); j++)
        {
            if (i == j)
            {
                row.push_back(0);
            }
            else
            {
                row.push_back(-mat.matrix[i][j] / mat.matrix[i][i]);
            }
        }

        row.push_back(mat.bValues[i] / mat.matrix[i][i]);
        coefficients.matrix.push_back(row);
    }
    return coefficients;
}

double calculateL2Norm(vector<double> vec1, vector<double> vec2)
{
    double sum = 0;
    for (int i = 0; i < vec1.size(); i++)
    {
        sum += pow(vec1[i] - vec2[i], 2);
    }
    return sqrt(sum);
}

double calculateRelativeError(double previous, double current)
{
    return abs((current - previous) / current);
}

vector<double> jacobiMethod(matrix mat, vector<double> startingSolutions, double desiredError)
{

    vector<double> previousSolutions = startingSolutions;
    vector<double> currentSolutions = startingSolutions;

    double previousNorm = 0;

    int iterations = 0;
    double error = numeric_limits<double>::infinity();

    while (error > desiredError && iterations < MAX_ITERATIONS)
    {
        for (int i = 0; i < mat.matrix.size(); i++)
        {
            double sum = 0;
            for (int j = 0; j < mat.matrix[i].size() - 1; j++)
            {

                if (j != i)
                {
                    sum += mat.matrix[i][j] * previousSolutions[j];
                }
            }

            sum += mat.matrix[i][mat.matrix[i].size() - 1];
            currentSolutions[i] = sum;
        }

        double currentNorm = calculateL2Norm(previousSolutions, currentSolutions);
        error = calculateRelativeError(previousNorm, currentNorm);

        // check for oscillation
        bool oscillating = true;

        for (int i = 0; i < currentSolutions.size(); i++)
        {
            if (fabs(currentSolutions[i] - previousSolutions[i]) > EPSILON)
            {
                oscillating = false;
            }
        }

        if (oscillating)
        {
            cout << "The method is oscillating based on C++ Float precision." << endl;
            return currentSolutions;
        }

        previousSolutions = currentSolutions;

        // Print the current iteration 1-indexed
        cout << "Iteration: " << iterations + 1 << endl;
        cout << "[ ";
        printVector(currentSolutions);
        cout << "] T" << endl;
        cout << "Error: " << error << endl;
        cout << endl;

        previousNorm = currentNorm;
        iterations++;
    }

    if (error > desiredError)
    {
        cout << "The method did not reach the desired error after " << MAX_ITERATIONS << " iterations." << endl;
    }

    cout << EPSILON << endl
         << endl;

    return currentSolutions;
}

vector<double> gaussSeidelMethod(matrix mat, vector<double> startingSolutions, double desiredError)
{
    vector<double> previousSolutions = startingSolutions;
    vector<double> currentSolutions = startingSolutions;

    double previousNorm = 0;

    int iterations = 0;
    double error = numeric_limits<double>::infinity();

    while (error > desiredError && iterations < MAX_ITERATIONS)
    {
        for (int i = 0; i < mat.matrix.size(); i++)
        {
            double sum = 0;
            for (int j = 0; j < mat.matrix[i].size() - 1; j++)
            {

                if (j != i)
                {
                    sum += mat.matrix[i][j] * currentSolutions[j];
                }
            }

            sum += mat.matrix[i][mat.matrix[i].size() - 1];
            currentSolutions[i] = sum;
        }

        double currentNorm = calculateL2Norm(previousSolutions, currentSolutions);
        error = calculateRelativeError(previousNorm, currentNorm);

        // check for oscillation
        bool oscillating = true;

        for (int i = 0; i < currentSolutions.size(); i++)
        {
            if (fabs(currentSolutions[i] - previousSolutions[i]) > EPSILON)
            {
                oscillating = false;
            }
        }

        if (oscillating)
        {
            cout << "The method is oscillating according to C++ Float precision." << endl
                 << endl;
            return currentSolutions;
        }

        previousSolutions = currentSolutions;

        // Print the current iteration 1-indexed
        cout << "Iteration: " << iterations + 1 << endl;
        cout << "[ ";
        printVector(currentSolutions);
        cout << "] T" << endl;
        cout << "Error: " << error << endl;
        cout << endl;

        previousNorm = currentNorm;
        iterations++;
    }

    if (error > desiredError)
    {
        cout << "The method did not reach the desird error after " << MAX_ITERATIONS << " iterations." << endl;
    }

    return currentSolutions;
}