namespace DP {

    int fibonacci(int n) {
        if (n <= 1) {
            return n;
        }

        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    int fibonacci_top_down(int n, int *dp) {
        if (n <= 1) {
            return n;
        }
        if (dp[n] != -1) {
            return dp[n];
        }

        dp[n] = fibonacci_top_down(n - 1, dp) + fibonacci_top_down(n - 2, dp);
        return dp[n];
    }

    int fibonacci_top_down(int n) {
        int *dp = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            dp[i] = -1;
        }
        int output = fibonacci_top_down(n, dp);
        delete [] dp;
        return output;
    }

    int fibonacci_bottom_up(int n) {
        int *dp = new int[n + 1];

        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        int output = dp[n];

        delete [] dp;

        return output;
    }
}