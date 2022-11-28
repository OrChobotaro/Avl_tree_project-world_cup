#include "RankPlayerData.h"


RankPlayerData::RankPlayerData(int playerID, int goals, int cards, Node<PlayerData>* m_ptrPlayer):
        m_playerID(playerID), m_goals(goals), m_cards(cards), m_ptrPlayer(m_ptrPlayer), m_ptrLinkedList(nullptr),
        m_ptrRankTree(nullptr) {}


int RankPlayerData::getPlayerID() const {
    return m_playerID;
}


Node<PlayerData>* RankPlayerData::getPlayerPtr() const {
    return m_ptrPlayer;
}

Node<RankPlayerData>* RankPlayerData::getPtrRankPlayerTree() const {
    return m_ptrRankTree;
}

LinkedListNode<RankPlayerData>* RankPlayerData::getPtrRankPlayerList() const {
    return m_ptrLinkedList;
}

void RankPlayerData::setGoals(int goals) {
    m_goals = goals;
}


void RankPlayerData::setCards(int cards) {
    m_cards = cards;
}


void RankPlayerData::setPtrPlayer(Node<PlayerData>* ptrPlayer){
    m_ptrPlayer = ptrPlayer;
}

void RankPlayerData::setPtrRankPlayerTree(Node<RankPlayerData> *other) {
    m_ptrRankTree = other;
}

void RankPlayerData::setPtrRankPlayerList(LinkedListNode<RankPlayerData>* other) {
    m_ptrLinkedList = other;
}

//todo: check if working
bool RankPlayerData::operator<(const RankPlayerData &other) const{
    if (m_goals < other.m_goals) {
        return true;
    }
    else if (m_goals == other.m_goals) {
        if (m_cards > other.m_cards) {
            return true;
        }
        else if (m_cards == other.m_cards) {
            if (m_playerID < other.m_playerID) {
                return true;
            }
        }
    }
    return false;
}


bool RankPlayerData::operator>(const RankPlayerData &other) const{
    return !(*this < other);
}




///------------------------------------------------------------///




TeamData::TeamData(int TeamID, int points):
        m_teamID(TeamID), m_points(points), m_numPlayers(0), m_numGoalKeepers(0), m_goals(0), m_cards(0),
        m_gamesPlayed(0), m_ptrRankTree(nullptr), m_ptrRankLinkedList(nullptr){}
//todo: add to initialization list highestRankPlayer, ptr to linked list

bool TeamData::operator<(const TeamData& other) const{
    if(this->m_teamID < other.m_teamID){
        return true;
    }
    return false;
}


bool TeamData::operator>(const TeamData& other) const{
    return (other < *this);
}

int TeamData::getTeamID() {
    return this->m_teamID;
}

int TeamData::getTeamPoints() {
    return this->m_teamID;
}

int TeamData::getNumPlayers() {
    return this->m_numPlayers;
}

int TeamData::getNumGoalKeepers() {
    return this->m_numGoalKeepers;
}

int TeamData::getGoals() {
    return this->m_goals;
}

int TeamData::getCard() {
    return this->m_cards;
}

int TeamData::getGames() {
    return this->m_gamesPlayed;
}

AvlTree<RankPlayerData>* TeamData::getPtrRankTree() {
    return m_ptrRankTree;
}

LinkedList<RankPlayerData>* TeamData::getPtrRankLinkedList() {
    return m_ptrRankLinkedList;
}



PlayerData::PlayerData(int playerID, int teamID, int gamesPlayed, int goals, int cards, bool goalKeeper) :
        m_playerID(playerID),m_teamID(teamID), m_individualGamesPlayed(gamesPlayed), m_goals(goals), m_cards(cards),
        m_isGoalKeeper(goalKeeper), m_ptrTeam(nullptr) ,m_PtrRankPlayer(nullptr) {}



int PlayerData::getTeamID() const {
    return m_teamID;
}

int PlayerData::getPlayerID() const {
    return m_playerID;
}

int PlayerData::getIndividualGamesPlayed() const {
    return m_individualGamesPlayed;
}

int PlayerData::getCards() const {
    return m_cards;
}

int PlayerData::getGoals() const {
    return m_goals;
}

Node<TeamData>* PlayerData::getPtrTeam() const {
    return m_ptrTeam;
}

Node<RankPlayerData>* PlayerData::getPtrPlayerRankTree() const {
    return m_PtrRankPlayer;
}


void PlayerData::setCards(int cards) {
    m_cards = cards;
}

void PlayerData::setGoals(int goals) {
    m_goals = goals;
}

void PlayerData::setIndividualGamesPlayed(int individualGamesPlayed) {
    m_individualGamesPlayed = individualGamesPlayed;
}

void PlayerData::setPlayerID(int teamID) {
    m_playerID = m_playerID;
}

void PlayerData::setPtrPlayerRank(Node<RankPlayerData> *node) {
    m_PtrRankPlayer = node;
}

void PlayerData::setPtrTeam(Node<TeamData> *node) {
    m_ptrTeam = node;
}


bool PlayerData::operator<(const PlayerData &other) const {
    return m_playerID < other.m_playerID;
}

bool PlayerData::operator>(const PlayerData &other) const {
    return !(*this < other);
}

