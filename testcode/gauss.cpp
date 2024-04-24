// #include "read.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#define MAT_SIZE_ 3
using namespace std;

void printMatrix(const double a[MAT_SIZE_][MAT_SIZE_], const double b[MAT_SIZE_]);
void gauss(double a[MAT_SIZE_][MAT_SIZE_], double b[MAT_SIZE_]);

int main()
{

    // a[COLUNA][LINHA]
    double a[MAT_SIZE_][MAT_SIZE_] = {
        {22, 6, 14},
        {18, 9, -5},
        {13, -4, 10}}; // 3x3 matrix

    double b[MAT_SIZE_] =
        {9, 8, 4}; // 3x1 matrix
    printMatrix(a, b);

    gauss(a, b);

    printMatrix(a, b);

    return 0;
}

void printMatrix(const double a[MAT_SIZE_][MAT_SIZE_], const double b[MAT_SIZE_])
{
    stringstream ss;

    for (int i = 0; i < MAT_SIZE_; i++)
    {
        ss << "| ";
        for (int j = 0; j < MAT_SIZE_; j++)
        {
            if (a[i][j] >= 0)
                ss << " " << a[i][j] << std::setfill(' ') << std::setw(3) << " ";
            else
                ss << a[i][j] << std::setfill(' ') << std::setw(3) << " ";
        }
        if (b[i] >= 0)
            ss << "|  " << b[i] << std::setfill(' ') << std::setw(3) << " | " << endl;
        else
            ss << "| " << b[i] << std::setfill(' ') << std::setw(3) << " | " << endl;
    }
    ss << endl
       << endl;
    cout << ss.str();
}
void gauss(double a[MAT_SIZE_][MAT_SIZE_], double b[MAT_SIZE_])
{
    int n = MAT_SIZE_;

    for (int i = 0; i < n; i++)
    {
        // Encontrar a linha com o maior valor absoluto na coluna i
        int maxRow = i;
        for (int k = i + 1; k < n; k++)
        {
            if (abs(a[k][i]) > abs(a[maxRow][i]))
            {
                maxRow = k;
            }
        }

        // Trocar a linha máxima com a linha atual
        for (int k = i; k < n; k++)
        {
            double temp = a[maxRow][k];
            a[maxRow][k] = a[i][k];
            a[i][k] = temp;
        }
        double temp = b[maxRow];
        b[maxRow] = b[i];
        b[i] = temp;

        // Fazer todos os elementos abaixo deste um zero
        for (int k = i + 1; k < n; k++)
        {
            double factor = a[k][i] / a[i][i];
            for (int j = i; j < n; j++)
            {
                a[k][j] -= factor * a[i][j];
            }
            b[k] -= factor * b[i];
        }
    }

    // Resolver Ax=b para uma matriz triangular superior
    for (int i = n - 1; i >= 0; i--)
    {
        for (int k = i + 1; k < n; k++)
        {
            b[i] -= a[i][k] * b[k];
        }
        b[i] = b[i] / a[i][i];
    }
}