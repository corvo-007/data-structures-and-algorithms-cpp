#include <vector>

namespace Backtracking {

    void subsets(const std::vector<int> &vec, int index, std::vector<int> &subset, std::vector<std::vector<int>> &output) {
        if (index == vec.size()) {
            output.push_back(subset);
            return ;
        }

        subset.push_back(vec[index]);
        subsets(vec, index + 1, subset, output);
        subset.pop_back();
        subsets(vec, index + 1, subset, output);
    }

    std::vector<std::vector<int>> subsets(const std::vector<int> &vec) {
        std::vector<std::vector<int>> output;
        std::vector<int> subset;
        subsets(vec, 0, subset, output);
        return output;
    }
}