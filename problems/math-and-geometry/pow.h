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
        long abs_n = abs((long) n);

        for (long i = 1; i <= abs_n; i++) {
            res *= x;
        }

        return (n > 0) ? res : 1 / res;
    }
}