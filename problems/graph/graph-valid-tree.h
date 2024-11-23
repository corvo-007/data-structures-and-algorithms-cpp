#include <vector>
#include <unordered_map>
#include <unordered_set>

namespace Graph {

    bool dfs(std::unordered_map<int, std::vector<int>> &map, int vertex, int prevVertex, std::unordered_set<int> &visited) {
        if (visited.count(vertex)) {
            return false;
        }

        visited.insert(vertex);

        for (int i = 0; i < map[vertex].size(); i++) {
            if (prevVertex != map[vertex][i] && !dfs(map, map[vertex][i], vertex, visited)) {
                return false;
            }
        }

        return true;
    }

    bool validTree(int n, std::vector<std::vector<int>> &edges) {
        std::unordered_map<int, std::vector<int>> map;

        for (const std::vector<int> &edge : edges) {
            map[edge[0]].push_back(edge[1]);
            map[edge[1]].push_back(edge[0]);
        }

        std::unordered_set<int> visited;

        return dfs(map, 0, -1, visited) && visited.size() == n;
    }
}