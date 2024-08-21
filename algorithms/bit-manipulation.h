#include <vector>

namespace BIT {

	int singleNumber(const std::vector<int> &vec) {
		int single = 0;
		for (const int &i: vec) {
			single ^= i;
		}
		return single;
	}

	int hammingWeight(int n) {
		int count = 0;

		for (int i = 0; i < 32; i++) {
			count += (n >> i) & 1;
		}
		return count;
	}

	int hammingWeight_(int n) {
		int count = 0;

		while (n) {
			count++;
			n &= n - 1;
		}
		return count;
	}

	std::vector<int> countBits(int n) {
		std::vector<int> dp(n + 1);
		dp[0] = 0;

		int offset = 1;

		for (int i = 1; i <= n; i++) {
			if (2 * offset == i) {
				offset = i;
			}
			dp[i] = 1 + dp[i - offset];
		}
		return dp;
	}

	uint32_t reverseBits(uint32_t n) {
		int reverse = 0;

		for (int i = 0; i < 32; i++) {
			reverse |= ((n >> i) & 1) << (31 - i);
		}
		return reverse;
	}

	int missingNumber(const std::vector<int> &vec) {
		int missing = vec.size();

		for (int i = 0; i < vec.size(); i++) {
			missing ^= i ^ vec[i];
		}

		return missing;
	}

	int missingNumber_(const std::vector<int> &vec) {
		int sum = vec.size();

		for (int i = 0; i < vec.size(); i++) {
			sum += i - vec[i];
		}

		return sum;
	}

	int sum(int a, int b) {
		while (b) {
			int temp = a;
			a ^= b;
			b = (temp & b) << 1;
		}
		return a;
	}
}
