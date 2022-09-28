#include "../../../common/node.h"

template <typename T>
class Queue {
    Node<T> *head;
    Node<T> *tail;
    int _size;

    public:

    Queue() {
        head = NULL;
        tail = NULL;
        _size = 0;
    }

    void push(T data) {
        if (head == NULL) {
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
        if (head == NULL) {
            return 0;
        }
        T data = head -> data;
        Node<T> *temp = head;
        head = head -> next;
        delete temp;
        if (head == NULL) {
            tail = NULL;
        }
        _size--;
        return data;
    }

    T front() const {
        if (head == NULL) {
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