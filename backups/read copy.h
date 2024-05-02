#ifndef _READ_H
#define _READ_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
// #include "probStruct.h"

extern int startingPeople;

struct prob_struct
{
    std::string x;
    double prob;
    std::string y;
};

prob_struct str2Prob(const std::string);
std::ostream &operator<<(std::ostream &os, const prob_struct &prob);

std::vector<prob_struct> *readFile(const std::string);
bool compare(const prob_struct prob1, const prob_struct prob2);

#endif // _READ_H