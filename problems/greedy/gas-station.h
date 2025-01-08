#include <vector>
#include <numeric>

namespace Greedy {
    int canCompleteCircuit_brute_force(const std::vector<int> &gas, const std::vector<int> &cost) {
        for (int i = 0; i < gas.size(); i++) {
            if (gas[i] < cost[i]) {
                continue;
            }

            int tank = gas[i] - cost[i];

            int j = (i + 1) % gas.size();


            while (j != i) {
                tank += gas[j] - cost[j];

                if (tank < 0) {
                    break;
                }
                j = (j + 1) % gas.size();
            }

            if (i == j) {
                return i;
            }
        }
        return -1;
    }

    int canCompleteCircuit_two_pointer(const std::vector<int> &gas, const std::vector<int> &cost) {
        int start = gas.size() - 1, end = 0;

        int tank = gas[start] - cost[start];

        while (start > end) {
            if (tank < 0) {
                start--;
                tank += gas[start] - cost[start];
            }
            else {
                tank += gas[end] - cost[end];
                end++;
            }
        }

        return (tank >= 0) ? start : -1;
    }

    int canCompleteCircuit(const std::vector<int> &gas, const std::vector<int> &cost) {
        int totalGas = std::accumulate(gas.begin(), gas.end(), 0);
        int totalCost = std::accumulate(cost.begin(), cost.end(), 0);

        if (totalGas < totalCost) {
            return -1;
        }

        int index = 0, tank = 0;

        for (int i = 0; i < gas.size(); i++) {
            tank += (gas[i] - cost[i]);

            if (tank < 0) {
                tank = 0;
                index = i + 1;
            }
        }
        return index;
    }
}