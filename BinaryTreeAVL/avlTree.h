#ifndef DATA_STRUCTURES_EX1_AvlTree_H
#define DATA_STRUCTURES_EX1_AvlTree_H

#include <iostream>
#include "Node.h"

template<class T>
bool isLeaf(Node<T>* node);

int max(int a, int b);

template<class T>
int calcHeight(Node<T>* node);



template<class T>
class AvlTree{
public:
    AvlTree();
    AvlTree(const AvlTree<T>& otherTree) = delete;
    AvlTree<T>& operator=(const AvlTree<T>& otherTree) = delete;
    ~AvlTree() = default;

    void insert(Node<T>* temp, const T& key);
    void updateHeights(Node<T>* node);
    Node<T>* find(const T& key) const;

    //todo: check if needed!
    Node<T>* getRoot() const;


    void balanceTree(Node<T>* lastAddedNode);
    int calcBalance(Node<T>* node);

    void LL(Node<T>* unbalancedNode);
    void RR(Node<T>* unbalancedNode);
    void LR(Node<T>* unbalancedNode);
    void RL(Node<T>* unbalancedNode);

private:
    Node<T>* m_root;
    Node<T>* newNode(const T& key); //todo: לבדוק אם צריך לקבל גם אב

};



template<class T>
AvlTree<T>::AvlTree(): m_root(nullptr){};


template<class T>
Node<T>* AvlTree<T>::newNode(const T& key) {
    return new Node<T>(key);
}

template<class T>
Node<T>* AvlTree<T>::getRoot() const {
    return m_root;
}


template<class T>
void AvlTree<T>::insert(Node<T>* temp, const T& key){
    
    if(temp == nullptr){
        if(m_root == nullptr){
            //todo: ERROR -  check if avl tree is not empty
        } 
        m_root = newNode(key);
        return;
    }

    //todo: ERROR if we need to check the key is valid
    
    Node<T>* tempParent;
    bool isLeft = false;

    while(temp != nullptr){
        tempParent = temp;
        if(key < temp->getKey()){
            temp = temp->getLeft();
            isLeft = true;
        }
        else if(key > temp->getKey()){
            temp = temp->getRight();
            isLeft = false;
        }
        else{
            //todo: ERROR?
        }
    }

    Node<T>* node = newNode(key);
    node->setParent(tempParent);
    if(isLeft){
        tempParent->setLeft(node);
    }
    else{
        tempParent->setRight(node);
    }

    updateHeights(node);
}

template<class T>
void AvlTree<T>::updateHeights(Node<T> *node) {
    if (node == nullptr) {
        //todo - ERROR
    }
//    bool isHeightUpdated = 1;
    while(/*isHeightUpdated &&*/ node) {
        if (isLeaf(node)) {
            node->setHeight(0);
            node = node->getParent();
            continue;
        }
        int maxHeight = calcHeight(node);
//        if ((maxHeight+1) == node->getHeight()) {
//            isHeightUpdated = 0;
//
//            continue;
//        }
        node->setHeight(maxHeight+1);
        node = node->getParent();
    }
}

template<class T>
bool isLeaf(Node<T>* node){
    if (!node->getLeft() && !node->getRight()) {
        return true;
    }
    return false;
}

template<class T>
int calcHeight(Node<T>* node){
    int heightRight = 0;
    int heightLeft = 0;
    if (node->getRight()) {
        heightRight = (node->getRight())->getHeight();
    }
    if (node->getLeft()) {
        heightLeft = (node->getLeft())->getHeight();
    }
    return max(heightLeft, heightRight);
}

