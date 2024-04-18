#include "read.h"
int startingPeople = 0;

std::vector<prob_struct> *readFile(std::string s)
{
    std::string line;

    std::vector<prob_struct> *prob = new std::vector<prob_struct>();
    std::ifstream file(s);
    if (file.is_open())
    {
        std::string s = "";
        for (int i = 0; std::getline(file, line); i++)
        {
            if (i == 0)
                s = line;
            else
                prob->push_back(str2Prob(line));
        }
        file.close();
        sort(prob->begin(), prob->end(), compare);
        startingPeople = std::stoi(s);
        // std::cout << "Starting people: " << startingPeople << std::endl;
    }
    else
        std::cout << "Unable to open file";

    return prob;
}

prob_struct str2Prob(std::string line)
{
    prob_struct prob;
    std::istringstream iss(line);
    std::string x, trash, y;
    double p;

    prob.x, prob.y = "";
    prob.prob = NULL;

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
