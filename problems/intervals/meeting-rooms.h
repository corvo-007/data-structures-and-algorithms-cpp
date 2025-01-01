#include <vector>
#include <algorithm>

namespace Intervals {
    bool canAttendMeetings(std::vector<std::vector<int>> &intervals) {
        if (intervals.size() <= 1) {
            return true;
        }

        std::sort(intervals.begin(), intervals.end());

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }
        return true;
    }
}