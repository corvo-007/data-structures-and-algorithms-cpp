#include <vector>
#include <queue>

namespace PriorityQueue {

    class KthLargest {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        int k;

    public:
        KthLargest(int k, std::vector<int> &nums): k(k) {
            for (int i = 0; i < k && i < nums.size(); i++) {
                pq.push(nums[i]);
            }

            for (int i = k; i < nums.size(); i++) {
                if (pq.top() < nums[i]) {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }

        int add(int val) {
            if (pq.empty() || pq.size() < k) {
                pq.push(val);
                return pq.top();
            }

            if (pq.top() < val) {
                pq.pop();
                pq.push(val);
            }

            return pq.top();
        }
    };
}
