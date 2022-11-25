#ifndef DATA_STRUCTURES_EX1_PLAYERNODE_H
#define DATA_STRUCTURES_EX1_PLAYERNODE_H

//#include "BinaryTreeAVL/Node.h"
#include "../TeamsTree/TeamNode.h"

class PlayerNode : public Node<int>{
public:
    PlayerNode() = delete;
    PlayerNode(int playerID, int teamID, int gamesPlayed, int goals, int cards, bool goalKeeper);
    PlayerNode(const PlayerNode& otherPlayerNode) = delete;
    PlayerNode& operator=(const PlayerNode& otherPlayerNode) = delete;
    ~PlayerNode() = default;

    int getPlayerID() const;
    int getTeamID() const;
    int getIndividualGamesPlayed() const;
    int getGoals() const;
    int getCards() const;
    TeamNode* getTeamPtr() const;
    //todo: add getter to pointer of linked list

    void setTeamID(int teamID);
    void setIndividualGamesPlayed(int individualGamesPlayed);
    void setGoals(int goals);
    void setCards(int cards);
    void setTeamPtr(TeamNode* teamPtr);
    //todo: add getter to pointer of linked list


private:
    int m_teamID;
    int m_individualGamesPlayed;
    int m_goals;
    int m_cards;
    bool m_isGoalKeeper;
    TeamNode* m_teamPtr; //not initialized yet
    //todo: add pointer to linked list

};




#endif //DATA_STRUCTURES_EX1_PLAYERNODE_H
