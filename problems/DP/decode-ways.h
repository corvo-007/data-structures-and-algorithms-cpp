#include <string>
#include <vector>

namespace DP {

	int decodeWays(const std::string &s, int index) {
		if (index == s.length()) {
			return 1;
		}

		if (s[index] == '0') {
			return 0;
		}

		int ways = decodeWays(s, index + 1);

		if (index + 1 < s.length() && (s[index] == '1' || (s[index] == '2' && s[index + 1] >= '0' && s[index + 1] <= '6'))) {
			ways += decodeWays(s, index + 2);
		}
		return ways;
	}

	int decodeWays_brute_force(const std::string &s) {
		return decodeWays(s, 0);
	}

	int decodeWays_top_down(const std::string &s, int index, std::vector<int> &ways) {
		if (index == s.length()) {
			return 1;
		}

		if (s[index] == '0') {
			return 0;
		}

		if (ways[index] != -1) {
			return ways[index];
		}

		ways[index] = decodeWays_top_down(s, index + 1, ways);

		if (index + 1 < s.length() && (s[index] == '1' || (s[index] == '2' && s[index + 1] >= '0' && s[index + 1] <= '6'))) {
			ways[index] += decodeWays_top_down(s, index + 2, ways);
		}

		return ways[index];
	}

	int decodeWays_top_down(const std::string &s) {
		std::vector<int> ways(s.length(), -1);

		return decodeWays_top_down(s, 0, ways);
	}

	int decodeWays_bottom_up(const std::string &s) {
		if (s.length() == 0) {
			return 0;
		}
		if (s[0] == '0') {
			return 0;
		}

		int one = 1;
		int two = 1;
		
		for (int i = 0; i < s.length(); i++) {

			int temp = 0;
			if (s[i] != '0') {
				temp = two;
			}
			if (i - 1 >= 0 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6'))) {
				temp += one;
			}

			one = two;
			two = temp;
		}

		return two;
	}
}
