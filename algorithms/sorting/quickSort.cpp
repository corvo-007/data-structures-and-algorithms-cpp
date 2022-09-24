#include <iostream>
#include "../../common/functions.h"

using namespace std;

int partition(int *arr, int start, int end) {
    int pivot = start;
    for (int i = start + 1; i <= end; i++) {
        if (arr[start] > arr[i]) {
            pivot++;
        }
    }

    int temp = arr[start];
    arr[start] = arr[pivot];
    arr[pivot] = temp;

    int i = start, j = end;
    while (i < pivot && j > pivot) {
        if (arr[i] < arr[pivot]) {
            i++;
            continue;
        }
        if (arr[j] >= arr[pivot]) {
            j--;
            continue;
        }
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    return pivot;
}

void quickSort(int *arr, int start, int end) {
    if (start >= end) {
        return ;
    }
    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
}

void quickSort(int *arr, int n) {
    quickSort(arr, 0, n - 1);
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

    quickSort(arr, n);

    cout << "After sorting the array: \n";
    print_array(arr, n);
}