#include "logicaMat.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " FILENAME" << endl;
        return 1;
    }
    printEverything(argv[1]);
    cout << "\ndone!" << endl;
    return 0;
}