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
    delete numNodesToDelete;
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

    RankPlayerData data = (*listNode)->m_data;
    data.setPtrRankPlayerList(*listNode);
    data.setPtrRankPlayerTree(nullptr);
    treeNode->setKey(data);
    (*listNode)->m_data.setPtrRankPlayerTree(treeNode);
    (*listNode)->m_data.getPlayerPtr()->m_key.m_PtrRankTeamPlayerTree = treeNode;
    *listNode = (*listNode)->getNext();

    updateEmptyTreeAux(treeNode->getRight(), listNode);

}







void buildEmptyTreePlayerID(int requiredSize, const PlayerID& nullKey, AvlTree<PlayerID>& tree) {
    int height = calcEmptyTreeHeight(requiredSize);
    int numNodesCompleteTree = exponent(height+1) - 1;
    int* numNodesToDelete = new int(numNodesCompleteTree - requiredSize);
    buildCompleteEmptyTreePlayerID(requiredSize, nullKey, tree);
    deleteNodesEmptyTreeAuxPlayerID(tree.getRoot(), numNodesToDelete, height);
    delete numNodesToDelete;
}



void buildCompleteEmptyTreePlayerID(int requiredSize, const PlayerID& nullKey, AvlTree<PlayerID>& tree) {
    int height = calcEmptyTreeHeight(requiredSize);
    Node<PlayerID>* root = tree.newNode(nullKey);
    root->setHeight(height);
    tree.setRoot(root);
    if (height > 0) {
        auxEmptyTreePlayerID(tree, tree.getRoot(), height-1, nullKey);
    }
}


void auxEmptyTreePlayerID(AvlTree<PlayerID>& tree, Node<PlayerID>* node, int height, const PlayerID& nullKey) {
    if (node == nullptr) {
        return;
    }
    if (height == -1) {
        return;
    }
    Node<PlayerID>* rightNode = tree.newNode(nullKey);
    rightNode->setParent(node);
    rightNode->setHeight(height);
    node->setRight(rightNode);
    auxEmptyTreePlayerID(tree, rightNode, height-1, nullKey);

    Node<PlayerID>* leftNode = tree.newNode(nullKey);
    leftNode->setParent(node);
    leftNode->setHeight(height);
    node->setLeft(leftNode);
    auxEmptyTreePlayerID(tree, leftNode, height-1, nullKey);
}



void deleteNodesEmptyTreeAuxPlayerID(Node<PlayerID>* node, int* numNodesToDelete, int height) {
    if (node->isLeaf()) {
        return;
    }

    deleteNodesEmptyTreeAuxPlayerID(node->getRight(), numNodesToDelete, height);
    Node<PlayerID>* right = node->getRight();
    int distRightFromRoot = calcDistFromRootPlayerID(right);
    if (right->isLeaf() && *numNodesToDelete != 0 && distRightFromRoot == height) {
        removeLeafPlayerID(node->getRight());
        *numNodesToDelete -= 1;
    }
    deleteNodesEmptyTreeAuxPlayerID(node->getLeft(), numNodesToDelete, height);
    Node<PlayerID>* left = node->getLeft();
    int distLeftFromRoot = calcDistFromRootPlayerID(left);
    if (left->isLeaf() && *numNodesToDelete != 0 && distLeftFromRoot == height) {
        removeLeafPlayerID(node->getLeft());
        *numNodesToDelete -= 1;
        node->setHeight(0);
    }
    updateHeights(node);
}



