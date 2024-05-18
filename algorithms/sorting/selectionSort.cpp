#include <iostream>
#include "../../common/functions.h"

void selectionSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int smallIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[smallIndex]) {
                smallIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[smallIndex];
        arr[smallIndex] = temp;
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

    selectionSort(arr, n);

    std::cout << "After sorting the array: \n";
    print_array(arr, n);
}