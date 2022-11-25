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




#include <iostream>
#include <random>






int main(){

/*    AvlTree<int> tree1;

    // Tree RR
    tree1.insert(tree1.getRoot(), 63);
    tree1.insert(tree1.getRoot(), 20);
    tree1.insert(tree1.getRoot(), 100);
    tree1.insert(tree1.getRoot(), 78);
    tree1.insert(tree1.getRoot(), 34);
    tree1.insert(tree1.getRoot(), 12);
    tree1.insert(tree1.getRoot(), 5);
    tree1.insert(tree1.getRoot(), 110);
    tree1.insert(tree1.getRoot(), 103);
    tree1.insert(tree1.getRoot(), 154);
    tree1.insert(tree1.getRoot(), 160);
    //printInorder(tree1.getRoot());
    //tree1.balanceTree(tree1.find(160));


    //Tree LR
    AvlTree<int> tree2;

    tree2.insert(tree2.getRoot(), 15);
    tree2.insert(tree2.getRoot(), 10);
    tree2.insert(tree2.getRoot(), 6);
    tree2.insert(tree2.getRoot(), 20);
    tree2.insert(tree2.getRoot(), 24);
    tree2.insert(tree2.getRoot(), 13);
    tree2.insert(tree2.getRoot(), 12);
    tree2.insert(tree2.getRoot(), 7);
    tree2.insert(tree2.getRoot(), 17);
    tree2.insert(tree2.getRoot(), 4);
    tree2.insert(tree2.getRoot(), 14);
    tree2.insert(tree2.getRoot(), 11);
    //printInorder(tree2.getRoot());
    //tree2.balanceTree(tree2.find(11));*/

    //Tree RL
    AvlTree<int> treeRL;
    treeRL.insert(11);
    treeRL.insert(19);
    treeRL.insert(25);
    treeRL.insert(23);
    treeRL.insert(8);
    treeRL.insert(13);
    treeRL.insert(29);
    treeRL.insert(6);
    treeRL.insert(12);
    treeRL.insert(10);
    treeRL.insert(17);
    treeRL.insert(15);


    treeRL.switchNodes(nullptr, treeRL.find(4));
    //treeRL.balanceTree(treeRL.find(15));

//    Node<int>* nodeTest;
//    nodeTest = treeRL.findFollowNode(treeRL.find(13));
//
//    treeRL.switchNodes(treeRL.find(13), treeRL.find(8));


    //removeTree
/*    AvlTree<int> removeTree;
    removeTree.insert(removeTree.getRoot(), 5);
    removeTree.insert(removeTree.getRoot(), 2);
    removeTree.insert(removeTree.getRoot(), 8);
    removeTree.insert(removeTree.getRoot(), 1);
    removeTree.insert(removeTree.getRoot(), 6);
    removeTree.insert(removeTree.getRoot(), 4);
    removeTree.insert(removeTree.getRoot(), 3);
    removeTree.insert(removeTree.getRoot(), 10);
    removeTree.insert(removeTree.getRoot(), 7);
    removeTree.insert(removeTree.getRoot(), 9);
    removeTree.insert(removeTree.getRoot(), 11);
    removeTree.insert(removeTree.getRoot(), 12);

    removeTree.remove(1);*/

    return 0;
}