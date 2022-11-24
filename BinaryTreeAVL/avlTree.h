#ifndef DATA_STRUCTURES_EX1_AvlTree_H
#define DATA_STRUCTURES_EX1_AvlTree_H

#include <iostream>
#include "Node.h"
#include "../wet1util.h"
#include <exception>
#include <assert.h>

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

    StatusType insert(Node<T>* temp, const T& key);
    StatusType insertToBinaryTree (Node<T>* temp, Node<T>* node, const T& key);

    void remove (const T& key);
    Node<T>* removeFromBinaryTree (Node<T>* node);
    void removeNodeAux(Node<T>* node);


    //todo: check if needed!
    Node<T>* getRoot() const;


    void balanceTree(Node<T>* lastAddedNode);
    int calcBalance(Node<T>* node);

    void updateHeights(Node<T>* node);
    Node<T>* find(const T& key) const;
    Node<T>* findFollowNode(Node<T>* node);
    void switchNodes(Node<T>* node1, Node<T>* node2);
    bool isLeft(Node<T>* parent, Node<T>* node);

    Node<T>* LL(Node<T>* unbalancedNode);
    Node<T>* RR(Node<T>* unbalancedNode);
    Node<T>* LR(Node<T>* unbalancedNode);
    Node<T>* RL(Node<T>* unbalancedNode);

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
StatusType AvlTree<T>::insert(Node<T>* temp, const T& key){
    try {
        Node<T>* node = newNode(key);
        StatusType result = insertToBinaryTree(temp, node, key);
        if (result == StatusType::FAILURE) {
            delete node;
            return StatusType::FAILURE;
        }
        updateHeights(node);
        balanceTree(node);
    }
    catch (std::bad_alloc& error) {
        return StatusType::ALLOCATION_ERROR;
    }
    return StatusType::SUCCESS;
}


template <class T>
StatusType AvlTree<T>::insertToBinaryTree (Node<T>* temp, Node<T>* node, const T& key) {
    if(temp == nullptr){
        if(m_root == nullptr){
            m_root = node;
            return StatusType::SUCCESS;
        }
        return StatusType::FAILURE;
    }

    Node<T>* tempParent;
    bool isLeft;

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
            return StatusType::FAILURE;
        }
    }

    node->setParent(tempParent);
    if(isLeft){
        tempParent->setLeft(node);
    }
    else{
        tempParent->setRight(node);
    }
    return StatusType::SUCCESS;
}



