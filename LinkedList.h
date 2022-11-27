#ifndef DATA_STRUCTURES_EX1_LINKEDLIST_H
#define DATA_STRUCTURES_EX1_LINKEDLIST_H

#include "LinkedListNode.h"
#include "wet1util.h"


template<class T>
class LinkedList{
public:

    LinkedList() = delete;

    LinkedList(const T& nullParam);

    LinkedList(const LinkedList<T>& otherList) = default;
    LinkedList<T>& operator=(const LinkedList& otherList) = delete;

    LinkedListNode<T>* getStart();
    LinkedListNode<T>* getEnd();

    void setStart(LinkedListNode<T>* node);
    void setEnd(LinkedListNode<T>* node);

    LinkedListNode<T>* newLinkedListNode(const T& data);

    StatusType insertBefore(LinkedListNode<T>* node, const T& data, LinkedListNode<T>** ptrSave);
    StatusType insertAfter(LinkedListNode<T>* node, const T& data, LinkedListNode<T>** ptrSave);
    StatusType deleteNode(LinkedListNode<T>* nodeToRemove);

//    StatusType uniteListsNew(LinkedList<T>* List2, LinkedList<T>* newList);
    void clearList(LinkedListNode<T>* start);

    int countNodes();
    ~LinkedList();


private:
    LinkedListNode<T>* m_start;
    LinkedListNode<T>* m_end;

};

template<class T>
int LinkedList<T>::countNodes(){
    LinkedListNode<T>* node = this->m_start;
    int counter = 0;
    while(node){
        counter++;
        node = node->getNext();
    }
    return counter;
}

template<class T>
StatusType uniteLists(LinkedListNode<T>* startList1, LinkedListNode<T>* startList2,
                          LinkedListNode<T>* newStart, LinkedListNode<T>* newEnd);


//todo:: check if works
template<class T>
LinkedList<T>::LinkedList(const T& nullParam) {
    m_start = newLinkedListNode(nullParam);
    m_end = newLinkedListNode(nullParam);

    m_start->setNext(m_end);
    m_end->setPrevious(m_start);
}



template<class T>
LinkedList<T>::~LinkedList() {
    clearList(m_start);
}

template<class T>
LinkedListNode<T>* LinkedList<T>::getStart() {
    return m_start;
}

template<class T>
LinkedListNode<T>* LinkedList<T>::getEnd() {
    return m_end;
}

template<class T>
void LinkedList<T>::setStart(LinkedListNode<T>* node) {
    m_start = node;
}

template<class T>
void LinkedList<T>::setEnd(LinkedListNode<T>* node) {
    m_end = node;
}


template<class T>
LinkedListNode<T>* LinkedList<T>::newLinkedListNode(const T& data){
    return new LinkedListNode<T>(data);
}


template<class T>
void LinkedList<T>::clearList(LinkedListNode<T>* start){
    LinkedListNode<T>* temp;
    while (start){
        temp = start;
        start = start->getNext();
        delete temp;
    }
    delete start;
}

template<class T>
StatusType LinkedList<T>::insertBefore(LinkedListNode<T>* node, const T& data, LinkedListNode<T>** ptrSave) {
    assert(node);
    assert(data);
    assert(ptrSave);

    LinkedListNode<T>* previousNode = node->getPrevious();
    LinkedListNode<T>* newNodeMiddle;

    try{
        newNodeMiddle = newLinkedListNode(data);
    }
    catch (std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }

    previousNode->setNext(newNodeMiddle);
    newNodeMiddle->setPrevious(previousNode);
    newNodeMiddle->setNext(node);
    node->setPrevious(newNodeMiddle);

    *ptrSave = newNodeMiddle;

    return StatusType::SUCCESS;
}

template<class T>
StatusType LinkedList<T>::insertAfter(LinkedListNode<T> *node, const T& data, LinkedListNode<T>** ptrSave) {

    //assert(node);
    //assert(data);
    //assert(ptrSave);


    LinkedListNode<T>* nextNode = node->getNext();
    LinkedListNode<T>* newNodeMiddle;
    try{
         newNodeMiddle = newLinkedListNode(data);

    } catch (std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }

    node->setNext(newNodeMiddle);
    newNodeMiddle->setPrevious(node);
    newNodeMiddle->setNext(nextNode);
    nextNode->setPrevious(newNodeMiddle);

    *ptrSave = newNodeMiddle;

    return StatusType::SUCCESS;
}

template<class T>
StatusType LinkedList<T>::deleteNode(LinkedListNode<T>* nodeToRemove){
    assert(nodeToRemove);

    if(!nodeToRemove){
        // check what to return if fails
        return StatusType::FAILURE;
    }

    LinkedListNode<T>* prevNode = nodeToRemove->getPrevious();
    LinkedListNode<T>* nextNode = nodeToRemove->getNext();


    prevNode->setNext(nextNode);
    nextNode->setPrevious(prevNode);

    nodeToRemove->setNext(nullptr);
    nodeToRemove->setPrevious(nullptr);

    delete nodeToRemove;

    return StatusType::SUCCESS;

}


template<class T>
StatusType uniteLists(LinkedListNode<T>* startList1, LinkedListNode<T>* startList2,
                      LinkedListNode<T>* newStart, LinkedListNode<T>* newEnd){
    assert(startList1);
    assert(startList2);
    assert(newStart);
    assert(newEnd);

    if(!newStart || !newEnd){
        return StatusType::FAILURE;
    }


    LinkedListNode<T>* currNode1 = startList1->getNext();
    LinkedListNode<T>* currNode2 = startList2->getNext();
    LinkedListNode<T>* currNewNode = newStart;

    startList1->setNext(nullptr);
    startList2->setNext(nullptr);


    while(currNode1->getNext() && currNode2->getNext()){
        if(currNode1->getData() < currNode2->getData()){
            currNewNode->setNext(currNode1);
            currNode1->setPrevious(currNewNode);
            currNewNode = currNewNode->getNext();
            currNode1 = currNode1->getNext();

        }
        else{
            currNewNode->setNext(currNode2);
            currNode2->setPrevious(currNewNode);
            currNewNode = currNewNode->getNext();
            currNode2 = currNode2->getNext();
        }
    }

    if(currNode1->getNext()){
        while(currNode1->getNext()){
            currNewNode->setNext(currNode1);
            currNewNode = currNewNode->getNext();
            currNode1 = currNode1->getNext();
        }


    }
    else if(currNode2->getNext()){
        while(currNode2->getNext()){
            currNewNode->setNext(currNode2);
            currNewNode = currNewNode->getNext();
            currNode2 = currNode2->getNext();
        }
    }


    startList1->setNext(currNode1);
    LinkedListNode<T>* endNode1 = currNode1;
    endNode1->setPrevious(startList1);

    LinkedListNode<T>* endNode2 = currNode2;
    startList2->setNext(endNode2);
    endNode2->setPrevious(startList2);

    currNewNode->setNext(newEnd);


    return StatusType::SUCCESS;

}



#endif //DATA_STRUCTURES_EX1_LINKEDLIST_H