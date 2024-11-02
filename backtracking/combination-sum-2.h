#include <vector>
#include <algorithm>

namespace Backtracking {

    void combinationSum(const std::vector<int> &vec, int index, const int sum, const int target, std::vector<int> &combination, std::vector<std::vector<int>> &combinations) {
        if (sum == target) {
            combinations.push_back(combination);
            return ;
        }
        if (sum > target || index == vec.size()) {
            return ;
        }

        combination.push_back(vec[index]);
        combinationSum(vec, index + 1, sum + vec[index], target, combination, combinations);
        combination.pop_back();
        
        while (index + 1 < vec.size() && vec[index] == vec[index + 1]) {
            index += 1;
        }
        combinationSum(vec, index + 1, sum, target, combination, combinations);
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int> &vec, const int target) {
        std::sort(vec.begin(), vec.end());
        std::vector<std::vector<int>> combinations;
        std::vector<int> combination;
        combinationSum(vec, 0, 0, target, combination, combinations);
        return combinations;
    }
}