template<class T>
void AvlTree<T>::updateHeights(Node<T> *node) {
    assert(node);
    while(node) {
        if (isLeaf(node)) {
            node->setHeight(0);
            node = node->getParent();
            continue;
        }
        int maxHeight = calcHeight(node);
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
Node<T>* AvlTree<T>::balanceTree(Node<T>* lastAddedNode){
    assert(lastAddedNode);
    Node<T>* node = lastAddedNode;

    bool isBalanceUpdated = true; // todo: change name / check if needed
    while(node && isBalanceUpdated){
        if(isLeaf(node)){
            node = node->getParent();
            continue;
        }

        int currentNodeBalance = calcBalance(node);
        //assert(!(currentNodeBalance < (-2) || currentNodeBalance > 2));

        int leftBalance = calcBalance(node->getLeft());
        //assert(!(leftBalance < (-2) || leftBalance > 2));

        int rightBalance = calcBalance(node->getRight());
        //assert(!(rightBalance < (-2) || rightBalance > 2));

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
    return nullptr;
}



template<class T>
void AvlTree<T>::remove(const T &key) {
    Node<T>* node = find(key);
    Node<T>* parent = removeFromBinaryTree(node);
    Node<T>* nodeToBalance = parent;
    while(nodeToBalance){
        nodeToBalance = balanceTree(nodeToBalance);
    }
}



template<class T>
Node<T>* AvlTree<T>::removeFromBinaryTree(Node<T> *node) {
    Node<T>* parent = node->getParent();
    if (node->getLeft() && node->getRight()){
        Node<T>* followingNode = findFollowNode(node);
        parent = followingNode->getParent();
        switchNodes(node, followingNode);
    }
    removeNodeAux(node);
    if (parent) {
        updateHeights(parent);
    }
    return parent;
}





template<class T>
void AvlTree<T>::switchNodes(Node<T> *node1, Node<T> *node2) {
    if (m_root == node1) {
        m_root = node2;
    }
    else if (m_root == node2) {
        m_root = node1;
    }
    Node<T>* leftNode1 = node1->getLeft();
    Node<T>* rightNode1 = node1->getRight();
    Node<T>* parentNode1 = node1->getParent();
    bool isLeftNode1;
    if (parentNode1) {
        isLeftNode1 = isLeft(parentNode1, node1);
    }

    Node<T>* leftNode2 = node2->getLeft();
    Node<T>* rightNode2 = node2->getRight();
    Node<T>* parentNode2 = node2->getParent();
    bool isLeftNode2;
    if (parentNode2) {
        isLeftNode2 = isLeft(parentNode2, node2);
    }

    node2->setLeft(leftNode1);
    if (leftNode1) {
        leftNode1->setParent(node2);
    }
    node2->setRight(rightNode1);
    if (rightNode1) {
        rightNode1->setParent(node2);
    }
    node2->setParent(parentNode1);
    if (parentNode1) {
        if (isLeftNode1) {
            parentNode1->setLeft(node2);
        }
        else {
            parentNode1->setRight(node2);
        }
    }

    node1->setLeft(leftNode2);
    if (leftNode2) {
        leftNode2->setParent(node1);
    }
    node1->setRight(rightNode2);
    if (rightNode2) {
        rightNode2->setParent(node1);
    }
    node1->setParent(parentNode2);
    if (parentNode2) {
        if (isLeftNode2) {
            parentNode2->setLeft(node1);
        }
        else {
            parentNode2->setRight(node1);
        }
    }

    int heightNode2 = node2->getHeight();
    node2->setHeight(node1->getHeight());
    node1->setHeight(heightNode2);
}


// remove node when has one or less sons.
template<class T>
void AvlTree<T>::removeNodeAux(Node<T> *node) {
    Node<T>* parent = node->getParent(); //might be null!
    if (isLeaf(node)) {
        if (isLeft(parent, node)) {
            parent->setLeft(nullptr);
        }
        else {
            parent->setRight(nullptr);
        }
        delete node;
        return;
    }

    Node<T>* left = node->getLeft(); // might be null
    Node<T>* right = node->getRight(); // might be null
    if(parent){
        bool isRemoveNodeLeftSon = isLeft(parent, node);
        if (isRemoveNodeLeftSon) {
            if(left){
                parent->setLeft(left);
                left->setParent(parent);
            }
            else {
                parent->setLeft(right);
                right->setParent(parent);
            }
        }
        else {
            if(left){
                parent->setRight(left);
                left->setParent(parent);
            }
            else {
                parent->setRight(right);
                right->setParent(parent);
            }
        }
    }
    delete node;
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
Node<T>* AvlTree<T>::LL(Node<T>* unbalancedNode){

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
    return nodeA;
}

template<class T>
Node<T>* AvlTree<T>::RR(Node<T>* unbalancedNode){

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
    return nodeA;
}

template<class T>
Node<T>* AvlTree<T>::LR(Node<T>* unbalancedNode){
    Node<T>* nodeB = unbalancedNode->getLeft();
    RR(nodeB);
    return LL(unbalancedNode);
}

template<class T>
Node<T>* AvlTree<T>::RL(Node<T>* unbalancedNode){
    Node<T>* nodeB = unbalancedNode->getRight();
    LL(nodeB);
    return RR(unbalancedNode);
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
