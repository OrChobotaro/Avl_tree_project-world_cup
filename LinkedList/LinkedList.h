#ifndef DATA_STRUCTURES_EX1_LINKEDLIST_H
#define DATA_STRUCTURES_EX1_LINKEDLIST_H

#include "LinkedListNode.h"
#include "../wet1util.h"


template<class T>
class LinkedList{
public:

    LinkedList() = delete;

    LinkedList(const T& nullParam);

    LinkedList(const LinkedList<T>& otherList) = default;
    LinkedList<T>& operator=(const LinkedList& otherList) = delete;

    LinkedListNode<T>* getStart();
    LinkedListNode<T>* getEnd();

    LinkedListNode<T>* setStart(LinkedListNode<T>* node);
    LinkedListNode<T>* setEnd(LinkedListNode<T>* node);

    LinkedListNode<T>* newLinkedListNode(const T& data);

    StatusType insertBefore(LinkedListNode<T>* node, const T& data, LinkedListNode<T>** ptrSave);
    StatusType insertAfter(LinkedListNode<T>* node, const T& data, LinkedListNode<T>** ptrSave);
    StatusType deleteNode(LinkedListNode<T>* nodeToRemove);

//    StatusType uniteListsNew(LinkedList<T>* List2, LinkedList<T>* newList);
    void clearList(LinkedListNode<T>* start);





    ~LinkedList();




private:
    LinkedListNode<T>* m_start;
    LinkedListNode<T>* m_end;

};

//template<class T>
//StatusType uniteListsNew(LinkedList<T>& List2, LinkedList<T>& newList, T nullData);

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
LinkedListNode<T>* LinkedList<T>::setStart(LinkedListNode<T>* node) {
    m_start = node;
}

