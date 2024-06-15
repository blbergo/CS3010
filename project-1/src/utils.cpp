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

void printMatrix(vector<vector<int>> matrix)
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

vector<int> getMaxAbsValues(vector<vector<int>> matrix)
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