#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
string _PATH_CASOS = "./Casos/caso";
string _PATH_RESULTADOS = "./Outs/out";
string _PATH_EXT = ".txt";
void read(string s);

int main(int argc, char *argv[])
{
    string s;
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " FILENAME" << endl;
        // return 1;
        s = "1";
    }
    else
        s = argv[1];

    s = _PATH_CASOS + s + _PATH_EXT;
    cout << "Reading file: " << s << endl;
    read(s);
    return 0;
}

void read(string s)
{
    string line;
    ifstream file(s);
    if (!file.is_open())
    {
        cout << "Unable to open file" << endl;
        return;
    }
    s = "";
    int startingPeople = 0;
    vector<string> v_lines;
    for (int i = 0; getline(file, line); i++)
    {
        if (i == 0)
            s = line;
        else
            v_lines.push_back(line);
    }
    file.close();
    sort(v_lines.begin(), v_lines.end());                              // deixa a lista em ordem crescente
    swap(v_lines[v_lines.size() - 1], v_lines[v_lines.size() - 2]);    // deixa o Diploma por ultimo
    if (!(istringstream(s) >> line >> line >> line >> startingPeople)) //
        startingPeople = -1;

    /*====================================================================*/
    int v_size = v_lines.size();
    int m_size = v_size / 2 + 1;
#ifdef DEBUG
    cout << "v_size: " << v_size << endl;
    cout << "m_size: " << m_size << endl;
#endif
    double matrix[m_size][m_size];
    string matrix_column_names[m_size];

    for (int i = 0; i < v_size; i++)
    {
        for (int j = 0; j < v_size; j++)
        {
            if (i == j && i % 2)
            {
                string from_var, trash, to_var, aux;
                istringstream(v_lines[i]) >> from_var >> trash >> aux >> trash >> to_var;
                matrix[i][j] = stod(aux);
                matrix_column_names[i] = from_var;
            }
            else if (i == j + 1 && i % 2)
            {
                string from_var, trash, to_var, aux;
                istringstream(v_lines[j]) >> from_var >> trash >> aux >> trash >> to_var;
                matrix[i][j] = stod(aux);
                matrix_column_names[i] = to_var;
            }
            else if (j % 2 == 0)
                matrix[i][j] = 0;
        }
    }
    /*====================================================================*/
    for (int i = 0; i < m_size; i++)
    {
        for (int j = 0; j < m_size; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    /*====================================================================*/

    cout << "Starting people: " << startingPeople << endl;
    for (auto i : v_lines)
        cout << i << endl;
}