#include <cmath>
#include <algorithm>
#include <climits>

namespace DP {

    int minCountOfSquaredNum(int n) {
        if (n <= 1) {
            return n;
        }

        int ans = INT_MAX;
        int root_n = sqrt(n);
        for (int i = 1; i <= root_n; i++) {
            ans = std::min(ans, minCountOfSquaredNum(n - i * i));
        }

        return ans + 1;
    }

    int minCountOfSquaredNum_top_down(int n, int *arr) {
        if (n <= 1) {
            return n;
        }
        if (arr[n] != -1) {
            return arr[n];
        }

        
        arr[n] = INT_MAX;
        int root_n = sqrt(n);
        for (int i = 1; i <= root_n; i++) {
            arr[n] = std::min(arr[n], minCountOfSquaredNum_top_down(n - i * i, arr));
        }

        arr[n]++;

        return arr[n];
    }

    int minCountOfSquaredNum_top_down(int n) {
        int *arr = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            arr[i] = -1;
        }

        int output = minCountOfSquaredNum_top_down(n, arr);

        delete [] arr;

        return output;
    }

    int minCountOfSquaredNum_bottom_up(int n) {
        int *dp = new int[n + 1];

        dp[0] = 0;
        dp[1] = 1;


        for (int i = 2; i <= n; i++) {
            dp[i] = i;
            int root_i = sqrt(i);

            for (int j = 1; j <= root_i; j++) {
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
        }

        int output = dp[n];

        delete [] dp;

        return output;
    }
}