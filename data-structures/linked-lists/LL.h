#include <iostream>
// #include "../../common/node.h"

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this -> data = data;
        next = NULL;
    }
};

Node* takeInput() {
    Node *head = NULL;
    int data;
    std::cout << "Enter the elements in Linked List (Enter -1 to stop):\n";
    std::cin >> data;
    while (data != -1) {
        if (head == NULL) {
            head = new Node(data);
        }
        else {
            Node *temp = head;
            while (temp -> next != NULL) {
                temp = temp -> next;
            }
            temp -> next = new Node(data);
        }
        std::cin >> data;
    }
    return head;
}

Node* takeInput_better() {
    Node *head = NULL, *tail = NULL;
    int data;
    std::cout << "Enter the elements in Linked List (Enter -1 to stop):\n";
    std::cin >> data;

    while (data != -1) {
        if (head == NULL) {
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
    if (head == NULL) {
        return head;
    }
    if (i == 0) {
        Node *newNode = new Node(data);
        newNode -> next = head;
        return newNode;
    }
    Node *temp = head;
    int count = 0;
    while (temp != NULL && count < i - 1) {
        temp = temp -> next;
        count++;
    }
    if (temp == NULL) {
        return head;
    }
    Node *newNode = new Node(data);
    newNode -> next = temp -> next;
    temp -> next = newNode;
    return head;
}

Node* deleteNode(Node *head, int index) {
    if (head == NULL) {
        return NULL;
    }
    if (index == 0) {
        Node *newHead = head -> next;
        delete head;
        return newHead;
    }
    int count = 0;
    Node *temp = head;
    while (temp != NULL && count < index - 1) {
        count++;
        temp = temp -> next;
    }
    if (temp == NULL || temp -> next == NULL) {
        return head;
    }
    Node *delNode = temp -> next;
    temp -> next = delNode -> next;
    delete delNode;
    return head;
}

void printLL(Node *head) {
    while (head != NULL) {
        std::cout << head -> data << ' ';
        head = head -> next;
    }
    std::cout << '\n';
}