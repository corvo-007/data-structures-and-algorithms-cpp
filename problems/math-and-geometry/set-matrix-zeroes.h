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

    void setZeroes(std::vector<std::vector<int>> &matrix) {
        int firstrow = false, firstcol = false;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) {
                        firstrow = true;
                    }
                    if (j == 0) {
                        firstcol = true;
                    }
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (firstrow) {
            for (int i = 1; i < matrix[0].size(); i++) {
                matrix[0][i] = 0;
            }
        }
        if (firstcol) {
            for (int i = 1; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
}