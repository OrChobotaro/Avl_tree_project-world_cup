#include "BinaryTreeAVL/avlTree.h"

int main(){

    AvlTree<int> tree1;

    Node<int> *node = new Node<int>(3);
    tree1.insert(node, 2);

    return 0;
}