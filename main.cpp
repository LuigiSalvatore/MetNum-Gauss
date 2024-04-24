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
    double array[mat->size()][mat->size()];

    /*cout << "prob size: " << prob->size() << endl
         << "mat line size: " << mat->size() << endl
         << "mat row size: " << mat->at(0).size() << endl
         << "\ndone!" << endl;
*/
    int v = 0;
    for (auto i : *mat)
    {
        int w = 0;
        for (auto j : i)
        {
            array[v][w] = j;
            w++;
        }
        v++;
    }

    return 0;
}
