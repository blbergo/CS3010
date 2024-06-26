#include <output.h>

void writeMatrixToCSV(vector<vector<double>> mat, string filename)
{
    ofstream file;
    file.open(filename);

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            file << mat[i][j] << ",";
        }
        file << endl;
    }

    file.close();
}