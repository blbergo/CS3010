#include <main.h>
#include <utils.h>

int main(int argc, char const *argv[])
{
    vector<double> f = {2,
                        -11.7,
                        17.7,
                        -5};

    double bisectionPartA = bisectionMethod(0, 4, f, evaluateFunction, "bisection-a.csv");
    cout << "Root of the function using the bisection method for equation 1: " << bisectionPartA << endl;

    double bisectionPartB = bisectionMethod(0, 8, f, evaluateSpecialFunction, "bisection-b.csv");
    cout << "Root of the function using the bisection method for equation 2: " << bisectionPartB << endl;

    double newtonPartA = newtonRaphsonMethod(4, f, evaluateFunction, "newton-a.csv");
    cout << "Root of the function using the Newton-Raphson method for equation 1: " << newtonPartA << endl;

    double newtonPartB = newtonRaphsonMethod(8, f, evaluateSpecialFunction, "newton-b.csv");
    cout << "Root of the function using the Newton-Raphson method for equation 2: " << newtonPartB << endl;

    return 0;
}
