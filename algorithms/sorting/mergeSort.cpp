#include <iostream>
#include "../../common/functions.h"

void merge(int *arr, int start, int mid, int end) {
    int size1 = mid - start + 1;
    int size2 = end - mid;

    int *arr1 = new int[size1];
    int *arr2 = new int[size2];

    for (int i = 0; i < size1; i++) {
        arr1[i] = arr[start + i];
    }
    for (int i = 0; i < size2; i++) {
        arr2[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = start;
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i++];
        }
        else {
            arr[k] = arr2[j++];
        }
        k++;
    }

    while (i < size1) {
        arr[k++] = arr1[i++];
    }
    while (j < size2) {
        arr[k++] = arr2[j++];
    }
}

void mergeSort(int *arr, int start, int end) {
    if (start >= end) {
        return ;
    }
    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void mergeSort(int *arr, int n) {
    mergeSort(arr, 0, n - 1);
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

    mergeSort(arr, n);

    std::cout << "After sorting the array: \n";
    print_array(arr, n);
}