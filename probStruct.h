#ifndef _PROBSTRUCT_H
#define _PROBSTRUCT_H

#include <string>
#include <sstream>

struct prob_struct
{
    std::string x;
    double prob;
    std::string y;
};

prob_struct str2Prob(const std::string);
std::ostream &operator<<(std::ostream &os, const prob_struct &prob);

#endif // _PROBSTRUCT_H