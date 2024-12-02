#include <vector>
#include <queue>
#include <unordered_map>

namespace PriorityQueue {

    int leastInterval(std::vector<char> &tasks, int n) {
        if (n == 0) {
            return tasks.size();
        }

        std::unordered_map<char, int> map;

        for (char task : tasks) {
            map[task]++;
        }

        std::priority_queue<int> pq;

        for (std::pair<char, int> pair : map) {
            pq.push(pair.second);
        }

        std::queue<std::pair<int, int>> queue;

        int interval = 0;

        while (!pq.empty() || !queue.empty()) {
            if (!queue.empty() && queue.front().second == interval) {
                pq.push(queue.front().first);
                queue.pop();
            }

            if (!pq.empty()) {
                int temp = pq.top() - 1;
                pq.pop();

                if (temp) {
                    queue.push({ temp, interval + n + 1 });
                }
            }

            interval++;
        }

        return interval;
    }
}