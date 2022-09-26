#include <climits>

template <typename T>
class Stack {
    T *data;
    int nextIndex;
    int capacity;

    public:

    Stack(int totalSize) {
        data = new T[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    void push(T element) {
        if (nextIndex == capacity) {
            return ;
        }
        data[nextIndex++] = element;
    }

    T pop() {
        if (nextIndex == 0) {
            return 0;
        }
        return data[--nextIndex];
    }

    T top() {
        if (nextIndex == 0) {
            return 0;
        }
        return data[nextIndex - 1];
    }

    int size() {
        return nextIndex;
    }

    bool isEmpty() {
        return nextIndex == 0;
    }
};