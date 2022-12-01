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
    if (m_goals > other.m_goals) {
        return true;
    }
    else if (m_goals == other.m_goals) {
        if (m_cards < other.m_cards) {
            return true;
        }
        else if (m_cards == other.m_cards) {
            if (m_playerID > other.m_playerID) {
                return true;
            }
        }
    }
    return false;
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
    return m_ptrRankTree.get();
}

LinkedList<RankPlayerData>* TeamData::getPtrRankLinkedList() {
    return m_ptrRankLinkedList.get();
}

void TeamData::increaseNumPlayers(){
    m_numPlayers+=1;
}

void TeamData::setPtrRankTree(const std::shared_ptr<AvlTree<RankPlayerData>>& other){
    m_ptrRankTree = other;
}

void TeamData::setPtrRankList(const std::shared_ptr<LinkedList<RankPlayerData>>& other){
    m_ptrRankLinkedList = other;
}

void TeamData::addPoints(int pointsToAdd) {
    m_points += pointsToAdd;
}





void TeamData::setNumPlayers(int numPlayers) {
    m_numPlayers = numPlayers;
}
void TeamData::setNumGoalKeepers(int numGoalKeepers){
    m_numGoalKeepers = numGoalKeepers;
}

void TeamData::setNumGoals(int numGoals) {
    m_goals = numGoals;
}
void TeamData::setNumCards(int numCards) {
    m_cards = numCards;
}


void TeamData::addGoals(int goalsToAdd){
    m_goals+=goalsToAdd;
}

void TeamData::subtractGoals(int goalsToSubtract){
    m_goals-=goalsToSubtract;
}

void TeamData::addCards(int cardsToAdd){
    m_cards+=cardsToAdd;
}

void TeamData::subtractCards(int cardsToSubtract){
    m_cards-=cardsToSubtract;
}

void TeamData::increaseGoalKeeper(){
    m_numGoalKeepers+=1;
}

void TeamData::decreaseGoalKeeper(){
    m_numGoalKeepers-=1;
}





PlayerData::PlayerData(int playerID, int teamID, int gamesPlayed, int goals, int cards, bool goalKeeper) :
        m_playerID(playerID),m_teamID(teamID), m_individualGamesPlayed(gamesPlayed), m_goals(goals), m_cards(cards),
        m_isGoalKeeper(goalKeeper), m_ptrTeam(nullptr) ,m_PtrRankAllPlayersTree(nullptr), m_PtrRankTeamPlayerTree(nullptr){}



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

Node<RankPlayerData>* PlayerData::getPtrRankTeamPlayerTree() const {
    return m_PtrRankTeamPlayerTree;
}

Node<RankPlayerData>* PlayerData::getPtrRankAllPlayersTree() const {
    return m_PtrRankAllPlayersTree;
}

void PlayerData::setCards(int cards) {
    m_cards = cards;
}

void PlayerData::setTeamID(int teamID) {
    m_teamID = teamID;
}

void PlayerData::setGoals(int goals) {
    m_goals = goals;
}

bool PlayerData::isGoalKeeper() const{
    return m_isGoalKeeper;
}

//void PlayerData::setIndividualGamesPlayed(int individualGamesPlayed) {
//    m_individualGamesPlayed = individualGamesPlayed;
//}

void PlayerData::setPlayerID(int teamID) {
    m_playerID = m_playerID;
}

void PlayerData::setPtrRankAllPlayersTree(Node<RankPlayerData> *node) {
    m_PtrRankAllPlayersTree = node;
}


void PlayerData::setPtrRankTeamPlayerTree(Node<RankPlayerData> *node) {
    m_PtrRankTeamPlayerTree = node;
}

void PlayerData::setPtrTeam(Node<TeamData> *node) {
    m_ptrTeam = node;
}



void PlayerData::subtractIndividualGamesPlayed(int gamesPlayed){
    m_individualGamesPlayed-= gamesPlayed;
}

void PlayerData::increaseIndividualGamesPlayer(int gamesPlayed) {
    m_individualGamesPlayed += gamesPlayed;
}


bool PlayerData::operator<(const PlayerData &other) const {
    return m_playerID < other.m_playerID;
}

bool PlayerData::operator>(const PlayerData &other) const {
    return m_playerID > other.m_playerID;
}





////----------------------------------------------------------------------


Node<PlayerData>* findPlayer(int playerID, Node<PlayerData>* root){
    Node<PlayerData>* temp = root;
    while (temp) {
        int tempID = temp->getKey().getPlayerID();
        if (tempID < playerID) {
            temp = temp->getRight();
        }
        else if (tempID > playerID) {
            temp = temp->getLeft();
        }
        else if (tempID == playerID) {
            return temp;
        }
    }
    return nullptr;
}



Node<TeamData>* findTeam(int teamID, Node<TeamData>* root) {
    Node<TeamData>* temp = root;
    while (temp) {
        int tempID = temp->getKey().getTeamID();
        if (tempID < teamID) {
            temp = temp->getRight();
        }
        else if (tempID > teamID) {
            temp = temp->getLeft();
        }
        else if (tempID == teamID) {
            return temp;
        }
    }
    return nullptr;
}


////---------------------------------


#include "validTeams.h"


ValidTeams::ValidTeams(int teamID, Node<TeamData>* ptrTeamData) :
        m_teamID(teamID), m_ptrTeamData(ptrTeamData), m_points(0){};



bool ValidTeams::operator<(const ValidTeams& other) const{
    return this->m_teamID < other.m_teamID;
}

bool ValidTeams::operator>(const ValidTeams& other) const{
    return this->m_teamID > other.m_teamID;
}