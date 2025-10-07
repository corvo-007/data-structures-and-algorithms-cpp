#include <algorithm>
#include <unordered_map>
#include <string>

namespace ArrayAndHashing {
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        return s == t;
    }

    bool isAnagram_optimised_using_hashmap(const std::string s, const std::string t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::unordered_map<char, int> char_count;

        for (const char &ch : s) {
            char_count[ch]++;
        }

        for (const char &ch : t) {
            if (!char_count.count(ch) || char_count[ch] == 0) {
                return false;
            }
            char_count[ch]--;
        }

        return true;
    }

    bool isAnagram_optimised_using_array_1(const std::string s, const std::string t) {
        if (s.length() != t.length()) {
            return false;
        }

        int count[26] = {0};

        for (const char &ch : s) {
            count[ch - 'a']++;
        }

        for (const char &ch : t) {
            if (!count[ch - 'a']) {
                return false;
            }
            count[ch - 'a']--;
        }

        return true;
    }

    bool isAnagram_optimised_using_array_2(const std::string s, const std::string t) {
        if (s.length() != t.length()) {
            return false;
        }

        int count[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }

        return true;
    }
}
