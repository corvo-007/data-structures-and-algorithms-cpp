#include <vector>
#include <algorithm>

namespace Intervals {

    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }

        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> output;

        int i = 0;
        while (i < intervals.size()) {
            int end = intervals[i][1];
            int j = i + 1;

            while (j < intervals.size() && intervals[j][0] <= end) {
                end = std::max(end, intervals[j][1]);
                j++;
            }
            output.push_back({ intervals[i][0], end });
            i = j;
        }

        return output;
    }
}