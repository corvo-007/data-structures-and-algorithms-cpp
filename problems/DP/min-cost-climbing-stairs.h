#include <algorithm>
#include <vector>

namespace DP {

	int minCostClimbingStair_brute_force(const std::vector<int> &vec, int i) {
		if (i >= vec.size()) {
			return 0;
		}
		int cost1 = minCostClimbingStair_brute_force(vec, i + 1);
		int cost2 = minCostClimbingStair_brute_force(vec, i + 2);

		return std::min(cost1, cost2) + vec[i];
	}

	int minCostClimbingStair_brute_force(const std::vector<int> &vec) {
		if (vec.size() == 2) {
			return std::min(vec[0], vec[1]);
		}
		return minCostClimbingStair_brute_force(vec, vec[0] < vec[1] ? 0 : 1);
	}

	int minCostClimbingStair_top_down(const std::vector<int> &vec, int i, int *arr) {
		if (i >= vec.size()) {
			return 0;
		}

		if (arr[i] != -1) {
			return arr[i];
		}

		int cost1 = minCostClimbingStair_top_down(vec, i + 1, arr);
		int cost2 = minCostClimbingStair_top_down(vec, i + 2, arr);

		arr[i] = std::min(cost1, cost2) + vec[i];
		return arr[i];
	}

	int minCostClimbingStair_top_down(const std::vector<int> &vec) {
		int *arr = new int[vec.size()];
		std::fill(arr, arr + vec.size(), -1);

		int output = minCostClimbingStair_top_down(vec, vec[0] < vec[1] ? 0 : 1, arr);

		delete [] arr;

		return output;
	}

	int minCostClimbingStair_bottom_up(const std::vector<int> &vec) {
		if (vec.size() == 2) {
			return std::min(vec[0], vec[1]);
		}

		int one = vec[0];
		int two = vec[1];

		for (int i = 2; i < vec.size(); i++) {
			int temp = std::min(one, two) + vec[i];
			one = two;
			two = temp;
		}

		return std::min(one, two);
	}
}
