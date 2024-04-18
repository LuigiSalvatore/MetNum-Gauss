#include <iostream>

const int size = 5;
// Create a 5x5 matrix A
int A[size][size];
// Create a 5x1 matrix B
int B[size];
void makeMat();
void printMatA();
void printMatB();
void gauss();

int main()
{
    makeMat();
    printMatA();
    printMatB();
    gauss();
    printMatB();

    return 0;
}

void makeMat()
{

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            A[i][j] = i + j + 1; // Replace this with your actual values
        }
    }

    for (int i = 0; i < size; i++)
    {
        int soma = 0;
        for (int j = 0; j < size; j++)
        {
            soma = soma + A[i][j];
        }
        B[i] = soma; // Replace this with your actual values
    }
}
void printMatA()
{

    // Print matrix A
    std::cout << "Matrix A:" << std::endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void printMatB()
{
    // Print matrix B
    std::cout << "Matrix B:" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << B[i] << std::endl;
    }
}
void gauss() // solves the system of equations using Gauss elimination
{
    int i, j, k;
    double temp;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (j > i)
            {
                temp = A[j][i] / A[i][i];
                for (k = 0; k < size; k++)
                {
                    A[j][k] = A[j][k] - temp * A[i][k];
                }
                B[j] = B[j] - temp * B[i];
            }
        }
    }
    for (i = size - 1; i >= 0; i--)
    {
        temp = 0;
        for (j = i; j < size; j++)
        {
            temp = temp + A[i][j] * B[j];
        }
        B[i] = (B[i] - temp) / A[i][i];
    }
}