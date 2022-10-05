#include <iostream>
#include "../../../common/binaryTreeNode.h"
#include "../../queue/queue-using-LL/queue.h"

BinaryTreeNode<int>* takeInputRecursive() {
    int data;
    std::cout << "Enter data (-1 to put NULL): ";
    std::cin >> data;
    if (data == -1) {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    root -> left = takeInputRecursive();
    root -> right = takeInputRecursive();
    return root;
}

BinaryTreeNode<int>* takeInputLevelWise() {
    int data;
    std::cout << "Enter data: ";
    std::cin >> data;
    if (data == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    Queue<BinaryTreeNode<int>*> queue;

    queue.push(root);

    while (!queue.isEmpty()) {
        BinaryTreeNode<int> *front = queue.pop();

        std::cout << "Enter left data of " << front -> data << ": ";
        std::cin >> data;
        if (data != -1) {
            front -> left = new BinaryTreeNode<int>(data);
            queue.push(front -> left);
        }
        std::cout << "Enter right data of " << front -> data << ": ";
        std::cin >> data;
        if (data != -1) {
            front -> right = new BinaryTreeNode<int>(data);
            queue.push(front -> right);
        }
    }
    return root;
}

int numOfNodes(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + numOfNodes(root -> left) + numOfNodes(root -> right);
}

void printBinaryTreeRecursive(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return ;
    }
    std::cout << root -> data << ": ";
    if (root -> left) {
        std::cout << "L: "<< root -> left -> data;
    }
    if (root -> left && root -> right) {
        std::cout << ", ";
    }
    if (root -> right) {
        std::cout << "R: " << root -> right -> data;
    }
    std::cout << '\n';
    printBinaryTreeRecursive(root -> left);
    printBinaryTreeRecursive(root -> right);
}

void printBinaryTreeLevelWise(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return ;
    }
    Queue<BinaryTreeNode<int>*> queue;

    queue.push(root);

    while (!queue.isEmpty()) {
        BinaryTreeNode<int> *front = queue.pop();

        std::cout << front -> data << ": ";
        if (front -> left) {
            std::cout << "L: " << front -> left -> data;
            queue.push(front -> left);
        }
        if (front -> left && front -> right) {
            std::cout << ", ";
        }
        if (front -> right) {
            std::cout << "R: " << front -> right -> data;
            queue.push(front -> right);
        }
        std::cout << '\n';
    }
}