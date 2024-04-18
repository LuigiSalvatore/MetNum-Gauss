/* arquivo para testar transformar o input em uma matrix n° x n°*/
#include "read.h"

using namespace std;

vector<prob_struct> *prob;
vector<vector<double>> *mat = new vector<vector<double>>();
void geraMatriz();
void printMat();

int main()
{
    prob = readFile("caso1.txt");
    // cout << prob->size() << endl; // should use n/2 +1 for number of variables
    cout << ". . . " << startingPeople << " size: " << prob->size() << endl;
    for (int i = 0; i < prob->size(); i++)
        cout << prob->at(i) << endl;
    geraMatriz();
    cout << "size of mat: " << mat->size() << endl;
    cout << "mat: " << endl
         << endl;
    printMat();

    return 0;
}

void geraMatriz(std::string nomeArquivo)
{
    prob = readFile(nomeArquivo);
    geraMatriz();
}
void geraMatriz()
{
    for (int i = 0; i < prob->size(); i++) // line
    {
        vector<double> *row = new vector<double>();
        if (i % 2 == 0)
            continue;
        else
            for (int j = 0; j < prob->size(); j++) // row
            {
                if (i == j && i % 2) // quando as duas variáveis são iguais
                    row->push_back(prob->at(i).prob);
                else if (i == j + 1 && i % 2)
                    row->push_back(prob->at(j).prob);
                else
                    row->push_back(0);
            }
        mat->push_back(*row);
    }
}
void printMat()
{

    for (auto i : *mat)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}