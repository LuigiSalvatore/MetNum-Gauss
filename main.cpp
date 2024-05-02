#include "logicaMat.h"
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    /**/ if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " FILENAME" << endl;
        return 1;
    }

    mat = {{1, 1, 1, 12},
           {2, -1, 2, 12},
           {1, -1, -3, -16}}; /* */
    geraMatriz(argv[1], 1);
    printMat();
    gauss();

    // printMat();
    //  cout << "Gente que entrou: " << startingPeople << " size: " << prob.size() << endl;
    //  printDeps();

    return 0;
}
