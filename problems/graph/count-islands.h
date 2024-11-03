#include <vector>
#include <queue>
#include <unordered_set>

namespace Graph {

    void dfs(std::vector<std::vector<char>> &grid, int i, int j) {
        if (i == -1 || i == grid.size() || j == -1 || j == grid[0].size() || grid[i][j] == '0') {
            return ;
        }

        grid[i][j] = '0';

        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
    }

    void bfs(std::vector<std::vector<char>> &grid, int i, int j) {
        std::queue<std::pair<int, int>> queue;

        queue.push({i, j});

        while (!queue.empty()) {
            auto [first, second] = queue.front();
            queue.pop();

            if (grid[first][second] == '0') {
                continue;
            }

            grid[first][second] = '0';

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
    }

    // changes grid
    int numIslands(std::vector<std::vector<char>> &grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(const std::vector<std::vector<char>> &grid, int i, int j, std::unordered_set<int> &visited) {
        if (i == -1 || i == grid.size() || j == -1 || j == grid[0].size() || grid[i][j] == '0' || visited.count(i * grid[0].size() + j)) {
            return ;
        }

        visited.insert(i * grid[0].size() + j);

        dfs(grid, i - 1, j, visited);
        dfs(grid, i, j + 1, visited);
        dfs(grid, i + 1, j, visited);
        dfs(grid, i, j - 1, visited);
    }

    void bfs(const std::vector<std::vector<char>> &grid, int i, int j, std::unordered_set<int> &visited) {

        std::queue<std::pair<int, int>> queue;

        queue.push({i, j});

        while (!queue.empty()) {
            auto [first, second] = queue.front();
            queue.pop();

            if (visited.count(first * grid[0].size() + second) || grid[first][second] == '0') {
                continue;
            }

            visited.insert(first * grid[0].size() + second);

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
    }

    int numIslands(const std::vector<std::vector<char>> &grid) {
        int count = 0;

        std::unordered_set<int> visited;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!visited.count(i * grid[0].size() + j) && grid[i][j] == '1') {
                    bfs(grid, i, j, visited);
                    count++;
                }
            }
        }

        return count;
    }
}