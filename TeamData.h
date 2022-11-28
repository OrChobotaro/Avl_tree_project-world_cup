//#ifndef DATA_STRUCTURES_EX1_TEAMDATA_H
//#define DATA_STRUCTURES_EX1_TEAMDATA_H
//
//#include "LinkedList.h"
//#include "avlTree.h"
//#include "PlayerData.h"
//
//class TeamData{
//public:
//
//    TeamData() = delete;
//    TeamData(int TeamID, int points);
//    TeamData(const TeamData& otherTeam) = delete;
//    TeamData& operator=(const TeamData& otherTeam) = delete;
//    bool operator<(const TeamData& other) const;
//    bool operator>(const TeamData& other) const;
//    ~TeamData() = default;
//
//    int getTeamID();
//    int getTeamPoints();
//    int getNumPlayers();
//    int getNumGoalKeepers();
//    int getGoals();
//    int getCard();
//    int getGames();
//    AvlTree<RankPlayerData>* getPtrRankTree();
//    LinkedList<RankPlayerData>* getPtrRankLinkedList();
//
//
//private:
//    int m_teamID;
//    int m_points;
//    int m_numPlayers;
//    int m_numGoalKeepers;
//    int m_goals;
//    int m_cards;
//    int m_gamesPlayed;
//    AvlTree<RankPlayerData>* m_ptrRankTree;
//    LinkedList<RankPlayerData>* m_ptrRankLinkedList;
//};
//
//
//
//#endif //DATA_STRUCTURES_EX1_TEAMDATA_H
