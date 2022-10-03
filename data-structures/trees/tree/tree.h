#include <iostream>
#include "../../../common/treeNode.h"

void printTreeRecursive(TreeNode<int> *root) {
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