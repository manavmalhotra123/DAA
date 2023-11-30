#include <iostream>
#include <vector>

void sequentialColoring(const std::vector<std::vector<int>>& adj) {
    int nv = adj.size();
    std::vector<int> colors(nv, -1);

    for (int i = 0; i < nv; ++i) {
        std::vector<bool> used(nv, false);

        for (int j = 0; j < nv; ++j) {
            if (adj[i][j] && colors[j] != -1) {
                used[colors[j]] = true;
            }
        }

        int j;
        for (j = 1; j <= nv; ++j) {
            if (!used[j]) {
                colors[i] = j;
                break;
            }
        }
    }

    for (int i = 0; i < nv; ++i) {
        std::cout << "Vertex " << i << ": Color " << colors[i] << std::endl;
    }
}

int main() {
    // Define a simple graph (adjacency matrix)
    std::vector<std::vector<int>> adj = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };

    sequentialColoring(adj);

    return 0;
}
