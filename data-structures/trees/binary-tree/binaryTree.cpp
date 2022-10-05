#include <iostream>
#include "binaryTree.h"

using namespace std;

int main() {
    BinaryTreeNode<int> *root = takeInputLevelWise();

    printBinaryTreeLevelWise(root);
}