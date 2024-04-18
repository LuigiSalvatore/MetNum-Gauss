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