#include <main.h>
#include <input.h>

int main(int argc, char const *argv[])
{
    matrix mat;
    string READING_FROM_FILE = prompt("Do you want to read from a file? (y/n): ");

    if (READING_FROM_FILE == "y")
    {
        string FILENAME = prompt("Enter the filepath: ");
        mat = readMatrixFromFile(FILENAME);
    }
    else
    {
        cout << "Reading from console..." << endl;
        mat = readMatrixFromConsole();
    }

    string STARTING_SOLUTIONS = prompt("Enter the starting solutions: ");
    string DESIRED_ERROR = prompt("Enter the desired error: ");

    matrix coeffecients = calculateCoeffecients(mat);
    printMatrix(coeffecients);

    vector<double> solutions = stringToVector(STARTING_SOLUTIONS);
    double desiredError = stod(DESIRED_ERROR);

    cout << "Jacobi Method:" << endl;
    vector<double> jacobi = jacobiMethod(coeffecients, solutions, desiredError);
    cout << "Jacobi solutions: ";
    printVector(jacobi);
    cout << endl
         << endl;

    cout << "Gauss-Seidel Method:" << endl;
    vector<double> gaussSeidel = gaussSeidelMethod(coeffecients, solutions, desiredError);
    cout << "Gauss-Seidel solutions: ";
    printVector(gaussSeidel);
    cout << endl;

    return 0;
}
