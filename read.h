#ifndef _READ_H
#define _READ_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "probStruct.h"

std::vector<prob_struct> *readFile(const std::string);
bool compare(const prob_struct prob1, const prob_struct prob2);

#endif // _READ_H