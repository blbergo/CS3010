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
 * @brief Function to calculate the coefficients of the matrix
 *
 * @param[in] mat Matrix to calculate the coefficients for.
 * @return matrix The matrix with the coefficients.
 */
matrix calculateCoeffecients(matrix mat);

/**
 * @brief Function to calculate the error between the previous and current values
 *
 * @param[in] previous The previous value.
 * @param[in] current The current value.
 * @return double The error between the two values.
 */
double calculateRelativeError(double previous, double current);

/**
 * @brief Function to calculate the Jacobi method
 *
 * @param[in] coefficients The coefficients of the matrix.
 * @param[in] vector<startingSolutions> The starting solutions.
 * @param[in] desiredError The desired error.
 * @return vector<double> The solutions.
 */
vector<double> jacobiMethod(matrix coefficients, vector<double> startingSolutions, double desiredError);

/**
 * @brief Function to calculate the Gauss-Seidel method
 *
 * @param[in] coefficients The coefficients of the matrix.
 * @param[in] vector<startingSolutions> The starting solutions.
 * @param[in] desiredError The desired error.
 * @return vector<double> The solutions.
 */

vector<double> gaussSeidelMethod(matrix coefficients, vector<double> startingSolutions, double desiredError);