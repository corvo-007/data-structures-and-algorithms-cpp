#include <iostream>
#include "tree.h"

using namespace std;

int main() {
    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *node1 = new TreeNode<int>(2);
    TreeNode<int> *node2 = new TreeNode<int>(3);
    TreeNode<int> *node3 = new TreeNode<int>(4);
    TreeNode<int> *node4 = new TreeNode<int>(5);
    TreeNode<int> *node5 = new TreeNode<int>(6);
    
    root -> children.push_back(node1);
    root -> children.push_back(node2);
    node2 -> children.push_back(node5);
    root -> children.push_back(node3);
    root -> children.push_back(node4);

    printTreeRecursive(root);
}