#include <vector>

namespace DP {

    int maxProductSubarray_brute_force(const std::vector<int> &vec) {
        int maxProduct = INT_MIN;

        for (int i = 0; i < vec.size(); i++) {
            for (int j = i; j < vec.size(); j++) {
                int prod = 1;
                for (int k = i; k <= j; k++) {
                    prod *= vec[k];
                }
                maxProduct = std::max(maxProduct, prod);
            }
        }

        return maxProduct;
    }

    int maxProductSubarray_brute_force_optimised(const std::vector<int> &vec) {
        int maxProduct = INT_MIN;

        for (int i = 0; i < vec.size(); i++) {
            int prod = 1;
            for (int j = i; j < vec.size(); j++) {
                prod *= vec[j];
                maxProduct = std::max(maxProduct, prod);
            }
        }
        return maxProduct;
    }

    int maxProductSubarray(const std::vector<int> &vec) {
        int maxP = vec[0];

        int maxCurrP = vec[0];
        int minCurrP = vec[0];
        for (int i = 1; i < vec.size(); i++) {
            int temp = std::max(std::max(maxCurrP * vec[i], minCurrP * vec[i]), vec[i]);
            minCurrP = std::min(std::min(maxCurrP * vec[i], minCurrP * vec[i]), vec[i]);
            maxCurrP = temp;

            maxP = std::max(maxP, maxCurrP);
        }

        return maxP;
    }
}