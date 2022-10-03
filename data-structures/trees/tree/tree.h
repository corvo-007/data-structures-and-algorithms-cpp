#include <iostream>
#include "../../../common/treeNode.h"
#include "../../queue/queue-using-LL/queue.h"

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

TreeNode<int>* takeInputLevelWise() {
    int data;
    std::cout << "Enter root: ";
    std::cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);

    Queue<TreeNode<int>*> queue;
    queue.push(root);

    while (!queue.isEmpty()) {
        TreeNode<int> *front = queue.pop();
        int n;
        std::cout << "Enter number of children of " << front -> data << ": ";
        std::cin >> n;
        if (n > 0) {
            std::cout << "Enter " << n << " children of " << front -> data << ": \n";
        }
        for (int i = 0; i < n; i++) {
            std::cin >> data;
            TreeNode<int> *child = new TreeNode<int>(data);
            front -> children.push_back(child);
            queue.push(child);
        }
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