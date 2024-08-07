#include <string>

namespace DP {

	bool isPalindrome(const std::string &str, int start, int end) {
		while (start < end) {
			if (str[start] != str[end]) {
				return false;
			}
			start++;
			end--;
		}
		return true;
	}

	std::string longestPalindrome_brute_force(const std::string &str) {
        std::string output;
		int length = 0;

		for (int i = 0; i < str.length(); i++) {
            std::string temp = "";

			for (int j = i; j < str.length(); j++) {
                temp += str[j];
				if (isPalindrome(str, i, j)) {
                    if (j - i + 1 > length) {
                        output = temp;
                        length = j - i + 1;
                    }
				}
			}
		}

		return output;
	}

	std::string longestPalindrome_optimised(const std::string &str) {
		if (str.length() == 0) {
			return "";
		}
		int length = 0;
        std::string output;

		for (int i = 0; i < str.length(); i++) {
			int j = i, k = i;

			while (j >= 0 && k < str.length() && str[j] == str[k]) {
                if (k - j + 1 > length) {
                    length = k - j + 1;
                    output = str.substr(j, length);
                }
				j--;
				k++;
			}

            j = i;
            k = i + 1;

            while (j >= 0 && k < str.length() && str[j] == str[k]) {
                if (k - j + 1 > length) {
                    length = k - j + 1;
                    output = str.substr(j, length);
                }
                j--;
                k++;
            }
		}

		return output;
	}
}
