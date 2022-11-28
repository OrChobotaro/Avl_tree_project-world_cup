#include "PlayerData.h"
//
//PlayerData::PlayerData(int playerID, int teamID, int gamesPlayed, int goals, int cards, bool goalKeeper) :
//m_playerID(playerID),m_teamID(teamID), m_individualGamesPlayed(gamesPlayed), m_goals(goals), m_cards(cards),
//m_isGoalKeeper(goalKeeper), m_ptrTeam(nullptr) ,m_PtrRankPlayer(nullptr) {}
//
//
//
//int PlayerData::getTeamID() const {
//    return m_teamID;
//}
//
//int PlayerData::getPlayerID() const {
//    return m_playerID;
//}
//
//int PlayerData::getIndividualGamesPlayed() const {
//    return m_individualGamesPlayed;
//}
//
//int PlayerData::getCards() const {
//    return m_cards;
//}
//
//int PlayerData::getGoals() const {
//    return m_goals;
//}
//
//Node<TeamData>* PlayerData::getPtrTeam() const {
//    return m_ptrTeam;
//}
//
//Node<RankPlayerData>* PlayerData::getPtrPlayerRankTree() const {
//    return m_PtrRankPlayer;
//}
//
//
//void PlayerData::setCards(int cards) {
//    m_cards = cards;
//}
//
//void PlayerData::setGoals(int goals) {
//    m_goals = goals;
//}
//
//void PlayerData::setIndividualGamesPlayed(int individualGamesPlayed) {
//    m_individualGamesPlayed = individualGamesPlayed;
//}
//
//void PlayerData::setPlayerID(int teamID) {
//    m_playerID = m_playerID;
//}
//
//void PlayerData::setPtrPlayerRank(Node<RankPlayerData> *node) {
//    m_PtrRankPlayer = node;
//}
//
//void PlayerData::setPtrTeam(Node<TeamData> *node) {
//    m_ptrTeam = node;
//}
//
//
//bool PlayerData::operator<(const PlayerData &other) const {
//    return m_playerID < other.m_playerID;
//}
//
//bool PlayerData::operator>(const PlayerData &other) const {
//    return !(*this < other);
//}
//
