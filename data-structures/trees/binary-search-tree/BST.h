#include <iostream>
#include "../../../common/binaryTreeNode.h"

class BST {
    BinaryTreeNode<int> *root;

public:
    BST() {
        root = nullptr;
    }

private:
    BinaryTreeNode<int>* insertRecursive(BinaryTreeNode<int> *root, int data) const {
        if (root == nullptr) {
            root = new BinaryTreeNode<int>(data);
            return root;
        }

        if (data <= root -> data) {
            root -> left = insertRecursive(root -> left, data);
        }
        else {
            root -> right = insertRecursive(root -> right, data);
        }
        return root;
    }
    
    bool searchRecursive(BinaryTreeNode<int> *root, int data) const {
        if (root == nullptr) {
            return false;
        }
        if (root -> data == data) {
            return true;
        }
        if (root -> data > data) {
            return searchRecursive(root -> left, data);
        }
        return searchRecursive(root -> right, data);
    }

    BinaryTreeNode<int>* removeRecursive(BinaryTreeNode<int> *root, int data) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root -> data == data) {

            if (root -> left == nullptr && root -> right == nullptr) {
                delete root;
                return nullptr;
            }

            BinaryTreeNode<int> *temp = nullptr;

            if (root -> left == nullptr) {
                temp = root -> right;
                root -> right = nullptr;
                delete root;
                return temp;
            }

            if (root -> right == nullptr) {
                temp = root -> left;
                root -> left = nullptr;
                delete root;
                return temp;
            }

            temp = root -> right;

            while (temp -> left != nullptr) {
                temp = temp -> left;
            }

            root -> data = root -> data + temp -> data;
            temp -> data = root -> data - temp -> data;
            root -> data = root -> data - temp -> data;

            root -> right = removeRecursive(root -> right, data);

            return root;
        }

        if (root -> data > data) {
            root -> left = removeRecursive(root -> left, data);
        }
        else {
            root -> right = removeRecursive(root -> right, data);
        }

        return root;
    }

    void printTreeRecursive(const BinaryTreeNode<int>* const root) const {
        if (root == nullptr) {
            return ;
        }

        std::cout << root -> data << ':';

        if (root -> left != nullptr) {
            std::cout << "L:" << root -> left -> data << ',';
        }
        if (root -> right != nullptr) {
            std::cout << "R:" << root -> right -> data;
        }
        std::cout << '\n';

        printTreeRecursive(root -> left);
        printTreeRecursive(root -> right);
    }

public:
    void insertRecursive(int data) {
        root = insertRecursive(root, data);
    }

    bool searchRecursive(int data) const {
        return searchRecursive(root, data);
    }

    void removeRecursive(int data) {
        root = removeRecursive(root, data);
    }

    void printTreeRecursive() const {
        printTreeRecursive(root);
    }
};