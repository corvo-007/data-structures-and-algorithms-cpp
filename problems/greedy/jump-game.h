#include <vector>

namespace Greedy {
    bool canJump_recursion(const std::vector<int> &vec, int index) {
        if (index >= vec.size() - 1) {
            return true;
        }

        for (int i = vec[index]; i >= 1; i--) {
            if (canJump_recursion(vec, index + i)) {
                return true;
            }
        }
        return false;
    }

    bool canJump_recursion(const std::vector<int> &vec) {
        return canJump_recursion(vec, 0);
    }

    bool canJump_top_down(const std::vector<int> &vec, int index, std::vector<bool> &memo) {
        if (index >= vec.size() - 1) {
            return true;
        }

        if (!memo[index]) {
            return false;
        }

        for (int i = vec[index]; i >= 1; i--) {
            if (canJump_top_down(vec, index + i, memo)) {
                return true;
            }
        }
        memo[index] = false;
        return false;
    }

    bool canJump_top_down(const std::vector<int> &vec) {
        std::vector<bool> memo(vec.size(), true);
        return canJump_top_down(vec, 0, memo);
    }

    bool canJump_bottom_up(const std::vector<int> &vec) {
        std::vector<bool> dp(vec.size(), false);
        dp[0] = true;

        for (int i = 0; i < vec.size(); i++) {
            if (!dp[i]) {
                continue;
            }

            if (i + vec[i] >= vec.size() - 1) {
                return true;
            }

            for (int j = 1; j <= vec[i]; j++) {
                dp[i + j] = true;
            }
        }

        return false;
    }

    bool canJump(const std::vector<int> &vec) {
        int goal = vec.size() - 1;

        for (int i = vec.size() - 2; i >= 0; i--) {
            if (i + vec[i] >= goal) {
                goal = i;
            }
        }

        return goal == 0;
    }
}