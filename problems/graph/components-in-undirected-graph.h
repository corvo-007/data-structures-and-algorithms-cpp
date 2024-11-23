#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

namespace Graph {
    void bfs(std::unordered_map<int, std::vector<int>> &map, int vertex, std::unordered_set<int> &visited) {
        std::queue<int> queue;

        queue.push(vertex);

        while (!queue.empty()) {
            int front = queue.front();
            queue.pop();

            visited.insert(front);

            for (const int &i : map[front]) {
                if (!visited.count(i)) {
                    queue.push(i);
                }
            }
        }
    }

    void dfs(std::unordered_map<int, std::vector<int>> &map, int vertex, std::unordered_set<int> &visited) {
        if (visited.count(vertex)) {
            return;
        }

        visited.insert(vertex);

        for (const int &i : map[vertex]) {
            dfs(map, i, visited);
        }
    }

    int countComponents(int n, const std::vector<std::vector<int>> &edges) {
        std::unordered_map<int, std::vector<int>> map;

        for (const std::vector<int> &edge : edges) {
            map[edge[0]].push_back(edge[1]);
            map[edge[1]].push_back(edge[0]);
        }

        int count = 0;
        std::unordered_set<int> visited;

        for (int i = 0; i < n; i++) {
            if (!visited.count(i)) {
                bfs(map, i, visited);
                count++;
            }
        }

        return count;
    }
}