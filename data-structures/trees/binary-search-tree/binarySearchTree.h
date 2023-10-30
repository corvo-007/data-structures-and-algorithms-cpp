#include <iostream>
#include <vector>
#include "../../../common/binaryTreeNode.h"
#include "../../../common/node.h"

bool searchInBST(BinaryTreeNode<int> *root, int searchValue) {
    if (root == NULL) {
        return false;
    }
    if (root -> data == searchValue) {
        return true;
    }
    if (root -> data > searchValue) {
        return searchInBST(root -> left, searchValue);
    }
    return searchInBST(root -> right, searchValue);
}

void printInRange(BinaryTreeNode<int> *root, int min, int max) {
    if (root == nullptr) {
        return ;
    }
    if (root -> data > min) {
        printInRange(root -> left, min, max);
    }
    if (root -> data >= min && root -> data <= max) {
        std::cout << root -> data << ' ';
    }
    if (root -> data <= max) {
        printInRange(root -> right, min, max);
    }
}

// We don't know if the Binary Tree is a BST
int minimum(BinaryTreeNode<int> *root) {
    if (root == nullptr) {
        return INT_MAX;
    }
    return std::min(root -> data, std::min(minimum(root -> left), minimum(root -> right)));
}

// We don't know if the Binary Tree is a BST
int maximum(BinaryTreeNode<int> *root) {
    if (root == nullptr) {
        return INT_MIN;
    }
    return std::max(root -> data, std::max(maximum(root -> left), maximum(root -> right)));
}

bool isBST(BinaryTreeNode<int> *root) {
    if (root == nullptr) {
        return true;
    }
    return root -> data > maximum(root -> left) && root -> data <= minimum(root -> right) && isBST(root -> left) && isBST(root -> right);
}

std::pair<bool, std::pair<int, int>> isBST_optimised1_helper(BinaryTreeNode<int> *root) {
    if (root == nullptr) {
        return { true, { INT_MAX, INT_MIN } };
    }
    auto left = isBST_optimised1_helper(root -> left);
    auto right = isBST_optimised1_helper(root -> right);

    bool isbst = left.first && right.first && root -> data > left.second.second && root -> data <= right.second.first;
    std::pair<int, int> minmax = { std::min(root -> data, std::min(left.second.first, right.second.first)), std::max(root -> data, std::max(left.second.second, right.second.second)) };
    return { isbst, minmax };
}

bool isBST_optimised1(BinaryTreeNode<int> *root) {
    if (root == nullptr) {
        return true;
    }
    return isBST_optimised1_helper(root).first;
}

bool isBST_optimised2_helper(BinaryTreeNode<int> *root, int min, int max) {
    if (root == nullptr) {
        return true;
    }

    if (root -> data < min || root -> data > max) {
        return false;
    }
    bool isLeftBST = isBST_optimised2_helper(root -> left, min, root -> data - 1);
    return isLeftBST && isBST_optimised2_helper(root -> right, root -> data, max);
}

bool isBST_optimised2(BinaryTreeNode<int> *root) {
    if (root == nullptr) {
        return true;
    }
    return isBST_optimised2_helper(root, INT_MIN, INT_MAX);
}

BinaryTreeNode<int>* constructBSTFromSortedArray(const int* const arr, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = start + (end - start) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[mid]);
    root -> left = constructBSTFromSortedArray(arr, start, mid - 1);
    root -> right = constructBSTFromSortedArray(arr, mid + 1, end);

    return root;
}

BinaryTreeNode<int>* constructBSTFromSortedArray(const int* const arr, const int n) {
    if (n == 0) {
        return nullptr;
    }
    return constructBSTFromSortedArray(arr, 0, n - 1);
}

BinaryTreeNode<int>* constructBSTFromSortedArray(const std::vector<int> &v, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = start + (end - start) / 2;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(v[mid]);
    root -> left = constructBSTFromSortedArray(v, start, mid - 1);
    root -> right = constructBSTFromSortedArray(v, mid + 1, end);

    return root;
}

BinaryTreeNode<int>* constructBSTFromSortedArray(const std::vector<int> &v) {
    if (v.size() == 0) {
        return nullptr;
    }
    return constructBSTFromSortedArray(v, 0, v.size() - 1);
}

Node<int>* constructLinkedListFromBST(const BinaryTreeNode<int>* const root) {
    if (root == nullptr) {
        return nullptr;
    }

    Node<int> *head = new Node<int>(root -> data);

    Node<int> *leftHead = constructLinkedListFromBST(root -> left);
    if (leftHead != nullptr) {
        Node<int> *temp = leftHead;
        while (temp -> next != nullptr) {
            temp = temp -> next;
        }
        temp -> next = head;
    }

    Node<int> *rightHead = constructLinkedListFromBST(root -> right);

    head -> next = rightHead;

    return (leftHead == nullptr) ? head : leftHead;
}

std::pair<Node<int>*, Node<int>*> constructLinkedListFromBST_optimised_helper(const BinaryTreeNode<int>* const root) {
    if (root == nullptr) {
        return { nullptr, nullptr };
    }

    Node<int> *head = new Node<int>(root -> data);

    auto leftPair = constructLinkedListFromBST_optimised_helper(root -> left);

    if (leftPair.first != nullptr) {
        leftPair.second -> next = head;
    }

    auto rightPair = constructLinkedListFromBST_optimised_helper(root -> right);

    head -> next = rightPair.first;

    return { (leftPair.first != nullptr) ? leftPair.first : head, (rightPair.first != nullptr) ? rightPair.second : head };
}

Node<int>* constructLinkedListFromBST_optimised(const BinaryTreeNode<int>* const root) {
    if (root == nullptr) {
        return nullptr;
    }
    return constructLinkedListFromBST_optimised_helper(root).first;
}

std::vector<int>* getPath(const BinaryTreeNode<int>* const root, int data) {
    if (root == nullptr) {
        return nullptr;
    }
    std::vector<int> *path = nullptr;
    if (root -> data == data) {
        path = new std::vector<int>();
        path -> push_back(data);
        return path;
    }

    if (root -> data > data) {
        path = getPath(root -> left, data);
    }
    else {
        path = getPath(root -> right, data);
    }

    if (path != nullptr) {
        path -> push_back(root -> data);
    }

    return path;
}