#include <iostream>
// #include "../../common/node.h"

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this -> data = data;
        next = nullptr;
    }
};

Node* takeInput() {
    Node *head = nullptr;
    int data;
    std::cout << "Enter the elements in Linked List (Enter -1 to stop):\n";
    std::cin >> data;
    while (data != -1) {
        if (head == nullptr) {
            head = new Node(data);
        }
        else {
            Node *temp = head;
            while (temp -> next != nullptr) {
                temp = temp -> next;
            }
            temp -> next = new Node(data);
        }
        std::cin >> data;
    }
    return head;
}

Node* takeInput_better() {
    Node *head = nullptr, *tail = nullptr;
    int data;
    std::cout << "Enter the elements in Linked List (Enter -1 to stop):\n";
    std::cin >> data;

    while (data != -1) {
        if (head == nullptr) {
            head = new Node(data);
            tail = head;
        }
        else {
            tail -> next = new Node(data);
            tail = tail -> next;
        }
        std::cin >> data;
    }
    return head;
}

Node* insertNode(Node *head, int i, int data) {
    if (head == nullptr) {
        return head;
    }
    if (i == 0) {
        Node *newNode = new Node(data);
        newNode -> next = head;
        return newNode;
    }
    Node *temp = head;
    int count = 0;
    while (temp != nullptr && count < i - 1) {
        temp = temp -> next;
        count++;
    }
    if (temp == nullptr) {
        return head;
    }
    Node *newNode = new Node(data);
    newNode -> next = temp -> next;
    temp -> next = newNode;
    return head;
}

Node* deleteNode(Node *head, int index) {
    if (head == nullptr) {
        return nullptr;
    }
    if (index == 0) {
        Node *newHead = head -> next;
        delete head;
        return newHead;
    }
    int count = 0;
    Node *temp = head;
    while (temp != nullptr && count < index - 1) {
        count++;
        temp = temp -> next;
    }
    if (temp == nullptr || temp -> next == nullptr) {
        return head;
    }
    Node *delNode = temp -> next;
    temp -> next = delNode -> next;
    delete delNode;
    return head;
}

void printLL(Node *head) {
    while (head != nullptr) {
        std::cout << head -> data << ' ';
        head = head -> next;
    }
    std::cout << '\n';
}