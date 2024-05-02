#include "logicaMat.h"
#include <iomanip>
#include <cmath>

std::vector<prob_struct> prob;
std::vector<std::vector<double>> mat;

void geraMatriz(std::string nomeArquivo, const int a)
{
    prob = readFile(nomeArquivo);
    if (a == 0)
        geraMatriz();
    else if (a == 1)
        geraMatriz(1);
}
void geraMatriz()
{
    for (int i = 0; i < prob.size(); i++) // line
    {
        std::vector<double> *row = new std::vector<double>();
        if (i % 2 == 0)
            continue;
        else
        {
            for (int j = 0; j < prob.size(); j++) // row
            {
                if (i == j && i % 2) // quando as duas variáveis são iguais
                    row->push_back(prob.at(i).prob);
                else if (i == j + 1 && i % 2)
                    row->push_back(prob.at(j).prob);
                else if (j % 2 == 0)
                    row->push_back(0);
            }
            mat.push_back(*row);
        }
    }
    std::vector<double> *row = new std::vector<double>();
    for (int i = 0; i < prob.size(); i++)
    {
        if (i % 2 == 0)
            row->push_back(0);
        else if (i + 1 == prob.size())
            row->push_back(1);
    }
    mat.push_back(*row);
}
void printMat()
{

    for (auto i : mat)
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
    geraMatriz(s, 1);
    std::cout << "Gente que entrou: " << startingPeople << " size: " << prob.size() << std::endl;
    for (int i = 0; i < prob.size(); i++)
        std::cout << prob.at(i) << std::endl;
    std::cout << "size of mat: " << mat.size() << std::endl;
    std::cout << "mat: " << std::endl
              << std::endl;
    printMat();
}
void printDeps()
{
    std::cout << "Dependencies: " << std::endl;
    for (auto it : prob)
        if (it.x == it.y)
            std::cout << it.x << "\t Roda \t\t\t\t\t" << it.prob << "% de chance" << std::endl;
        else
            std::cout << it.x << "\t Vai para\t" << it.y << "\t\t" << it.prob << "% de chance" << std::endl;
    std::cout << std::endl;
}
void geraMatriz(int)
{
    double v_size = prob.size();
    int m_size = std::ceil(v_size / 2);
#ifdef DEBUG
    std::cout << "v_size: " << v_size << std::endl;
    std::cout << "m_size: " << m_size << std::endl;
#endif
    std::vector<std::vector<double>> mAux;

    bool aux = true;
    for (int i = 0; i < m_size; i++)
    {
        std::vector<double> row;
        for (int j = 0; j < m_size; j++)
        {
            if (i == j) // quando o aluno rodar
            {
                row.push_back(prob[i + i].prob - 1);
                aux = !aux;
            }
            else if (i == j + 1) // quando o aluno for para a próxima matéria
            {
                row.push_back(prob[i + i - 1].prob);
                aux = !aux;
            }
            else
                row.push_back(0);
        }
        mAux.push_back(row);
    }
    mat = mAux;
}
void gauss()
{
    std::cout << std::endl;
    int n = mat.size() - 1;
    std::vector<double> B(n + 1, 0);
    B[0] = -startingPeople; /**/
    for (int j = 0; j <= n; j++)
    {
        for (int i = 0; i <= n; i++)
        {
            if (i > j)
            {
                double div = -(mat[i][j] / mat[j][j]);
                for (int k = 0; k <= n; k++)
                    mat[i][k] = div * mat[j][k] + mat[i][k];
                B[i] = div * B[j] + B[i];
            }
        }
    }
    for (int i = n; i >= 0; --i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            B[i] -= mat[i][j] * B[j];
        }
        B[i] /= mat[i][i];
    }
    for (auto i : B)
        std::cout << i << std::endl;
}
void gauss(int)
{

    int n = mat.size();
    for (int i = 0; i < n - 1; i++)
    {
        std::cout << "i: " << i << std::endl;
        /*
        double maxEl = abs(mat.at(i).at(i));
        int maxRow = i;
        for (int k = i + 1; k < n; k++)
        {
            if (abs(mat.at(k).at(i)) > maxEl)
            {
                maxEl = abs(mat.at(k).at(i));
                maxRow = k;
            }
        }
        for (int k = i; k < n + 1; k++)
        {
            double tmp = mat.at(maxRow).at(k);
            mat.at(maxRow).at(k) = mat.at(i).at(k);
            mat.at(i).at(k) = tmp;
        }*/
        for (int k = i + 1; k < n; k++)
        {
            double c = -mat[k][i] / mat[i][i];
            // std::cout << "n,k,i: " << n << "," << k << "," << i << std::endl;
            for (int j = i; j < n + 1; j++)
                if (i == j)
                    mat[k][j] = 0;
                else
                    mat[k][j] += c * mat[i][j];
        }
        printMat();
    } /*
     std::vector<double> *x = new std::vector<double>(n);
     for (int i = n - 1; i >= 0; i--)
     {
         x->at(i) = mat.at(i).at(n) / mat.at(i).at(i);
         for (int k = i - 1; k >= 0; k--)
             mat.at(k).at(n) -= mat.at(k).at(i) * x->at(i);
     }
     for (auto i : *x)
         std::cout << i << std::endl;
 */
}