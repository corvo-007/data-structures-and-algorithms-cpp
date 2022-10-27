#include <iostream>
#include "binaryTree.h"

using namespace std;

int main() {
    BinaryTreeNode<int> *root = takeInputLevelWise();

    cout << "Number of nodes: " << numOfNodes(root) << '\n';

    cout << "node is present: " << findNode(root, 5) << '\n';

    cout << "Height of the binary tree: " << height(root) << '\n';

    printBinaryTreeLevelWise(root);

    printPreOrder(root);
    cout << '\n';

    printPostOrder(root);
    cout << '\n';

    cout << "Sum of binary tree: " << sumOfBinaryTree(root) << '\n';
}