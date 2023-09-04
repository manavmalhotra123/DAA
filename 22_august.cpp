// 22 August 2023 : lab 3 DAA 
// Code 1:Graph implementation using adjacency matrix 


#include <iostream>

using namespace std;

class Graph
{
    int nodes;
    int **adj;

public:
    Graph(int nodes)
    {
        this->nodes = nodes;
        adj = new int *[nodes];
        for (int i = 0; i < nodes; i++)
        {
            adj[i] = new int[nodes];
            for (int j = 0; j < nodes; j++)
            {
                adj[i][j] = 0;
            }
        }
    }

    void AddEdge(int source, int target)
    {
        adj[source][target] = 1;
    }

    void show(){
        cout<<"Graph is "<<endl;
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph g(5);

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        int source, target;
        cout << "Enter source and target: ";
        cin >> source >> target;
        g.AddEdge(source, target);
    }

    g.show();
}