#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
    int **adjacencyMatrix;
    int nodes;

public:
    Graph(int nodes)
    {
        this->nodes = nodes;

        adjacencyMatrix = new int *[nodes];
        for (int i = 0; i < nodes; i++)
        {
            adjacencyMatrix[i] = new int[nodes];
        }

        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }

    void AddEdge(int source, int destination, bool isDirected)
    {
        adjacencyMatrix[source][destination] = 1;

        if (!isDirected)
        {
            adjacencyMatrix[destination][source] = 1;
        }
    }

    void ShowGraph()
    {
        cout << "Graph Adjacency Matrix: " << endl;

        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    int findDegree(int node)
    {
        int degree = 0;
        for (int i = 0; i < nodes; i++)
        {
            if (adjacencyMatrix[node][i] == 1)
            {
                degree++;
            }
        }
        return degree;
    }

    void removeEdge(int source, int target)
    {
        adjacencyMatrix[source][target] = 0;
    }

    bool isConnected()
    {
        vector<bool> visited(nodes, false);
        int startNode = -1;

        for (int i = 0; i < nodes; i++)
        {
            if (findDegree(i) > 0)
            {
                startNode = i;
                break;
            }
        }

        if (startNode == -1)
        {
            return true;
        }

        DFS(startNode, visited);

        for (int i = 0; i < nodes; i++)
        {
            if (!visited[i] && findDegree(i) > 0)
            {
                return false;
            }
        }

        return true;
    }

    void DFS(int node, vector<bool> &visited)
    {
        visited[node] = true;

        for (int i = 0; i < nodes; i++)
        {
            if (adjacencyMatrix[node][i] && !visited[i])
            {
                DFS(i, visited);
            }
        }
    }

    void FleuryAlgorithm()
    {
        if (!isConnected())
        {
            cout << "The graph does not have an Eulerian circuit or path." << endl;
            return;
        }

        int startNode = 0;

        cout << "Eulerian Circuit/Path:" << endl;

        while (findDegree(startNode) == 0)
        {
            startNode++;
        }

        vector<int> circuit;
        circuit.push_back(startNode);
        int current = startNode;

        while (!circuit.empty())
        {
            int next = -1;

            for (int i = 0; i < nodes; i++)
            {
                if (adjacencyMatrix[current][i])
                {
                    next = i;
                    break;
                }
            }

            if (next == -1)
            {
                cout << current << " ";
                circuit.pop_back();
                if (!circuit.empty())
                {
                    current = circuit.back();
                }
            }
            else
            {
                removeEdge(current, next);
                circuit.push_back(next);
                current = next;
            }
        }

        cout << endl;
    }
};

int main()
{
    int numNodes = 5;
    Graph g(numNodes);

    g.AddEdge(0, 1, false);
    g.AddEdge(1, 2, false);
    g.AddEdge(2, 3, false);
    g.AddEdge(3, 4, false);
    g.AddEdge(4, 0, false);

    cout << "Original Graph:" << endl;
    g.ShowGraph();

    cout << "Applying Fleury's Algorithm:" << endl;
    g.FleuryAlgorithm();

    return 0;
}
