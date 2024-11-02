#include <vector>

namespace DP {

	int houseRobber_brute_force(const std::vector<int> &vec, int index) {
		if (index >= vec.size()) {
			return 0;
		}
		int amount1 = vec[index] + houseRobber_brute_force(vec, index + 2);
		int amount2 = houseRobber_brute_force(vec, index + 1);

		return std::max(amount1, amount2);
	}

	int houseRobber_brute_force(const std::vector<int> &vec) {
		return houseRobber_brute_force(vec, 0);
	}

	int houseRobber_top_down(const std::vector<int> &vec, int index, std::vector<int> &arr) {
		if (index >= vec.size()) {
			return 0;
		}
		if (arr[index] != -1) {
			return arr[index];
		}

		int amount1 = vec[index] + houseRobber_top_down(vec, index + 2, arr);
		int amount2 = houseRobber_top_down(vec, index + 1, arr);

		arr[index] = std::max(amount1, amount2);
		return arr[index];
	}

	int houseRobber_top_down(const std::vector<int> &vec) {
		std::vector<int> arr(vec.size());
		std::fill(arr.begin(), arr.end(), -1);

		return houseRobber_top_down(vec, 0, arr);
	}

	int hosueRobber_bottom_up(const std::vector<int> &vec) {
		if (vec.size() == 0) {
			return 0;
		}
		if (vec.size() == 1) {
			return vec[0];
		}
		if (vec.size() == 2) {
			return std::max(vec[0], vec[1]);
		}

		std::vector<int> dp(vec.size());

		int one = vec[0];
		int two = std::max(vec[0], vec[1]);

		for (int i = 2; i < vec.size(); i++) {
			int temp = std::max(one + vec[i], two);
			one = two;
			two = temp;
		}

		return two;
	}
}
