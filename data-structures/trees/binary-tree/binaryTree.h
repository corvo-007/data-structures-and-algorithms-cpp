#include <iostream>
#include "../../../common/binaryTreeNode.h"

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