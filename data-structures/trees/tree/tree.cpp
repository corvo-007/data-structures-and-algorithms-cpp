#include <iostream>
#include "tree.h"

using namespace std;

int main() {
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);

    cout << "number of nodes: " << numNodes(root);
}