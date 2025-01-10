#include <vector>

namespace MathAndGeometry {
    void rotate_with_space(std::vector<std::vector<int>> &matrix) {
        int n = matrix.size();

        std::vector<std::vector<int>> output(n, std::vector<int>(n));

        for (int i = 0; i < n; i++) {
            int k = n - i - 1;
            for (int j = 0; j < n; j++) {
                output[j][k] = matrix[i][j];
            }
        }

        matrix = output;
    }
}