#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

namespace AdvancedGraphs {
    int networkDelayTime(const std::vector<std::vector<int>> &times, int n, int k) {
        std::unordered_map<int, std::unordered_map<int, int>> network;

        for (auto time : times) {
            network[time[0]][time[1]] = time[2];
        }

        std::queue<int> q;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        std::unordered_set<int> visited;

        q.push(k);

        int time = 0;

        while (!q.empty() || !pq.empty()) {
            while (!pq.empty() && pq.top().first == time) {
                if (!visited.count(pq.top().second)) {
                    q.push(pq.top().second);
                }
                pq.pop();
            }

            while (!q.empty()) {
                int current = q.front();
                q.pop();

                visited.insert(current);
                if (visited.size() == n) {
                    return time;
                }

                for (auto it = network[current].begin(); it != network[current].end(); it++) {
                    if (visited.count(it -> first)) {
                        continue;
                    }
                    if (it -> second == 0) {
                        q.push(it -> first);
                    }
                    else {
                        pq.push({ time + it -> second, it -> first });
                    }
                }
            }

            time++;
        }

        return -1;
    }
}