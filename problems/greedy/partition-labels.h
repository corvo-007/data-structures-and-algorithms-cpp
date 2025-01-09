#include <vector>
#include <string>
#include <unordered_map>

namespace Greedy {
    std::vector<int> partitionLabels(std::string s) {
        std::unordered_map<char, int> last_pos;

        for (int i = 0; i < s.length(); i++) {
            last_pos[s[i]] = i;
        }

        int left = 0;
        std::vector<int> output;

        while (left < s.length()) {
            int right = last_pos[s[left]];
            for (int i = left + 1; i < right; i++) {
                right = std::max(right, last_pos[s[i]]);
            }

            output.push_back(right - left + 1);
            left = right + 1;
        }

        return output;
    }
}