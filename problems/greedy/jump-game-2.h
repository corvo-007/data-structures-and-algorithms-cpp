#include <vector>

namespace Greedy {
    int jump_recursion(const std::vector<int> &vec, int index) {
        if (index >= vec.size() - 1) {
            return 0;
        }

        int steps = INT_MAX;

        for (int i = 1; i <= vec[index]; i++) {
            int temp = jump_recursion(vec, index + i);
            if (temp != INT_MAX) {
                steps = std::min(steps, temp + 1);
            }
        }

        return steps;
    }

    int jump_recursion(const std::vector<int> &vec) {
        return jump_recursion(vec, 0);
    }

    int jump_top_down(const std::vector<int> &vec, int index, std::vector<int> &memo) {
        if (index >= vec.size() - 1) {
            return 0;
        }

        if (memo[index] != -1) {
            return memo[index];
        }

        int steps = INT_MAX;

        for (int i = 1; i <= vec[index]; i++) {
            int temp = jump_top_down(vec, index + i, memo);
            if (temp != INT_MAX) {
                steps = std::min(steps, temp + 1);
            }
        }

        memo[index] = steps;
        return steps;
    }

    int jump_top_down(const std::vector<int> &vec) {
        std::vector<int> memo(vec.size(), -1);
        return jump_top_down(vec, 0, memo);
    }

    int jump_bottom_up(const std::vector<int> &vec) {
        int size = vec.size();
        std::vector<int> dp(size, INT_MAX);

        dp[0] = 0;

        for (int i = 0; i < size; i++) {
            int end = std::min(size - 1, i + vec[i]);
            for (int j = i + 1; j <= end; j++) {
                dp[j] = std::min(dp[j], dp[i] + 1);
            }
        }

        return dp[size - 1];
    }

    int jump(const std::vector<int> &vec) {
        int jumps = 0, left = 0, right = 0;

        while (right < vec.size() - 1) {
            int temp = 0;

            for (int i = left; i <= right; i++) {
                temp = std::max(temp, i + vec[i]);
            }

            left = right + 1;
            right = temp;
            jumps++;
        }
        return jumps;
    }
}