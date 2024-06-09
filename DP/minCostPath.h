#include <algorithm>

namespace DP {

    int minCostPath_brute_force(int **matrix, int m, int n, int i, int j) {
        if (i >= m || j >= n) {
            return INT_MAX;
        }
        if (i == m - 1 && j == n - 1) {
            return matrix[i][j];
        }

        int dir1 = minCostPath_brute_force(matrix, m, n, i + 1, j);
        int dir2 = minCostPath_brute_force(matrix, m, n, i, j + 1);
        int dir3 = minCostPath_brute_force(matrix, m, n, i + 1, j + 1);

        return matrix[i][j] + std::min(dir1, std::min(dir2, dir3));
    }

    int minCostPath_brute_force(int **matrix, int m, int n) {
        return minCostPath_brute_force(matrix, m, n, 0, 0);
    }

    int minCostPath_memoization(int **matrix, int m, int n, int i, int j, int **arr) {
        if (i >= m || j >= n) {
            return INT_MAX;
        }
        if (i == m - 1 && j == n - 1) {
            return matrix[i][j];
        }
        if (arr[i][j] != -1) {
            return arr[i][j];
        }

        int dir1 = minCostPath_memoization(matrix, m, n, i + 1, j, arr);
        int dir2 = minCostPath_memoization(matrix, m, n, i, j + 1, arr);
        int dir3 = minCostPath_memoization(matrix, m, n, i + 1, j + 1, arr);

        arr[i][j] = matrix[i][j] + std::min(dir1, std::min(dir2, dir3));

        return arr[i][j];
    }

    int minCostPath_memoization(int **matrix, int m, int n) {
        int **arr = new int*[m];
        for (int i = 0; i < m; i++) {
            arr[i] = new int[n];
            for (int j = 0; j < n; j++) {
                arr[i][j] = -1;
            }
        }

        int output = minCostPath_memoization(matrix, m, n, 0, 0, arr);

        for (int i = 0; i < m; i++) {
            delete [] arr[i];
        }

        delete [] arr;

        return output;
    }

    int minCostPath_dp(int **matrix, int m, int n) {
        int **dp = new int*[m + 1];
        for (int i = 0; i <= m; i++) {
            dp[i] = new int[n + 1];
            dp[i][0] = INT_MAX;
            if (i == 0) {
                for (int j = 1; j <= n; j++) {
                    dp[i][j] = INT_MAX;
                }
            }
        }

        dp[0][0] = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1]));
                dp[i][j] += matrix[i - 1][j - 1];

            }
        }

        int output = dp[m][n];

        for (int i = 0; i <= m; i++) {
            delete [] dp[i];
        }

        delete [] dp;

        return output;
    }
}