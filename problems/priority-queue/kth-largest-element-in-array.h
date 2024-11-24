#include <vector>
#include <queue>

namespace PriorityQueue {

    int findKthLargest(std::vector<int> &nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        for (int i = 0; i < k && i < nums.size(); i++) {
            pq.push(nums[i]);
        }

        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
}