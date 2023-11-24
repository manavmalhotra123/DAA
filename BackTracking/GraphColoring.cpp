#include <iostream>

#define V 4 // Number of vertices

// Function to check if it's safe to assign a color to a vertex
bool isSafe(int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; ++i) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

// Recursive function to assign colors to vertices
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
    if (v == V) {
        // All vertices colored
        return true;
    }

    for (int c = 1; c <= m; ++c) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            // Recursively assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }

            // If assigning the color doesn't lead to a solution, backtrack
            color[v] = 0;
        }
    }

    return false;
}

// Function to perform graph coloring
bool graphColoring(bool graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; ++i) {
        color[i] = 0;
    }

    if (!graphColoringUtil(graph, m, color, 0)) {
        std::cout << "No solution exists with " << m << " colors.\n";
        return false;
    }

    std::cout << "Graph coloring possible with " << m << " colors:\n";
    for (int i = 0; i < V; ++i) {
        std::cout << "Vertex " << i << " --> Color " << color[i] << "\n";
    }

    return true;
}

int main() {
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3; // Number of colors

    graphColoring(graph, m);

    return 0;
}
