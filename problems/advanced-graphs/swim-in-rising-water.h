#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include "../../data-structures/disjoint-set/disjointSet.h"

namespace AdvancedGraphs {
    int maxInGrid(const std::vector<std::vector<int>> &grid) {
        int max = INT_MIN;
        for (const auto &row : grid) {
            max = std::max(max, *std::max_element(row.begin(), row.end()));
        }
        return max;
    }

    bool dfs(const std::vector<std::vector<int>> &grid, int i, int j, int &t, std::vector<std::vector<bool>> &output) {
        if (i == -1 || i == grid.size() || j == -1 || j == grid.size() || !output[i][j]) {
            return false;
        }

        if (grid[i][j] > t) {
            output[i][j] = false;
            return false;
        }

        if (i == grid.size() - 1 && i == j) {
            return true;
        }

        output[i][j] = false;
        output[i][j] = dfs(grid, i - 1, j, t, output) || dfs(grid, i, j + 1, t, output) || dfs(grid, i + 1, j, t, output) || dfs(grid, i, j - 1, t, output);
        return output[i][j];
    }

    bool checkPath(const std::vector<std::vector<int>> &grid, int t) {
        std::vector<std::vector<bool>> output(grid.size(), std::vector(grid.size(), true));
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

    int swimInWater_dijkstra(const std::vector<std::vector<int>> &grid) {
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid.size(), false));

        std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<std::pair<int, std::pair<int, int>>>> pq;

        const std::vector<std::pair<int, int>> directions = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

        pq.push({ grid[0][0], { 0, 0 }});
        visited[0][0] = true;

        while (!pq.empty()) {
            auto [ min_t, ij_pair ] = pq.top();
            pq.pop();

            auto &[ i, j ] = ij_pair;

            if (i == grid.size() - 1 && i == j) {
                return min_t;
            }

            for (auto &[ di, dj ] : directions) {
                int ni = i + di, nj = j + dj;

                if (ni == -1 || ni == grid.size() || nj == -1 || nj == grid.size() || visited[ni][nj]) {
                    continue;
                }

                pq.push({ std::max(min_t, grid[ni][nj]), { ni, nj }});
                visited[ni][nj] = true;
            }
        }

        return -1;
    }

    int swimInWater_kruskal(const std::vector<std::vector<int>> &grid) {
        std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<std::pair<int, std::pair<int, int>>>> pq;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                pq.push({ grid[i][j], { i, j }});
            }
        }

        const std::vector<std::pair<int, int>> directions = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

        DisjointSet disjointSet(grid.size() * grid.size());

        while (!pq.empty()) {
            auto [ t, ij_pair ] = pq.top();
            pq.pop();

            for (auto &[ di, dj ] : directions) {
                int ni = ij_pair.first + di, nj = ij_pair.second + dj;

                if (ni == -1 || ni == grid.size() || nj == -1 || nj == grid.size() || grid[ni][nj] > t) {
                    continue;
                }

                disjointSet.unionByRank(ij_pair.first * grid.size() + ij_pair.second, ni * grid.size() + nj);
            }

            if (disjointSet.findParent(0) == disjointSet.findParent(grid.size() * grid.size() - 1)) {
                return t;
            }
        }

        return -1;
    }
}