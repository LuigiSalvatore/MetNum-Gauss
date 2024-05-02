#include <iostream>

const int MAX_ROWS = 3;

const int MAX_COLS = 4;

void gaussJordan(double matrix[MAX_ROWS][MAX_COLS], int rows, int cols)
{

    for (int i = 0; i < rows; ++i)
    {

        // Normalização da linha atual

        double divisor = matrix[i][i];

        for (int j = 0; j < cols; ++j)
        {

            matrix[i][j] /= divisor;
        }

        // Redução das outras linhas

        for (int k = 0; k < rows; ++k)
        {

            if (k != i)
            {

                double factor = matrix[k][i];

                for (int j = 0; j < cols; ++j)
                {

                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }
}

void printMatrix(double matrix[MAX_ROWS][MAX_COLS], int rows, int cols)
{

    for (int i = 0; i < rows; ++i)
    {

        for (int j = 0; j < cols; ++j)
        {

            std::cout << matrix[i][j] << "\t";
        }

        std::cout << std::endl;
    }
}

int main()
{

    double matrix[MAX_ROWS][MAX_COLS] = {

        {2, 1, -1, 8},

        {-3, -1, 2, -11},

        {-2, 1, 2, -3}

    };

    std::cout << "Matrix inicial:" << std::endl;

    printMatrix(matrix, MAX_ROWS, MAX_COLS);

    gaussJordan(matrix, MAX_ROWS, MAX_COLS);

    std::cout << "Solução:" << std::endl;

    printMatrix(matrix, MAX_ROWS, MAX_COLS);

    return 0;
}