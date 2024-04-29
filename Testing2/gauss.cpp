#include <iostream>
#include <vector>

void gaussElimination(std::vector<std::vector<double>> &matrix)
{

    for (int i = 0; i < m_size; i++)
    {
        // Find maximum in column i:
        double maxEl = abs(matrix[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < m_size; k++)
        {
            if (abs(matrix[k][i]) > maxEl)
            {
                maxEl = abs(matrix[k][i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row:
        std::swap(matrix[maxRow], matrix[i]);

        // Make all rows below this one 0 in current column:
        for (int k = i + 1; k < m_size; k++)
        {
            double c = -matrix[k][i] / matrix[i][i];
            for (int j = i; j < m_size + 1; j++)
            {
                if (i == j)
                {
                    matrix[k][j] = 0;
                }
                else
                {
                    matrix[k][j] += c * matrix[i][j];
                }
            }
        }
    }
    std::cout << "cheguei aqui\m_size";

    // Solve equation Ax=b for an upper triangular matrix A:
    std::vector<double> x(m_size);
    for (int i = m_size - 1; i >= 0; i--)
    {
        x[i] = matrix[i][m_size] / matrix[i][i];
        for (int k = i - 1; k >= 0; k--)
        {
            matrix[k][m_size] -= matrix[k][i] * x[i];
        }
    }

    // Print solution:
    for (int i = 0; i < m_size; i++)
    {
        std::cout << x[i] << std::endl;
    }
}