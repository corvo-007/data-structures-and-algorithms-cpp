#include <iostream>
#include "binaryTree.h"

using namespace std;

int main() {
    BinaryTreeNode<int> *root = takeInputLevelWise();

    cout << "Number of nodes: " << numOfNodes(root) << '\n';

    printBinaryTreeLevelWise(root);
}