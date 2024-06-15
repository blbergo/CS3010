#include <utils.h>
#include <iostream>
using namespace std;

void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void printVector(vector<float> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void printMatrix(matrix matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<int> getMaxAbsValues(matrix matrix)
{
    vector<int> maxValues;

    // loop through the rows
    for (int i = 0; i < matrix.size(); i++)
    {
        int max = abs(matrix[i][0]);

        // loop through the columns
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (abs(matrix[i][j]) > max)
            {
                max = abs(matrix[i][j]);
            }
        }
        maxValues.push_back(max);
    }

    return maxValues;
}

vector<float> getRowRatios(matrix matrix, vector<int> maxValues, int colIdx)
{
    vector<float> ratios;

    for (int i = 0; i < matrix.size(); i++)
    {
        ratios.push_back((float)abs(matrix[i][colIdx]) / (float)maxValues[i]);
    }

    return ratios;
}

int getTargetK(vector<float> ratios)
{
    int targetK = 0;
    int maxRatio = ratios[0];

    for (int i = 0; i < ratios.size(); i++)
    {
        if (ratios[i] > maxRatio)
        {
            maxRatio = ratios[i];
            targetK = i;
        }
    }

    return targetK;
}