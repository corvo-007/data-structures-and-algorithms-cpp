#include <string>
#include <vector>

namespace Backtracking {

    bool isPalindrome(std::string s) {
        for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    void backtrack(const std::string &s, const int index, std::vector<std::string> &partitions, std::vector<std::vector<std::string>> &output) {
        if (index == s.length()) {
            output.push_back(partitions);
            return ;
        }

        std::string str = "";

        for (int i = index; i < s.length(); i++) {
            str.push_back(s[i]);

            if (isPalindrome(str)) {
                partitions.push_back(str);
                backtrack(s, i + 1, partitions, output);
                partitions.pop_back();
            }
        }
    }

    std::vector<std::vector<std::string>> partition(const std::string s) {
        std::vector<std::string> partitions;
        std::vector<std::vector<std::string>> output;
        backtrack(s, 0, partitions, output);
        return output;
    }
}