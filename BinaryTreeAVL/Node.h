#ifndef DATA_STRUCTURES_EX1_NODE_H
#define DATA_STRUCTURES_EX1_NODE_H


int max(int a, int b);


template<class T>
class Node {
public:
    Node() = delete;
    Node(const T& key);
    Node(const Node& otherNode) = delete;
    Node& operator=(const Node& otherNode) = delete;
    ~Node() = default;

    T getKey() const;
    Node<T>* getParent() const;
    Node<T>* getLeft() const;
    Node<T>* getRight() const;
    int getHeight() const;


    void setParent(Node<T>* newParent);
    void setRight(Node<T>* newRight);
    void setLeft(Node<T>* newLeft);
    void setHeight(int height);

//    bool isNextTo(Node<T> *node1);
//    void switchCloseNodes(Node<T>* node2);
    bool isLeftNew(Node<T>* parent);
    virtual void switchNodes(Node<T>* nodeToSwitchWith);
    virtual void reversSwitchNodes(const T& key);
    bool isLeaf();
    int calcHeight();

    void setKey(T newKey);

private:
    T m_key;
    Node<T>* m_right;
    Node<T>* m_left;
    Node<T>* m_parent;
    int m_height;

};





template<class T>
Node<T>::Node(const T& key):
    m_key(key), m_parent(nullptr), m_height(0), m_left(nullptr), m_right(nullptr){};


template<class T>
T Node<T>::getKey() const{
        return m_key;
}

template<class T>
void Node<T>::setParent(Node<T>* newParent){
    m_parent = newParent;
}

template<class T>
void Node<T>::setRight(Node<T>* newRight){
    m_right = newRight;
}


template<class T>
void Node<T>::setHeight(int height) {
     m_height = height;
}


template<class T>
void Node<T>::setLeft(Node<T>* newLeft){
    m_left = newLeft;
}


template<class T>
Node<T>* Node<T>::getParent() const{
    return m_parent;
}


template<class T>
Node<T>* Node<T>::getLeft() const{
    return m_left;
}


template<class T>
Node<T>* Node<T>::getRight() const{
    return m_right;
}

template<class T>
int Node<T>::getHeight() const {
    return m_height;
}



template<class T>
void Node<T>::setKey(T newKey){
    m_key = newKey;
}

template<class T>
bool Node<T>::isLeaf(){
    if (!this->getLeft() && !this->getRight()) {
        return true;
    }
    return false;
}

//template<class T>
//bool Node<T>::isNextTo(Node<T> *node1){
//    if(node1->getRight() == this || node1->getRight() == this || this->getRight() == node1 || this->getLeft() == node1){
//        return true;
//    }
//    return false;
//}

// copying nodeToSwitchWith to this
template<class T>
void Node<T>::switchNodes(Node<T>* nodeToSwitchWith){
    this->setKey(nodeToSwitchWith->getKey());
}

template<class T>
void Node<T>::reversSwitchNodes(const T& key){
    this->setKey(key);
}


template<class T>
int Node<T>::calcHeight(){
    Node<T>* node = this;
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
//
//template<class T>
//void Node<T>::switchCloseNodes(Node<T>* node2){
//    Node<T>* node1Left = this->getLeft();
//    Node<T>* node1Right = this->getRight();
//    Node<T>* node1Parent = this->getParent();
//    Node<T>* node2Left = node2->getLeft();
//    Node<T>* node2Right = node2->getRight();
//    Node<T>* node2Parent = node2->getParent();
//
//    Node<T>* node1;
//    // continue the opposite situation
//    //check if works!!
//    if(node2->getRight() == this || node2->getLeft() == this){
//        Node<T>* temp = node2;
//        node2 = this;
//        node1 = temp;
//
//
//    }
//    else{
//        node1 = this;
//    }
//
//
//
//    if(node1->getRight() == node2 || node1->getLeft() == node2){
//        bool isLeft;
//        bool isLeft2;
//
//        node2->setParent(node1Parent);
//        isLeft = node1->isLeftNew(node1Parent);
//         if(node1Parent){
//             if(isLeft){
//                 node1Parent->setLeft(node2);
//             }
//             else {
//                 node1Parent->setRight(node2);
//             }
//         }
//
//         isLeft2 = node1->isLeftNew(node2);
//         if(isLeft2){
//             node2->setLeft(node1);
//             node1->setParent((node2));
//             node2->setRight(node1Right);
//             if(node1Right){
//                 node1Right->setParent(node2);
//             }
//         }
//         else {
//             node2->setRight(node1);
//             node1->setParent(node2);
//             node2->setLeft(node1Left);
//             if(node1Left){
//                 node1Left->setParent(node2);
//             }
//         }
//
//        node1->setRight(node2Right);
//        node1->setLeft(node2Left);
//    }
//}


template<class T>
bool Node<T>::isLeftNew(Node<T>* parent){
    bool isLeft = false;
    if(parent->getLeft() == this){
        isLeft = true;
    }
    return isLeft;
}




#endif //DATA_STRUCTURES_EX1_NODE_H
