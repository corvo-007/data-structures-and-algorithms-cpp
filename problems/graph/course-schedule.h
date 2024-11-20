#include <vector>
#include <unordered_map>
#include <unordered_set>

namespace Graph {

    bool dfs(std::unordered_map<int, std::vector<int>> &map, int course, std::unordered_set<int> &visited) {
        if (visited.count(course)) {
            return false;
        }

        if (map[course].size() == 0) {
            return true;
        }

        visited.insert(course);

        for (int i = 0; i < map[course].size(); i++) {
            if (!dfs(map, map[course][i], visited)) {
                return false;
            }
        }

        visited.erase(course);
        map[course].clear();

        return true;
    }

    bool courseSchedule(int numCourses, std::vector<std::vector<int>> &prerequisites) {
        std::unordered_map<int, std::vector<int>> map;

        for (int i = 0; i < prerequisites.size(); i++) {
            map[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }


        std::unordered_set<int> visited;

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(map, i, visited)) {
                return false;
            }
        }

        return true;
    }
}