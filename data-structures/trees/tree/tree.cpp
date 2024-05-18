#include <iostream>
#include "tree.h"

int main() {
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);

    std::cout << "number of nodes: " << numNodes(root) << '\n';
    std::cout << "height of nodes: " << height(root) << '\n';
}