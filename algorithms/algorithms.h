#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include "../common/node.h"

namespace Algo {

    // kadane's algorithm
    int maximumSumSubArray(int *arr, int n) {
        if (n == 0) {
            return 0;
        }

        int maxSum = arr[0];
        int currSum = 0;

        for (int i = 0; i < n; i++) {
            if (currSum < 0) {
                currSum = 0;
            }
            currSum += arr[i];

            maxSum = std::max(maxSum, currSum);
        }

        return maxSum;
    }

    // floyd's cycle detection
    bool cycleDetection(Node<int> *head) {
        Node<int> *slow = head;
        Node<int> *fast = head;

        while (fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }

    int kmp() {
        return 0;
    }

    int partition(int *arr, int start, int end) {
        int pivot = start;

        for (int i = start; i < end; i++) {
            if (arr[i] <= arr[end]) {
                std::swap(arr[i], arr[pivot]);
                pivot++;
            }
        }

        std::swap(arr[pivot], arr[end]);
        return pivot;
    }

    int quickSelect(int *arr, int start, int end, int k) {
        if (start > end) {
            return INT_MIN;
        }

        int pivot = partition(arr, start, end);

        if (k - 1 == pivot) {
            return arr[pivot];
        }

        return (k - 1 < pivot) ? quickSelect(arr, start, pivot - 1, k) : quickSelect(arr, pivot + 1, end, k);
    }

    int quickSelect(int *arr, int n, int k) {
        return (k <= 0 || k > n) ? INT_MIN : quickSelect(arr, 0, n - 1, k);
    }

    int quickSelectKthLargest(int *arr, int n, int k) {
        return quickSelect(arr, n, n - k  + 1);
    }

    // boyer-moore majority voting algorithm
    int majorityElement(int *arr, int n) {
        int major = 0, majorCount = 0;

        for (int i = 0; i < n; i++) {
            if (majorCount == 0) {
                major = arr[i];
            }
            majorCount += (arr[i] == major) ? 1 : -1;
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == major) {
                count++;
            }
        }

        return (count > n / 2) ? major : INT_MIN;
    }

    int gcd(int a, int b) {
        if (a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }

    int gcdIterative(int a, int b) {
        while (a != 0) {
            int temp = b % a;
            b = a;
            a = temp;
        }

        return b;
    }
}