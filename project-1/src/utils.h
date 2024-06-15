#include <vector>
using namespace std;

/**
 * @brief Function to print a vector of integers
 *
 * @param[in] vec Vector of integers.
 */
void printVector(vector<int> vec);

/**
 * @brief Function to print a matrix of integers
 *
 * @param[in] matrix 2D vector of integers.
 */
void printMatrix(vector<vector<int>> matrix);

/**
 * @brief Function to find the maximum value in each row of a matrix
 *
 * @param[in] matrix 2D vector of integers.
 * @return vector<int>
 */
vector<int> getMaxAbsValues(vector<vector<int>> matrix);