#ifndef DATA_STRUCTURES_EX1_AvlTree_H
#define DATA_STRUCTURES_EX1_AvlTree_H

#include <iostream>
#include "Node.h"
#include "../wet1util.h"
#include <exception>
#include <assert.h>





template<class T>
void updateHeights(Node<T>* node);


template<class T>
class AvlTree{
public:
    AvlTree();
    AvlTree(const AvlTree<T>& otherTree) = default;
    AvlTree<T>& operator=(const AvlTree<T>& otherTree) = delete;
    ~AvlTree() = default;

    StatusType insert(const T& key);
    StatusType insertToBinaryTree (Node<T>* node, const T& key);

    StatusType remove (const T& key);
    Node<T>* removeFromBinaryTree (Node<T>* node);
    void removeNodeAux(Node<T>* node);


    //todo: check if needed!
    Node<T>* getRoot() const;

    void setRoot(Node<T>* node);


    Node<T>* balanceTree(Node<T>* lastAddedNode);
    int calcBalance(Node<T>* node);


    Node<T>* find(const T& key) const;
    Node<T>* findFollowNode(Node<T>* node);
    //void switchNodes(Node<T>* node1, Node<T>* node2);
    //
//    bool isLeft(Node<T>* parent, Node<T>* node);

    Node<T>* LL(Node<T>* unbalancedNode);
    Node<T>* RR(Node<T>* unbalancedNode);
    Node<T>* LR(Node<T>* unbalancedNode);
    Node<T>* RL(Node<T>* unbalancedNode);


    Node<T>* newNode(const T& key); //todo: לבדוק אם צריך לקבל גם אב



private:
    Node<T>* m_root;


};



template<class T>
AvlTree<T>::AvlTree(): m_root(nullptr){}


template<class T>
Node<T>* AvlTree<T>::newNode(const T& key) {
    return new Node<T>(key);
}

template<class T>
Node<T>* AvlTree<T>::getRoot() const {
    return m_root;
}


