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

int numNodes(TreeNode<int> *root) {
    if (root == nullptr) {
        return 0;
    }
    int num = 1;
    for (int i = 0; i < root -> children.size(); i++) {
        num += numNodes(root -> children[i]);
    }
    return num;
}

int sumOfTree(TreeNode<int> *root) {
    if (root == nullptr) {
        return 0;
    }
    int sum = root -> data;
    for (int i = 0; i < root -> children.size(); i++) {
        sum += sumOfTree(root -> children[i]);
    }
    return sum;
}

TreeNode<int>* maxTreeNode(TreeNode<int> *root) {
    if (root == nullptr) {
        return nullptr;
    }
    TreeNode<int> *maxNode = root;
    for (int i = 0; i < root -> children.size(); i++) {
        TreeNode<int> *maxInSubTree = maxTreeNode(root -> children[i]);
        if (maxInSubTree -> data > maxNode -> data) {
            maxNode = maxInSubTree;
        }
    }
    return maxNode;
}

int height(TreeNode<int> *root) {
    if (root == nullptr) {
        return 0;
    }
    int maxHeight = 0;

    for (int i = 0; i < root -> children.size(); i++) {
        int h = height(root -> children[i]);
        if (h > maxHeight) {
            maxHeight = h;
        }
    }
    return maxHeight + 1;
}

void printTreeRecursive(TreeNode<int> *root) {
    if (root == nullptr) {
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

void printTreeLevelWise(TreeNode<int> *root) {
    if (root == nullptr) {
        return ;
    }
    Queue<TreeNode<int>*> queue;
    queue.push(root);

    while (!queue.isEmpty()) {
        TreeNode<int> *front = queue.pop();

        std::cout << front -> data << ": ";
        for (int i = 0; i < front -> children.size(); i++) {
            queue.push(front -> children[i]);
            if (i == front -> children.size() - 1) {
                std::cout << front -> children[i] -> data;
                break;
            }
            std::cout << front -> children[i] -> data << ", ";
        }
        std::cout << '\n';
    }
}