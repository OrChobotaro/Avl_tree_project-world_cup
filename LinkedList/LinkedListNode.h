#ifndef DATA_STRUCTURES_EX1_LINKEDLISTNODE_H
#define DATA_STRUCTURES_EX1_LINKEDLISTNODE_H


template<class T>
class LinkedListNode{
public:

    LinkedListNode() = delete;
    LinkedListNode(T data);
    LinkedListNode(const LinkedListNode& otherNode) = delete;
    //LinkedListNode& operator=(const LinkedListNode& otherNode);
    ~LinkedListNode() = default;

    LinkedListNode<T>* getNext() const;
    LinkedListNode<T>* getPrevious() const;
    LinkedListNode<T>* getData() const;

    void setNext(LinkedListNode<T>* next);
    void setPrevious(LinkedListNode<T>* previous);



private:
    T m_data;
    LinkedListNode<T>* m_next;
    LinkedListNode<T>* m_previous;
    void setData(T newData);
};


template<class T>
LinkedListNode<T>::LinkedListNode(T data): m_data(data), m_next(nullptr), m_previous(nullptr){}

//template<class T>
//LinkedListNode<T>& LinkedListNode<T>::operator=(const LinkedListNode& otherNode){
//    this->setPrevious(otherNode.getPrevious());
//    this->setNext(otherNode.getNext());
//    this->setData(otherNode.getData());
//}


template<class T>
LinkedListNode<T>* LinkedListNode<T>::getNext() const{
    return m_next;
}

template<class T>
LinkedListNode<T>* LinkedListNode<T>::getPrevious() const {
    return m_previous;
}

template<class T>
LinkedListNode<T>* LinkedListNode<T>::getData() const{
    return m_data;
}

template<class T>
void LinkedListNode<T>::setNext(LinkedListNode<T>* next){
    m_next = next;
}

template<class T>
void LinkedListNode<T>::setPrevious(LinkedListNode<T>* previous){
    m_previous = previous;
}

template<class T>
void LinkedListNode<T>::setData(T newData){
    m_data = newData;
}

#endif //DATA_STRUCTURES_EX1_LINKEDLISTNODE_H
