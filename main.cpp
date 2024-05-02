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

    geraMatriz(argv[1], 1);
    // printMat();
    gauss();
    importantPrints();
    // printMat();
    //  cout << "Gente que entrou: " << startingPeople << " size: " << prob.size() << endl;
    //  printDeps();

    return 0;
}
