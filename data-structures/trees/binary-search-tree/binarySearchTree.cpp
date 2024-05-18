#include <iostream>
#include "binarySearchTree.h"

int main() {
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(4);
    root -> left = new BinaryTreeNode<int>(2);
    root -> right = new BinaryTreeNode<int>(6);
    root -> left -> left = new BinaryTreeNode<int>(1);
    root -> left -> right = new BinaryTreeNode<int>(3);
    root -> right -> left = new BinaryTreeNode<int>(5);
    root -> right -> right = new BinaryTreeNode<int>(7);

    std::cout << searchInBST(root, 3) << '\n';
    std::cout << searchInBST(root, 5) << '\n';
    std::cout << searchInBST(root, 0) << '\n';
    std::cout << searchInBST(root, 8) << '\n';

    printInRange(root, 1, 2);
    std::cout << '\n';

    std::cout << isBST(root) << '\n';


    Node<int> *head = constructLinkedListFromBST_optimised(root);

    while (head != nullptr) {
        std::cout << head -> data << "->";
        head = head -> next;
    }
    std::cout << '\n';

    std::vector<int> *path = getPath(root, 3);

    auto it = path -> begin();

    while (it != path -> end()) {
        std::cout << *it << ' ';
        ++it;
    }
    std::cout << '\n';

    delete root;
    delete head;
    delete path;

}