template<class T>
LinkedListNode<T>* LinkedList<T>::setEnd(LinkedListNode<T>* node) {
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



//template<class T>
//StatusType LinkedList<T>::uniteLists(LinkedListNode<T>* startList1, LinkedListNode<T>* startList2,
//                                     LinkedListNode<T>* newStart, LinkedListNode<T>** newEnd){
//    //dont need to delete dummys - D'tor
//    //null in onw of the lists
//    //null in two lists
//
//
//    LinkedListNode<T>* nodeList1 = startList1->getNext();
//    LinkedListNode<T>* nodeList2 = startList2->getNext();
//    LinkedListNode<T>* temp1;
//    LinkedListNode<T>* temp2;
//
//    LinkedListNode<T>* nodeNewList = newStart;
//    LinkedListNode<T>* tempNewNode;
//
//    startList1->setNext(nullptr);
//    startList2->setNext(nullptr);
//
//
//    while(nodeList1->getNext() && nodeList2->getNext()){
//        if(startList1->getData() > startList2->getData()){
//            temp2 = nodeList2;
//            tempNewNode = nodeNewList;
//
//            tempNewNode->setNext(temp2);
//            temp2->setPrevious(tempNewNode);
//
//            nodeList2 = nodeList2->getNext();
//            nodeNewList = nodeNewList->getNext();
//        }
//        else{
//            temp1 = nodeList1;
//            tempNewNode = nodeNewList;
//
//            tempNewNode->setNext(temp1);
//            temp1->setPrevious(tempNewNode);
//
//            nodeList1 = nodeList1->getNext();
//            nodeNewList = nodeNewList->getNext();
//        }
//    }
//
//    if(!nodeList1->getNext()){
//        // connecting start to end
//        startList1->setNext(nodeList1);
//        //clear list
//        clearList(startList1);
//
//        nodeNewList->setNext(nodeList2);
//
//        //clear start_node1
//        clearList(startList1);
//
//
//        *newEnd =
//    }
//
//
//    return StatusType::SUCCESS;
//
//
//}

//
//template<class T>
//StatusType LinkedList<T>::uniteListsNew(LinkedList<T>* List2, LinkedList<T>* newList){
//    //dont need to delete dummys - D'tor
//    //null in onw of the lists
//    //null in two lists
//
//    LinkedList<T>* List1 = this;
//
//    LinkedListNode<T>* startList1 = List1->getStart();
//    LinkedListNode<T>* startList2 = List2->getStart();
//
//    LinkedListNode<T>* nodeList1 = startList1->getNext();
//    LinkedListNode<T>* nodeList2 = startList2->getNext();
//    LinkedListNode<T>* temp1;
//    LinkedListNode<T>* temp2;
//
//    LinkedListNode<T>* newStart;
//    try {
//        newStart = newLinkedListNode();
//    }
//    catch(std::bad_alloc& e){
//        return StatusType::FAILURE;
//    }
//
//    LinkedListNode<T>* nodeNewList = newStart;
//    LinkedListNode<T>* tempNewNode;
//
//    startList1->setNext(nullptr);
//    startList2->setNext(nullptr);
//
//
//    while(nodeList1->getNext() && nodeList2->getNext()){
//        if(startList1->getData() > startList2->getData()){
//            temp2 = nodeList2;
//            tempNewNode = nodeNewList;
//
//            tempNewNode->setNext(temp2);
//            temp2->setPrevious(tempNewNode);
//
//            nodeList2 = nodeList2->getNext();
//            nodeNewList = nodeNewList->getNext();
//        }
//        else{
//            temp1 = nodeList1;
//            tempNewNode = nodeNewList;
//
//            tempNewNode->setNext(temp1);
//            temp1->setPrevious(tempNewNode);
//
//            nodeList1 = nodeList1->getNext();
//            nodeNewList = nodeNewList->getNext();
//        }
//    }
//
//    if(!nodeList1->getNext()){
//        // connecting start to end list1
//        startList1->setNext(nodeList1);
//        //clear list1
//        clearList(startList1);
//
//        nodeNewList->setNext(nodeList2);
//
//        //clear start_node2
//        clearList(startList2);
//
//        newList->setEnd(List2->getEnd());
//        newList->setStart(List2->getStart());
//
//    } else{
//        startList2->setNext(nodeList2);
//        clearList(startList2);
//
//        nodeNewList->setNext(nodeList1);
//
//        clearList(startList1);
//
//
//    }
//
//
//    return StatusType::SUCCESS;
//
//
//}




//template<class T>
//StatusType uniteListsNew(LinkedList<int>& List1, LinkedList<int>& List2, LinkedList<T>& newList, T nullData){
//
//    //LinkedList<T> List1 = *this;
//    LinkedListNode<T>* startList1 = List1.getStart()->getNext();
//    LinkedListNode<T>* startList2 = List2.getStart()->getNext();
//    LinkedListNode<T>* newStart;
//    LinkedListNode<T>* newEnd;
//
//    try{
//        newStart = newLinkedListNode(nullData);
//        newEnd = newLinkedListNode(nullData);
//    }
//    catch(std::bad_alloc& e){
//        return StatusType::ALLOCATION_ERROR;
//    }
//
//    newList.setStart(newStart);
//    LinkedListNode<T>* saveStart = newStart;
//    //LinkedListNode<T>* tempStart = newStart;
//    LinkedListNode<T>* newNode;
//
//    while(startList1->getNext() && startList2->getNext()) {
//        if (startList1->getData() > startList2->getData()) {
//
//            try{
//                newNode = nullptr;
//                newNode = newLinkedListNode(startList2->getData());
//                //tempStart = newStart;
//                newStart->setNext(newNode);
//                newNode->setPrevious(newStart);
//                newStart = newStart->getNext();
//            }
//            catch(std::bad_alloc& e){
//                LinkedList<T>::clearList(saveStart);
//                return StatusType::ALLOCATION_ERROR;
//            }
//        }
//        else{
//
//            try{
//                LinkedListNode<T>* newNode = newLinkedListNode(startList1->getData());
//                newStart->setNext(newNode);
//                newNode->setPrevious(newStart);
//                newStart = newStart->getNext();
//
//            }
//            catch(std::bad_alloc& e){
//                clearList(saveStart);
//                return StatusType::ALLOCATION_ERROR;
//            }
//        }
//
//        newList.setEnd(newEnd);
//    }
//
//    return StatusType::SUCCESS;
//}


template<class T>
StatusType uniteLists(LinkedListNode<T>* startList1, LinkedListNode<T>* startList2,
                      LinkedListNode<T>* newStart, LinkedListNode<T>* newEnd){


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
            currNode1->getNext();
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
