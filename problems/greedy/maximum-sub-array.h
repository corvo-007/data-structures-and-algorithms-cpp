#include <vector>
#include <climits>

namespace Greedy {
    int maxSubArray(const std::vector<int> &vec) {
        int max = INT_MIN;
        int curr_sum = 0;

        for (const int &n : vec) {
            curr_sum += n;
            max = std::max(max, curr_sum);
            if (curr_sum < 0) {
                curr_sum = 0;
            }
        }

        return max;
    }
}