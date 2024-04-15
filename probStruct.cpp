#include "probStruct.h"

prob_struct str2Prob(std::string line)
{
    prob_struct prob;
    std::istringstream iss(line);
    std::string x, trash, y;
    double p;

    prob.x, prob.y = "";
    prob.prob = 0.0;

    if (!(iss >> x >> trash >> p >> trash >> y))
        return prob;

    prob.x = x;
    prob.prob = p;
    prob.y = y;

    return prob;
}

bool compare(const prob_struct prob1, const prob_struct prob2)
{
    if (prob1.x == prob2.x)
        return prob1.y < prob2.y;
    return prob1.x < prob2.x;
}

std::ostream &operator<<(std::ostream &os, const prob_struct &prob)
{
    os << prob.x << "->" << prob.prob << "->" << prob.y;
    return os;
}