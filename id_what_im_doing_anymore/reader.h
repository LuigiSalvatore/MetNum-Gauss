#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

class Data
{
public:
    std::string from;
    std::string to;
    double prob;

    Data(std::string &a, std::string &b, double c);
    ~Data();
    friend std::ostream &operator<<(std::ostream &os, const Data &data);
    friend bool operator<(const Data &data1, const Data &data2);
};
bool cmp(const Data &data1, const Data &data2);

class Reader
{
private:
    std::vector<Data> data;
    int startingPeople;
    std::vector<std::vector<double>> mat; // matriz de probabilidade
    std::vector<std::string> linhas;
    void populateMat();

public:
    Reader(std::string &s);
    ~Reader();
};