template<class T>
StatusType AvlTree<T>::insert(const T& key){
/*    if (!key) {
        return StatusType::FAILURE;
    }*/
    try {
        Node<T>* node = newNode(key);
        StatusType result = insertToBinaryTree(node, key);
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
StatusType AvlTree<T>::insertToBinaryTree (Node<T>* node, const T& key) {
    if(m_root == nullptr){
        m_root = node;
        return StatusType::SUCCESS;
    }

    Node<T>* temp = m_root;
    Node<T>* tempParent = nullptr;
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
void updateHeights(Node<T> *node) {
    assert(node);
    while(node) {
        if (node->isLeaf()) {
            node->setHeight(0);
            node = node->getParent();
            continue;
        }
        int maxHeight = node->calcHeight();
        node->setHeight(maxHeight+1);
        node = node->getParent();
    }
}





template<class T>
Node<T>* AvlTree<T>::balanceTree(Node<T>* lastAddedNode){
    assert(lastAddedNode);
    Node<T>* node = lastAddedNode;

    while(node){
        if(node->isLeaf()){
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
                return LL(node);
            }
            else if(leftBalance == -1){
                return LR(node);
            }
        }
        else if(currentNodeBalance == -2){
            if(rightBalance == 0 || rightBalance == -1){
                return RR(node);
            }
            else if(rightBalance == 1){
                return RL(node);
            }
        }
        node = node->getParent();
    }
    return nullptr;
}



template<class T>
StatusType AvlTree<T>::remove(const T &key) {
    Node<T>* node = find(key);
    if(!node){
        return StatusType::FAILURE;
    }
    try{
        Node<T>* parent = removeFromBinaryTree(node);
        Node<T>* nodeToBalance = parent;
        while(nodeToBalance){
            nodeToBalance = balanceTree(nodeToBalance);
        }

    }
    catch (std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
    return StatusType::SUCCESS;
}



template<class T>
Node<T>* AvlTree<T>::removeFromBinaryTree(Node<T> *node) {
    Node<T>* followingNode = nullptr;
    Node<T>* parent = node->getParent();
    T nodeToDeleteKey = node->getKey();
    try{
        if (node->getLeft() && node->getRight()){
            followingNode = findFollowNode(node);
            parent = followingNode->getParent();
            node->switchNodes(followingNode);
            removeNodeAux(followingNode);
        }
        else{
            removeNodeAux(node);
        }

    }
    catch (std::bad_alloc& e) {
        node->reversSwitchNodes(nodeToDeleteKey);
        throw std::bad_alloc();
    }
    if (parent) {
        updateHeights(parent);
    }
    return parent;
}



//
//
//template<class T>
//void AvlTree<T>::switchNodes(Node<T> *node1, Node<T> *node2) {
//
//    if(node1->isNextTo(node2)){
//        node1->switchCloseNodes(node2);
//        return;
//    }
//
//    if (m_root == node1) {
//        m_root = node2;
//    }
//    else if (m_root == node2) {
//        m_root = node1;
//    }
//    Node<T>* leftNode1 = node1->getLeft();
//    Node<T>* rightNode1 = node1->getRight();
//    Node<T>* parentNode1 = node1->getParent();
//    bool isLeftNode1;
//    if (parentNode1) {
//        isLeftNode1 = isLeft(parentNode1, node1);
//    }
//
//    Node<T>* leftNode2 = node2->getLeft();
//    Node<T>* rightNode2 = node2->getRight();
//    Node<T>* parentNode2 = node2->getParent();
//    bool isLeftNode2;
//    if (parentNode2) {
//        isLeftNode2 = isLeft(parentNode2, node2);
//    }
//
//    node2->setLeft(leftNode1);
//    if (leftNode1) {
//        leftNode1->setParent(node2);
//    }
//    node2->setRight(rightNode1);
//    if (rightNode1) {
//        rightNode1->setParent(node2);
//    }
//    node2->setParent(parentNode1);
//    if (parentNode1) {
//        if (isLeftNode1) {
//            parentNode1->setLeft(node2);
//        }
//        else {
//            parentNode1->setRight(node2);
//        }
//    }
//
//    node1->setLeft(leftNode2);
//    if (leftNode2) {
//        leftNode2->setParent(node1);
//    }
//    node1->setRight(rightNode2);
//    if (rightNode2) {
//        rightNode2->setParent(node1);
//    }
//    node1->setParent(parentNode2);
//    if (parentNode2) {
//        if (isLeftNode2) {
//            parentNode2->setLeft(node1);
//        }
//        else {
//            parentNode2->setRight(node1);
//        }
//    }
//
//    int heightNode2 = node2->getHeight();
//    node2->setHeight(node1->getHeight());
//    node1->setHeight(heightNode2);
//}



// remove node when has one or less sons.
template<class T>
void AvlTree<T>::removeNodeAux(Node<T> *node) {
    Node<T>* parent = node->getParent(); //might be null!
    if (node->isLeaf() && parent) {
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

    Node<T>* left = node->getLeft(); // might be null
    Node<T>* right = node->getRight(); // might be null
    bool isRemoveNodeLeftSon;
    if(parent){
        isRemoveNodeLeftSon = node->isLeftNew(parent);
        if (isRemoveNodeLeftSon) {
            if(left){
                parent->setLeft(left);
                left->setParent(parent);
                node->setLeft(nullptr);
            }
            else {
                parent->setRight(right);
                right->setParent(parent);
                node->setRight(nullptr);
            }
        }
        else {
            if(left){
                parent->setRight(left);
                left->setParent(parent);
                node->setLeft(nullptr);
            }
            else {
                parent->setRight(right);
                right->setParent(parent);
                node->setRight(nullptr);
            }
        }
    }


//    bool isLeft = node->isLeftNew(parent);
//    if(isLeft){
//        parent->setLeft(nullptr);
//    }
//    else{
//        parent->setRight(nullptr);
//    }
    // if parent not exist: means the tree has two or less nodes: root and leaf.
    else{
        if(left){
            m_root = left;
            left->setParent(nullptr);
        }
        else if(right){
            m_root = right;
            right->setParent(nullptr);
        }
        else {
            // Node with no parent and no sons == root;
            m_root = nullptr;
        }
    }
    node->setParent(nullptr);


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
    if(nodeALeft){

        nodeALeft->setParent(unbalancedNode);
    }

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

template<class T>
Node<T>* AvlTree<T>::findFollowNode(Node<T>* node){
    Node<T>* temp = node;
    Node<T>* followingNode = temp;
    temp = temp->getRight();
    while(temp){
        followingNode = temp;
        temp = temp->getLeft();
    }
    return followingNode;
}

//template<class T>
//bool AvlTree<T>::isLeft(Node<T>* parent, Node<T>* node){
//    bool isLeft = false;
//    if(parent->getLeft() == node){
//        isLeft = true;
//    }
//    return isLeft;
//}


template<class T>
void AvlTree<T>::setRoot(Node<T> *node) {
    m_root = node;
}




#endif //DATA_STRUCTURES_EX1_AvlTree_H
