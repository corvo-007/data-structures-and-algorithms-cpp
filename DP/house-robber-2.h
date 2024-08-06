#include <vector>

namespace DP {

	int houseRobber1(const std::vector<int> &vec) {
		if (vec.size() == 0) {
			return 0;
		}
		if (vec.size() == 1) {
			return vec[0];
		}
		if (vec.size() == 2) {
			return std::max(vec[0], vec[1]);
		}

		int one = vec[0];
		int two = std::max(vec[0], vec[1]);

		for (int i = 2; i < vec.size(); i++) {
			int temp = std::max(one + vec[i], two);
			one = two;
			two = temp;
		}

		return std::max(one, two);
	}

	int houseRobber2(std::vector<int> &vec) {
		if (vec.size() == 0) {
			return 0;
		}
		if (vec.size() == 1) {
			return vec[0];
		}
		if (vec.size() == 2) {
			return std::max(vec[0], vec[1]);
		}

		int temp = vec[vec.size() - 1];
		vec.pop_back();

		int one = houseRobber1(vec);
		vec.push_back(temp);
		vec.erase(vec.begin());


		int two = houseRobber1(vec);

		return std::max(one, two);
	}
}
