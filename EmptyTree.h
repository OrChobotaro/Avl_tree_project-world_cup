#ifndef DATA_STRUCTURES_EX1_EMPTYTREE_H
#define DATA_STRUCTURES_EX1_EMPTYTREE_H

#include "avlTree.h"
#include "LinkedList.h"
#include "RankPlayerData.h"

int calcEmptyTreeHeight(int requiredSize);
int exponent (int exponent);

void auxEmptyTree(AvlTree<RankPlayerData>& tree, Node<RankPlayerData>* node, int height, const RankPlayerData& nullKey);



void buildCompleteEmptyTree(int requiredSize, const RankPlayerData& nullKey, AvlTree<RankPlayerData>& tree);


void buildEmptyTree(int requiredSize, const RankPlayerData& nullKey, AvlTree<RankPlayerData>& tree);


void deleteNodesEmptyTreeAux(Node<RankPlayerData>* node, int* numNodesToDelete, int height);


void deleteNodesEmptyTreeAux(Node<RankPlayerData>* node, int* numNodesToDelete, int height);



void removeLeaf(Node<RankPlayerData>* node);


int calcDistFromRoot(Node<RankPlayerData>* node);


void updateEmptyTreeAux(Node<RankPlayerData>* treeNode, LinkedListNode<RankPlayerData>** listNode);

void updateEmptyTree(AvlTree<RankPlayerData>& emptyTree, LinkedList<RankPlayerData>& list);





#endif //DATA_STRUCTURES_EX1_EMPTYTREE_H
