#include <iostream>
#include <vector>
#include "../../../common/binaryTreeNode.h"
#include "../../queue/queue-using-LL/queue.h"

BinaryTreeNode<int>* takeInputRecursive() {
    int data;
    std::cout << "Enter data (-1 to put NULL): ";
    std::cin >> data;
    if (data == -1) {
        return nullptr;
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
        return nullptr;
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
    return (root == nullptr) ? 0 : 1 + numOfNodes(root -> left) + numOfNodes(root -> right);
}

bool findNode(BinaryTreeNode<int> *root, int data) {
    return (root == nullptr) ? false : (root -> data == data) ? true : (findNode(root -> left, data)) ? true : findNode(root -> right, data);
}

int height(BinaryTreeNode<int> *root) {
    return (root == nullptr) ? 0 : 1 + std::max(height(root -> left), height(root -> right));
}

int sumOfBinaryTree(BinaryTreeNode<int> *root) {
    return (root == nullptr) ? 0 : root -> data + sumOfBinaryTree(root -> left) + sumOfBinaryTree(root -> right);
}

void printBinaryTreeRecursive(BinaryTreeNode<int> *root) {
    if (root == nullptr) {
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
    if (root == nullptr) {
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

void printPreOrder(BinaryTreeNode<int> *root) {
    if (root == nullptr) {
        return ;
    }
    std::cout << root -> data << ' ';
    printPreOrder(root -> left);
    printPreOrder(root -> right);
}

std::vector<int>* preOrderVector(BinaryTreeNode<int> *root) {
    if (root == nullptr) {
        return nullptr;
    }
    std::vector<int> *ans = new std::vector<int>();
    ans -> push_back(root -> data);
    std::vector<int> *left = preOrderVector(root -> left);
    if (left != nullptr) {
        for (int i = 0; i < left -> size(); i++) {
            ans -> push_back(left -> at(i));
        }
    }
    std::vector<int> *right = preOrderVector(root -> right);
    if (right != nullptr) {
        for (int i = 0; i < right -> size(); i++) {
            ans -> push_back(right -> at(i));
        }
    }
    return ans;
}

void printPostOrder(BinaryTreeNode<int> *root) {
    if (root == nullptr) {
        return ;
    }
    printPostOrder(root -> left);
    printPostOrder(root -> right);
    std::cout << root -> data << ' ';
}

std::vector<int>* postOrderVector(BinaryTreeNode<int> *root) {
    if (root == nullptr) {
        return nullptr;
    }
    std::vector<int> *ans = postOrderVector(root -> left);
    std::vector<int> *right = postOrderVector(root -> right);

    if (ans == nullptr) {
        ans = new std::vector<int>();
    }
    if (right != nullptr) {
        for (int i = 0; i < right -> size(); i++) {
            ans -> push_back(right -> at(i));
        }
    }
    ans -> push_back(root -> data);
    return ans;
}

BinaryTreeNode<int>* getLCANode(BinaryTreeNode<int>* const root, int d1, int d2) {
    if (root == nullptr) {
        return root;
    }

    if (root -> data == d1 || root -> data == d2) {
        return root;
    }

    auto left = getLCANode(root -> left, d1, d2);
    auto right = getLCANode(root -> right, d1, d2);

    return (left && right) ? root : (left) ? left : right;
}

int getLCA(BinaryTreeNode<int>* const root, int d1, int d2) {
    if (root == nullptr) {
        return -1;
    }
    auto node = getLCANode(root, d1, d2);
    return (node) ? node -> data : -1;
}