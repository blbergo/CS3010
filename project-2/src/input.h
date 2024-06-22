#include <iostream>
#include <fstream>
#include <string.h>
#include <utils.h>

using namespace std;

/**
 * @brief Function to prompt the user for input
 *
 * @param[in] message String.
 * @return string
 */
string prompt(string message);

/**
 * @brief Function to read a matrix from a file
 *
 * @param[in] filename String.
 * @return matrix
 */
matrix readMatrixFromFile(string filename);

/**
 * @brief Function to read a matrix from the console
 *
 * @return matrix
 */
matrix readMatrixFromConsole();

/**
 * @brief Function to convert a string to a vector of doubles
 *
 * @param[in] str String.
 * @return vector<double>
 */
vector<double> stringToVector(string str);