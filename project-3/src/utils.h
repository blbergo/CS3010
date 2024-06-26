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
 * @brief Function to calculate the error between the previous and current values
 *
 * @param[in] previous The previous value.
 * @param[in] current The current value.
 * @return double The error between the two values.
 */
double calculateRelativeError(double previous, double current);
