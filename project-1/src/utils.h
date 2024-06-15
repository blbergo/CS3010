#include <vector>
using namespace std;

typedef vector<vector<int>> matrix;

/**
 * @brief Function to print a vector of integers
 *
 * @param[in] vec Vector of integers.
 */
void printVector(vector<int> vec);
void printVector(vector<float> vec);

/**
 * @brief Function to print a matrix of integers
 *
 * @param[in] matrix 2D vector of integers.
 */
void printMatrix(matrix matrix);

/**
 * @brief Function to find the maximum value in each row of a matrix
 *
 * @param[in] matrix 2D vector of integers.
 * @return vector<int>
 */
vector<int> getMaxAbsValues(matrix matrix);

/**
 * @brief Function to get the ratios of the rows of a matrix
 *
 * @param[in] row Vector of integers.
 * @param[in] maxValues Vector of integers.
 * @param[in] colIdx Integer.
 * @return vector<float>
 */
vector<float> getRowRatios(matrix matrix, vector<int> maxValues, int colIdx);

/**
 * @brief Function to get the target K value for a row
 *
 * @param[in] ratios Vector of floats.
 * @return int
 */
int getTargetK(vector<float> ratios);