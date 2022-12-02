//#include "avlTree.h"
//#include <iostream>
//#include "LinkedList.cpp"
//#include "EmptyTree.h"
//
//#include "PlayerData.cpp"
//#include "TeamData.cpp"
//
//
//
//void printInorder(Node<int>* node)
//{
//    if (node == nullptr)
//        return;
//
//    /* first recur on left child */
//    printInorder(node->getLeft());
//
//    /* then print the data of node */
//    std::cout << node->getKey() << " ";
//
//    /* now recur on right child */
//    printInorder(node->getRight());
//}
//
//
//
//
//
//
//
//
//
//
//
//int main(){
////
////    AvlTree<int> tree1;
////
////    // Tree RR
////    tree1.insert( 63);
////    tree1.insert( 20);
////    tree1.insert(100);
////    tree1.insert( 78);
////    tree1.insert( 34);
////    tree1.insert( 12);
////    tree1.insert( 5);
////    tree1.insert( 110);
////    tree1.insert( 103);
////    tree1.insert( 154);
////    tree1.insert( 160);
////    //printInorder(tree1.getRoot());
////    //tree1.balanceTree(tree1.find(160));
////
////
////    //Tree LR
////    AvlTree<int> tree2;
////
////    tree2.insert( 15);
////    tree2.insert( 10);
////    tree2.insert( 6);
////    tree2.insert( 20);
////    tree2.insert( 24);
////    tree2.insert( 13);
////    tree2.insert( 12);
////    tree2.insert( 7);
////    tree2.insert( 17);
////    tree2.insert( 4);
////    tree2.insert( 14);
////    tree2.insert( 11);
////    //printInorder(tree2.getRoot());
////    //tree2.balanceTree(tree2.find(11));
////
////
////    //Tree RL
////    AvlTree<int> treeRL;
////    treeRL.insert(11);
////    treeRL.insert(19);
////    treeRL.insert(25);
////    treeRL.insert(23);
////    treeRL.insert(8);
////    treeRL.insert(13);
////    treeRL.insert(29);
////    treeRL.insert(6);
////    treeRL.insert(12);
////    treeRL.insert(10);
////    treeRL.insert(17);
////    treeRL.insert(15);
////
////
////
////
////    //removeTree
////    AvlTree<int> removeTree;
////    removeTree.insert(5);
////    removeTree.insert(2);
////    removeTree.insert(8);
////    removeTree.insert(1);
////    removeTree.insert(6);
////    removeTree.insert(4);
////    removeTree.insert(3);
////
////
////
////    //trying to remove not existing node
//////    StatusType res = removeTree.remove(20);
////
////
////    removeTree.remove(2);
////    removeTree.remove(5);
////    removeTree.remove(4);
////    removeTree.remove(3);
////    removeTree.remove(1);
////    removeTree.remove(6);
////    removeTree.remove(8);
////    removeTree.remove(8);
////
//
////    LinkedListNode<int> *endNode = new LinkedListNode<int>(0);
////    LinkedListNode<int> *startNode = new LinkedListNode<int>(0);
////
////    LinkedListNode<int> *node1 = new LinkedListNode<int>(4);
////    LinkedListNode<int> *node2 = new LinkedListNode<int>(6);
////    LinkedListNode<int> *node3 = new LinkedListNode<int>(7);
////    LinkedListNode<int> *node4 = new LinkedListNode<int>(5);
////    LinkedListNode<int> *node5 = new LinkedListNode<int>(3);
////
////    LinkedListNode<int> *node6 = new LinkedListNode<int>(4);
////    LinkedListNode<int> *node7 = new LinkedListNode<int>(6);
////    LinkedListNode<int> *node8 = new LinkedListNode<int>(7);
////    LinkedListNode<int> *node9 = new LinkedListNode<int>(5);
////    LinkedListNode<int> *node10 = new LinkedListNode<int>(3);
//
//
//
////    LinkedList<int> myList(0);
////    LinkedList<int> myList2(0);
////    LinkedList<int> myListNew(0);
//
//
////    myList.insertAfter(myList.getStart(), 2, &node1);
////    myList.insertAfter(node1, 5, &node2);
////    myList.insertAfter(node2, 8, &node3);
//
////    myList.insertAfter(node4, 38, &node5);
//
//
//
//
//
////    myList2.insertAfter(myList2.getStart(),3 , &node2);
////    myList2.insertAfter(node2, 4, &node3);
////    myList2.insertAfter(node3, 6, &node4);
////    myList2.insertAfter(node4, 7, &node5);
////    myList.insertAfter(node5, 10, &node6);
////    myList.insertAfter(node6, 38, &node7);
////    myList2.insertAfter(node7, 40, &node8);
////    myList.insertAfter(node8, 56, &node9);
////    myList.insertAfter(node9, 99, &node10);
//////    myList.insertAfter(node7, 101, &node8);
//////    myList.insertAfter(node8, 323, &node9);
////
////
////    std::cout << "myList " << myList.countNodes() -2 << std::endl;
////    std::cout << "myList2 " << myList2.countNodes() -2 << std::endl;
////    uniteLists( myList2.getStart(), myList.getStart(),startNode, endNode);
//////    uniteLists(myList.getStart(), myList2.getStart(), startNode, endNode);
////
////    myListNew.setStart(startNode);
////
////    std::cout << "myListNew " << myListNew.countNodes() -2 << std::endl;
//
////    myList.deleteNode(node1);
////    myList.deleteNode(node2);
////    myList.deleteNode(node3);
////    myList.deleteNode(node4);
////    myList.deleteNode(node5);
//
//    PlayerData player1(-1, 0, 0, 0, 0, true);
//    LinkedList<PlayerData> myList3(player1);
//
//
//
//    AvlTree<PlayerData> tree1 = buildEmptyTree(6, player1);
//
//    TeamData team1(1, 4);
//    //PlayerData player1(11, 22, 3, 4, 1, true);
//    PlayerData player2(12, 22, 5, 1, 4, false);
//    PlayerData player3(13, 23, 1, 3, 0, false);
//    PlayerData player4(14, 22, 3, 4, 1, true);
//    PlayerData player5(18, 22, 5, 1, 4, false);
//    PlayerData player6(20, 23, 1, 3, 0, false);
//
//
//    LinkedListNode<PlayerData> *node1 = new LinkedListNode<PlayerData>(player1);
//    LinkedListNode<PlayerData> *node2 = new LinkedListNode<PlayerData>(player2);
//    LinkedListNode<PlayerData> *node3 = new LinkedListNode<PlayerData>(player3);
//    LinkedListNode<PlayerData> *node4 = new LinkedListNode<PlayerData>(player4);
//    LinkedListNode<PlayerData> *node5 = new LinkedListNode<PlayerData>(player5);
//    LinkedListNode<PlayerData> *node6 = new LinkedListNode<PlayerData>(player6);
//
//
//    myList3.insertAfter(myList3.getStart(), player2, &node2);
//    myList3.insertAfter(node2, player3, &node1);
//    myList3.insertAfter(node1, player1, &node3);
//    myList3.insertAfter(node3, player1, &node4);
//    myList3.insertAfter(node4, player1, &node5);
//    myList3.insertAfter(node5, player1, &node6);
//
//    AvlTree<PlayerData> playersTree;
//    playersTree.insert(player1);
//    playersTree.insert(player3);
//    playersTree.insert(player2);
//    playersTree.insert(player4);
//    playersTree.insert(player5);
//    playersTree.insert(player6);
//
//    updateEmptyTree(tree1, myList3);
//
//    AvlTree<RankPlayerData> rankTree;
//
//
//
//    return 0;
//}


