#include "BinaryTreeAVL/avlTree.h"

void printInorder(Node<int>* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->getLeft());

    /* then print the data of node */
    std::cout << node->getKey() << " ";

    /* now recur on right child */
    printInorder(node->getRight());
}




int main(){

    AvlTree<int> tree1;
    tree1.insert(nullptr, 89);
    tree1.insert(tree1.getRoot(), 22);
    tree1.insert(tree1.getRoot(), 54);
    tree1.insert(tree1.getRoot(), 103);
    tree1.insert(tree1.getRoot(), 76);
    tree1.insert(tree1.getRoot(), 100);

    return 0;
}