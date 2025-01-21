#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <queue>

namespace AdvancedGraphs {
    bool dfs(std::unordered_map<std::string, std::map<std::string, int>> &graph, std::string airport, int used_tickets, int total_tickets, std::vector<std::string> &output) {
        if (used_tickets == total_tickets) {
            output.push_back(airport);
            return true;
        }

        if (!graph.count(airport)) {
            return false;
        }

        output.push_back(airport);

        for (auto &pair : graph.at(airport)) {
            if (pair.second != 0) {
                pair.second--;
                if (dfs(graph, pair.first, used_tickets + 1, total_tickets, output)) {
                    return true;
                }
                pair.second++;
            }
        }

        output.pop_back();
        return false;
    }

    std::vector<std::string> findItinerary(const std::vector<std::vector<std::string>> &tickets) {
        std::unordered_map<std::string, std::map<std::string, int>> graph;

        for (const auto &ticket : tickets) {
            graph[ticket[0]][ticket[1]]++;
        }

        int total_tickets = tickets.size();

        std::vector<std::string> output;

        dfs(graph, "JFK", 0, total_tickets, output);

        return output;
    }
}