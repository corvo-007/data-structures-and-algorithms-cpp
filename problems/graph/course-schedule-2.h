#include <vector>
#include <unordered_map>
#include <unordered_set>

namespace Graph {
    bool dfs(std::unordered_map<int, std::vector<int>> &map, int course, std::unordered_set<int> &visited, std::unordered_set<int> &finished, std::vector<int> &output) {
        if (visited.count(course)) {
            return false;
        }

        if (finished.count(course)) {
            return true;
        }

        visited.insert(course);

        for (int i = 0; i < map[course].size(); i++) {
            if (!dfs(map, map[course][i], visited, finished, output)) {
                return false;
            }
        }

        visited.erase(course);
        finished.insert(course);
        output.push_back(course);

        return true;
    }

    std::vector<int> findOrder(int courses, std::vector<std::vector<int>> &prerequisites) {
        std::unordered_map<int, std::vector<int>> map;

        for (const auto &prerequisite : prerequisites) {
            map[prerequisite[0]].push_back(prerequisite[1]);
        }

        std::unordered_set<int> visited;
        std::unordered_set<int> finished;

        std::vector<int> output;

        for (int i = 0; i < courses; i++) {
            if (!dfs(map, i, visited, finished, output)) {
                return {};
            }
        }

        return output;
    }
}