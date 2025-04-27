#include <vector>
#include <queue>
#include <climits>
#include <cstdlib>

namespace AdvancedGraphs {
    int manhattanDistance(const std::vector<int> &p1, const std::vector<int> &p2) {
        return std::abs(p1[0] - p2[0]) + std::abs(p1[1] - p2[1]);
    }

    // prim's algorithm
    int minCostConnectPoints(const std::vector<std::vector<int>> &points) {
        std::vector<bool> visited(points.size(), false);
        std::vector<int> weights(points.size(), INT_MAX);

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        pq.push({ 0, 0 });

        int cost = 0;

        while (!pq.empty()) {
            auto curr_point = pq.top();
            pq.pop();

            if (visited[curr_point.second]) {
                continue;
            }

            visited[curr_point.second] = true;

            cost += curr_point.first;

            for (int i = 0; i < points.size(); i++) {
                if (i != curr_point.second && !visited[i]) {
                    int dist = manhattanDistance(points[curr_point.second], points[i]);
                    if (dist < weights[i]) {
                        weights[i] = dist;
                        pq.push({ dist, i });
                    }
                }
            }
        }

        return cost;
    }

    // prim's algorithm
    int minCostConnectPoints_optimised(const std::vector<std::vector<int>> &points) {
        std::vector<bool> visited(points.size(), false);
        std::vector<int> weights(points.size(), INT_MAX);

        int cost = 0;
        int edges = 0;
        int node = 0;

        while (edges < points.size() - 1) {
            visited[node] = true;

            int next_node = -1;

            for (int i = 0; i < points.size(); i++) {
                if (visited[i]) {
                    continue;
                }

                int dist = manhattanDistance(points[node], points[i]);
                weights[i] = std::min(weights[i], dist);

                if (next_node == -1 || weights[i] < weights[next_node]) {
                    next_node = i;
                }
            }

            cost += weights[next_node];
            node = next_node;
            edges++;
        }

        return cost;
    }
}