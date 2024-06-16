#include <utils.h>
#include <iostream>
using namespace std;

void printVector(vector<double> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
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

vector<double> getMaxAbsValues(matrix matrix)
{
    vector<double> maxValues;

    // loop through the rows
    for (int i = 0; i < matrix.matrix.size(); i++)
    {
        double localMax = abs(matrix.matrix[i][0]);

        // loop through the columns
        for (int j = 0; j < matrix.matrix[i].size(); j++)
        {
            localMax = max(localMax, abs(matrix.matrix[i][j]));
        }
        maxValues.push_back(localMax);
    }

    return maxValues;
}

vector<double> getRowRatios(matrix matrix, vector<double> maxValues, vector<int> l, int colIdx)
{
    vector<double> ratios;

    for (int i = colIdx; i < matrix.matrix.size(); i++)
    {
        ratios.push_back(std::abs(matrix.matrix[l[i]][colIdx]) / maxValues[l[i]]);
    }

    return ratios;
}

vector<double> calculateRatios(matrix matrix, vector<double> s, vector<int> l, int colIdx)
{
    vector<double> ratios;

    for (int i = 0; i < l.size(); i++)
    {
        ratios.push_back(abs(matrix.matrix[l[i]][colIdx] / s[l[i]]));
    }

    return ratios;
}

int getTargetK(vector<double> ratios, int colIdx)
{
    int targetK = 0;
    double maxRatio = numeric_limits<double>::infinity() * -1;

    for (int i = colIdx; i < ratios.size(); i++)
    {
        if (ratios[i] > maxRatio)
        {
            maxRatio = ratios[i];
            targetK = i;
        }
    }

    return targetK;
}

vector<int> swapValues(vector<int> l, int k, int targetK)
{
    int temp = l[k];
    l[k] = l[targetK];
    l[targetK] = temp;

    return l;
}

matrix eliminateRows(matrix matrix, vector<int> l, int colIdx, int pivotIdx, vector<int> pivotedRows)
{
    for (int i = 0; i < l.size(); i++)
    {
        if (l[i] != pivotIdx && find(pivotedRows.begin(), pivotedRows.end(), i) == pivotedRows.end())
        {
            double factor = matrix.matrix[l[i]][colIdx] / matrix.matrix[pivotIdx][colIdx];
        
            for (int j = colIdx; j < matrix.matrix[i].size(); j++)
            {
                double result = matrix.matrix[l[i]][j] - (factor * matrix.matrix[pivotIdx][j]);
                matrix.matrix[l[i]][j] = result;
            }

            double bResult = matrix.bValues[l[i]] - (factor * matrix.bValues[pivotIdx]);
            matrix.bValues[l[i]] = bResult;
        }
    }

    return matrix;
}

vector<double> backSubstitution(matrix matrix, vector<int> l)
{
    vector<double> solutions = {};

    cout << "Solutions:" << endl;
    for (int i = 0; i < l.size(); i++)
    {

        vector<double> row = matrix.matrix[l[i]];
        reverse(row.begin(), row.end());

        double solution = matrix.bValues[l[i]];

        for (int j = solutions.size() - 1; j >= 0; j--)
        {
            solution -= row[j] * solutions[j];
        }

        solution /= row[solutions.size()];

        cout << "x" << l[i] + 1 << " = " << solution << endl;

        solutions.push_back(solution);
    }

    return solutions;
}

void scaledPartialPivoting(matrix matrix)
{
    vector<double>
        s = getMaxAbsValues(matrix);
    vector<int> l = {};

    for (int i = 0; i < matrix.matrix.size(); i++)
    {
        l.push_back(i);
    }

    vector<int> pivotedRows;
    vector<int> order;

    for (int i = 0; i < l.size(); i++)
    {
        cout << "Matrix at iteration " << i << ":" << endl;
        printMatrix(matrix);

        vector<double> ratios = calculateRatios(matrix, s, l, i);

        int k = getTargetK(ratios, i);
        cout << "Ratios: ";
        printVector(ratios);

        // output is plus 1 for non-zero indexing
        cout << "Pivot row: " << k + 1 << endl;

        matrix = eliminateRows(matrix, l, i, l[k], pivotedRows);
        order.push_back(l[k]);
        l = swapValues(l, k, i);
        pivotedRows.push_back(l[k]);
    };

    cout << "Final Matrix:" << endl;
    printMatrix(matrix);

    cout << "B values:" << endl;
    printVector(matrix.bValues);
    cout << endl;

    reverse(order.begin(), order.end());

    backSubstitution(matrix, order);
}