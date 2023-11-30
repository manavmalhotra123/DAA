#include <iostream>
#include <vector>
#include <algorithm>

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
    
    void addEdge(int source, int destination, int weight) {
        if (source >= 0 && source < n && destination >= 0 && destination < n) {
            AdjacencyMatrix[source][destination] = weight;
            if (isBidirectional) {
                AdjacencyMatrix[destination][source] = weight;
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

    int findParent(std::vector<int>& parent, int vertex) {
        if (parent[vertex] == -1)
            return vertex;
        return findParent(parent, parent[vertex]);
    }

    void unionSet(std::vector<int>& parent, int x, int y) {
        int xSet = findParent(parent, x);
        int ySet = findParent(parent, y);
        parent[xSet] = ySet;
    }

    void kruskalMST() {
        std::vector<std::vector<int>> edges;
        std::vector<int> parent(n, -1);

        // Store all edges from the graph
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (AdjacencyMatrix[i][j] != 0) {
                    edges.push_back({AdjacencyMatrix[i][j], i, j});
                }
            }
        }

        // Sort edges based on weight
        std::sort(edges.begin(), edges.end());

        std::cout << "Minimum Spanning Tree (Kruskal's Algorithm):" << std::endl;
        for (auto edge : edges) {
            int weight = edge[0];
            int src = edge[1];
            int dest = edge[2];

            int srcParent = findParent(parent, src);
            int destParent = findParent(parent, dest);

            if (srcParent != destParent) {
                std::cout << "Edge: " << src << " - " << dest << " Weight: " << weight << std::endl;
                unionSet(parent, srcParent, destParent);
            }
        }
    }
};

int main() {
    int nodes = 4; // Number of nodes in the graph
    bool isBidirectional = false; // Set to true if the graph is bidirectional
    
    Graph myGraph(nodes, isBidirectional);
    
    // Adding edges with weights (hardcoded graph)
    myGraph.addEdge(0, 1, 10);
    myGraph.addEdge(0, 2, 6);
    myGraph.addEdge(0, 3, 5);
    myGraph.addEdge(1, 3, 15);
    myGraph.addEdge(2, 3, 4);

    myGraph.printGraph();

    myGraph.kruskalMST();
    
    return 0;
}
