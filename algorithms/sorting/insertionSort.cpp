#include <iostream>
#include "../../common/functions.h"

using namespace std;

void insertionSort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main() {
    int n;
    cout << "Enter size of the array: ";
    cin >> n;
    if (n <= 0) {
        cout << "Size of array cannot be less than 1";
        return 0;
    }

    int *arr = new int[n];

    cout << "Enter " << n << " elements in the array\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Before sorting the array: \n";
    print_array(arr, n);

    insertionSort(arr, n);

    cout << "After sorting the array: \n";
    print_array(arr, n);
}