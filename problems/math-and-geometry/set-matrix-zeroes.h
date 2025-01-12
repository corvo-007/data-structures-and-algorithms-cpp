#include <vector>
#include <unordered_set>

namespace MathAndGeometry {
    void setZeroes(std::vector<std::vector<int>> &matrix) {
        std::unordered_set<int> rows;
        std::unordered_set<int> cols;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for (int row : rows) {
            for (int i = 0; i < matrix[0].size(); i++) {
                matrix[row][i] = 0;
            }
        }

        for (int col : cols) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][col] = 0;
            }
        }
    }
}