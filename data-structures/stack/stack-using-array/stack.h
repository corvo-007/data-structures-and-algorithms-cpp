#include <iostream>
#include <climits>

class Stack {
    int *data;
    int nextIndex;
    int capacity;

    public:

    Stack(int totalSize) {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    void push(int element) {
        if (nextIndex == capacity) {
            std::cout << "Stack is full\n";
            return ;
        }
        data[nextIndex++] = element;
    }

    int pop() {
        if (nextIndex == 0) {
            std:: cout << "Stack is empty\n";
            return INT_MIN;
        }
        return data[--nextIndex];
    }

    int top() {
        if (nextIndex == 0) {
            std::cout << "Stack is empty\n";
            return INT_MIN;
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