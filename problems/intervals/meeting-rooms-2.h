#include <vector>
#include <algorithm>
#include <queue>

namespace Intervals {
    int minMeetingRooms(std::vector<std::vector<int>> &intervals) {
        if (intervals.size() <= 1) {
            return intervals.size();
        }

        std::sort(intervals.begin(), intervals.end());

        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        minHeap.push(intervals[0][1]);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= minHeap.top()) {
                minHeap.pop();
            }
            minHeap.push(intervals[i][1]);
        }

        return minHeap.size();
    }
}