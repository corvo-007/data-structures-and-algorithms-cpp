#include <vector>
#include <algorithm>

namespace Intervals {

    int recursion(const std::vector<std::vector<int>> &intervals, int index, int end) {
        if (index == intervals.size()) {
            return 0;
        }

        int res = recursion(intervals, index + 1, end);

        if (end == INT_MIN || intervals[index][0] >= end) {
            res = std::max(res, 1 + recursion(intervals, index + 1, intervals[index][1]));
        }

        return res;
    }

    int eraseOverlapIntervals(const std::vector<std::vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end());
        return intervals.size() - recursion(intervals, 0, INT_MIN);
    }

    int eraseOverlapIntervals_optimised(const std::vector<std::vector<int>> &intervals) {
        if (intervals.size() <= 1) {
            return 0;
        }

        std::sort(intervals.begin(), intervals.end());

        int excludedInterval = 0;
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < end) {
                excludedInterval++;
                end = std::min(end, intervals[i][1]);
            }
            else {
                end = intervals[i][1];
            }
        }

        return excludedInterval;
    }
}
