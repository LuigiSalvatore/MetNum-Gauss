#include "reader.h"

Reader::Reader(std::string &s)
{
    std::string line;
    std::ifstream file(s);
    if (file.is_open())
    {
        std::string s = "";
        for (int i = 0; std::getline(file, line); i++)
        {
            if (i == 0)
                s = line;
            else
            {
                linhas.push_back(line);
            }
        }
        file.close();
        if (!(std::istringstream(s) >> line >> line >> line >> startingPeople))
            startingPeople = -1;
        for (int i = 0; i < linhas.size(); i++)
        {
            std::string from, to, trash, prob;
            std::istringstream iss(linhas.at(i));
            iss >> from >> trash >> prob >> trash >> to;
            data.push_back(Data(from, to, std::stod(prob)));
        }
    }
    else
    {
        std::cout << "Unable to open file";
        return;
    }
    populateMat();
}

Reader::~Reader()
{
}
void Reader::populateMat()
{
    std::cout << "Gente que entrou: " << startingPeople << " size: " << data.size() << std::endl;
    for (int i = 0; i < data.size(); i++)
        std::cout << data.at(i) << std::endl;

    std::cout << "started sorting\n";
    sort(data.begin(), data.end(), cmp);
    std::cout << "finished sorting\n";

    std::cout << "Gente que entrou: " << startingPeople << " size: " << data.size() << std::endl;
    for (int i = 0; i < data.size(); i++)
        std::cout << data.at(i) << std::endl;
}

Data::Data(std::string &a, std::string &b, double c)
{
    from = a;
    to = b;
    prob = c;
}

Data::~Data() {}

std::ostream &operator<<(std::ostream &os, const Data &data)
{
    os << data.from << " " << data.prob << " " << data.to;
    return os;
}
// const bool &operator<(const Data &data1, const Data &data2)
// {
//     if (data1.to == "Diploma")
//         return false;
//     else if (data2.to == "Diploma")
//         return true;
//     if (data1.from == data2.from)
//         return data1.to < data2.to;
//     return data1.from < data2.from;
// }
bool cmp(const Data &data1, const Data &data2)
{
    if (data1.to == "Diploma")
        return false;
    else if (data2.to == "Diploma")
        return true;
    if (data1.from == data2.from)
        return data1.to < data2.to;
    return data1.from < data2.from;
}