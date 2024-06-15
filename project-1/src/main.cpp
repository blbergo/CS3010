#include <main.h>
#include <utils.h>

int main()
{
    vector<vector<int>> matrix = {
        {3, -13, 9, 3},
        {-6, 4, 1, 18},
        {6, -2, 2, 4},
        {12, -8, 6, 10}};
    vector<int> bValues = {-19, -34, 16, 26};

    vector<int> maxValues = getMaxAbsValues(matrix);
    printVector(maxValues);
}
