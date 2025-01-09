#include <vector>

namespace Greedy {
    bool mergeTriplets(const std::vector<std::vector<int>> &triplets, const std::vector<int> &target) {
        bool first = false, second = false, third = false;

        for (const auto &triplet : triplets) {
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]) {
                continue;
            }

            first |= triplet[0] == target[0];
            second |= triplet[1] == target[1];
            third |= triplet[2] == target[2];

            if (first && second && third) {
                return true;
            }
        }

        return false;
    }
}