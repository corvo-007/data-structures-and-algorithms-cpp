#include <queue>

namespace PriorityQueue {

    class MedianFinder {
        std::priority_queue<int> maxHeap;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    public:

        void addNum(int num) {
            if (minHeap.empty() && maxHeap.empty()) {
                minHeap.push(num);
                return ;
            }

            if (num <= minHeap.top()) {
                maxHeap.push(num);
            }
            else {
                minHeap.push(num);
            }

            if (maxHeap.size() > minHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else if (minHeap.size() - maxHeap.size() > 1) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }

        double findMedian() {
            return minHeap.size() == maxHeap.size() ? (maxHeap.top() + minHeap.top()) / 2.0 : minHeap.top();
        }
    };
}