#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

namespace Intervals {
    std::vector<int> minInterval_brute_force(std::vector<std::vector<int>> &intervals, std::vector<int> &queries) {
        std::vector<int> output;
        for (const int &query : queries) {
            int i = INT_MAX;

            for (const std::vector<int> &interval : intervals) {
                if (interval[0] <= query && query <= interval[1] && interval[1] - interval[0] + 1 < i) {
                    i = interval[1] - interval[0] + 1;
                }
            }

            output.push_back(i != INT_MAX ? i : -1);
        }

        return output;
    }

    std::vector<int> minInterval(std::vector<std::vector<int>> &intervals, std::vector<int> &queries) {
        auto sortedQueries = queries;

        std::sort(intervals.begin(), intervals.end());
        std::sort(sortedQueries.begin(), sortedQueries.end());

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
        std::unordered_map<int, int> map;

        int i = 0;

        for (const int &query : sortedQueries) {
            while (i < intervals.size() && query >= intervals[i][0]) {
                minHeap.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }

            while (!minHeap.empty() && minHeap.top().second < query) {
                minHeap.pop();
            }

            map[query] = !minHeap.empty() ? minHeap.top().first : -1;
        }

        std::vector<int> output;

        for (const int &query : queries) {
            output.push_back(map[query]);
        }

        return output;
    }
}