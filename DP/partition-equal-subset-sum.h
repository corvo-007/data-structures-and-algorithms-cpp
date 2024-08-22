#include <vector>
#include <numeric>
#include <bitset>

namespace DP {

	bool canPartition_brute_force_1(const std::vector<int> &vec, int index, int bagOne, int bagTwo) {
		if (index == vec.size()) {
			return bagOne == bagTwo;
		}

		return canPartition_brute_force_1(vec, index + 1, bagOne + vec[index], bagTwo) || canPartition_brute_force_1(vec, index + 1, bagOne, bagTwo + vec[index]);
	}

	bool canPartition_brute_force_1(const std::vector<int> &vec) {
		return canPartition_brute_force_1(vec, 0, 0, 0);
	}

	bool canPartition_brute_force_2(const std::vector<int> &vec, int index, int sum, int target) {
		if (index == vec.size()) {
			return sum == target;
		}

		return canPartition_brute_force_2(vec, index + 1, sum + vec[index], target) || canPartition_brute_force_2(vec, index + 1, sum, target);
	}

	bool canPartition_brute_force_2(const std::vector<int> &vec) {
		int sum = std::accumulate(vec.begin(), vec.end(), 0);
		if (sum & 1) {
			return false;
		}
		return canPartition_brute_force_2(vec, 0, 0, sum / 2);
	}

	bool canParition_dp(const std::vector<int> &vec) {
		int sum = std::accumulate(vec.begin(), vec.end(), 0);

		if (sum & 1) {
			return false;
		}

		sum /= 2;
		std::vector<std::vector<int>> dp(vec.size() + 1, std::vector<int>(sum + 1));

		dp[0][0] = true;

		for (int i = 1; i <= vec.size(); i++) {
			for (int j = 0; j <= sum; j++) {
				if (j - vec[i - 1] >= 0) {
					dp[i][j] = dp[i - 1][j] || dp[i - 1][j - vec[i - 1]];
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}

		return dp[vec.size()][sum];
	}

	bool canPartition_bit_manipulation(const std::vector<int> &vec) {
		int sum = std::accumulate(vec.begin(), vec.end(), 0);
		if (sum & 1) {
			return 0;
		}

		sum >>= 1;

		std::bitset<20000> bitset(1);

		for (const int &i: vec) {
			bitset |= (bitset << i);
		}

		return bitset[sum];
	}
}
