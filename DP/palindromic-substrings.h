#include <string>

namespace DP {

    int palindromicSubstrings(const std::string &str) {
        if (str.length() <= 1) {
            return str.length();
        }

        int count = 0;

        for (int i = 0; i < str.length(); i++) {
            int j = i, k = i;

            while (j >= 0 && k < str.length() && str[j] == str[k]) {
                count++;
                j--;
                k++;
            }

            j = i;
            k = i + 1;

            while (j >= 0 && k < str.length() && str[j] == str[k]) {
                count++;
                j--;
                k++;
            }
        }

        return count;
    }
}