#include <iostream>
#include <vector>

class Graph {
private:
    int n;
    bool isBidirectional;
public:
    int **AdjacencyMatrix;
    Graph(int n, bool isBidirectional) : n(n), isBidirectional(isBidirectional) {
        AdjacencyMatrix = new int *[n];
        for (int i = 0; i < n; i++) {
            AdjacencyMatrix[i] = new int[n]();
        }
    }
    
    void addEdge(int source, int destination) {
        if (source >= 0 && source < n && destination >= 0 && destination < n) {
            AdjacencyMatrix[source][destination] += 1;
            if (isBidirectional) {
                AdjacencyMatrix[destination][source] += 1;
            }
        } else {
            std::cout << "Invalid edge: (" << source << ", " << destination << ")" << std::endl;
        }
    }
    
    void printGraph() {
        std::cout << "Adjacency Matrix:" << std::endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << AdjacencyMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    bool isSafe(int v, int pos, const std::vector<int>& path) {
        if (AdjacencyMatrix[path[pos - 1]][v] == 0)
            return false;

        for (int i = 0; i < pos; ++i)
            if (path[i] == v)
                return false;

        return true;
    }

    bool hamiltonianPathUtil(std::vector<int>& path, int pos) {
        if (pos == n) {
            for (int i = 0; i < n; i++)
                std::cout << path[i] << " ";
            return true;
        }

        for (int v = 1; v < n; ++v) {
            if (isSafe(v, pos, path)) {
                path[pos] = v;
                if (hamiltonianPathUtil(path, pos + 1))
                    return true;
                path[pos] = -1;
            }
        }

        return false;
    }

    bool hamiltonianPath() {
        std::vector<int> path(n, -1);
        path[0] = 0;

        if (!hamiltonianPathUtil(path, 1)) {
            std::cout << "No Hamiltonian Path exists." << std::endl;
            return false;
        }

        std::cout << std::endl;
        return true;
    }
};

int main() {
    int nodes = 4; // Number of nodes in the graph
    bool isBidirectional = true; // Set to true if the graph is bidirectional
    
    Graph myGraph(nodes, isBidirectional);
    
    // Adding edges
    myGraph.addEdge(0, 1);
    myGraph.addEdge(0, 2);
    myGraph.addEdge(1, 2);
    myGraph.addEdge(2, 3);
    
    myGraph.printGraph();

    std::cout << "Hamiltonian Path:" << std::endl;
    myGraph.hamiltonianPath();
    
    return 0;
}
