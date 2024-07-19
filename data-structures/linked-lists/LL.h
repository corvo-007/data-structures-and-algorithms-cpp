#include <iostream>
#include "../../common/node.h"

Node<int>* takeInput() {
    Node<int> *head = nullptr;
    int data;
    std::cout << "Enter the elements in Linked List (Enter -1 to stop):\n";
    std::cin >> data;
    while (data != -1) {
        if (head == nullptr) {
            head = new Node<int>(data);
        }
        else {
            Node<int> *temp = head;
            while (temp -> next != nullptr) {
                temp = temp -> next;
            }
            temp -> next = new Node<int>(data);
        }
        std::cin >> data;
    }
    return head;
}

Node<int>* takeInput_better() {
    Node<int> *head = nullptr, *tail = nullptr;
    int data;
    std::cout << "Enter the elements in Linked List (Enter -1 to stop):\n";
    std::cin >> data;

    while (data != -1) {
        if (head == nullptr) {
            head = new Node<int>(data);
            tail = head;
        }
        else {
            tail -> next = new Node<int>(data);
            tail = tail -> next;
        }
        std::cin >> data;
    }
    return head;
}

Node<int>* insertNode(Node<int> *head, int i, int data) {
    if (head == nullptr) {
        return head;
    }
    if (i == 0) {
        Node<int> *newNode = new Node<int>(data);
        newNode -> next = head;
        return newNode;
    }
    Node<int> *temp = head;
    int count = 0;
    while (temp != nullptr && count < i - 1) {
        temp = temp -> next;
        count++;
    }
    if (temp == nullptr) {
        return head;
    }
    Node<int> *newNode = new Node<int>(data);
    newNode -> next = temp -> next;
    temp -> next = newNode;
    return head;
}

Node<int>* deleteNode(Node<int> *head, int index) {
    if (head == nullptr) {
        return nullptr;
    }
    if (index == 0) {
        Node<int> *newHead = head -> next;
        delete head;
        return newHead;
    }
    int count = 0;
    Node<int> *temp = head;
    while (temp != nullptr && count < index - 1) {
        count++;
        temp = temp -> next;
    }
    if (temp == nullptr || temp -> next == nullptr) {
        return head;
    }
    Node<int> *delNode = temp -> next;
    temp -> next = delNode -> next;
    delete delNode;
    return head;
}

void printLL(Node<int> *head) {
    while (head != nullptr) {
        std::cout << head -> data << ' ';
        head = head -> next;
    }
    std::cout << '\n';
}