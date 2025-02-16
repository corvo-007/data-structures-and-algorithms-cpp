#include <vector>
#include <unordered_map>
#include <queue>

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
}