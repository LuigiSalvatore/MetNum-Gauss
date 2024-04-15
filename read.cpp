#include "read.h"

std::vector<prob_struct> *readFile(std::string s)
{
    std::string line;

    std::vector<prob_struct> *prob = new std::vector<prob_struct>();
    std::ifstream file(s);
    if (file.is_open())
    {
        while (std::getline(file, line))
            prob->push_back(str2Prob(line));
        file.close();
        sort(prob->begin(), prob->end(), compare);
    }
    else
    {
        std::cout << "Unable to open file";
    }
    return prob;
}
