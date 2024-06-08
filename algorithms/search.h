namespace Search {

    int linearSearch(int *arr, int n, int searchValue) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == searchValue) {
                return i;
            }
        }
        return -1;
    }

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

    int binarySearch_recursive(int *arr, int start, int end, int searchValue) {
        if (start > end) {
            return -1;
        }
        
        int mid = start + (end - start) / 2;
        if (arr[mid] == searchValue) {
            return mid;
        }
        if (arr[mid] < searchValue) {
            return binarySearch_recursive(arr, mid + 1, end, searchValue);
        }
        return binarySearch_recursive(arr, start, mid - 1, searchValue);
    }

    int binarySearch_recursive(int *arr, int n, int searchValue) {
        return binarySearch_recursive(arr, 0, n - 1, searchValue);
    }
}