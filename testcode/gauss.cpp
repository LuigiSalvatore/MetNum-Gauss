// #include "read.h"
#include <iostream>
#include <iomanip>
#define MAT_SIZE_ 3
using namespace std;

void printMatrix(const float a[MAT_SIZE_][MAT_SIZE_], const float b[MAT_SIZE_]);

int main()
{
    // a[COLUNA][LINHA]
    float a[MAT_SIZE_][MAT_SIZE_] = {
        {22, 6, 14},
        {18, 9, -5},
        {13, -4, 10}}; // 3x3 matrix

    float b[MAT_SIZE_] =
        {9, 8, 4}; // 3x1 matrix

    printMatrix(a, b);

    /*
    - preciso zerar a primeira coluna da segunda linha e da terceira linha (l2 = l2 - ( l2[0] / l1[0] ) *l1)
    */
    for (int i = 1; i < MAT_SIZE_; i++)
    {
        float m = a[i][0] / a[0][0];
        for (int j = 0; j < MAT_SIZE_; j++)
            a[i][j] = a[i][j] - (m * a[0][j]);
        b[i] = b[i] - (m * b[0]);
        printMatrix(a, b);
    }
}

void printMatrix(const float a[MAT_SIZE_][MAT_SIZE_], const float b[MAT_SIZE_])
{
    stringstream ss;

    for (int i = 0; i < MAT_SIZE_; i++)
    {
        ss << "| ";
        for (int j = 0; j < MAT_SIZE_; j++)
        {
            if (a[i][j] >= 0)
                ss << " " << a[i][j] << std::setfill(' ') << std::setw(3) << " ";
            else
                ss << a[i][j] << std::setfill(' ') << std::setw(3) << " ";
        }
        if (b[i] >= 0)
            ss << "|  " << b[i] << std::setfill(' ') << std::setw(3) << " | " << endl;
        else
            ss << "| " << b[i] << std::setfill(' ') << std::setw(3) << " | " << endl;
    }
    ss << endl
       << endl;
    cout << ss.str();
}
