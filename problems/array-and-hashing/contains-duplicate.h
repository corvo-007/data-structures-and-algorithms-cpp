#include <algorithm>
#include <unordered_set>
#include <vector>

namespace ArrayAndHashing {
    bool containsDuplicate_brute_force(const std::vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }

    bool containsDuplicate_sorting(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }

    bool containsDuplicate_hashing(const std::vector<int> &nums) {
        std::unordered_set<int> seen;
        for (const int &num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
}