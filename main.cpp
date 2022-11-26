#include "BinaryTreeAVL/avlTree.h"
#include <iostream>
#include "LinkedList/LinkedListNode.h"
#include "LinkedList/LinkedList.h"
#include "BinaryTreeAVL/EmptyTree.h"


void printInorder(Node<int>* node)
{
    if (node == nullptr)
        return;

    /* first recur on left child */
    printInorder(node->getLeft());

    /* then print the data of node */
    std::cout << node->getKey() << " ";

    /* now recur on right child */
    printInorder(node->getRight());
}











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


/*

    //removeTree
    AvlTree<int> removeTree;
    removeTree.insert(5);
    removeTree.insert(2);
    removeTree.insert(8);
    removeTree.insert(1);
    removeTree.insert(6);
    removeTree.insert(4);
    removeTree.insert(3);



    //trying to remove not existing node
//    StatusType res = removeTree.remove(20);


    removeTree.remove(2);
    removeTree.remove(5);
    removeTree.remove(4);
    removeTree.remove(3);
    removeTree.remove(1);
    removeTree.remove(6);
    removeTree.remove(8);
    removeTree.remove(8);


    LinkedListNode<int> *endNode = new LinkedListNode<int>(0);
    LinkedListNode<int> *startNode = new LinkedListNode<int>(0);

    LinkedListNode<int> *node1 = new LinkedListNode<int>(4);
    LinkedListNode<int> *node2 = new LinkedListNode<int>(6);
    LinkedListNode<int> *node3 = new LinkedListNode<int>(7);
    LinkedListNode<int> *node4 = new LinkedListNode<int>(5);
    LinkedListNode<int> *node5 = new LinkedListNode<int>(3);

    LinkedListNode<int> *node6 = new LinkedListNode<int>(4);
    LinkedListNode<int> *node7 = new LinkedListNode<int>(6);
    LinkedListNode<int> *node8 = new LinkedListNode<int>(7);
    LinkedListNode<int> *node9 = new LinkedListNode<int>(5);
    LinkedListNode<int> *node10 = new LinkedListNode<int>(3);


    LinkedList<int> myList(0);
    LinkedList<int> myList2(0);
    LinkedList<int> myListNew(0);


    myList.insertAfter(myList.getStart(), 2, &node1);
    myList.insertAfter(node1, 5, &node2);
    myList.insertAfter(node2, 8, &node3);
    myList.insertAfter(node3, 10, &node4);
    myList.insertAfter(node4, 38, &node5);
    myList.insertAfter(node5, 56, &node6);
    myList.insertAfter(node6, 99, &node7);
    myList.insertAfter(node7, 101, &node8);
    myList.insertAfter(node8, 323, &node9);


    /*

    myList2.insertAfter(myList2.getStart(),3 , &node6);
    myList2.insertAfter(node6, 4, &node7);
    myList2.insertAfter(node7, 6, &node8);
    myList2.insertAfter(node8, 7, &node9);
    myList2.insertAfter(node9, 40, &node10);


    uniteLists(myList.getStart(), myList2.getStart(), startNode, endNode);
//    uniteLists(myList.getStart(), myList2.getStart(), startNode, endNode);




//    myList.deleteNode(node1);
//    myList.deleteNode(node2);
//    myList.deleteNode(node3);
//    myList.deleteNode(node4);
//    myList.deleteNode(node5);


    AvlTree<int> tree = buildEmptyTree(9, 0);
    updateEmptyTree(tree, myList);


    return 0;
}