#include "worldcup23a1.h"

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


/*
    RankPlayerData player0(-1, 0, 0, 0);
    RankPlayerData player1(1, 0, 0, 0);
    RankPlayerData player2(2, 0, 0, 0);
    RankPlayerData player3(3, 0, 0, 0);
    RankPlayerData player4(4, 0, 0, 0);
    RankPlayerData player5(5, 0, 0, 0);
    RankPlayerData player6(6, 0, 0, 0);
    RankPlayerData player7(7, 0, 0, 0);


    LinkedList<RankPlayerData> myList3(player0);



    AvlTree<RankPlayerData> tree1 = buildEmptyTree(6, player0);

    TeamData team1(1, 4);

    //LinkedListNode<RankPlayerData> *node1 = new LinkedListNode<PlayerData>(player1);
    LinkedListNode<RankPlayerData> *node2 = new LinkedListNode<RankPlayerData>(player2);
    LinkedListNode<RankPlayerData> *node3 = new LinkedListNode<RankPlayerData>(player3);
    LinkedListNode<RankPlayerData> *node4 = new LinkedListNode<RankPlayerData>(player4);
    LinkedListNode<RankPlayerData> *node5 = new LinkedListNode<RankPlayerData>(player5);
    LinkedListNode<RankPlayerData> *node6 = new LinkedListNode<RankPlayerData>(player6);
    LinkedListNode<RankPlayerData> *node7 = new LinkedListNode<RankPlayerData>(player7);


    myList3.insertAfter(myList3.getStart(), player2, &node2);
    myList3.insertAfter(node2, player3, &node3);
    myList3.insertAfter(node3, player4, &node7);
    myList3.insertAfter(node7, player5, &node4);
    myList3.insertAfter(node4, player6, &node5);
    myList3.insertAfter(node5, player7, &node6);

    AvlTree<RankPlayerData> playersTree;
    playersTree.insert(player1);
    playersTree.insert(player3);
    playersTree.insert(player2);
    playersTree.insert(player4);
    playersTree.insert(player5);
    playersTree.insert(player6);

    updateEmptyTree(tree1, myList3);

    AvlTree<RankPlayerData> rankTree;
*/

