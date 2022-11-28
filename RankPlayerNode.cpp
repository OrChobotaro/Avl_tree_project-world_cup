#include "RankPlayerNode.h"


RankPlayerNode::RankPlayerNode(const RankPlayerData &data, LinkedListNode<RankPlayerData>* ptrList) :
Node<RankPlayerData>(data), m_ptrList(ptrList) {}


int RankPlayerNode::getID() const {
    return (getKey()).getPlayerID();
}

Node<int>* RankPlayerNode::getPtrPlayer() const {
    return (getKey()).getPlayerPtr();
}


LinkedListNode<RankPlayerData>* RankPlayerNode::getPtrList() const {
    return m_ptrList;
}


void RankPlayerNode::setGoals(int goals) {
    getKey().setGoals(goals);
}


void RankPlayerNode::setCards(int cards) {
    getKey().setCards(cards);
}


void RankPlayerNode::setPtrPlayer(Node<int> *ptrPlayer) {
    getKey().setPtrPlayer(ptrPlayer);
}


void RankPlayerNode::setPtrList(LinkedListNode<RankPlayerData> *ptrList) {
    m_ptrList = ptrList;
}


RankPlayerNode* RankPlayerNode::newRankNode(const RankPlayerData &data, LinkedListNode<RankPlayerData>* ptrList) {
    return new RankPlayerNode(data, ptrList);
}