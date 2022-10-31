#include <iostream>
#include "binarySearchTree.h"

using namespace std;

int main() {
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(4);
    root -> left = new BinaryTreeNode<int>(2);
    root -> right = new BinaryTreeNode<int>(6);
    root -> left -> left = new BinaryTreeNode<int>(1);
    root -> left -> right = new BinaryTreeNode<int>(3);
    root -> right -> left = new BinaryTreeNode<int>(5);
    root -> right -> right = new BinaryTreeNode<int>(7);

    cout << searchInBST(root, 3) << '\n';
    cout << searchInBST(root, 5) << '\n';
    cout << searchInBST(root, 0) << '\n';
    cout << searchInBST(root, 8) << '\n';
}