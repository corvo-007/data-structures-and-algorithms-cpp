#include <vector>

namespace Backtracking {

    void permute(std::vector<int> &vec, int index, std::vector<std::vector<int>> &permutations) {
        if (index == vec.size()) {
            permutations.push_back(vec);
            return ;
        }

        for (int i = index; i < vec.size(); i++) {
            std::swap(vec[i], vec[index]);
            permute(vec, index + 1, permutations);
            std::swap(vec[i], vec[index]);
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int> &vec) {
        std::vector<std::vector<int>> output;
        permute(vec, 0, output);
        return output;
    }
}