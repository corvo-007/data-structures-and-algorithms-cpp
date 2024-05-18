#include <iostream>

int binarySearch(int *arr, int n, int searchValue) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == searchValue) {
            return mid;
        }
        if (arr[mid] < searchValue) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Size of the array cannot be less than 1";
        return -1;
    }
    int *arr = new int[n];
    std::cout << "Enter " << n << " elements in the array (array must be sorted otherwise binary search will fail)\n";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int searchValue;
    std::cout << "Enter the search value: ";
    std::cin >> searchValue;
    int index = binarySearch(arr, n, searchValue);
    if (index != -1) {
        std::cout << "Found the searched element at index " << index + 1;
    }
    else {
        std::cout << "Element is not in the array";
    }
}