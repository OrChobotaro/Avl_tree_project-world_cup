#ifndef DATA_STRUCTURES_EX1_RANKPLAYERDATA_H
#define DATA_STRUCTURES_EX1_RANKPLAYERDATA_H



#include "LinkedList.h"
#include "avlTree.h"
#include "PlayerData.h"
#include <iostream>
#include <memory>

class TeamData;
class PlayerData;
class PlayerID;


class RankPlayerData {
public:
    RankPlayerData(int playerID, int goals, int cards, Node<PlayerData>* m_ptrPlayer);
    RankPlayerData(const RankPlayerData& rankPlayer) = default;
    RankPlayerData& operator=(const RankPlayerData& rankPlayer) = default;
    ~RankPlayerData() = default;

    int getPlayerID() const;
    int getGoals() const;
    int getCards() const;

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
    Node<RankPlayerData>* m_ptrRankTree;
private:
    int m_playerID;
    int m_goals;
    int m_cards;
    Node<PlayerData>* m_ptrPlayer; // pointer to players' tree
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
    AvlTree<PlayerID>* getPtrIDTree();

    void increaseNumPlayers();
    void setPtrRankTree(const std::shared_ptr<AvlTree<RankPlayerData>>& other);
    void setPtrRankList(const std::shared_ptr<LinkedList<RankPlayerData>>& other);
    void setPtrIDTree(const std::shared_ptr<AvlTree<PlayerID>>& other);
    void setNumPlayers(int numPlayers);
    void setNumGoalKeepers(int numGoalKeepers);
    void setNumGoals(int numGoals);
    void setNumCards(int numCards);
    void setPoints(int points);

    void addGoals(int goalsToAdd);
    void subtractGoals(int goalsToSubtract);
    void addCards(int cardsToAdd);
    void subtractCards(int cardsToSubtract);
    void increaseGoalKeeper();
    void decreaseGoalKeeper();
    void addPoints(int pointsToAdd);



    int m_points;
    int m_gamesPlayed;
    std::shared_ptr<AvlTree<RankPlayerData>> m_ptrRankTree;
    std::shared_ptr<AvlTree<PlayerID>> m_ptrIDTree;
private:
    int m_teamID;
    int m_numPlayers;
    int m_numGoalKeepers;
    int m_goals;
    int m_cards;
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

    void setPlayerID(int playerID);
    void setIndividualGamesPlayed(int individualGamesPlayed);
    void setGoals(int goals);
    void setCards(int cards);
    void setTeamID(int teamID);
    void setPtrTeam(Node<TeamData>* node);
    void setPtrRankAllPlayersTree(Node<RankPlayerData>* node);
    void setPtrRankTeamPlayerTree(Node<RankPlayerData>* node);


    void subtractIndividualGamesPlayed(int gamesPlayed);
    void increaseIndividualGamesPlayer(int gamesPlayed);
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



class ValidTeams{
public:

    ValidTeams(int teamID, Node<TeamData>* ptrTeamData);
    ValidTeams(const ValidTeams& other) = default;
    ValidTeams& operator=(const ValidTeams& other) = default;
    ~ValidTeams() = default;

    int getTeamId() const;
    int getTotalRank() const;
    void setTeamID(int newID);
    LinkedListNode<ValidTeams>* getPtrLinkedList();
    Node<TeamData>* getPtrTeamData();


    void setTotalRank(int rank);
    void setPtrLinkedList(LinkedListNode<ValidTeams>* other);
    void setPtrTeamData(Node<TeamData>* other);



    bool operator<(const ValidTeams& other) const;
    bool operator>(const ValidTeams& other) const;


private:
    int m_teamID;
    Node<TeamData>* m_ptrTeamData; // pointer to node in teams' tree
    int m_totalRank;
//    int m_points;
    LinkedListNode<ValidTeams> *m_ptrLinkedList;
};



class PlayerID {
public:
    PlayerID(int playerID, Node<PlayerData>* ptrPlayer);
    PlayerID(const PlayerID& other) = default;
    PlayerID& operator=(const PlayerID& other) = default;
    ~PlayerID() = default;

    bool operator<(const PlayerID& other) const;
    bool operator>(const PlayerID& other) const;

    Node<PlayerData>* getPtrPlayer() const;
    int getPlayerID() const;

    void setPtrPlayer(Node<PlayerData>* ptrPlayer);

private:
    int m_playerId;
    Node<PlayerData>* m_ptrPlayer;
};




Node<PlayerData>* findPlayer(int playerID, Node<PlayerData>* root);
PlayerData findPlayerKey(int playerID, Node<PlayerData>* root);

Node<TeamData>* findTeam(int teamID, Node<TeamData>* root);
TeamData findTeamKey(int teamID, Node<TeamData>* root);

Node<ValidTeams>* findValidTeam(int teamID, Node<ValidTeams>* root);
ValidTeams findValidTeamKey(int teamID, Node<ValidTeams>* root);

Node<PlayerID>* findIDPlayer(int playerID, Node<PlayerID>* root);
PlayerID findIDPlayerKey(int playerID, Node<PlayerID>* root);


LinkedListNode<RankPlayerData>* insertNode(const RankPlayerData& rankPlayer, AvlTree<RankPlayerData>* tree,
                                           LinkedList<RankPlayerData>* list);




#endif //DATA_STRUCTURES_EX1_RANKPLAYERDATA_H