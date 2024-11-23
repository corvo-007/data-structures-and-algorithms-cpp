#include <vector>

namespace Graph {
    int findParent(int vertex, const std::vector<int> &parents) {
        while (parents[vertex] != -1) {
            vertex = parents[vertex];
        }

        return vertex;
    }

    std::vector<int> findRedundantConnection(std::vector<std::vector<int>> &edges) {
        int n = edges.size();

        std::vector<int> parents(n, -1);

        for (int i = 0; i < n; i++) {
            int srcParent = findParent(edges[i][0] - 1, parents);
            int destParent = findParent(edges[i][1] - 1, parents);

            if (srcParent == destParent) {
                return edges[i];
            }

            parents[destParent] = srcParent;
        }

        return {};
    }
}