#include <iostream>
#include "../../../common/treeNode.h"

TreeNode<int>* takeInputRecursive() {
    int data;
    std::cout << "Enter data: ";
    std::cin >> data;

    TreeNode<int> *root = new TreeNode<int>(data);

    int n;
    std::cout << "Enter number of children: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        root -> children.push_back(takeInputRecursive());
    }
    return root;
}

void printTreeRecursive(TreeNode<int> *root) {
    if (root == NULL) {
        return ;
    }
    std::cout << root -> data << ": ";
    for (int i = 0; i < root -> children.size(); i++) {
        if (i == root -> children.size() - 1) {
            std::cout << root -> children[i] -> data;
            break;
        }
        std::cout << root -> children[i] -> data << ", ";
    }
    std::cout << '\n';

    for (int i = 0; i < root -> children.size(); i++) {
        printTreeRecursive(root -> children[i]);
    }
}