#include "logicaMat.h"
#include "test.h"
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " FILENAME" << endl;
        return 1;
    }
    geraMatriz(argv[1]);

    gaussElimination(*mat);
    return 0;
}
