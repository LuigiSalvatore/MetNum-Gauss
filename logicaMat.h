#ifndef _LOGICA_MAT_H
#define _LOGICA_MAT_H
#include "read.h"

extern std::vector<prob_struct> prob;
extern std::vector<std::vector<double>> mat;

void geraMatriz();                                 // usa as variaveis globais 'prob' e 'mat' para criar uma matriz com base n
void geraMatriz(const int);                        // usa as variaveis globais 'prob' e 'mat' para criar uma matriz com base n
void geraMatriz(const std::string);                // recebe um nome de arquivo, popula a 'prob' e cria uma matriz com base nela
void geraMatriz(const std::string, const int = 0); // recebe um nome de arquivo, popula a 'prob' e cria uma matriz com base nela
void printMat();                                   // imprime a matriz
void printDeps();                                  // imprime as dependencias em forma de string
void printEverything(const std::string s);         // imprime tudo, inclusive a matriz
void gauss();                                      // resolve o sistema linear
void importantPrints();

#endif // _LOGICA_MAT_H