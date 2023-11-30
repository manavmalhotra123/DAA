#include <iostream>
#include <vector>
#include <queue>

class Graph {
private:
    int n;
    bool isBidirectional;
public:
    int **AdjacencyMatrix;
    Graph(int n, bool isBidirectional) {
        this->n = n;
        this->isBidirectional = isBidirectional;
        AdjacencyMatrix = new int *[n];
        for (int i = 0; i < n; i++) {
            AdjacencyMatrix[i] = new int[n];
            for (int j = 0; j < n; j++) {
                // Initialize the adjacency matrix with zeros
                AdjacencyMatrix[i][j] = 0;
            }
        }
    }
    
    void addEdge(int source, int destination) {
        if (source >= 0 && source < n && destination >= 0 && destination < n) {
            AdjacencyMatrix[source][destination] = 1;
            if (isBidirectional) {
                AdjacencyMatrix[destination][source] = 1;
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

    void topologicalSort() {
        std::vector<int> inDegree(n, 0);
        std::queue<int> q;

        // Calculate in-degrees for each vertex
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (AdjacencyMatrix[i][j]) {
                    inDegree[j]++;
                }
            }
        }

        // Add vertices with in-degree 0 to the queue
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform topological sort
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            std::cout << v << " ";

            for (int i = 0; i < n; ++i) {
                if (AdjacencyMatrix[v][i]) {
                    if (--inDegree[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    int nodes = 4; // Number of nodes in the graph
    bool isBidirectional = false; // Set to true if the graph is bidirectional
    
    Graph myGraph(nodes, isBidirectional);
    
    // Adding edges (hardcoded graph)
    myGraph.addEdge(0, 1);
    myGraph.addEdge(0, 2);
    myGraph.addEdge(1, 3);
    myGraph.addEdge(2, 3);

    myGraph.printGraph();

    std::cout << "Topological Sort: ";
    myGraph.topologicalSort();
    
    return 0;
}
