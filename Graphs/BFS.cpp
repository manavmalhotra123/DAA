#include <iostream>
#include <climits>


class Stack {
private:
    int top;
    int capacity;
    int* array;

public:
    Stack(int capacity) {
        this->capacity = capacity;
        top = -1;
        array = new int[capacity];
    }

    void push(int value) {
        if (top == capacity - 1) {
            std::cout << "Stack overflow" << std::endl;
            return;
        }

        array[++top] = value;
    }

    int pop() {
        if (top == -1) {
            std::cout << "Stack underflow" << std::endl;
            return INT_MIN;
        }

        return array[top--];
    }

    bool isEmpty() {
        return top == -1;
    }

    ~Stack() {
        delete[] array;
    }
};

class Graph {
private:
    int n;
    bool isBidirectional;
    int** adjacencyMatrix;

public:
    Graph(int n, bool isBidirectional) {
        this->n = n;
        this->isBidirectional = isBidirectional;
        adjacencyMatrix = new int*[n];
        for (int i = 0; i < n; i++) {
            adjacencyMatrix[i] = new int[n];
            for (int j = 0; j < n; j++) {
                // Initialize the adjacency matrix with zeros
                adjacencyMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int source, int destination) {
        if (source >= 0 && source < n && destination >= 0 && destination < n) {
            adjacencyMatrix[source][destination] = 1;
            if (isBidirectional) {
                adjacencyMatrix[destination][source] = 1;
            }
        } else {
            std::cout << "Invalid edge: (" << source << ", " << destination << ")" << std::endl;
        }
    }

    void DFS(int startNode) {
        bool* visited = new bool[n];
        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }

        Stack stack(n);

        visited[startNode] = true;
        std::cout << "DFS Traversal starting from node " << startNode << ": ";

        stack.push(startNode);

        while (!stack.isEmpty()) {
            int currentNode = stack.pop();
            std::cout << currentNode << " ";

            for (int i = 0; i < n; ++i) {
                if (adjacencyMatrix[currentNode][i] == 1 && !visited[i]) {
                    stack.push(i);
                    visited[i] = true;
                }
            }
        }

        delete[] visited;
    }

    void printGraph() {
        std::cout << "Adjacency Matrix:" << std::endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << adjacencyMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
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

    int startNode = 0; // Starting node for DFS traversal
    myGraph.DFS(startNode);

    return 0;
}
