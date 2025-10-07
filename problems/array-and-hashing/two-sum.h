#include <vector>
#include <unordered_map>

namespace ArrayAndHashing {
    std::vector<int> twoSum_brute_force(const std::vector<int> &nums, int target) {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return { i, j };
                }
            }
        }

        return {};
    }

    std::vector<int> twoSum_optimised(std::vector<int> &nums, int target) {
        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            if (map.count(target - nums[i])) {
                return { map[target - nums[i]], i };
            }
            map[nums[i]] = i;
        }

        return {};
    }
}