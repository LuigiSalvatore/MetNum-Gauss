#include "logicaMat.h"
#include <iomanip>

std::vector<prob_struct> *prob;
std::vector<std::vector<double>> *mat = new std::vector<std::vector<double>>();

void geraMatriz(std::string nomeArquivo)
{
    prob = readFile(nomeArquivo);
    geraMatriz();
}
void geraMatriz()
{
    for (int i = 0; i < prob->size(); i++) // line
    {
        std::vector<double> *row = new std::vector<double>();
        if (i % 2 == 0)
            continue;
        else
        {
            for (int j = 0; j < prob->size(); j++) // row
            {
                if (i == j && i % 2) // quando as duas variáveis são iguais
                    row->push_back(prob->at(i).prob);
                else if (i == j + 1 && i % 2)
                    row->push_back(prob->at(j).prob);
                else if (j % 2 == 0)
                    row->push_back(0);
            }
            mat->push_back(*row);
        }
    }
    std::vector<double> *row = new std::vector<double>();
    for (int i = 0; i < prob->size(); i++)
    {
        if (i % 2 == 0)
            row->push_back(0);
        else if (i + 1 == prob->size())
            row->push_back(1);
    }
    mat->push_back(*row);
}
void printMat()
{

    for (auto i : *mat)
    {
        for (auto j : i)
        {
            std::cout << std::setprecision(6) << std::fixed << j << " ";
        }
        std::cout << std::endl;
    }
}
void printEverything(std::string s)
{
    geraMatriz(s);
    std::cout << "Gente que entrou: " << startingPeople << " size: " << prob->size() << std::endl;
    for (int i = 0; i < prob->size(); i++)
        std::cout << prob->at(i) << std::endl;
    std::cout << "size of mat: " << mat->size() << std::endl;
    std::cout << "mat: " << std::endl
              << std::endl;
    printMat();
}
std::vector<double> *gauss()
{
    int n = mat->size();
    for (int i = 0; i < n; i++)
    {
        // Search for maximum in this column
        double maxEl = abs(mat->at(i).at(i));
        int maxRow = i;
        for (int k = i + 1; k < n; k++)
        {
            if (abs(mat->at(k).at(i)) > maxEl)
            {
                maxEl = abs(mat->at(k).at(i));
                maxRow = k;
            }
        }

        // Swap maximum row with current row (column by column)
        for (int k = i; k < n + 1; k++)
        {
            double tmp = mat->at(maxRow).at(k);
            mat->at(maxRow).at(k) = mat->at(i).at(k);
            mat->at(i).at(k) = tmp;
        }

        // Make all rows below this one 0 in current column
        for (int k = i + 1; k < n; k++)
        {
            double c = -mat->at(k).at(i) / mat->at(i).at(i);
            for (int j = i; j < n + 1; j++)
            {
                if (i == j)
                {
                    mat->at(k).at(j) = 0;
                }
                else
                {
                    mat->at(k).at(j) += c * mat->at(i).at(j);
                }
            }
        }
    }

    // Solve equation Ax=b for an upper triangular matrix A
    std::vector<double> *x = new std::vector<double>(n);
    for (int i = n - 1; i >= 0; i--)
    {
        x->at(i) = mat->at(i).at(n) / mat->at(i).at(i);
        for (int k = i - 1; k >= 0; k--)
        {
            mat->at(k).at(n) -= mat->at(k).at(i) * x->at(i);
        }
    }

    return x;
}
void gauss2()
{
    int n = mat->size();
    for (int i = 0; i < n; i++)
    {
        // Search for maximum in this column
        double maxEl = abs(mat->at(i).at(i));
        int maxRow = i;
        for (int k = i + 1; k < n; k++)
        {
            if (abs(mat->at(k).at(i)) > maxEl)
            {
                maxEl = abs(mat->at(k).at(i));
                maxRow = k;
            }
        }

        // Swap maximum row with current row (column by column)
        std::cout << "CHEGUEI AQUI KRL" << std::endl;

        for (int k = i; k < n + 1; k++)
        {
            double tmp = mat->at(maxRow).at(k);
            mat->at(maxRow).at(k) = mat->at(i).at(k);
            mat->at(i).at(k) = tmp;
        }
        std::cout << "CHEGUEI AQUI KRL" << std::endl;

        // Make all rows below this one 0 in current column
        for (int k = i + 1; k < n; k++)
        {
            double c = -mat->at(k).at(i) / mat->at(i).at(i);
            for (int j = i; j < n + 1; j++)
            {
                if (i == j)
                {
                    mat->at(k).at(j) = 0;
                }
                else
                {
                    mat->at(k).at(j) += c * mat->at(i).at(j);
                }
            }
        }
    }

    // Solve equation Ax=b for an upper triangular matrix A
    std::cout << "CHEGUEI AQUI KRL" << std::endl;
    std::vector<double> x(n);
    for (int i = n - 1; i >= 0; i--)
    {
        x.at(i) = mat->at(i).at(n) / mat->at(i).at(i);
        for (int k = i - 1; k >= 0; k--)
        {
            mat->at(k).at(n) -= mat->at(k).at(i) * x.at(i);
        }
    }

    // // Print result
    std::cout << "Result:\t";
    for (int i = 0; i < n; i++)
    {
        std::cout << x.at(i) << " ";
    }
    std::cout << std::endl;
}
std::vector<double> gaussElim() // resolve o sistema linear usando a eliminação de gauss, e retorna um vetor com as variaveis
{
    int n = mat->size();
    for (int i = 0; i < n; i++)
    {
        // Search for maximum in this column
        double maxEl = abs(mat->at(i).at(i));
        int maxRow = i;
        for (int k = i + 1; k < n; k++)
        {
            if (abs(mat->at(k).at(i)) > maxEl)
            {
                maxEl = abs(mat->at(k).at(i));
                maxRow = k;
            }
        }

        // Swap maximum row with current row (column by column)
        for (int k = i; k < n + 1; k++)
        {
            double tmp = mat->at(maxRow).at(k);
            mat->at(maxRow).at(k) = mat->at(i).at(k);
            mat->at(i).at(k) = tmp;
        }

        // Make all rows below this one 0 in current column
        for (int k = i + 1; k < n; k++)
        {
            double c = -mat->at(k).at(i) / mat->at(i).at(i);
            for (int j = i; j < n + 1; j++)
            {
                if (i == j)
                {
                    mat->at(k).at(j) = 0;
                }
                else
                {
                    mat->at(k).at(j) += c * mat->at(i).at(j);
                }
            }
        }
    }

    // Solve equation Ax=b for an upper triangular matrix A
    std::vector<double> x(n);
    for (int i = n - 1; i >= 0; i--)
    {
        x.at(i) = mat->at(i).at(n) / mat->at(i).at(i);
        for (int k = i - 1; k >= 0; k--)
        {
            mat->at(k).at(n) -= mat->at(k).at(i) * x.at(i);
        }
    }

    return x;
}
void gaussElimination(std::vector<std::vector<double>> &matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        // Find maximum in column i:
        double maxEl = abs(matrix[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++)
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
        for (int k = i + 1; k < n; k++)
        {
            double c = -matrix[k][i] / matrix[i][i];
            for (int j = i; j < n + 1; j++)
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

    // Solve equation Ax=b for an upper triangular matrix A:
    std::vector<double> x(n);
    x[0] = startingPeople;
    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = matrix[i][n] / matrix[i][i];
        for (int k = i - 1; k >= 0; k--)
        {
            matrix[k][n] -= matrix[k][i] * x[i];
        }
    }

    // Print solution:
    for (int i = 0; i < n; i++)
    {
        std::cout << x[i] << std::endl;
    }
}