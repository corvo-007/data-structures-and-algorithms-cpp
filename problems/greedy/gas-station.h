#include <vector>

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
}