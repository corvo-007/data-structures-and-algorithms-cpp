#include <unordered_set>

namespace MathAndGeometry {
    bool isHappy(int n) {
        if (n == 1) {
            return true;
        }

        std::unordered_set<int> set;

        while (!set.count(n)) {
            set.insert(n);
            int sum = 0;

            while (n) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }

            n = sum;

            if (n == 1) {
                return true;
            }
        }

        return false;
    }
}