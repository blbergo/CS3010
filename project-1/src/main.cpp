#include <main.h>
#include <input.h>

int main(int argc, char const *argv[])
{
    matrix matrix;
    string READING_FROM_FILE = prompt("Do you want to read from a file? (y/n): ");

    if (READING_FROM_FILE == "y")
    {
        string FILENAME = prompt("Enter the filepath: ");
        matrix = readMatrixFromFile(FILENAME);
    }
    else
    {
        cout << "Reading from console..." << endl;
        matrix = readMatrixFromConsole();
    }

    scaledPartialPivoting(matrix);

    return 0;
}
