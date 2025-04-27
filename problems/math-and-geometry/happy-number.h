#include <unordered_set>

namespace MathAndGeometry {
    int sumOfSquaresOfDigits(int n) {
        int sum = 0;

        while (n) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        if (n == 1) {
            return true;
        }

        std::unordered_set<int> set;

        while (!set.count(n)) {
            set.insert(n);
            n = sumOfSquaresOfDigits(n);

            if (n == 1) {
                return true;
            }
        }

        return false;
    }

    bool isHappy2(int n) {
        if (n == 1) {
            return true;
        }

        int slow = sumOfSquaresOfDigits(n);
        int fast = sumOfSquaresOfDigits(slow);

        while (slow != fast) {
            slow = sumOfSquaresOfDigits(slow);
            fast = sumOfSquaresOfDigits(sumOfSquaresOfDigits(fast));

            if (fast == 1) {
                return true;
            }
        }

        return slow == 1;
    }
}