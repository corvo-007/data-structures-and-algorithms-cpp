#include <iostream>
#include "../../../common/binaryTreeNode.h"

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