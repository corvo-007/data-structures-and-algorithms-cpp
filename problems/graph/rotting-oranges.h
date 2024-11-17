#include <vector>
#include <queue>
#include <unordered_set>

namespace Graph {

    int orangesRotting(std::vector<std::vector<int>> &grid) {
        int rows = grid.size(), cols = grid[0].size();

        std::queue<std::pair<int, int>> queue;

        int fresh = 0, minutes = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                }
                else if (grid[i][j] == 2) {
                    queue.push({i, j});
                }
            }
        }

        std::vector<std::pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while (!queue.empty() && fresh > 0) {
            int size = queue.size();

            while (size--) {
                auto [ i, j ] = queue.front();
                queue.pop();

                for (auto direction: directions) {
                    direction.first += i;
                    direction.second += j;

                    if (direction.first < 0 || direction.first == rows || direction.second < 0 || direction.second == cols || grid[direction.first][direction.second] != 1) {
                        continue;
                    }

                    grid[direction.first][direction.second] = 2;
                    fresh--;
                    queue.push({ direction.first, direction.second });
                }
            }

            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
}