template<class T>
void AvlTree<T>::balanceTree(Node<T>* lastAddedNode){
    Node<T>* node = lastAddedNode;

    bool isBalanceUpdated = true; // todo: change name / check if needed
    while(node && isBalanceUpdated){
        if(isLeaf(node)){
            node = node->getParent();
            continue;
        }

        int currentNodeBalance = calcBalance(node);
        //todo: error if balance >2 or <-2

        int leftBalance = calcBalance(node->getLeft());
        int rightBalance = calcBalance(node->getRight());

        if(currentNodeBalance == 2){
            if(leftBalance == 0 || leftBalance == 1){
                LL(node);
            }
            else if(leftBalance == -1){
                LR(node);
            }
            isBalanceUpdated = false;
        }
        else if(currentNodeBalance == -2){
            if(rightBalance == 0 || rightBalance == -1){
                RR(node);
            }
            else if(rightBalance == 1){
                RL(node);
            }
            isBalanceUpdated = false;
        }
        node = node->getParent();
    }
}


template<class T>
int AvlTree<T>::calcBalance(Node<T>* node){
    if(!node){
        return 0;
    }

    int heightLeft = -1;
    int heightRight = -1;

    if(node->getRight()){
        heightRight = (node->getRight())->getHeight();
    }
    if(node->getLeft()){
        heightLeft = (node->getLeft())->getHeight();
    }

    return (heightLeft - heightRight);
}


template<class T>
void AvlTree<T>::LL(Node<T>* unbalancedNode){

    Node<T>* nodeA = unbalancedNode->getLeft();
    Node<T>* nodeARight = nodeA->getRight(); //might be null
    Node<T>* parentOfUnbalancedNode = unbalancedNode->getParent(); //might be null

    //Ar from right of A to left of B
    unbalancedNode->setLeft(nodeARight);
    if(nodeARight){
        nodeARight->setParent(unbalancedNode);
    }

    // A parent of B an B left of A
    unbalancedNode->setParent(nodeA);
    nodeA->setRight(unbalancedNode);

    // B parent is A parent
    nodeA->setParent(parentOfUnbalancedNode);
    if(parentOfUnbalancedNode){
        if(parentOfUnbalancedNode->getLeft() == unbalancedNode){
            parentOfUnbalancedNode->setLeft(nodeA);
        }
        else {
            parentOfUnbalancedNode->setRight(nodeA);
        }
    } else {
        m_root = nodeA;
    }


    updateHeights(unbalancedNode);
}

template<class T>
void AvlTree<T>::RR(Node<T>* unbalancedNode){

    // A right of B
    Node<T>* nodeA = unbalancedNode->getRight();
    // AL
    Node<T>* nodeALeft = nodeA->getLeft(); //might be null
    Node<T>* parentOfUnbalancedNode = unbalancedNode->getParent(); //might be null

    // AL -> Right B
    unbalancedNode->setRight(nodeALeft);
    nodeALeft->setParent(unbalancedNode);

    // A -> Parent B
    unbalancedNode->setParent(nodeA);
    nodeA->setLeft(unbalancedNode);

    if(parentOfUnbalancedNode){
        if(parentOfUnbalancedNode->getLeft() == unbalancedNode){
            parentOfUnbalancedNode->setLeft(nodeA);
        }
        else {
            parentOfUnbalancedNode->setRight(nodeA);
        }
    } else {
        m_root = nodeA;
    }

    nodeA->setParent(parentOfUnbalancedNode);


    updateHeights(unbalancedNode);

}

template<class T>
void AvlTree<T>::LR(Node<T>* unbalancedNode){
    Node<T>* nodeB = unbalancedNode->getLeft();
    RR(nodeB);
    LL(unbalancedNode);
}

template<class T>
void AvlTree<T>::RL(Node<T>* unbalancedNode){
    Node<T>* nodeB = unbalancedNode->getRight();
    LL(nodeB);
    RR(unbalancedNode);
}

template<class T>
Node<T>* AvlTree<T>::find(const T& key) const {
    Node<T>* temp = m_root;
    while (temp != nullptr) {
        if (key < temp->getKey()) {
            temp = temp->getLeft();
        }
        else if (key > temp->getKey()) {
            temp = temp->getRight();
        }
        else {
            return temp;
        }
    }
    //todo: Throw error NodeNotFound
    return nullptr;
}


int max(int a, int b) {
    if (a >= b) {
        return a;
    }
    return b;
}



#endif //DATA_STRUCTURES_EX1_AvlTree_H
