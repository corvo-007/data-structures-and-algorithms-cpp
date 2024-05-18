#include "../../../common/node.h"

template <typename T>
class Queue {
    Node<T> *head;
    Node<T> *tail;
    int _size;

    public:

    Queue() {
        head = nullptr;
        tail = nullptr;
        _size = 0;
    }

    void push(T data) {
        if (head == nullptr) {
            head = new Node<T>(data);
            tail = head;
        }
        else {
            tail -> next = new Node<T>(data);
            tail = tail -> next;
        }
        _size++;
    }

    T pop() {
        if (head == nullptr) {
            return 0;
        }
        T data = head -> data;
        Node<T> *temp = head;
        head = head -> next;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
        _size--;
        return data;
    }

    T front() const {
        if (head == nullptr) {
            return 0;
        }
        return head -> data;
    }

    int size() const {
        return _size;
    }

    bool isEmpty() const {
        return _size == 0;
    }
};