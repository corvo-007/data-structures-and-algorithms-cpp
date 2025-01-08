#include <vector>
#include <algorithm>
#include <unordered_map>

namespace Greedy {
    bool isNStraightHand(std::vector<int> &hand, int groupSize) {
        if (hand.size() % groupSize) {
            return false;
        }

        std::sort(hand.begin(), hand.end());

        std::unordered_map<int, int> map;

        for (const int &h : hand) {
            map[h]++;
        }

        for (const int &h: hand) {
            if (!map.count(h)) {
                continue;
            }

            if (map.count(h - 1)) {
                continue;
            }

            int j = h;
            while (j < h + groupSize) {
                if (!map.count(j)) {
                    return false;
                }

                map[j]--;

                if (map[j] == 0) {
                    map.erase(j);
                }

                j++;
            }
        }

        return true;
    }
}