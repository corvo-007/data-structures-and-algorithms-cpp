#include <vector>
#include <queue>

namespace AdvancedGraphs {
    int manhattanDistance(const std::vector<int> &p1, const std::vector<int> &p2) {
        return std::abs(p1[0] - p2[0]) + std::abs(p1[1] - p2[1]);
    }

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
}