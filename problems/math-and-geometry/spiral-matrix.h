#include <vector>

namespace MathAndGeometry {
    std::vector<int> spiralOrder(const std::vector<std::vector<int>> &matrix) {
        std::vector<int> output;

        int n = std::min(matrix.size(), matrix[0].size());

        for (int i = 0; i <= (n - 1) / 2; i++) {
            int minrow = i, mincol = i, maxrow = matrix.size() - 1 - i, maxcol = matrix[0].size() - i - 1;
            for (int col = mincol; col <= maxcol; col++) {
                output.push_back(matrix[minrow][col]);
            }

            minrow++;

            if (minrow > maxrow) {
                break;
            }

            for (int row = minrow; row <= maxrow; row++) {
                output.push_back(matrix[row][maxcol]);
            }

            maxcol--;

            if (maxcol < mincol) {
                break;
            }

            for (int col = maxcol; col >= mincol; col--) {
                output.push_back(matrix[maxrow][col]);
            }

            maxrow--;

            for (int row = maxrow; row >= minrow; row--) {
                output.push_back(matrix[row][mincol]);
            }
        }

        return output;
    }
}
