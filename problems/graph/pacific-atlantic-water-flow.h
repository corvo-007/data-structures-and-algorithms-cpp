#include <vector>

namespace Graph {

    void dfs(const std::vector<std::vector<int>> &heights, int i, int j, std::vector<std::vector<int>> &grid, const int &ocean, std::vector<std::vector<int>> &output) {
        if (grid[i][j] >= ocean) {
            return;
        }

        grid[i][j] += ocean;

        if (grid[i][j] == 3) {
            output.push_back({ i, j });
        }

        if (i - 1 >= 0 && heights[i - 1][j] >= heights[i][j]) {
            dfs(heights, i - 1, j, grid, ocean, output);
        }

        if (j + 1 < grid[0].size() && heights[i][j + 1] >= heights[i][j]) {
            dfs(heights, i, j + 1, grid, ocean, output);
        }

        if (i + 1 < grid.size() && heights[i + 1][j] >= heights[i][j]) {
            dfs(heights, i + 1, j, grid, ocean, output);
        }

        if (j - 1 >= 0 && heights[i][j - 1] >= heights[i][j]) {
            dfs(heights, i, j - 1, grid, ocean, output);
        }
    }

    std::vector<std::vector<int>> pacificAtlantic(const std::vector<std::vector<int>> &heights) {

        std::vector<std::vector<int>> grid(heights.size(), std::vector<int>(heights[0].size(), 0));
        std::vector<std::vector<int>> output;

        for (int i = 0; i < heights.size(); i++) {
            dfs(heights, i, 0, grid, 1, output);
        }

        for (int i = 0; i < heights[0].size(); i++) {
            dfs(heights, 0, i, grid, 1, output);
        }

        for (int i = 0; i < heights.size(); i++) {
            dfs(heights, i, heights[0].size() - 1, grid, 2, output);
        }

        for (int i = 0; i < heights[0].size(); i++) {
            dfs(heights, heights.size() - 1, i, grid, 2, output);
        }

        return output;
    }
}