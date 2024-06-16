#include <vector>
#include <iomanip>
#include <limits>
#include <algorithm>

using namespace std;

struct matrix
{
    vector<vector<double>> matrix;
    vector<double> bValues;
};

/**
 * @brief Function to print a vector of integers
 *
 * @param[in] vec Vector of integers.
 */
void printVector(vector<double> vec);

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
void printMatrix(matrix matrix);

/**
 * @brief Function to find the maximum value in each row of a matrix
 *
 * @param[in] matrix 2D vector of integers.
 * @return vector<double>
 */
vector<double> getMaxAbsValues(matrix matrix);

/**
 * @brief Function to calculate the ratios of a row
 *
 * @param[in] matrix 2D vector of integers.
 * @param[in] s Vector of doubles.
 * @param[in] l Vector of integers.
 * @param[in] colIdx Integer.
 * @return vector<double>
 */
vector<double> calculateRatios(matrix matrix, vector<double> s, vector<int> l, int colIdx);

/**
 * @brief Function to get the target K value for a row
 *
 * @param[in] ratios Vector of doubles.
 * @return int
 */
int getTargetK(vector<double> ratios, int colIdx);

/**
 * @brief Function to swap values in a vector
 *
 * @param[in] l Vector of integers.
 * @param[in] k Integer.
 * @param[in] colIdx Integer.
 * @return vector<int>
 */
vector<int> swapValues(vector<int> l, int k, int colIdx);

/**
 * @brief Function to swap values in a matrix
 *
 * @param[in] matrix 2D vector of integers.
 * @param[in] k Integer.
 * @param[in] colIdx Integer.
 * @return matrix
 */
matrix eliminateRows(matrix matrix, vector<int> l, int colIdx, int pivotIdx, vector<int> pivotedRows);

/**
 * @brief Function to perform back substitution
 *
 * @param[in] matrix 2D vector of integers.
 * @param[in] l Vector of integers.
 * @return vector<double>
 */
vector<double> backSubstitution(matrix matrix, vector<int> l);

/**
 * @brief Function to perform scaled partial pivoting
 *
 * @param[in] matrix 2D vector of integers.
 */
void scaledPartialPivoting(matrix matrix);