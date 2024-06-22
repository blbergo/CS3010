#include <input.h>

string prompt(string message)
{
    string input;
    cout << message;
    getline(cin, input);
    return input;
}

matrix readMatrixFromFile(string filename)
{
    matrix matrix;
    string line;
    ifstream file(filename);

    while (getline(file, line))
    {
        vector<double> row;
        string value;
        istringstream iss(line);

        while (getline(iss, value, ' '))
        {
            row.push_back(stod(value));
        }

        vector<double> coeffecients(row.begin(), row.end() - 1);

        matrix.matrix.push_back(coeffecients);
        matrix.bValues.push_back(row.back());
    }

    return matrix;
}

matrix readMatrixFromConsole()
{
    matrix matrix;
    int n = stoi(prompt("Enter the number of equations: "));

    for (int i = 0; i < n; i++)
    {
        vector<double> row;
        string line = prompt("Enter the coefficients separated by spaces: ");
        istringstream iss(line);
        string value;

        while (getline(iss, value, ' '))
        {
            row.push_back(stod(value));
        }

        vector<double> coeffecients(row.begin(), row.end() - 1);
        matrix.matrix.push_back(coeffecients);
        matrix.bValues.push_back(row.back());
    }

    return matrix;
}

vector<double> stringToVector(string str)
{
    vector<double> vec;
    istringstream iss(str);
    string value;

    while (getline(iss, value, ' '))
    {
        vec.push_back(stod(value));
    }

    return vec;
}