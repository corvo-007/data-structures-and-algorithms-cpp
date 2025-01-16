#include <vector>
#include <unordered_map>

namespace MathAndGeometry {
    class DetectSquares {
        std::unordered_map<int, std::unordered_map<int, int>> points;
        
    public:
        DetectSquares() {

        }

        void add(std::vector<int> point) {
            points[point[0]][point[1]]++;
        }

        int count(std::vector<int> point) {
            int c = 0;
            for (auto i = points.begin(); i != points.end(); i++) {
                if (i -> first == point[0]) {
                    continue;
                }

                for (auto j = i -> second.begin(); j != i -> second.end(); j++) {
                    if (j -> first == point[1]) {
                        continue;
                    }

                    if (std::abs(point[0] - i -> first) != std::abs(point[1] - j -> first)) {
                        continue;
                    }

                    if (points.count(point[0]) && points[point[0]].count(j -> first) && i -> second.count(point[1])) {
                        c += j -> second * points[point[0]][j -> first] * i -> second[point[1]];
                    }
                }
            }

            return c;
        }
    };
}