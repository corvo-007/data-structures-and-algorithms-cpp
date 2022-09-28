#include <iostream>
#include "LL.h"

using namespace std;


int main() {
    Node *head = takeInput_better();
    printLL(head);
    int index, data;
    cin >> index >> data;
    head = insertNode(head, index, data);
    printLL(head);
    head = deleteNode(head, index);
    printLL(head);
}