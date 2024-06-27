#include <main.h>
#include <utils.h>

int main(int argc, char const *argv[])
{
    double EPSILON = 0.001;

    vector<double> f = {2,
                        -11.7,
                        17.7,
                        -5};

    // bisection
    double bisectionPartA1 = bisectionMethod(0, 4, f, evaluateFunction, "bisection-a-1.csv");
    printMethodResult("Bisection Root 1 (a):", bisectionPartA1);

    double bisectionPartA2 = bisectionMethod(0, bisectionPartA1, f, evaluateFunction, "bisection-a-2.csv");
    printMethodResult("Bisection Root 2 (a):", bisectionPartA2);

    double bisectionPartA3 = bisectionMethod(bisectionPartA1, bisectionPartA2, f, evaluateFunction, "bisection-a-3.csv");
    printMethodResult("Bisection Root 3 (a):", bisectionPartA3);

    double bisectionPartB = bisectionMethod(120, 130, f, evaluateSpecialFunction, "bisection-b.csv");
    printMethodResult("Bisection Root (b):", bisectionPartB);

    // NR
    double newtonPartA1 = newtonRaphsonMethod(0, f, evaluateFunction, "newton-a-1.csv");
    printMethodResult("Newton-Raphson Root 1 (a):", newtonPartA1);

    double newtonPartA2 = newtonRaphsonMethod(newtonPartA1 + 1, f, evaluateFunction, "newton-a-2.csv");
    printMethodResult("Newton-Raphson Root 2 (a):", newtonPartA2);

    double newtonPartA3 = newtonRaphsonMethod(newtonPartA2 + 1, f, evaluateFunction, "newton-a-3.csv");
    printMethodResult("Newton-Raphson Root 3 (a):", newtonPartA3);

    double newtonPartB = newtonRaphsonMethod(120, f, evaluateSpecialFunction, "newton-b.csv");
    printMethodResult("Newton-Raphson Root (b):", newtonPartB);

    // secant
    double secantPartA1 = secantMethod(0, 4, f, evaluateFunction, "secant-a-1.csv");
    printMethodResult("Secant Root 1 (a):", secantPartA1);

    double secantPartA2 = secantMethod(0, secantPartA1 - 1, f, evaluateFunction, "secant-a-2.csv");
    printMethodResult("Secant Root 2 (a):", secantPartA2);

    double secantPartA3 = secantMethod(0, secantPartA1 + 1, f, evaluateFunction, "secant-a-3.csv");
    printMethodResult("Secant Root 3 (a):", secantPartA3);

    double secantPartB = secantMethod(120, 130, f, evaluateSpecialFunction, "secant-b.csv");
    printMethodResult("Secant Root (b):", secantPartB);

    // FP
    double falsePositionPartA1 = falsePositionMethod(0, 4, f, evaluateFunction, "false-position-a-1.csv");
    printMethodResult("False Position Root 1 (a):", falsePositionPartA1);

    double falsePositionPartA2 = falsePositionMethod(falsePositionPartA1 + 1, 2, f, evaluateFunction, "false-position-a-2.csv");
    printMethodResult("False Position Root 2 (a):", falsePositionPartA2);

    double falsePositionPartA3 = falsePositionMethod(falsePositionPartA2 + 1, 4, f, evaluateFunction, "false-position-a-3.csv");
    printMethodResult("False Position Root 3 (a):", falsePositionPartA3);

    double falsePositionPartB = falsePositionMethod(120, 130, f, evaluateSpecialFunction, "false-position-b.csv");
    printMethodResult("False Position Root (b):", falsePositionPartB);

    return 0;
}
