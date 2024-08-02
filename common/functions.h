#include <iostream>
#include <vector>
#include <unordered_map>

void print_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

template <typename T>
std::ostream& operator<<(std::ostream &out, const std::vector<T> &vec) {
    for (const auto &i: vec) {
        out << i << ' ';
    }
    return out;
}

std::unordered_map<char, int> frequencyCount(const std::string &str) {
	std::unordered_map<char, int> map;

	for (char c: str) {
		map[c]++;
	}
	return map;
}
