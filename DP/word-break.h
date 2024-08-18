#include <string>
#include <vector>

namespace DP {

	bool isPrefix(const std::string &s, int index, const std::string &word) {
		if (s.length() - index < word.length()) {
			return false;
		}

		for (int i = 0; i < word.length(); i++, index++) {
			if (s[index] != word[i]) {
				return false;
			}
		}
		return true;
	}

	bool wordBreak_brute_force(const std::string &s, int index, const std::vector<std::string> &words) {
		if (index == s.length()) {
			return true;
		}

		for (const std::string &word: words) {
			if (isPrefix(s, index, word)) {
				bool ans = wordBreak_brute_force(s, index + word.length(), words);

				if (ans) {
					return true;
				}
			}
		}

		return false;
	}

	bool wordBreak_brute_force(const std::string &s, const std::vector<std::string> &words) {
		return wordBreak_brute_force(s, 0, words);
	}


	bool wordBreak_top_down(const std::string &s, int index, const std::vector<std::string> &words, std::vector<int> &vec) {
		if (index == s.length()) {
			return true;
		}

		if (vec[index] != -1) {
			return vec[index];
		}

		for (const std::string &word: words) {
			if (isPrefix(s, index, word)) {
				bool ans = wordBreak_top_down(s, index + word.length(), words, vec);

				if (ans) {
					vec[index] = true;
					return true;
				}
			}
		}

		vec[index] = false;
		return false;
	}

	bool wordBreak_top_down(const std::string &s, const std::vector<std::string> &words) {
		std::vector<int> vec(s.length(), -1);

		return wordBreak_top_down(s, 0, words, vec);
	}

	bool wordBreak_bottom_up(const std::string &s, const std::vector<std::string> &words) {
		std::vector<bool> dp(s.length() + 1, false);

		dp[s.length()] = true;


		for (int i = s.length() - 1; i >= 0; i--) {

			for (const std::string &word: words) {
				dp[i] = isPrefix(s, i, word) && dp[i + word.length()];
				if (dp[i]) {
					break;
				}
			}
		}

		return dp[0];
	}
}
