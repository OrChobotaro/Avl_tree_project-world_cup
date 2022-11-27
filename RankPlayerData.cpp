#include "RankPlayerData.h"


RankPlayerData::RankPlayerData(int playerID, int goals, int cards, Node<int>* m_ptrPlayer):
        m_playerID(playerID), m_goals(goals), m_cards(cards), m_ptrPlayer(m_ptrPlayer) {}


int RankPlayerData::getPlayerID() const {
    return m_playerID;
}


Node<int>* RankPlayerData::getPlayerPtr() const {
    return m_ptrPlayer;
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