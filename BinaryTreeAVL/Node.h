

template<class T>
class Node {
public:
    Node() = delete;
    Node(T key);
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



private:
    T m_key;
    Node<T>* m_right;
    Node<T>* m_left;
    Node<T>* m_parent;
    int m_height;
};



template<class T>
Node<T>::Node(T key):
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


#ifndef DATA_STRUCTURES_EX1_NODE_H
#define DATA_STRUCTURES_EX1_NODE_H

#endif //DATA_STRUCTURES_EX1_NODE_H
