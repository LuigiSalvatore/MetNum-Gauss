#ifndef _LOGICA_MAT_H
#define _LOGICA_MAT_H
#include "read.h"

extern std::vector<prob_struct> *prob;
extern std::vector<std::vector<double>> *mat;

void gaussElimination(std::vector<std::vector<double>> &matrix);

void geraMatriz();                         // usa as variaveis globais 'prob' e 'mat' para criar uma matriz com base n
void geraMatriz(const std::string);        // recebe um nome de arquivo, popula a 'prob' e cria uma matriz com base nela
void printMat();                           // imprime a matriz
void printEverything(const std::string s); // imprime tudo, inclusive a matriz
std::vector<double> *gauss();              // resolve o sistema linear
void gauss2();                             // resolve o sistema linear
std::vector<double> gaussElim();           // resolve o sistema linear usando a eliminação de gauss, e retorna um vetor com as variaveis

#endif // _LOGICA_MAT_H