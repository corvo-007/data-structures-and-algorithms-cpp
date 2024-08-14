#include <vector>

namespace DP {

	int coinChange_brute_force(const std::vector<int> &coins, int amount) {
		if (amount < 0) {
			return -1;
		}
		if (amount == 0) {
			return 0;
		}

		int minCoins = INT_MAX;

		for (int coin: coins) {
			int c = coinChange_brute_force(coins, amount - coin);
			if (c != -1 && c < minCoins) {
				minCoins = c;
			}
		}

		return (minCoins == INT_MAX) ? -1 : minCoins + 1;
	}

	int coinChange_top_down(const std::vector<int> &coins, int amount, std::vector<int> &vec) {
		if (amount < 0) {
			return -1;
		}

		if (amount == 0) {
			return 0;
		}

		if (vec[amount] != INT_MIN) {
			return vec[amount];
		}

		int minCoins = INT_MAX;

		for (int coin: coins) {
			int c = coinChange_top_down(coins, amount - coin, vec);
			if (c != -1 && c < minCoins) {
				minCoins = c;
			}
		}

		vec[amount] = (minCoins == INT_MAX) ? -1 : minCoins + 1;
		return vec[amount];
	}

	int coinChange_top_down(const std::vector<int> &coins, int amount) {
		std::vector<int> vec(amount + 1, INT_MIN);
		return coinChange_top_down(coins, amount, vec);
	}

	int coinChange_bottom_up(const std::vector<int> &coins, int amount) {
		if (amount < 0) {
			return -1;
		}
		if (amount == 0) {
			return 0;
		}

		std::vector<int> dp(amount + 1, INT_MIN);
		dp[0] = 0;

		for (int i = 1; i <= amount; i++) {
			int minCoins = INT_MAX;

			for (int coin: coins) {
				if (i - coin < 0) {
					continue;
				}
				if (dp[i - coin] != -1 && dp[i - coin] < minCoins) {
					minCoins = dp[i - coin];
				}
			}

			dp[i] = (minCoins == INT_MAX) ? -1 : minCoins + 1;
		}

		return dp[amount];
	}
}
