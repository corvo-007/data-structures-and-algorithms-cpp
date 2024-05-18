#include "BST.h"

int main() {
    BST bst;
    bst.insertRecursive(5);
    bst.insertRecursive(1);
    bst.insertRecursive(20);
    bst.insertRecursive(7);
    bst.insertRecursive(3);

    bst.printTreeRecursive();

    std::cout << bst.searchRecursive(3) << '\n';
    std::cout << bst.searchRecursive(7) << '\n';
    std::cout << bst.searchRecursive(5) << '\n';

    bst.removeRecursive(5);

    bst.printTreeRecursive();

    std::cout << bst.searchRecursive(5) << '\n';

    bst.insertRecursive(5);

    std::cout << bst.searchRecursive(5) << '\n';

    bst.printTreeRecursive();
}