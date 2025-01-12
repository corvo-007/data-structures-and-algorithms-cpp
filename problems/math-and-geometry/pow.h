#include <cmath>

namespace MathAndGeometry {
    double pow_iterative(double x, int n) {
        if (x == 0 || x == 1) {
            return x;
        }
        if (n == 0) {
            return 1;
        }

        double res = 1;
        long long abs_n = std::abs((long long) n);

        for (long long i = 1; i <= abs_n; i++) {
            res *= x;
        }

        return (n > 0) ? res : 1 / res;
    }

    double pow_recursive(double x, long long n) {
        if (x == 0 || x == 1) {
            return x;
        }
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return 1 / pow_recursive(x, std::abs(n));
        }

        return x * pow_recursive(x, n - 1);
    }

    double pow_recursive(double x, int n) {
        return pow_recursive(x, (long long) n);
    }

    double pow_recursive_optimised(double x, long long n) {
        if (x == 0 || x == 1) {
            return x;
        }
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return 1 / pow_recursive_optimised(x, std::abs(n));
        }

        double res = pow_recursive_optimised(x * x, n >> 1);
        return (n & 1) ? x * res : res;
    }

    double pow_recursive_optimised(double x, int n) {
        return pow_recursive_optimised(x, (long long) n);
    }

    double pow_recursive_tail(double x, long long n, double acc) {
        if (x == 0) {
            return 0;
        }
        if (n == 0 || x == 1) {
            return acc;
        }
        if (n < 0) {
            return 1 / pow_recursive_tail(x, std::abs(n), acc);
        }

        return pow_recursive_tail(x * x, n >> 1, (n & 1) ? acc * x : acc);
    }

    double pow_recursive_tail(double x, int n) {
        return pow_recursive_tail(x, (long long) n, 1);
    }
}