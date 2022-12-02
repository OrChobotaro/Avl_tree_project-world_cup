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




void buildEmptyTreePlayerID(int requiredSize, const PlayerID& nullKey, AvlTree<PlayerID>& tree);

void buildCompleteEmptyTreePlayerID(int requiredSize, const PlayerID& nullKey, AvlTree<PlayerID>& tree);

void auxEmptyTreePlayerID(AvlTree<PlayerID>& tree, Node<PlayerID>* node, int height, const PlayerID& nullKey);

void deleteNodesEmptyTreeAuxPlayerID(Node<PlayerID>* node, int* numNodesToDelete, int height);

void removeLeafPlayerID(Node<PlayerID>* node);

int calcDistFromRootPlayerID(Node<PlayerID>* node);

void updateEmptyTreePlayerID(AvlTree<PlayerID>& emptyTree, LinkedList<PlayerID>& list);

void updateEmptyTreeAuxPlayerID(Node<PlayerID>* treeNode, LinkedListNode<PlayerID>** listNode);





std::shared_ptr<LinkedList<PlayerID>> AVLTreeToLinkedListPlayerID(AvlTree<PlayerID>* tree, const PlayerID& nullParam, int treeSize);
void AVLTreeToLinkedListPlayerIDAux(Node<PlayerID>* nodeTree, LinkedListNode<PlayerID>** nodeList);

void AVLTreeToLinkedListValidTeamsAux(Node<ValidTeams>* nodeTree, LinkedListNode<ValidTeams>** nodeList);
std::shared_ptr<LinkedList<ValidTeams>> AVLTreeToLinkedListValidTeams(AvlTree<ValidTeams>* tree, const ValidTeams& nullParam,
                                                                      int treeSize);



#endif //DATA_STRUCTURES_EX1_EMPTYTREE_H
