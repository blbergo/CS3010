#include <utils.h>
#include <iostream>
#include <cmath>

using namespace std;

int MAX_ITERATIONS = 50;
double EPSILON = numeric_limits<float>::epsilon();

void printVector(vector<double> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
}

void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

double calculateRelativeError(double previous, double current)
{
    return abs((current - previous) / current);
}
