#include <vector>

namespace Backtracking {

    void combinationSum(const std::vector<int> &vec, int index, int sum, int target, std::vector<int> &subset, std::vector<std::vector<int>> &output) {
        if (sum > target || index == vec.size()) {
            return ;
        }
        if (sum == target) {
            output.push_back(subset);
            return ;
        }

        subset.push_back(vec[index]);
        combinationSum(vec, index, sum + vec[index], target, subset, output);
        subset.pop_back();
        combinationSum(vec, index + 1, sum, target, subset, output);
    }

    std::vector<std::vector<int>> combinationSum(const std::vector<int> &vec, int target) {
        std::vector<std::vector<int>> output;
        std::vector<int> subset;
        combinationSum(vec, 0, 0, target, subset, output);
        return output;
    }
}
