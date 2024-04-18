#include "read.h"
extern int startingPeople;
using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " FILENAME" << endl;
        return 1;
    }
    vector<prob_struct> *prob = readFile(argv[1]);
    cout << "Starting people: " << startingPeople << endl;
    /*      PRINTING         */
    // for (int i = 0; i < prob->size(); i++)
    //     cout << prob->at(i) << endl;

    cout << "done\n";
    // cin.get();

    return 0;
}