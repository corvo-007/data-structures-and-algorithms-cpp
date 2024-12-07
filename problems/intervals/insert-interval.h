#include <vector>

namespace Intervals {

    std::vector<std::vector<int>> insertInterval(std::vector<std::vector<int>> &intervals, std::vector<int> &newInterval) {
        std::vector<std::vector<int>> output;

        int i = 0;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            output.push_back(intervals[i]);
            i++;
        }

        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            i++;
        }

        output.push_back(newInterval);

        while (i < intervals.size()) {
            output.push_back(intervals[i]);
            i++;
        }

        return output;
    }
}
