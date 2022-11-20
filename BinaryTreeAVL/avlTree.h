#ifndef DATA_STRUCTURES_EX1_AvlTree_H
#define DATA_STRUCTURES_EX1_AvlTree_H

#include <iostream>

#include "Node.h"

template<class T>
class AvlTree{
public:
    AvlTree() = default;
    AvlTree(const AvlTree<T>& otherTree) = delete;
    AvlTree<T>& operator=(const AvlTree<T>& otherTree) = delete;
    ~AvlTree() = default;

    void insert(Node<T>* temp, const T& key);
    void updateHeights(Node<T>* node);


    /////////////////////////////////////toDelete
    Node<T>* getRoot() const {
        return m_root;
    }


private:
    Node<T>* m_root;
    Node<T>* newNode(const T& key); //todo: לבדוק אם צריך לקבל גם אב

};



int max(int a, int b) {
    if (a >= b) {
        return a;
    }
    return b;
}



template<class T>
Node<T>* AvlTree<T>::newNode(const T& key) {
    return new Node<T>(key);
}




template<class T>
void AvlTree<T>::insert(Node<T>* temp, const T& key){
    
    if(temp == nullptr){
        if(m_root != nullptr){
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

    bool isHeightUpdated = 1;
    while(isHeightUpdated && node) {
        if (!node->getLeft() && !node->getRight()) {
            node = node->getParent();
            continue;
        }
        int heightRight = 0;
        int heightLeft = 0;
        if (node->getRight()) {
            heightRight = (node->getRight())->getHeight();
        }
        if (node->getLeft()) {
            heightLeft = (node->getLeft())->getHeight();
        }
        int maxHeight = max(heightLeft, heightRight);
        if ((maxHeight+1) == node->getHeight()) {
            isHeightUpdated = 0;
            continue;
        }
        node->setHeight(maxHeight+1);
        node = node->getParent();
    }
}





#endif //DATA_STRUCTURES_EX1_AvlTree_H
