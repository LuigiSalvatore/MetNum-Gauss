#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

// using namespace std;
const std::string PATH = "./Casos/";
void read(std::string s);
void swap(double *a, double *b);
bool compare(std::string a, std::string b);

int main()
{
    read(PATH + "casob.txt");
    return 0;
}

void read(std::string s)
{
    std::string line;
    std::ifstream file(s);
    if (!file.is_open())
    {
        std::cout << "Unable to open file" << std::endl;
        return;
    }
    s = "";
    int startingPeople = 0;
    std::vector<std::string> v_lines;
    for (int i = 0; getline(file, line); i++)
    {
        if (i == 0)
            s = line;
        else
            v_lines.push_back(line);
    }
    file.close();
    sort(v_lines.begin(), v_lines.end());                                   // deixa a lista em ordem crescente
    swap(v_lines[v_lines.size() - 1], v_lines[v_lines.size() - 2]);         // deixa o Diploma por ultimo
    if (!(std::istringstream(s) >> line >> line >> line >> startingPeople)) //
        startingPeople = -1;

    /*====================================================================*/
    int v_size = v_lines.size();
    int m_size = v_size / 2 + 1;
#ifdef DEBUG
    std::cout << "v_size: " << v_size << std::endl;
    std::cout << "m_size: " << m_size << std::endl;
#endif
    double matrix[m_size][m_size];
    std::string matrix_column_names[m_size];
    /*====================================================================*/
    for (int i = 0; i < m_size; i++) // inicializa a matriz com 0
        for (int j = 0; j < m_size; j++)
            matrix[i][j] = 0;

    /*====================================================================*/
    for (int i = 0; i < m_size; i++) // prints matrix
    {
        for (int j = 0; j < m_size; j++)
            std::cout << std::fixed << matrix[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    /*====================================================================*/

    for (int i = 0; i < v_size; i++) // percorre todo o vetor de linhas
    {
        std::string from_var, to_var, aux, trash;
        std::istringstream(v_lines[i]) >> from_var >> trash >> aux >> trash >> to_var;
        if (i % 2 == 0)
        {
            matrix_column_names[i / 2] = from_var;
            matrix[i / 2][i / 2] = stod(aux) - 1;
        }
        else
        {
            matrix[i / 2 + 1][i / 2] = stod(aux);
        }
#ifdef DEBUG
        std::cout << "from_var: " << from_var << " to_var: " << to_var << " aux: " << aux << std::endl;
#endif
    }
    matrix[m_size - 1][m_size - 1] = -1; // sets last element of matrix to 1 for Diploma
    /*====================================================================*/
    // prints matrix //
    for (int i = 0; i < m_size; i++)
    {
        for (int j = 0; j < m_size; j++)
            std::cout << std::fixed << matrix[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    /*====================================================================*/

    for (int i = 0; i < m_size; i++)
    {
        // Find maximum in column i:
        double maxEl = abs(matrix[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < m_size; k++)
            if (abs(matrix[k][i]) > maxEl)
            {
                maxEl = abs(matrix[k][i]);
                maxRow = k;
            }

        // Swap maximum row with current row:

        swap(matrix[maxRow], matrix[i]);
        swap(matrix_column_names[maxRow], matrix_column_names[i]);

        // Make all rows below this one 0 in current column:
        for (int k = i + 1; k < m_size; k++)
        {
            double c = -matrix[k][i] / matrix[i][i];
            std::cout << "c: " << c << "\n";
            for (int j = i; j < m_size + 1; j++)

                if (i == j)
                    matrix[k][j] = 0;
                else
                    matrix[k][j] += c * matrix[i][j];
        }
    }
    std::cout << "cheguei aqui\n";
    ;
    /*====================================================================*/
    // prints matrix //
    for (int i = 0; i < m_size; i++)
    {
        for (int j = 0; j < m_size; j++)
            std::cout << std::fixed << matrix[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    /*====================================================================*/
    // Solve equation Ax=b for an upper triangular matrix A:
    std::vector<double> x(m_size);
    x[0] = startingPeople * -1;
    for (auto i : x)
        std::cout << i << std::endl;
    std::cout << std::endl;
    /*====================================================================*/
    for (int i = m_size - 1; i >= 0; i--)
    {
        x[i] = matrix[i][m_size] / matrix[i][i];
        for (int k = i - 1; k >= 0; k--)
            matrix[k][m_size] -= matrix[k][i] * x[i];
    }
    std::cout << std::endl;
    /*====================================================================*/
    // prints matrix //
    for (int i = 0; i < m_size; i++)
    {
        for (int j = 0; j < m_size; j++)
            std::cout << std::fixed << matrix[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    /*====================================================================*/

    // Print solution:
    for (int i = 0; i < m_size; i++)
        std::cout << x[i] << std::endl;

    std::cout << "Starting people: " << startingPeople << std::endl;
}
void swap(double *a, double *b)
{
    double aux[sizeof(a) / sizeof(a[0])];
    int m_size_loop = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < m_size_loop; i++)
    {
        aux[i] = a[i];
        a[i] = b[i];
        b[i] = aux[i];
    }
}
bool compare(auto &a, auto &b)
{
    std::string from_var, to_var, aux, trash, from_var2, to_var2, aux2, trash2;
    std::istringstream(a) >> from_var >> trash >> aux >> trash >> to_var;
    std::istringstream(b) >> from_var2 >> trash2 >> aux2 >> trash2 >> to_var2;
    if (from_var != from_var2)
        return from_var < from_var2;
    else if (to_var != to_var2)
        return to_var < to_var2;
    else
        return aux < aux2;
}
