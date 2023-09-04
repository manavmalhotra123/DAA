#include <iostream>
#include <fstream>

using namespace std;

class Graph
{
    int nodes;
    int edges;
    int **Adj;

public:
    Graph(char *filename)
    {
        ifstream file(filename);
        // checking for the file
        if (!file.is_open())
        {
            cout << "File not found";
            exit(1);
        }

        nodes = 0;
        edges = 0;

        char ch;
        while (file.get(ch))
        {
            if (ch == '\n')
            {
                nodes++;
            }
        }
        nodes++;

        Adj = new int *[nodes];
        for (int i = 0; i < nodes; i++)
        {
            Adj[i] = new int[nodes];
            for (int j = 0; j < nodes; j++)
            {
                Adj[i][j] = 0;
            }
        }

        file.clear();
        file.seekg(0, ios::beg);

        int node;
        int adjacent;
        char colon;
        for (int i = 0; i < nodes; i++)
        {
            file >> node >> colon;
            while (file.peek() != '\n' && !file.eof())
            {
                file >> adjacent;
                Adj[node][adjacent] = 1;
                edges++;
            }
        }
    }


    void Print()
    {
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                cout << Adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    Graph g("test.txt");
    g.Print();
    return 0;
}
