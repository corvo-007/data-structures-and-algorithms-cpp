#include <vector>
#include <climits>

namespace AdvancedGraphs {
    int findCheapestPrice(int n, const std::vector<std::vector<int>> &flights, int src, int dest, int k) {
        std::vector<int> prices(n, INT_MAX);

        prices[src] = 0;

        for (int i = 0; i <= k; i++) {
            std::vector<int> tempPrices = prices;

            for (const std::vector<int> &flight : flights) {
                if (prices[flight[0]] != INT_MAX && prices[flight[0]] + flight[2] < tempPrices[flight[1]]) {
                    tempPrices[flight[1]] = prices[flight[0]] + flight[2];
                }
            }

            prices = tempPrices;
        }

        return prices[dest] != INT_MAX ? prices[dest] : -1;
    }
}