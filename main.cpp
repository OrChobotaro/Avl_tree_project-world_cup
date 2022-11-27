#include "avlTree.h"
#include <iostream>
#include "LinkedList.cpp"
#include "EmptyTree.h"

#include "PlayerData.cpp"
#include "TeamData.cpp"



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
//
//    AvlTree<int> tree1;
//
//    // Tree RR
//    tree1.insert( 63);
//    tree1.insert( 20);
//    tree1.insert(100);
//    tree1.insert( 78);
//    tree1.insert( 34);
//    tree1.insert( 12);
//    tree1.insert( 5);
//    tree1.insert( 110);
//    tree1.insert( 103);
//    tree1.insert( 154);
//    tree1.insert( 160);
//    //printInorder(tree1.getRoot());
//    //tree1.balanceTree(tree1.find(160));
//
//
//    //Tree LR
//    AvlTree<int> tree2;
//
//    tree2.insert( 15);
//    tree2.insert( 10);
//    tree2.insert( 6);
//    tree2.insert( 20);
//    tree2.insert( 24);
//    tree2.insert( 13);
//    tree2.insert( 12);
//    tree2.insert( 7);
//    tree2.insert( 17);
//    tree2.insert( 4);
//    tree2.insert( 14);
//    tree2.insert( 11);
//    //printInorder(tree2.getRoot());
//    //tree2.balanceTree(tree2.find(11));
//
//
//    //Tree RL
//    AvlTree<int> treeRL;
//    treeRL.insert(11);
//    treeRL.insert(19);
//    treeRL.insert(25);
//    treeRL.insert(23);
//    treeRL.insert(8);
//    treeRL.insert(13);
//    treeRL.insert(29);
//    treeRL.insert(6);
//    treeRL.insert(12);
//    treeRL.insert(10);
//    treeRL.insert(17);
//    treeRL.insert(15);
//
//
//
//
//    //removeTree
//    AvlTree<int> removeTree;
//    removeTree.insert(5);
//    removeTree.insert(2);
//    removeTree.insert(8);
//    removeTree.insert(1);
//    removeTree.insert(6);
//    removeTree.insert(4);
//    removeTree.insert(3);
//
//
//
//    //trying to remove not existing node
////    StatusType res = removeTree.remove(20);
//
//
//    removeTree.remove(2);
//    removeTree.remove(5);
//    removeTree.remove(4);
//    removeTree.remove(3);
//    removeTree.remove(1);
//    removeTree.remove(6);
//    removeTree.remove(8);
//    removeTree.remove(8);
//

//    LinkedListNode<int> *endNode = new LinkedListNode<int>(0);
//    LinkedListNode<int> *startNode = new LinkedListNode<int>(0);
//
//    LinkedListNode<int> *node1 = new LinkedListNode<int>(4);
//    LinkedListNode<int> *node2 = new LinkedListNode<int>(6);
//    LinkedListNode<int> *node3 = new LinkedListNode<int>(7);
//    LinkedListNode<int> *node4 = new LinkedListNode<int>(5);
//    LinkedListNode<int> *node5 = new LinkedListNode<int>(3);
//
//    LinkedListNode<int> *node6 = new LinkedListNode<int>(4);
//    LinkedListNode<int> *node7 = new LinkedListNode<int>(6);
//    LinkedListNode<int> *node8 = new LinkedListNode<int>(7);
//    LinkedListNode<int> *node9 = new LinkedListNode<int>(5);
//    LinkedListNode<int> *node10 = new LinkedListNode<int>(3);



//    LinkedList<int> myList(0);
//    LinkedList<int> myList2(0);
//    LinkedList<int> myListNew(0);


//    myList.insertAfter(myList.getStart(), 2, &node1);
//    myList.insertAfter(node1, 5, &node2);
//    myList.insertAfter(node2, 8, &node3);

//    myList.insertAfter(node4, 38, &node5);





//    myList2.insertAfter(myList2.getStart(),3 , &node2);
//    myList2.insertAfter(node2, 4, &node3);
//    myList2.insertAfter(node3, 6, &node4);
//    myList2.insertAfter(node4, 7, &node5);
//    myList.insertAfter(node5, 10, &node6);
//    myList.insertAfter(node6, 38, &node7);
//    myList2.insertAfter(node7, 40, &node8);
//    myList.insertAfter(node8, 56, &node9);
//    myList.insertAfter(node9, 99, &node10);
////    myList.insertAfter(node7, 101, &node8);
////    myList.insertAfter(node8, 323, &node9);
//
//
//    std::cout << "myList " << myList.countNodes() -2 << std::endl;
//    std::cout << "myList2 " << myList2.countNodes() -2 << std::endl;
//    uniteLists( myList2.getStart(), myList.getStart(),startNode, endNode);
////    uniteLists(myList.getStart(), myList2.getStart(), startNode, endNode);
//
//    myListNew.setStart(startNode);
//
//    std::cout << "myListNew " << myListNew.countNodes() -2 << std::endl;

//    myList.deleteNode(node1);
//    myList.deleteNode(node2);
//    myList.deleteNode(node3);
//    myList.deleteNode(node4);
//    myList.deleteNode(node5);

    PlayerData player1(-1, 0, 0, 0, 0, true);
    LinkedList<PlayerData> myList3(player1);



    AvlTree<PlayerData> tree1 = buildEmptyTree(6, player1);

    TeamData team1(1, 4);
    //PlayerData player1(11, 22, 3, 4, 1, true);
    PlayerData player2(12, 22, 5, 1, 4, false);
    PlayerData player3(13, 23, 1, 3, 0, false);
    PlayerData player4(14, 22, 3, 4, 1, true);
    PlayerData player5(18, 22, 5, 1, 4, false);
    PlayerData player6(20, 23, 1, 3, 0, false);


    LinkedListNode<PlayerData> *node1 = new LinkedListNode<PlayerData>(player1);
    LinkedListNode<PlayerData> *node2 = new LinkedListNode<PlayerData>(player2);
    LinkedListNode<PlayerData> *node3 = new LinkedListNode<PlayerData>(player3);
    LinkedListNode<PlayerData> *node4 = new LinkedListNode<PlayerData>(player4);
    LinkedListNode<PlayerData> *node5 = new LinkedListNode<PlayerData>(player5);
    LinkedListNode<PlayerData> *node6 = new LinkedListNode<PlayerData>(player6);


    myList3.insertAfter(myList3.getStart(), player2, &node2);
    myList3.insertAfter(node2, player3, &node1);
    myList3.insertAfter(node1, player1, &node3);
    myList3.insertAfter(node3, player1, &node4);
    myList3.insertAfter(node4, player1, &node5);
    myList3.insertAfter(node5, player1, &node6);

    AvlTree<PlayerData> playersTree;
    playersTree.insert(player1);
    playersTree.insert(player3);
    playersTree.insert(player2);
    playersTree.insert(player4);
    playersTree.insert(player5);
    playersTree.insert(player6);

    updateEmptyTree(tree1, myList3);

    AvlTree<RankPlayerData> rankTree;



    return 0;
}