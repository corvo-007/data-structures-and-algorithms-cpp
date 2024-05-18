#include <iostream>
#include "binaryTree.h"

int main() {
    BinaryTreeNode<int> *root = takeInputLevelWise();

    std::cout << "Number of nodes: " << numOfNodes(root) << '\n';

    std::cout << "node is present: " << findNode(root, 5) << '\n';

    std::cout << "Height of the binary tree: " << height(root) << '\n';

    printBinaryTreeLevelWise(root);

    printPreOrder(root);
    std::cout << '\n';

    printPostOrder(root);
    std::cout << '\n';

    std::cout << "Sum of binary tree: " << sumOfBinaryTree(root) << '\n';
}