#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include "../common/functions.h"

namespace PathFinding {
    std::vector<int> dijkstra(int v, const std::unordered_map<int, std::vector<std::pair<int, int>>> &adjList, int src) {
        std::vector<int> dist(v, INT_MAX);

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        dist[src] = 0;
        pq.emplace(0, src);

        while (!pq.empty()) {
            auto [ weight, node ] = pq.top();
            pq.pop();

            if (weight > dist[node] || !adjList.count(node)) {
                continue;
            }

            for (auto &[ n, w ] : adjList.at(node)) {
                if (w + weight < dist[n]) {
                    dist[n] = w + weight;
                    pq.emplace(dist[n], n);
                }
            }
        }

        return dist;
    }

    std::vector<int> bellmanFord(int v, const std::unordered_map<int, std::vector<std::pair<int, int>>> &adjList, int src) {
        std::vector<int> dist(v, INT_MAX);

        dist[src] = 0;

        for (int i = 0; i < v; i++) {
            for (auto &[ s, adj_pair ] : adjList) {
                for (auto &[ d, w ] : adj_pair) {
                    if (dist[s] != INT_MAX && dist[s] + w < dist[d]) {
                        if (i == v - 1) {
                            return { -1 };
                        }

                        dist[d] = dist[s] + w;
                    }
                }
            }
        }

        return dist;
    }

    std::vector<std::vector<int>> floydWarshall(const std::vector<std::vector<int>> &graph) {
        int v = graph.size();
        std::vector<std::vector<int>> dist(v, std::vector<int>(v));
        copyMatrix(graph, dist);

        for (int k = 0; k < v; k++) {
            for (int i = 0; i < v; i++) {
                for (int j = 0; j < v; j++) {
                    if ((dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        return dist;
    }
}