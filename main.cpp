#include "logicaMat.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " FILENAME" << endl;
        return 1;
    }
    // geraMatriz(argv[1]);
    printEverything(argv[1]);
    cout << "prob size: " << prob->size() << endl
         << "mat line size: " << mat->size() << endl
         << "mat row size: " << mat->at(0).size() << endl
         << "\ndone!" << endl;
    return 0;
}