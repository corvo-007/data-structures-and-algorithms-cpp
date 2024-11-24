#include <vector>
#include <queue>

namespace PriorityQueue {

    int lastStoneWeight(std::vector<int> &stones) {
        std::priority_queue<int> pq;

        for (const int &stone : stones) {
            pq.push(stone);
        }

        while (pq.size() >= 2) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();

            if (first != second) {
                pq.push(first - second);
            }
        }

        return (!pq.empty()) ? pq.top() : 0;
    }
}
