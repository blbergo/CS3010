#include <utils.h>
#include <iostream>
#include <cmath>
#include <output.h>

using namespace std;

int MAX_ITERATIONS = 100;
double EPSILON = 0.001;

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

void printTableHeaders(vector<string> headers)
{
    for (int i = 0; i < headers.size() - 1; i++)
    {
        cout << headers[i] << " | ";
    }

    cout << headers[headers.size() - 1] << endl;

    for (int i = 0; i < headers.size() - 1; i++)
    {
        cout << "------";
    }
    cout << endl;
}

void printTableRow(vector<string> row)
{
    for (int i = 0; i < row.size() - 1; i++)
    {
        cout << row[i] << " | ";
    }

    cout << row[row.size() - 1] << endl;
}

double calculateRelativeError(double previous, double current)
{
    return abs((current - previous) / current);
}

double evaluateFunction(vector<double> f, double x)
{
    double result = 0;

    for (int i = 0; i < f.size() - 1; i++)
    {
        result += f[i] * pow(x, f.size() - 1 - i);
    }

    result += f[f.size() - 1];

    return result;
}

double evaluateSpecialFunction(vector<double> f, double x)
{
    return x + 10 - x * cosh(50 / x);
}

double bisectionMethod(double a, double b, vector<double> f, function<double(vector<double>, double)> evalFunction, string outputFilename)
{
    cout << "Bisection Method" << endl;
    double c = 0;
    double fa = evalFunction(f, a);
    double fb = evalFunction(f, b);
    double fc = 0;

    matrix rows;

    if (a * b > 0)
    {
        cout << "The function has the same sign at the endpoints." << endl;
        return 0;
    }

    printTableHeaders({"n", "a", "b", "f(a)", "f(b)", "c", "f(c)", "Error"});

    for (int i = 0; i < MAX_ITERATIONS; i++)
    {
        c = (a + b) / 2;
        fc = evalFunction(f, c);
        double error = (b - a) / pow(2, i + 1);

        printTableRow({to_string(i), to_string(a), to_string(b), to_string(fa), to_string(fb), to_string(c), to_string(fc), to_string(error)});
        rows.matrix.push_back({(double)i, a, b, fa, fb, c, fc, error});

        if (fc == 0 || error < EPSILON)
        {
            break;
        }

        if (fa * fc < 0)
        {
            b = c;
            fb = fc;
        }
        else
        {
            a = c;
            fa = fc;
        }
    }

    writeMatrixToCSV(rows.matrix, "./output/" + outputFilename);

    return c;
}

double newtonRaphsonMethod(double x0, vector<double> f, function<double(vector<double>, double)> evalFunction, string outputFilename)
{
    cout << "Newton-Raphson Method" << endl;
    double x1 = 0;
    double fx0 = evalFunction(f, x0);
    double fx1 = 0;
    double error = 0;

    matrix rows;

    printTableHeaders({"n", "x0", "f(x0)", "f'(x0)", "x1", "Error"});

    for (int i = 0; i < MAX_ITERATIONS; i++)
    {
        double fpx0 = (evalFunction(f, x0 + EPSILON) - evalFunction(f, x0)) / EPSILON;
        x1 = x0 - fx0 / fpx0;
        fx1 = evalFunction(f, x1);
        error = calculateRelativeError(x0, x1);

        printTableRow({to_string(i), to_string(x0), to_string(fx0), to_string(fpx0), to_string(x1), to_string(error)});
        rows.matrix.push_back({(double)i, x0, fx0, fpx0, x1, error});

        if (error < EPSILON)
        {
            break;
        }

        x0 = x1;
        fx0 = fx1;
    }

    writeMatrixToCSV(rows.matrix, "./output/" + outputFilename);

    return x1;
}