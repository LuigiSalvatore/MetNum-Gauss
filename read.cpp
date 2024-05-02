#include "read.h"

int startingPeople = 0;
std::vector<prob_struct> readFile(std::string s)
{
    std::string line;

    std::vector<prob_struct> prob;
    std::ifstream file(s);
    if (file.is_open())
    {
        std::string s = "";
        for (int i = 0; std::getline(file, line); i++)
        {
            if (i == 0)
                s = line;
            else
                prob.push_back(str2Prob(line));
        }
        file.close();
        sort(prob.begin(), prob.end(), compare);
        // prob.push_back(prob_struct{"Diploma", 1, "Diploma"});
        if (!(std::istringstream(s) >> line >> line >> line >> startingPeople))
            startingPeople = -1;
        prob_struct p_aux = {"Diploma", 0, "Diploma"};
        prob.push_back(p_aux);
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
    prob.prob = 0.0;

    if (!(iss >> x >> trash >> p >> trash >> y))
        return prob;

    prob.x = x + ' ';
    prob.prob = p;
    prob.y = y + ' ';

    return prob;
}

bool compare1(const prob_struct prob1, const prob_struct prob2)
{
    if (prob1.y == "Diploma")
        return false;
    else if (prob2.y == "Diploma")
        return true;
    if (prob1.x == prob2.x)
        return prob1.y < prob2.y;
    return prob1.x < prob2.x;
}

std::ostream &operator<<(std::ostream &os, const prob_struct &prob)
{
    os << prob.x << " -> " << prob.prob << " -> " << prob.y;
    return os;
}
bool compare(const prob_struct prob1, const prob_struct prob2)
{
    if (prob1.y == "Diploma")
        return false;
    else if (prob2.y == "Diploma")
        return true;
    if (prob1.x != prob2.x)
    {
        if (prob1.x[5] == ' ' && prob2.x[5] != ' ')
            return true;
        else if (prob1.x[5] != ' ' && prob2.x[5] == ' ')
            return false;
        else if (prob1.x[5] == ' ' && prob2.x[5] == ' ')
            return prob1.x < prob2.x;
        else if (prob1.x[5] != ' ' && prob2.x[5] != ' ')
            return prob1.x[4] < prob2.x[4];
    }
    else
        return prob1.y < prob2.y;
}