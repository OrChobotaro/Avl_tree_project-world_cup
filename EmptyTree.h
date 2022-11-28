#ifndef DATA_STRUCTURES_EX1_EMPTYTREE_H
#define DATA_STRUCTURES_EX1_EMPTYTREE_H

#include "avlTree.h"
#include "LinkedList.h"
#include "RankPlayerData.h"


int calcEmptyTreeHeight(int requiredSize);
int exponent (int exponent);


void auxEmptyTree(AvlTree<RankPlayerData> tree, Node<RankPlayerData>* node, int height, const RankPlayerData& nullKey);



AvlTree<RankPlayerData> buildCompleteEmptyTree(int requiredSize, const RankPlayerData& nullKey);


AvlTree<RankPlayerData> buildEmptyTree(int requiredSize, const RankPlayerData& nullKey);


void deleteNodesEmptyTreeAux(Node<RankPlayerData>* node, int* numNodesToDelete, int height);


void deleteNodesEmptyTreeAux(Node<RankPlayerData>* node, int* numNodesToDelete, int height);



void removeLeaf(Node<RankPlayerData>* node);


int calcDistFromRoot(Node<RankPlayerData>* node);


void updateEmptyTreeAux(Node<RankPlayerData>* treeNode, LinkedListNode<RankPlayerData>** listNode);

AvlTree<RankPlayerData> updateEmptyTree(const AvlTree<RankPlayerData>& emptyTree, LinkedList<RankPlayerData>& list);






/*int calcEmptyTreeHeight(int requiredSize);
int exponent (int exponent);

template<class T>
void auxEmptyTree(AvlTree<T> tree, Node<T>* node, int height, const T& nullKey);


template<class T>
AvlTree<T> buildCompleteEmptyTree(int requiredSize, const T& nullKey);

template<class T>
AvlTree<T> buildEmptyTree(int requiredSize, const T& nullKey);

template<class T>
void deleteNodesEmptyTreeAux(Node<T>* node, int* numNodesToDelete, int height);

template<class T>
void deleteNodesEmptyTreeAux(Node<T>* node, int* numNodesToDelete, int height);


template<class T>
void removeLeaf(Node<T>* node);

template<class T>
int calcDistFromRoot(Node<T>* node);



template<class T>
AvlTree<T> buildEmptyTree(int requiredSize, const T& nullKey) {
    int height = calcEmptyTreeHeight(requiredSize);
    int numNodesCompleteTree = exponent(height+1) - 1;
    int* numNodesToDelete = new int(numNodesCompleteTree - requiredSize);
    AvlTree<T> tree = buildCompleteEmptyTree(requiredSize, nullKey);
    deleteNodesEmptyTreeAux(tree.getRoot(), numNodesToDelete, height);
    return tree;
}




template<class T>
AvlTree<T> buildCompleteEmptyTree(int requiredSize, const T& nullKey) {
    int height = calcEmptyTreeHeight(requiredSize);
    AvlTree<T> tree;
    Node<T>* root = tree.newNode(nullKey);
    root->setHeight(height);
    tree.setRoot(root);
    if (height > 0) {
        auxEmptyTree(tree, tree.getRoot(), height-1, nullKey);
    }
    return tree;

}


template<class T>
void auxEmptyTree(AvlTree<T> tree, Node<T>* node, int height, const T& nullKey) {
    if (node == nullptr) {
        return;
    }
    if (height == -1) {
        return;
    }
    Node<T>* rightNode = tree.newNode(nullKey);
    rightNode->setParent(node);
    rightNode->setHeight(height);
    node->setRight(rightNode);
    auxEmptyTree(tree, rightNode, height-1, nullKey);

    Node<T>* leftNode = tree.newNode(nullKey);
    leftNode->setParent(node);
    leftNode->setHeight(height);
    node->setLeft(leftNode);
    auxEmptyTree(tree, leftNode, height-1, nullKey);

}






template<class T>
void deleteNodesEmptyTreeAux(Node<T>* node, int* numNodesToDelete, int height) {
    if (node->isLeaf()) {
        return;
    }

    deleteNodesEmptyTreeAux(node->getRight(), numNodesToDelete, height);
    Node<T>* right = node->getRight();
    int distRightFromRoot = calcDistFromRoot(right);
    if (right->isLeaf() && *numNodesToDelete != 0 && distRightFromRoot == height) {
        removeLeaf(node->getRight());
        *numNodesToDelete -= 1;
    }
    deleteNodesEmptyTreeAux(node->getLeft(), numNodesToDelete, height);
    Node<T>* left = node->getLeft();
    int distLeftFromRoot = calcDistFromRoot(left);
    if (left->isLeaf() && *numNodesToDelete != 0 && distLeftFromRoot == height) {
        removeLeaf(node->getLeft());
        *numNodesToDelete -= 1;
        node->setHeight(0);
    }
    updateHeights(node);
}


template<class T>
void removeLeaf(Node<T>* node) {
    Node<T>* parent = node->getParent();
    if (parent) {
        if (node->isLeftNew(parent)) {
            parent->setLeft(nullptr);
        }
        else {
            parent->setRight(nullptr);
        }
        node->setParent(nullptr);
        delete node;
        return;
    }
}


template<class T>
int calcDistFromRoot(Node<T>* node) {
    int counter = 0;
    Node<T>* temp = node;
    while (temp) {
        temp = temp->getParent();
        counter += 1;
    }
    return counter-1;
}



template<class T>
AvlTree<T> updateEmptyTree(AvlTree<T> emptyTree, LinkedList<T> list) {
    LinkedListNode<T>* temp = (list.getStart())->getNext();
    Node<T>* root = emptyTree.getRoot();
    updateEmptyTreeAux(root, &temp);
    return emptyTree;
}



template<class T>
void updateEmptyTreeAux(Node<T>* treeNode, LinkedListNode<T>** listNode) {
    if (!treeNode) {
        return;
    }
    updateEmptyTreeAux(treeNode->getLeft(), listNode);

    T data = (*listNode)->getData();
    treeNode->setKey(data);
    *listNode = (*listNode)->getNext();

    updateEmptyTreeAux(treeNode->getRight(), listNode);

}*/


#endif //DATA_STRUCTURES_EX1_EMPTYTREE_H
