#include <string>
#include <unordered_map>

namespace Greedy {
    bool checkValidString_recursion(const std::string &s, int index, int open) {
        if (index == s.length()) {
            return open == 0;
        }

        if (open < 0) {
            return false;
        }

        if (s[index] == '(') {
            return checkValidString_recursion(s, index + 1, open + 1);
        }
        
        if (s[index] == ')') {
            return checkValidString_recursion(s, index + 1, open - 1);
        }

        return checkValidString_recursion(s, index + 1, open + 1) || checkValidString_recursion(s, index + 1, open - 1) || checkValidString_recursion(s, index + 1, open);
    }

    bool checkValidString_recursion(const std::string &s) {
        return checkValidString_recursion(s, 0, 0);
    }
}
