#include <iostream>

using namespace std;

int linearSearch(int *arr, int n, int searchValue) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == searchValue) {
            return i;
        }
    }
    return -1;
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
    cout << "Enter " << n << " elements in the array\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int searchValue;
    cout << "Enter the search value: ";
    cin >> searchValue;
    int index = linearSearch(arr, n, searchValue);
    if (index != -1) {
        cout << "Found the searched element at index " << index + 1;
    }
    else {
        cout << "Element is not in the array";
    }
}