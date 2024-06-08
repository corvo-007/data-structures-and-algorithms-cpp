#include <vector>

class PriorityQueue {
    std::vector<int> pq;

public:
    PriorityQueue() {

    }

private:
    void upHeapify() {
        int child = pq.size() - 1;
        int parent = (child - 1) / 2;

        while (parent >= 0 && pq[child] < pq[parent]) {
            std::swap(pq[child], pq[parent]);

            child = parent;
            parent = (child - 1) / 2;
        }
    }

    void downHeapify() {
        int parent = 0;
        int leftChild = 2 * parent + 1;
        int rightChild = leftChild + 1;

        while (rightChild < pq.size() && (pq[parent] > pq[leftChild] || pq[parent] > pq[rightChild])) {
            int index = (pq[leftChild] < pq[rightChild]) ? leftChild : rightChild;

            std::swap(pq[parent], pq[index]);
            parent = index;

            leftChild = 2 * parent + 1;
            rightChild = leftChild + 1;
        }

        if (leftChild < pq.size() && pq[parent] > pq[leftChild]) {
            std::swap(pq[parent], pq[leftChild]);
        }
    }

public:
    void push(int element) {
        pq.push_back(element);
        upHeapify();
    }

    int pop() {
        if (empty()) {
            return 0;
        }

        int value = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        downHeapify();

        return value;
    }

    int top() {
        return (empty()) ? 0 : pq[0];
    }

    int size() {
        return pq.size();
    }

    bool empty() {
        return pq.empty();
    }
};
