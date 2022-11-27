#ifndef DATA_STRUCTURES_EX1_RANKPLAYERDATA_H
#define DATA_STRUCTURES_EX1_RANKPLAYERDATA_H


#include "Node.h"
#include "LinkedListNode.h"


class RankPlayerData {
public:
    RankPlayerData(int playerID, int goals, int cards, Node<int>* m_ptrPlayer);
    RankPlayerData(const RankPlayerData& rankPlayer) = default;
    RankPlayerData& operator=(const RankPlayerData& rankPlayer) = default;
    ~RankPlayerData() = default;

    int getPlayerID() const;
    Node<int>* getPlayerPtr() const;

    void setGoals(int goals);
    void setCards(int cards);
    void setPtrPlayer(Node<int>* ptrPlayer);

    bool operator<(const RankPlayerData& other) const;
    bool operator>(const RankPlayerData& other) const;


private:
    int m_playerID;
    int m_goals;
    int m_cards;
    Node<int>* m_ptrPlayer;
    LinkedListNode<RankPlayerData>* m_ptrLinkedList;
    Node<RankPlayerData>* m_ptrRankTree;
};




#endif //DATA_STRUCTURES_EX1_RANKPLAYERDATA_H