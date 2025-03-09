#include <string>
#include <vector>

namespace DP {
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int size1 = text1.length();
        int size2 = text2.length();

        std::vector<std::vector<int>> dp(size1, std::vector<int>(size2));

        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                dp[i][j] = 0;

                if (text1[i] == text2[j]) {
                    dp[i][j] = (i > 0 && j > 0) ? dp[i - 1][j - 1] + 1 : 1;
                }
                else {
                    if (i > 0) {
                        dp[i][j] = dp[i - 1][j];
                    }
                    if (j > 0) {
                        dp[i][j] = std::max(dp[i][j], dp[i][j - 1]);
                    }
                }
            }
        }

        return dp[size1 - 1][size2 - 1];
    }
}
