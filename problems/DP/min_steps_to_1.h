#include <algorithm>
#include <cmath>

namespace DP {

    int minStepsTo1(int n) {
        if (n == 1) {
            return 0;
        }
        int a = minStepsTo1(n - 1);
        int b = (n & 1) ? INT_MAX : minStepsTo1(n / 2);
        int c = (n % 3) ? INT_MAX : minStepsTo1(n / 3);

        return 1 + std::min(a, std::min(b, c));
    }

    int minStepsTo1_top_down(int n, int *arr) {
        if (n == 1) {
            return 0;
        }
        if (arr[n] != -1) {
            return arr[n];
        }

        int a = minStepsTo1_top_down(n - 1, arr);
        int b = (n & 1) ? INT_MAX : minStepsTo1_top_down(n / 2, arr);
        int c = (n % 3) ? INT_MAX : minStepsTo1_top_down(n / 3, arr);

        arr[n] = 1 + std::min(a, std::min(b, c));
        return arr[n];
    }

    int minStepsTo1_top_down(int n) {
        int *arr = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            arr[i] = -1;
        }

        int output = minStepsTo1_top_down(n, arr);

        delete [] arr;

        return output;
    }

    int minStepsTo1_bottom_up(int n) {
        int *dp = new int[n + 1];

        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1];

            if ((i & 1) == 0) {
                dp[i] = std::min(dp[i], dp[i / 2]);
            }

            if (i % 3 == 0) {
                dp[i] = std::min(dp[i], dp[i / 3]);
            }

            dp[i]++;
        }

        int output = dp[n];

        delete [] dp;

        return output;
    }
}