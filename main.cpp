#include "BinaryTreeAVL/avlTree.h"

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