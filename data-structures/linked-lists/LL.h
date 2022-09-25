#include <iostream>
#include "../../common/node.h"

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

void printLL(Node *head) {
    while (head != NULL) {
        std::cout << head -> data << ' ';
        head = head -> next;
    }
    std::cout << '\n';
}