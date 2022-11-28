#include "EmptyTree.h"


int calcEmptyTreeHeight(int requiredSize) {
    int height = 0;
    int temp = 2;
    while (requiredSize > temp) {
        temp *=2;
        height+=1;
    }
    return height;
}


int exponent (int exponent) {
    int result = 1;
    while(exponent > 0) {
        result *= 2;
        --exponent;
    }
    return result;
}


void buildEmptyTree(int requiredSize, const RankPlayerData& nullKey, AvlTree<RankPlayerData>& tree) {
    int height = calcEmptyTreeHeight(requiredSize);
    int numNodesCompleteTree = exponent(height+1) - 1;
    int* numNodesToDelete = new int(numNodesCompleteTree - requiredSize);
    buildCompleteEmptyTree(requiredSize, nullKey, tree);
    deleteNodesEmptyTreeAux(tree.getRoot(), numNodesToDelete, height);
}





void buildCompleteEmptyTree(int requiredSize, const RankPlayerData& nullKey,
                                               AvlTree<RankPlayerData>& tree) {
    int height = calcEmptyTreeHeight(requiredSize);
    Node<RankPlayerData>* root = tree.newNode(nullKey);
    root->setHeight(height);
    tree.setRoot(root);
    if (height > 0) {
        auxEmptyTree(tree, tree.getRoot(), height-1, nullKey);
    }
}



void auxEmptyTree(AvlTree<RankPlayerData>& tree, Node<RankPlayerData>* node, int height, const RankPlayerData&
nullKey) {
    if (node == nullptr) {
        return;
    }
    if (height == -1) {
        return;
    }
    Node<RankPlayerData>* rightNode = tree.newNode(nullKey);
    rightNode->setParent(node);
    rightNode->setHeight(height);
    node->setRight(rightNode);
    auxEmptyTree(tree, rightNode, height-1, nullKey);

    Node<RankPlayerData>* leftNode = tree.newNode(nullKey);
    leftNode->setParent(node);
    leftNode->setHeight(height);
    node->setLeft(leftNode);
    auxEmptyTree(tree, leftNode, height-1, nullKey);

}







void deleteNodesEmptyTreeAux(Node<RankPlayerData>* node, int* numNodesToDelete, int height) {
    if (node->isLeaf()) {
        return;
    }

    deleteNodesEmptyTreeAux(node->getRight(), numNodesToDelete, height);
    Node<RankPlayerData>* right = node->getRight();
    int distRightFromRoot = calcDistFromRoot(right);
    if (right->isLeaf() && *numNodesToDelete != 0 && distRightFromRoot == height) {
        removeLeaf(node->getRight());
        *numNodesToDelete -= 1;
    }
    deleteNodesEmptyTreeAux(node->getLeft(), numNodesToDelete, height);
    Node<RankPlayerData>* left = node->getLeft();
    int distLeftFromRoot = calcDistFromRoot(left);
    if (left->isLeaf() && *numNodesToDelete != 0 && distLeftFromRoot == height) {
        removeLeaf(node->getLeft());
        *numNodesToDelete -= 1;
        node->setHeight(0);
    }
    updateHeights(node);
}



void removeLeaf(Node<RankPlayerData>* node) {
    Node<RankPlayerData>* parent = node->getParent();
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



int calcDistFromRoot(Node<RankPlayerData>* node) {
    int counter = 0;
    Node<RankPlayerData>* temp = node;
    while (temp) {
        temp = temp->getParent();
        counter += 1;
    }
    return counter-1;
}




void updateEmptyTree(AvlTree<RankPlayerData>& emptyTree, LinkedList<RankPlayerData>& list) {
    LinkedListNode<RankPlayerData>* temp = list.getStart()->getNext();
    Node<RankPlayerData>* root = emptyTree.getRoot();
    updateEmptyTreeAux(root, &temp);
}




void updateEmptyTreeAux(Node<RankPlayerData>* treeNode, LinkedListNode<RankPlayerData>** listNode) {
    if (!treeNode) {
        return;
    }
    updateEmptyTreeAux(treeNode->getLeft(), listNode);

    RankPlayerData data = (*listNode)->getData();
    data.setPtrRankPlayerList(*listNode);
    data.setPtrRankPlayerTree(nullptr);
    treeNode->setKey(data);
    (*listNode)->m_data.setPtrRankPlayerTree(treeNode);
    *listNode = (*listNode)->getNext();

    updateEmptyTreeAux(treeNode->getRight(), listNode);

}
