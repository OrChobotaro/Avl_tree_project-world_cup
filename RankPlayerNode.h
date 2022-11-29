//#ifndef DATA_STRUCTURES_EX1_RANKPLAYERNODE_H
//#define DATA_STRUCTURES_EX1_RANKPLAYERNODE_H
//
//#include "Node.h"
//#include "RankPlayerData.h"
//
//
//class RankPlayerNode : public Node<RankPlayerData> {
//public:
//    RankPlayerNode(const RankPlayerData& data, LinkedListNode<RankPlayerData>* ptrList);
//    RankPlayerNode(const RankPlayerNode& rankPlayerNode) = delete;
//    RankPlayerNode& operator=(const RankPlayerNode& rankPlayerNode) = delete;
//    ~RankPlayerNode();
//
//    int getID() const;
//    Node<int>* getPtrPlayer() const;
//    LinkedListNode<RankPlayerData>* getPtrList() const;
//
//    void setGoals(int goals);
//    void setCards(int cards);
//    void setPtrPlayer(Node<int>* ptrPlayer);
//    void setPtrList(LinkedListNode<RankPlayerData>* ptrList);
//
//    RankPlayerNode* newRankNode(const RankPlayerData& data, LinkedListNode<RankPlayerData>* ptrList);
//
//private:
//    LinkedListNode<RankPlayerData>* m_ptrList;
//};
//
//
//#endif //DATA_STRUCTURES_EX1_RANKPLAYERNODE_H
