#include <vector>
#include <queue>
#include <math.h>

namespace PriorityQueue {

    float distanceFromOrigin(int x, int y) {
        return sqrt(x * x + y * y);
    }

    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points, int k) {
        std::priority_queue<std::pair<float, std::pair<int, int>>> pq;

        for (int i = 0; i < k && i < points.size(); i++) {
            float d = distanceFromOrigin(points[i][0], points[i][1]);

            pq.push({d, {points[i][0], points[i][1]}});
        }

        for (int i = k; i < points.size(); i++) {
            float d = distanceFromOrigin(points[i][0], points[i][1]);

            float topDistance = pq.top().first;

            if (topDistance > d) {
                pq.pop();
                pq.push({d, {points[i][0], points[i][1]}});
            }
        }

        std::vector<std::vector<int>> output;

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            output.push_back({top.second.first, top.second.second});
        }

        return output;
    }
}