#include <iostream>
#include <limits.h>

#define V 4 // Number of vertices

// Function to check if a vertex is not yet included in the path
bool notInPath(int v, int path[], int pos) {
    for (int i = 0; i < pos; ++i) {
        if (path[i] == v) {
            return false;
        }
    }
    return true;
}

// Function to perform row reduction on the matrix
void reduceRows(int graph[V][V], int row[]) {
    for (int i = 0; i < V; ++i) {
        int minVal = INT_MAX;
        for (int j = 0; j < V; ++j) {
            if (graph[i][j] < minVal) {
                minVal = graph[i][j];
            }
        }
        row[i] = minVal;
    }
}

// Function to perform column reduction on the matrix
void reduceCols(int graph[V][V], int col[]) {
    for (int i = 0; i < V; ++i) {
        int minVal = INT_MAX;
        for (int j = 0; j < V; ++j) {
            if (graph[j][i] < minVal) {
                minVal = graph[j][i];
            }
        }
        col[i] = minVal;
    }
}

// Function to perform matrix reduction by subtracting row and column minimums
void reduceMatrix(int graph[V][V], int row[], int col[]) {
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (row[i] != INT_MAX && graph[i][j] != INT_MAX) {
                graph[i][j] -= row[i];
            }
            if (col[j] != INT_MAX && graph[i][j] != INT_MAX) {
                graph[i][j] -= col[j];
            }
        }
    }
}

// Recursive function to find the minimum weighted Hamiltonian cycle
void tspUtil(int graph[V][V], int path[], int bound, int cost, int pos, int& minCost) {
    if (pos == V) {
        // Last vertex reached, check if there's an edge from the last vertex to the starting vertex
        if (graph[path[pos - 1]][path[0]] != 0) {
            int currentCost = cost + graph[path[pos - 1]][path[0]];
            if (currentCost < minCost) {
                minCost = currentCost;
            }
        }
        return;
    }

    // Try different vertices as the next candidate in the path
    for (int i = 0; i < V; ++i) {
        if (graph[path[pos - 1]][i] != 0 && notInPath(i, path, pos)) {
            int currentBound = bound;
            int temp = bound;

            // Update the bound
            bound -= ((pos == 1) ? 0 : graph[path[pos - 1]][path[pos - 2]]);
            bound += graph[path[pos - 1]][i];

            // If the new bound is smaller than the minimum cost, explore further
            if (bound < minCost) {
                path[pos] = i;
                cost += graph[path[pos - 1]][i];

                tspUtil(graph, path, bound, cost, pos + 1, minCost);
            }

            // Reset values for next iteration
            cost -= graph[path[pos - 1]][i];
            bound = temp;
        }
    }
}

// Function to solve the Traveling Salesman Problem using Branch and Bound
int tsp(int graph[V][V]) {
    int row[V], col[V];
    int path[V + 1];
    for (int i = 0; i <= V; ++i) {
        path[i] = -1;
    }

    // Initialize row and column arrays
    for (int i = 0; i < V; ++i) {
        row[i] = INT_MAX;
        col[i] = INT_MAX;
    }

    // Perform row and column reductions
    reduceRows(graph, row);
    reduceCols(graph, col);

    // Perform matrix reduction
    reduceMatrix(graph, row, col);

    int bound = 0;
    for (int i = 0; i < V; ++i) {
        bound += row[i] + col[i];
    }

    int minCost = INT_MAX;
    path[0] = 0; // Start from the 0th vertex

    tspUtil(graph, path, bound, 0, 1, minCost);

    return minCost;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int minCost = tsp(graph);

    std::cout << "Minimum cost of the Traveling Salesman Problem is: " << minCost << std::endl;

    return 0;
}
