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
 * @brief Function to print the headers of a table
 *
 * @param[in] headers Vector of strings containing the headers.
 */
void printTableHeaders(vector<string> headers);

/**
 * @brief Function to print a row of a table
 *
 * @param[in] row Vector of strings containing the row.
 */
void printTableRow(vector<string> row);

/**
 * @brief Function to print the result of a method
 *
 * @param[in] method The name of the method.
 * @param[in] result The result of the method.
 */
void printMethodResult(string method, double result);

/**
 * @brief Function to calculate the error between the previous and current values
 *
 * @param[in] previous The previous value.
 * @param[in] current The current value.
 * @return double The error between the two values.
 */
double calculateRelativeError(double previous, double current);

/**
 * @brief Function to evaluate a function given a vector of coefficients and a value
 *
 * @param[in] f Vector of coefficients.
 * @param[in] x Value to evaluate the function at.
 * @return double The result of the function evaluation.
 */
double evaluateFunction(vector<double> f, double x);

/**
 * @brief Function to evaluate a special function given a value
 *
 * @param[in] x Value to evaluate the function at.
 * @param[in] f Vector of coefficients.
 * @return double The result of the function evaluation.
 */
double evaluateSpecialFunction(vector<double> f, double x);

/**
 * @brief Function to find the root of a function using the bisection method
 *
 * @param[in] a The lower bound of the interval.
 * @param[in] b The upper bound of the interval.
 * @param[in] f Vector of coefficients of the function.
 * @param[in] evalFunction Function to evaluate the function.
 * @param[in] outputFilename The name of the file to write the output to.
 * @return double The root of the function.
 */
double bisectionMethod(double a, double b, vector<double> f, function<double(vector<double>, double)> evalFunction, string outputFilename);

/**
 * @brief Function to find the root of a function using the Newton-Raphson method
 *
 * @param[in] x0 The initial guess.
 * @param[in] f Vector of coefficients of the function.
 * @param[in] evalFunction Function to evaluate the function.
 * @param[in] evalDerivative Function to evaluate the derivative of the function.
 * @param[in] outputFilename The name of the file to write the output to.
 * @return double The root of the function.
 */
double newtonRaphsonMethod(double x0, vector<double> f, function<double(vector<double>, double)> evalFunction, string outputFilename);

/**
 * @brief Function to find the root of a function using the secant method
 *
 * @param[in] x0 The first initial guess.
 * @param[in] x1 The second initial guess.
 * @param[in] f Vector of coefficients of the function.
 * @param[in] evalFunction Function to evaluate the function.
 * @param[in] outputFilename The name of the file to write the output to.
 * @return double The root of the function.
 */
double secantMethod(double x0, double x1, vector<double> f, function<double(vector<double>, double)> evalFunction, string outputFilename);

/**
 * @brief Function to find the root of a function using the false position method
 *
 * @param[in] a The lower bound of the interval.
 * @param[in] b The upper bound of the interval.
 * @param[in] f Vector of coefficients of the function.
 * @param[in] evalFunction Function to evaluate the function.
 * @param[in] outputFilename The name of the file to write the output to.
 * @return double The root of the function.
 */
double falsePositionMethod(double a, double b, vector<double> f, function<double(vector<double>, double)> evalFunction, string outputFilename);

/**
 * @brief Function to find the root of a function using the modified secant method
 *
 * @param[in] x0 The initial guess.
 * @param[in] delta The step size.
 * @param[in] f Vector of coefficients of the function.
 * @param[in] evalFunction Function to evaluate the function.
 * @param[in] outputFilename The name of the file to write the output to.
 * @return double The root of the function.
 */
double modifiedSecantMethod(double x0, double delta, vector<double> f, function<double(vector<double>, double)> evalFunction, string outputFilename);