#include <vector>

namespace MathAndGeometry {
    std::vector<int> plusOne(const std::vector<int> &digits) {
        int one = 1, carry = 0;

        std::vector<int> output = digits;

        for (int i = digits.size() - 1; i >= 0; i--) {
            int sum = carry + digits[i] + one;
            if (one) {
                one = 0;
            }

            output[i] = sum % 10;
            carry = sum / 10;
            if (!carry) {
                break;
            }
        }

        if (carry) {
            output.emplace(output.begin(), 1);
        }

        return output;
    }
}