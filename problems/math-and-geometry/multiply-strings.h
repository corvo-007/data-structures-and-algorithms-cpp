#include <string>
#include <algorithm>
#include <vector>

namespace MathAndGeometry {
    std::string add(std::string s1, std::string s2, int skipCount) {
        std::string sum = s1.substr(0, skipCount);
        int carry = 0;

        int i, j;

        for (i = skipCount, j = 0; i < s1.length() && j < s2.length(); i++, j++) {
            int s = (s1[i] - '0') + (s2[j] - '0') + carry;
            sum.push_back((s % 10) + '0');
            carry = s / 10;
        }

        for (; i < s1.length(); i++) {
            int s = (s1[i] - '0') + carry;
            sum.push_back((s % 10) + '0');
            carry = s / 10;
        }

        for (; j < s2.length(); j++) {
            int s = (s2[j] - '0') + carry;
            sum.push_back((s % 10) + '0');
            carry = s / 10;
        }

        if (carry) {
            sum.push_back('1');
        }

        return sum;
    }
    
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        std::string sum;
        int count = 0;
        for (int i = num1.size() - 1; i >= 0; i--) {
            std::string mul;
            int carry = 0;

            for (int j = num2.size() - 1; j >= 0; j--) {
                int p = (num1[i] - '0') * (num2[j] - '0') + carry;
                mul.push_back((p % 10) + '0');
                carry = p / 10;
            }

            if (carry) {
                mul.push_back(carry + '0');
            }

            sum = add(sum, mul, count);
            count++;
        }

        std::reverse(sum.begin(), sum.end());

        return sum;
    }

    std::string multiply_optimised(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        std::vector<int> sum(num1.size() + num2.size(), 0);

        for (int i = num1.size() - 1; i >= 0; i--) {
            int n = num1[i] - '0';
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; j--) {
                int s = sum[i + j + 1] + n * (num2[j] - '0');
                sum[i + j + 1] = s % 10;
                
                int c = sum[i + j] + s / 10 + carry;
                sum[i + j] = c % 10;
                carry = c / 10;
            }
        }

        std::string output;
        bool leading = true;

        for (int i = 0; i < sum.size(); i++) {
            if (leading && sum[i] == 0) {
                continue;
            }
            leading = false;
            output.push_back(sum[i] + '0');
        }

        return output;
    }
}