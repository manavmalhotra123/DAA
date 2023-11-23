#include <iostream>
#include <climits>


using namespace std; 

class Queue {
private:
    int front;
    int rear;
    int capacity;
    int* array;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        front = rear = -1;
        array = new int[capacity];
    }

    void enqueue(int value) {
        if (rear == capacity - 1) {
            std::cout << "Queue is full" << std::endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        array[++rear] = value;
    }

    int dequeue() {
        if (front == -1 || front > rear) {
            std::cout << "Queue is empty" << std::endl;
            return INT_MIN;
        }

        int value = array[front++];
        return value;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    ~Queue() {
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
            cout << "Invalid edge: (" << source << ", " << destination << ")" << std::endl;
        }
    }

    void DFS(int startNode) {
        bool* visited = new bool[n];
        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }

        Queue queue(n);

        visited[startNode] = true;
        cout << "DFS Traversal starting from node " << startNode << ": ";

        queue.enqueue(startNode);

        while (!queue.isEmpty()) {
            int currentNode = queue.dequeue();
            cout << currentNode << " ";

            for (int i = 0; i < n; ++i) {
                if (adjacencyMatrix[currentNode][i] == 1 && !visited[i]) {
                    queue.enqueue(i);
                    visited[i] = true;
                }
            }
        }

        delete[] visited;
    }

    void printGraph() {
        cout << "Adjacency Matrix:" << std::endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
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
