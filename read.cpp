#include "read.h"

using namespace std;

vector<prob_struct> *readFile(string s)
{
    string line;

    vector<prob_struct> *prob = new vector<prob_struct>();
    ifstream file(s);
    if (file.is_open())
    {
        while (getline(file, line))
            prob->push_back(str2Prob(line));
        file.close();
        sort(prob->begin(), prob->end(), compare);
    }
    else
    {
        cout << "Unable to open file";
    }
    return prob;
}