void removeLeafPlayerID(Node<PlayerID>* node) {
    Node<PlayerID>* parent = node->getParent();
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



int calcDistFromRootPlayerID(Node<PlayerID>* node) {
    int counter = 0;
    Node<PlayerID>* temp = node;
    while (temp) {
        temp = temp->getParent();
        counter += 1;
    }
    return counter-1;
}




void updateEmptyTreePlayerID(AvlTree<PlayerID>& emptyTree, LinkedList<PlayerID>& list) {
    LinkedListNode<PlayerID>* temp = list.getStart()->getNext();
    Node<PlayerID>* root = emptyTree.getRoot();
    updateEmptyTreeAuxPlayerID(root, &temp);
}




void updateEmptyTreeAuxPlayerID(Node<PlayerID>* treeNode, LinkedListNode<PlayerID>** listNode) {
    if (!treeNode) {
        return;
    }
    updateEmptyTreeAuxPlayerID(treeNode->getLeft(), listNode);

    PlayerID data = (*listNode)->getData();
    treeNode->setKey(data);
    *listNode = (*listNode)->getNext();

    updateEmptyTreeAuxPlayerID(treeNode->getRight(), listNode);

}





std::shared_ptr<LinkedList<PlayerID>> AVLTreeToLinkedListPlayerID(AvlTree<PlayerID>* tree, const PlayerID& nullParam, int treeSize) {
    std::shared_ptr<LinkedList<PlayerID>> list(new LinkedList<PlayerID>);
    LinkedListNode<PlayerID>* nodeStart = new LinkedListNode<PlayerID>(nullParam);
    LinkedListNode<PlayerID>* nodeEnd = new LinkedListNode<PlayerID>(nullParam);
    nodeStart->setNext(nodeEnd);
    nodeEnd->setPrevious(nodeStart);
    list->setStart(nodeStart);
    list->setEnd(nodeEnd);
    LinkedListNode<PlayerID>* temp = list->getStart();
    while (treeSize > 0) {
        LinkedListNode<PlayerID>* newListNode = new LinkedListNode<PlayerID>(nullParam);
        temp->setNext(newListNode);
        newListNode->setPrevious(temp);
        temp = temp->getNext();
        --treeSize;
    }
    temp->setNext(nodeEnd);
    nodeEnd->setPrevious(temp);

    LinkedListNode<PlayerID>* firstListNode = (*list).getStart()->getNext();
    AVLTreeToLinkedListPlayerIDAux(tree->getRoot(), &firstListNode);
    return list;
}


void AVLTreeToLinkedListPlayerIDAux(Node<PlayerID>* nodeTree, LinkedListNode<PlayerID>** nodeList) {
    if (!nodeTree) {
        return;
    }
    AVLTreeToLinkedListPlayerIDAux(nodeTree->getLeft(), nodeList);
    (*nodeList)->m_data = nodeTree->getKey();
    (*nodeList) = (*nodeList)->getNext();
    AVLTreeToLinkedListPlayerIDAux(nodeTree->getRight(), nodeList);
}


/*
std::shared_ptr<LinkedList<ValidTeams>> AVLTreeToLinkedListValidTeams(AvlTree<ValidTeams>* tree, const ValidTeams& nullParam,
                                                                 int treeSize) {
    std::shared_ptr<LinkedList<ValidTeams>> list(new LinkedList<ValidTeams>);
    LinkedListNode<ValidTeams>* nodeStart = new LinkedListNode<ValidTeams>(nullParam);
    LinkedListNode<ValidTeams>* nodeEnd = new LinkedListNode<ValidTeams>(nullParam);
    nodeStart->setNext(nodeEnd);
    nodeEnd->setPrevious(nodeStart);
    list->setStart(nodeStart);
    list->setEnd(nodeEnd);
    LinkedListNode<ValidTeams>* temp = list->getStart();
    while (treeSize > 0) {
        LinkedListNode<ValidTeams>* newListNode = new LinkedListNode<ValidTeams>(nullParam);
        temp->setNext(newListNode);
        newListNode->setPrevious(temp);
        temp = temp->getNext();
        --treeSize;
    }
    temp->setNext(nodeEnd);
    nodeEnd->setPrevious(temp);

    LinkedListNode<ValidTeams>* firstListNode = (*list).getStart()->getNext();
    AVLTreeToLinkedListValidTeamsAux(tree->getRoot(), &firstListNode);
    return list;
}


void AVLTreeToLinkedListValidTeamsAux(Node<ValidTeams>* nodeTree, LinkedListNode<ValidTeams>** nodeList) {
    if (!nodeTree) {
        return;
    }
    AVLTreeToLinkedListValidTeamsAux(nodeTree->getLeft(), nodeList);
    (*nodeList)->m_data = nodeTree->getKey();
    (*nodeList) = (*nodeList)->getNext();
    AVLTreeToLinkedListValidTeamsAux(nodeTree->getRight(), nodeList);
}*/
