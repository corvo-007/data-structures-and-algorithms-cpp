#include <iostream>
#include <vector>

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
