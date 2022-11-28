#include "RankPlayerData.h"


RankPlayerData::RankPlayerData(int playerID, int goals, int cards, Node<int>* m_ptrPlayer):
        m_playerID(playerID), m_goals(goals), m_cards(cards), m_ptrPlayer(m_ptrPlayer), m_ptrLinkedList(nullptr),
        m_ptrRankTree(nullptr) {}


int RankPlayerData::getPlayerID() const {
    return m_playerID;
}


Node<int>* RankPlayerData::getPlayerPtr() const {
    return m_ptrPlayer;
}

Node<RankPlayerData>* RankPlayerData::getPtrRankPlayerTree() const {
    return m_ptrRankTree;
}

LinkedListNode<RankPlayerData>* RankPlayerData::getPtrRankPlayerList() const {
    return m_ptrLinkedList;
}

void RankPlayerData::setGoals(int goals) {
    m_goals = goals;
}


void RankPlayerData::setCards(int cards) {
    m_cards = cards;
}


void RankPlayerData::setPtrPlayer(Node<int>* ptrPlayer){
    m_ptrPlayer = ptrPlayer;
}

void RankPlayerData::setPtrRankPlayerTree(Node<RankPlayerData> *other) {
    m_ptrRankTree = other;
}

void RankPlayerData::setPtrRankPlayerList(LinkedListNode<RankPlayerData>* other) {
    m_ptrLinkedList = other;
}

//todo: check if working
bool RankPlayerData::operator<(const RankPlayerData &other) const{
    if (m_goals < other.m_goals) {
        return true;
    }
    else if (m_goals == other.m_goals) {
        if (m_cards > other.m_cards) {
            return true;
        }
        else if (m_cards == other.m_cards) {
            if (m_playerID < other.m_playerID) {
                return true;
            }
        }
    }
    return false;
}


bool RankPlayerData::operator>(const RankPlayerData &other) const{
    return !(*this < other);
}