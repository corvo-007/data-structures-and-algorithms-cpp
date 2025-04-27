#include <vector>
#include <unordered_set>
#include <queue>
#include <climits>

namespace Graph {
    int bfs(const std::vector<std::vector<int>> &grid, int row, int col) {
        int dist = 0;

        std::unordered_set<int> visited;
        std::queue<std::pair<int, int>> queue;

        queue.push({ row, col });
        queue.push({ INT_MIN, INT_MIN });

        while (!queue.empty()) {
            auto [ i, j ] = queue.front();
            queue.pop();

            if (i == INT_MIN) {
                dist++;
                continue;
            }

            visited.insert(i * grid[0].size() + j);

            if (i - 1 >= 0 && !visited.count((i - 1) * grid[0].size()) && grid[i - 1][j] != -1) {
                if (grid[i - 1][j] == 0) {
                    return dist + 1;
                }

                queue.push({ i - 1, j });
            }

            if (j + 1 < grid[0].size() && !visited.count(i * grid[0].size() + j + 1) && grid[i][j + 1] != -1) {
                if (grid[i][j + 1] == 0) {
                    return dist + 1;
                }

                queue.push({ i, j + 1 });
            }

            if (i + 1 < grid.size() && !visited.count((i + 1) * grid[0].size() + j) && grid[i + 1][j] != -1) {
                if (grid[i + 1][j] == 0) {
                    return dist + 1;
                }

                queue.push({ i + 1, j });
            }

            if (j - 1 >= 0 && !visited.count(i * grid[0].size() + j - 1) && grid[i][j - 1] != -1) {
                if (grid[i][j - 1] == 0) {
                    return dist + 1;
                }

                queue.push({ i, j - 1});
            }

            if (!queue.empty() && queue.front().first == INT_MIN && queue.size() != 1) {
                queue.push({ INT_MIN, INT_MIN });
            }
        }

        return INT_MAX;
    }

    void wallsAndGates(std::vector<std::vector<int>> &grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == INT_MAX) {
                    grid[i][j] = bfs(grid, i, j);
                }
            }
        }
    }
}