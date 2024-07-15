#include <utility>

namespace Sort {

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

    void heapSort(int *arr, int n) {
        for (int i = 1; i < n; i++) {
            int child = i;
            int parent = (child - 1) / 2;

            while (parent >= 0 && arr[parent] > arr[child]) {
                std::swap(arr[parent], arr[child]);

                child = parent;
                parent = (child - 1) / 2;
            }
        }

        int size = n;

        while (size > 1) {
            std::swap(arr[0], arr[size - 1]);

            size--;

            int parent = 0;
            int left = 1;
            int right = 2;

            while (right < size && (arr[parent] > arr[left] || arr[parent] > arr[right])) {
                int index = (arr[left] < arr[right]) ? left : right;

                std::swap(arr[parent], arr[index]);

                parent = index;
                left = (2 * parent) + 1;
                right = left + 1;
            }

            if (left < size && arr[parent] > arr[left]) {
                std::swap(arr[parent], arr[left]);
            }
        }
    }
}