#include <vector>
#include <unordered_map>
#include <climits>

namespace DP {

	int LIS_brute_force(const std::vector<int> &vec, int index, int threshold) {
		if (index == vec.size()) {
			return 0;
		}

		int length1 = (vec[index] > threshold) ? LIS_brute_force(vec, index + 1, vec[index]) + 1 : 0;
		int length2 = LIS_brute_force(vec, index + 1, threshold);

		return std::max(length1, length2);

	}

	int LIS_brute_force(const std::vector<int> &vec) {
		return LIS_brute_force(vec, 0, INT_MIN);
	}

	struct pair_hash {
		template <typename T1, typename T2>
		std::size_t operator()(const std::pair<T1, T2> &p) const {
			auto h1 = std::hash<T1>{}(p.first);
			auto h2 = std::hash<T2>{}(p.second);

			return h1 ^ (h2 << 1);
		}
	};

	int LIS_top_down(const std::vector<int> &vec, int index, int threshold, std::unordered_map<std::pair<int, int>, int, pair_hash> &map) {
		if (index == vec.size()) {
			return 0;
		}

		std::pair<int, int> key = { index, threshold };
		if (map.count(key)) {
			return map[key];
		}

		int length1 = (vec[index] > threshold) ? LIS_top_down(vec, index + 1, vec[index], map) + 1 : 0;
		int length2 = LIS_top_down(vec, index + 1, threshold, map);

		map[key] = std::max(length1, length2);
		return map[key];
	}

	int LIS_top_down(const std::vector<int> &vec) {
		std::unordered_map<std::pair<int, int>, int, pair_hash> map;

		return LIS_top_down(vec, 0, INT_MIN, map);
	}

	int LIS_bottom_up(const std::vector<int> &vec) {
		std::vector<int> dp(vec.size(), 1);

		for (int i = 0; i < vec.size(); i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (vec[j] < vec[i]) {
					dp[i] = std::max(dp[i], dp[j] + 1);
				}
			}
		}

		int max = INT_MIN;
		for (int i = 0; i < dp.size(); i++) {
			max = std::max(max, dp[i]);
		}

		return max;
	}
}
