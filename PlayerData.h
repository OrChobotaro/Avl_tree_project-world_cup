#ifndef DATA_STRUCTURES_EX1_PLAYERDATA_H
#define DATA_STRUCTURES_EX1_PLAYERDATA_H

#include "LinkedList.h"
#include "TeamData.h"
#include "RankPlayerData.h"


class PlayerData {
public:
    PlayerData() = delete;
    PlayerData(int playerID, int teamID, int gamesPlayed, int goals, int cards, bool goalKeeper);
    PlayerData(const PlayerData& otherPlayerData) = default;
    PlayerData& operator=(const PlayerData& otherPlayerData) = default;
    ~PlayerData() = default;

    int getTeamID() const;
    int getPlayerID() const;
    int getIndividualGamesPlayed() const;
    int getGoals() const;
    int getCards() const;
    bool isGoalKeeper() const;
    //suppose to be a link to the linkedLint in the TreeRank
    //LinkedListNode<RankPlayerDataLinkedList>* getPtrPlayerList() const;
    Node<RankPlayerData>* getPtrPlayerRankTree() const;
    Node<TeamData>* getPtrTeam() const;

    void setPlayerID(int teamID);
    void setIndividualGamesPlayed(int individualGamesPlayed);
    void setGoals(int goals);
    void setCards(int cards);
    void setPtrTeam(Node<TeamData>* node);
    void setPtrPlayerRank(Node<RankPlayerData>* node);

    bool operator<(const PlayerData& other) const;
    bool operator>(const PlayerData& other) const;


private:
    int m_playerID;
    int m_teamID;
    int m_individualGamesPlayed;
    int m_goals;
    int m_cards;
    bool m_isGoalKeeper;
    Node<TeamData>* m_ptrTeam;
    Node<RankPlayerData>* m_PtrRankPlayer;
};





#endif //DATA_STRUCTURES_EX1_PLAYERDATA_H
