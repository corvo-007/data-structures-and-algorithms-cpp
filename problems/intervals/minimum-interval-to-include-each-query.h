#include <vector>

namespace Intervals {
    std::vector<int> minInterval_brute_force(std::vector<std::vector<int>> &intervals, std::vector<int> &queries) {
        std::vector<int> output;
        for (const int &query : queries) {
            int i = INT_MAX;

            for (const std::vector<int> &interval : intervals) {
                if (interval[0] <= query && query <= interval[1] && interval[1] - interval[0] + 1 < i) {
                    i = interval[1] - interval[0] + 1;
                }
            }

            output.push_back(i != INT_MAX ? i : -1);
        }

        return output;
    }
}