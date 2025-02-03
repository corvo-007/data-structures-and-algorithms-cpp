#include <vector>
#include <algorithm>

namespace AdvancedGraphs {
    int maxInGrid(const std::vector<std::vector<int>> &grid) {
        int max = INT_MIN;
        for (const auto &row : grid) {
            max = std::max(max, *std::max_element(row.begin(), row.end()));
        }
        return max;
    }

    bool dfs(const std::vector<std::vector<int>> &grid, int i, int j, int &t, std::vector<std::vector<bool>> &output) {
        if (i == -1 || i == grid.size() || j == -1 || j == grid[0].size() || !output[i][j]) {
            return false;
        }

        if (grid[i][j] > t) {
            output[i][j] = false;
            return false;
        }

        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return true;
        }

        output[i][j] = false;
        output[i][j] = dfs(grid, i - 1, j, t, output) || dfs(grid, i, j + 1, t, output) || dfs(grid, i + 1, j, t, output) || dfs(grid, i, j - 1, t, output);
        return output[i][j];
    }

    bool checkPath(const std::vector<std::vector<int>> &grid, int t) {
        std::vector<std::vector<bool>> output(grid.size(), std::vector(grid[0].size(), true));
        return dfs(grid, 0, 0, t, output);
    }

    int swimInWater(const std::vector<std::vector<int>> &grid) {
        int low = 0, high = maxInGrid(grid);

        int t = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (checkPath(grid, mid)) {
                t = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return t;
    }
}