#include <vector>
#include <string>

namespace Backtracking {

    void backtrack(const std::string &digits, const int index, std::string &combination, std::vector<std::string> &output, const std::vector<std::string> &characters) {
        if (index == digits.size()) {
            output.push_back(combination);
            return ;
        }

        for (const char &digit : characters[(digits[index] - '0') - 1]) {
            combination.push_back(digit);
            backtrack(digits, index + 1, combination, output, characters);
            combination.pop_back();
        }
    }

    std::vector<std::string> letterCombinations(const std::string digits) {
        if (digits == "") {
            return {};
        }
        std::vector<std::string> output;
        std::string combination = "";
        std::vector<std::string> characters = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtrack(digits, 0, combination, output, characters);
        return output;
    }
}