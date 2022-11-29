#ifndef DATA_STRUCTURES_EX1_RANKPLAYERDATA_H
#define DATA_STRUCTURES_EX1_RANKPLAYERDATA_H



#include "LinkedList.h"
#include "avlTree.h"
#include "PlayerData.h"
#include <iostream>
#include <memory>

class TeamData;
class PlayerData;


class RankPlayerData {
public:
    RankPlayerData(int playerID, int goals, int cards, Node<PlayerData>* m_ptrPlayer);
    RankPlayerData(const RankPlayerData& rankPlayer) = default;
    RankPlayerData& operator=(const RankPlayerData& rankPlayer) = default;
    ~RankPlayerData() = default;

    int getPlayerID() const;
    Node<PlayerData>* getPlayerPtr() const;
    Node<RankPlayerData>* getPtrRankPlayerTree() const;
    LinkedListNode<RankPlayerData>* getPtrRankPlayerList() const;


    void setGoals(int goals);
    void setCards(int cards);
    void setPtrPlayer(Node<PlayerData>* ptrPlayer);
    void setPtrRankPlayerTree(Node<RankPlayerData>* other);
    void setPtrRankPlayerList(LinkedListNode<RankPlayerData>* other);

    bool operator<(const RankPlayerData& other) const;
    bool operator>(const RankPlayerData& other) const;


    LinkedListNode<RankPlayerData>* m_ptrLinkedList;
private:
    int m_playerID;
    int m_goals;
    int m_cards;
    Node<PlayerData>* m_ptrPlayer; // pointer to players' tree
    Node<RankPlayerData>* m_ptrRankTree;
};




class TeamData{
public:

    TeamData() = delete;
    TeamData(int TeamID, int points);
    TeamData(const TeamData& otherTeam) = default;
    TeamData& operator=(const TeamData& otherTeam) = default;
    bool operator<(const TeamData& other) const;
    bool operator>(const TeamData& other) const;
    ~TeamData() = default;

    int getTeamID();
    int getTeamPoints();
    int getNumPlayers();
    int getNumGoalKeepers();
    int getGoals();
    int getCard();
    int getGames();
    AvlTree<RankPlayerData>* getPtrRankTree();
    LinkedList<RankPlayerData>* getPtrRankLinkedList();

    void increaseNumPlayers();
    void setPtrRankTree(const std::shared_ptr<AvlTree<RankPlayerData>>& other);
    void setPtrRankList(const std::shared_ptr<LinkedList<RankPlayerData>>& other);


private:
    int m_teamID;
    int m_points;
    int m_numPlayers;
    int m_numGoalKeepers;
    int m_goals;
    int m_cards;
    int m_gamesPlayed;
    std::shared_ptr<AvlTree<RankPlayerData>> m_ptrRankTree;
    std::shared_ptr<LinkedList<RankPlayerData>> m_ptrRankLinkedList;
};




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
    Node<RankPlayerData>* getPtrRankTeamPlayerTree() const;
    Node<RankPlayerData>* getPtrRankAllPlayersTree() const;
    Node<TeamData>* getPtrTeam() const;

    void setPlayerID(int teamID);
//    void setIndividualGamesPlayed(int individualGamesPlayed);
    void setGoals(int goals);
    void setCards(int cards);
    void setPtrTeam(Node<TeamData>* node);
    void setPtrRankAllPlayersTree(Node<RankPlayerData>* node);
    void setPtrRankTeamPlayerTree(Node<RankPlayerData>* node);


    void subtractIndividualGamesPlayed(int GamesPlayed);
    bool operator<(const PlayerData& other) const;
    bool operator>(const PlayerData& other) const;


    Node<RankPlayerData>* m_PtrRankAllPlayersTree;
    Node<RankPlayerData>* m_PtrRankTeamPlayerTree;
private:
    int m_playerID;
    int m_teamID;
    int m_individualGamesPlayed;
    int m_goals;
    int m_cards;
    bool m_isGoalKeeper;
    Node<TeamData>* m_ptrTeam;
};






#endif //DATA_STRUCTURES_EX1_RANKPLAYERDATA_H