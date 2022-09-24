#include <iostream>

using namespace std;

int binarySearch(int *arr, int start, int end, int searchValue) {
    if (start > end) {
        return -1;
    }
    
    int mid = start + (end - start) / 2;
    if (arr[mid] == searchValue) {
        return mid;
    }
    if (arr[mid] < searchValue) {
        return binarySearch(arr, mid + 1, end, searchValue);
    }
    return binarySearch(arr, start, mid - 1, searchValue);
}

int binarySearch(int *arr, int n, int searchValue) {
    return binarySearch(arr, 0, n - 1, searchValue);
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    if (n <= 0) {
        cout << "Size of the array cannot be less than 1";
        return -1;
    }
    int *arr = new int[n];
    cout << "Enter " << n << " elements in the array (array must be sorted otherwise binary search will fail)\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int searchValue;
    cout << "Enter the search value: ";
    cin >> searchValue;
    
    int index = binarySearch(arr, n, searchValue);
    
    if (index != -1) {
        cout << "Found the searched element at index " << index + 1;
    }
    else {
        cout << "Element is not in the array";
    }
}