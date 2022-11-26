
#include "PlayerNode.h"

PlayerNode::PlayerNode(int playerID, int teamID, int gamesPlayed, int goals, int cards, bool goalKeeper) :
        Node<int>(playerID), m_teamID(teamID), m_individualGamesPlayed(gamesPlayed), m_goals(goals), m_cards(cards),
        m_isGoalKeeper(goalKeeper), m_teamPtr(nullptr) {
    //todo: add pointer to the team
}


int PlayerNode::getPlayerID() const {
    return Node<int>::getKey();
}

int PlayerNode::getTeamID() const {
    return m_teamID;
}

int PlayerNode::getIndividualGamesPlayed() const {
    return m_individualGamesPlayed;
}

int PlayerNode::getGoals() const {
    return m_goals;
}

int PlayerNode::getCards() const {
    return m_cards;
}

TeamNode* PlayerNode::getTeamPtr() const {
    return m_teamPtr;
}


void PlayerNode::setTeamID(int teamID) {
    m_teamID = teamID;
}

void PlayerNode::setIndividualGamesPlayed(int individualGamesPlayed) {
    m_individualGamesPlayed = individualGamesPlayed;
}

void PlayerNode::setGoals(int goals) {
    m_goals = goals;
}

void PlayerNode::setCards(int cards) {
    m_cards = cards;
}

void PlayerNode::setTeamPtr(TeamNode *teamPtr) {
    m_teamPtr = teamPtr;
}
