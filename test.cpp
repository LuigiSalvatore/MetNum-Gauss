
#include "test.h"

void gauss(double **a, double *b)
{
    int n = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < n; i++)
    {
        // Encontrar a linha com o maior valor absoluto na coluna i
        int maxRow = i;
        for (int k = i + 1; k < n; k++)
        {
            if (std::abs(a[k][i]) > std::abs(a[maxRow][i]))
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