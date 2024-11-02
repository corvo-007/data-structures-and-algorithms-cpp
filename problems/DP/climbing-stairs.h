#include <algorithm>

namespace DP {

	int climbingStairs_brute_force(int n) {
		if (n <= 2) {
			return n;
		}
		return climbingStairs_brute_force(n - 1) + climbingStairs_brute_force(n - 2);
	}

	int climbingStairs_top_down(int n, int *arr) {
		if (n <= 2) {
			return n;
		}

		if (arr[n] != -1) {
			return arr[n];
		}

		arr[n] = climbingStairs_top_down(n - 1, arr) + climbingStairs_top_down(n - 2, arr);
		return arr[n];
	}

	int climbingStairs_top_down(int n) {
		if (n <= 2) {
			return n;
		}
		int *arr = new int[n + 1];
		std::fill(arr, arr + n + 1, -1);

		int output = climbingStairs_top_down(n, arr);

		delete [] arr;

		return output;
	}

	int climbingStairs_bottom_up(int n) {
		if (n <= 2) {
			return n;
		}
		int *dp = new int[n + 1];

		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;

		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}

		int output = dp[n];

		delete [] dp;
		return output;
	}
}
