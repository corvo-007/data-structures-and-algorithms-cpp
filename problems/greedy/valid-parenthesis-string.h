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

    bool checkValidString(const std::string &s) {
        int min = 0, max = 0;

        for (const char &c : s) {
            if (c == '(') {
                min++;
                max++;
            }
            else if (c == ')') {
                min--;
                max--;
            }
            else {
                min--;
                max++;
            }

            if (max < 0) {
                return false;
            }
            if (min < 0) {
                min = 0;
            }
        }
        return min == 0;
    }
}
