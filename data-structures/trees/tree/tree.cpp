#include <iostream>
#include "tree.h"

using namespace std;

int main() {
    TreeNode<int> *root = takeInputLevelWise();

    printTreeRecursive(root);
}