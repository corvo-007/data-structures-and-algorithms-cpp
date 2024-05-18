#include "../../../common/node.h"

template <typename T>
class Stack {
    Node<T> *head;
    int _size;

    public:

    Stack() {
        head = nullptr;
        _size = 0;
    }

    void push(T data) {
        if (head == nullptr) {
            head = new Node<T>(data);
        }
        else {
            Node<T> *node = new Node<T>(data);
            node -> next = head;
            head = node;
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
        _size--;
        return data;
    }

    T top() {
        if (head == nullptr) {
            return 0;
        }
        return head -> data;
    }

    int size() {
        return _size;
    }

    bool isEmpty() {
        return _size == 0;
    }
};