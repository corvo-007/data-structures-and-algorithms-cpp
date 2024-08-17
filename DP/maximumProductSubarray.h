#include <vector>

namespace DP {

    double maxProductSubarray_brute_force(const std::vector<int> &vec) {
        double maxProduct = INT_MIN;

        for (int i = 0; i < vec.size(); i++) {
            for (int j = i; j < vec.size(); j++) {
                double prod = 1;
                for (int k = i; k <= j; k++) {
                    prod *= vec[k];
                }
                maxProduct = std::max(maxProduct, prod);
            }
        }

        return maxProduct;
    }

    double maxProductSubarray_brute_force_optimised(const std::vector<int> &vec) {
        double maxProduct = INT_MIN;

        for (int i = 0; i < vec.size(); i++) {
            double prod = 1;
            for (int j = i; j < vec.size(); j++) {
                prod *= vec[j];
                maxProduct = std::max(maxProduct, prod);
            }
        }
        return maxProduct;
    }

    double maxProductSubarray(const std::vector<int> &vec) {
        double maxP = vec[0];

        double maxCurrP = vec[0];
        double minCurrP = vec[0];
        for (int i = 1; i < vec.size(); i++) {
            double temp = std::max(std::max(maxCurrP * vec[i], minCurrP * vec[i]), (double) vec[i]);
            minCurrP = std::min(std::min(maxCurrP * vec[i], minCurrP * vec[i]), (double) vec[i]);
            maxCurrP = temp;

            maxP = std::max(maxP, maxCurrP);
        }

        return maxP;
    }
}