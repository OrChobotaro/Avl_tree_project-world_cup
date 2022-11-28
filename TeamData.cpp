//#include "TeamData.h"
//
//TeamData::TeamData(int TeamID, int points):
//        m_teamID(TeamID), m_points(points), m_numPlayers(0), m_numGoalKeepers(0), m_goals(0), m_cards(0),
//        m_gamesPlayed(0), m_ptrRankTree(nullptr), m_ptrRankLinkedList(nullptr){}
////todo: add to initialization list highestRankPlayer, ptr to linked list
//
//bool TeamData::operator<(const TeamData& other) const{
//    if(this->m_teamID < other.m_teamID){
//        return true;
//    }
//    return false;
//}
//
//
//bool TeamData::operator>(const TeamData& other) const{
//    return (other < *this);
//}
//
//int TeamData::getTeamID() {
//    return this->m_teamID;
//}
//
//int TeamData::getTeamPoints() {
//    return this->m_teamID;
//}
//
//int TeamData::getNumPlayers() {
//    return this->m_numPlayers;
//}
//
//int TeamData::getNumGoalKeepers() {
//    return this->m_numGoalKeepers;
//}
//
//int TeamData::getGoals() {
//    return this->m_goals;
//}
//
//int TeamData::getCard() {
//    return this->m_cards;
//}
//
//int TeamData::getGames() {
//    return this->m_gamesPlayed;
//}
//
//AvlTree<RankPlayerData>* TeamData::getPtrRankTree() {
//    return m_ptrRankTree;
//}
//
//LinkedList<RankPlayerData>* TeamData::getPtrRankLinkedList() {
//    return m_ptrRankLinkedList;
//}
