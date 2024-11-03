#include <vector>
#include <unordered_set>
#include <queue>

namespace Graph {

    int dfs(const std::vector<std::vector<int>> &grid, int i, int j, std::unordered_set<int> &visited) {
        if (grid[i][j] == 0 || visited.count(i * grid[0].size() + j)) {
            return 0;
        }


        visited.insert(i * grid[0].size() + j);
        int area = 1;

        if (i - 1 >= 0) {
            area += dfs(grid, i - 1, j, visited);
        }
        if (j + 1 < grid[0].size()) {
            area += dfs(grid, i, j + 1, visited);
        }
        if (i + 1 < grid.size()) {
            area += dfs(grid, i + 1, j, visited);
        }
        if (j - 1 >= 0) {
            area += dfs(grid, i, j - 1, visited);
        }

        return area;
    }

    int bfs(const std::vector<std::vector<int>> &grid, int i, int j, std::unordered_set<int> &visited) {

        std::queue<std::pair<int, int>> queue;

        queue.push({i, j});

        int area = 0;

        while (!queue.empty()) {
            auto [first, second] = queue.front();
            queue.pop();

            if (grid[first][second] == 0 || visited.count(first * grid[0].size() + second)) {
                continue;
            }

            visited.insert(first * grid[0].size() + second);
            area++;

            if (first - 1 >= 0) {
                queue.push({first - 1, second});
            }
            if (second + 1 < grid[0].size()) {
                queue.push({first, second + 1});
            }
            if (first + 1 < grid.size()) {
                queue.push({first + 1, second});
            }
            if (second - 1 >= 0) {
                queue.push({first, second - 1});
            }
        }
        return area;
    }

    int maxAreaOfIsland(const std::vector<std::vector<int>> &grid) {
        std::unordered_set<int> visited;
        int maxarea = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && !visited.count(i * grid[0].size() + j)) {
                    int area = bfs(grid, i, j, visited);
                    maxarea = std::max(maxarea, area);
                }
            }
        }
        return maxarea;
    }
}