bool isWorking;

int main(){
    world_cup_t wc1;

    wc1.add_team(21, 78);

    StatusType s1 = wc1.add_player(2,21,2,3,3,false);
    wc1.add_player(3,21,9,3,8,false);
    wc1.add_player(4, 21, 2, 1, 3, true);
    wc1.add_player(5, 21, 5, 4, 3, false);
    wc1.add_player(8, 21, 2, 60, 3, true);
    wc1.add_player(1, 21, 30, 3, 3, true);
    wc1.add_player(10, 21, 5, 3, 17, false);
    wc1.add_player(200, 21, 5, 3, 17, false);
    wc1.add_player(201, 21, 5, 3, 17, false);
    wc1.add_player(202, 21, 5, 3, 17, false);
    wc1.add_player(203, 21, 5, 3, 17, false);
    wc1.add_player(204, 21, 5, 3, 17, false);


    wc1.add_team(22, 45);

    wc1.add_player(6,22,2,400,17,false);
    wc1.add_player(7,22,2,5,3,false);
    wc1.add_player(20, 22, 2, 3, 3, true);
    wc1.add_player(9, 22, 2, 5, 5, true);
    wc1.add_player(30, 22, 2, 3, 50, true);
    wc1.add_player(106, 22, 2, 3, 3, true);
    wc1.add_player(100, 22, 2, 100, 3, true);
    wc1.add_player(101, 22, 2, 3, 3, true);
    wc1.add_player(102, 22, 2, 3, 3, true);
    wc1.add_player(103, 22, 2, 3, 3, true);
    wc1.add_player(104, 22, 2, 300, 3, true);
    wc1.add_player(105, 22, 2, 3, 3, true);

//    output_t<int> closestTO5 = wc1.get_closest_player(5, 21);

    wc1.add_team(24, 78);

    wc1.remove_team(24);

    wc1.play_match(21, 22);
    wc1.get_num_played_games(3);
    output_t<int> team22points = wc1.get_team_points(22);
    output_t<int> team21points = wc1.get_team_points(21);

    output_t<int> topScorer = wc1.get_top_scorer(-3);
    output_t<int> topScorerTeam21 = wc1.get_top_scorer(21);

    output_t<int> numPlayersTeam21 = wc1.get_all_players_count(21);
    output_t<int> numPlayersTeam22 = wc1.get_all_players_count(22);
    output_t<int> numPlayers = wc1.get_all_players_count(-5);

    int *output = new int[12];


    wc1.get_all_players(22, output);

    //RankPlayerData rankPlayer(3, 4, 2, findPlayer(3, wc1.m_playersAVLTree.get()->getRoot()));
    //insertNode(rankPlayer, wc1.m_allPlayersRankTree.get(), wc1.m_allPlayersRankLinkedList.get());

    for(int i = 0; i< 12; i++){
        std::cout << output[i] << std::endl;
    }

    return 0;
}