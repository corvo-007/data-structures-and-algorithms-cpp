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

    void rotate(std::vector<std::vector<int>> &matrix) {
        for (int i = 0; i < matrix.size() / 2; i++) {
            for (int j = i; j < matrix.size() - i - 1; j++) {
                int m = i, n = j, save = matrix[i][j];

                for (int k = 0; k < 4; k++) {
                    int temp = n;
                    n = matrix.size() - m - 1;
                    m = temp;

                    std::swap(save, matrix[m][n]);
                }
            }
        }
    }
}