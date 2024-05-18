#include <iostream>
#include "../../common/functions.h"

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    std::cout << "Enter size of the array: ";
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Size of array cannot be less than 1";
        return 0;
    }

    int *arr = new int[n];

    std::cout << "Enter " << n << " elements in the array\n";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::cout << "Before sorting the array: \n";
    print_array(arr, n);

    bubbleSort(arr, n);

    std::cout << "After sorting the array: \n";
    print_array(arr, n);
}