#include "worldcup23a1.h"




world_cup_t::world_cup_t():m_numOfPlayers(0)
{
    //todo: initialize all


    // creating players tree
    std::shared_ptr<AvlTree<PlayerData>> playersTree(new AvlTree<PlayerData>);
    m_playersAVLTree = playersTree;

    // creating teams tree
    std::shared_ptr<AvlTree<TeamData>> teamsTree(new AvlTree<TeamData>);
    m_teamsAVLTree = teamsTree;

    // creating all players rank tree
    std::shared_ptr<AvlTree<RankPlayerData>> rankPlayersTree(new AvlTree<RankPlayerData>);
    m_allPlayersRankTree = rankPlayersTree;

    // creating valid teams - team with 11 players including a goalkeeper.
    std::shared_ptr<AvlTree<ValidTeams>> validTeamsTree(new AvlTree<ValidTeams>);
    m_validTeams = validTeamsTree;

    // creating null rank object to start and end of linked list
    RankPlayerData nullRank(-1, -1, -1, nullptr);

    // creating all players linked list
    std::shared_ptr<LinkedList<RankPlayerData>> rankPlayersList(new LinkedList<RankPlayerData>);
    m_allPlayersRankLinkedList = rankPlayersList;

    LinkedListNode<RankPlayerData>* nodeStart = new LinkedListNode<RankPlayerData>(nullRank);
    LinkedListNode<RankPlayerData>* nodeEnd = new LinkedListNode<RankPlayerData>(nullRank);

    m_allPlayersRankLinkedList->setStart(nodeStart);
    m_allPlayersRankLinkedList->setEnd(nodeEnd);

    nodeStart->setNext(nodeEnd);
    nodeEnd->setPrevious(nodeStart);

}

world_cup_t::~world_cup_t()
{
	// TODO: Your code goes here
}


// todo: create new tree
StatusType world_cup_t::add_team(int teamId, int points)
{

    if(teamId <= 0 || points <= 0)
        return StatusType::INVALID_INPUT;

    StatusType res;
	TeamData teamToInsert(teamId, points);
    res = m_teamsAVLTree->insert(teamToInsert);

    //TODO: add team to linkedList

    RankPlayerData nullRank(-1, -1, -1, nullptr);
    if(res == StatusType::SUCCESS){

        // creates linked list for ranking players in team
        std::shared_ptr<LinkedList<RankPlayerData>> newList(new LinkedList<RankPlayerData>(nullRank));
        m_teamsAVLTree->find(teamToInsert)->m_key.setPtrRankList(newList);

        // creates avl tree for ranking players in team
        std::shared_ptr<AvlTree<RankPlayerData>> newTree(new AvlTree<RankPlayerData>);
        m_teamsAVLTree->find(teamToInsert)->m_key.setPtrRankTree(newTree);
    }

	return res;

}

StatusType world_cup_t::remove_team(int teamId)
{
    if(teamId <= 0){
        return StatusType::INVALID_INPUT;
    }

    // creates object to find
    TeamData obj(teamId, 0);
    // find the object
    Node<TeamData>* nodeToDelete = m_teamsAVLTree->find(obj);

    // todo: check if node exists


    // if team is not empty
    if(nodeToDelete->m_key.getNumPlayers() > 0){
        return StatusType::FAILURE;
    }

//    //delete tree
//    AvlTree<RankPlayerData>* treeToDelete = nodeToDelete->m_key.getPtrRankTree();
//    delete treeToDelete;
//
//    //delete list
//    LinkedList<RankPlayerData>* listToDelete = nodeToDelete->m_key.getPtrRankLinkedList();
//    delete listToDelete;

    //todo: check memory leak

    StatusType res = m_teamsAVLTree->remove(obj);

	return res;
}

// todo: add player to new tree
StatusType world_cup_t::add_player(int playerId, int teamId, int gamesPlayed,
                                   int goals, int cards, bool goalKeeper)
{

    // check if playerID invalid
    if(playerId<=0 || teamId<=0 || gamesPlayed<=0 || goals<0 || cards <0){
        return StatusType::INVALID_INPUT;
    }

    // create new player object
    PlayerData newPlayer(playerId, teamId, gamesPlayed, goals, cards, goalKeeper);


    // find the team on teams' tree
    Node<TeamData>* teamNode = findTeam(teamId, m_teamsAVLTree->getRoot());

    if(!teamNode){ // find returns node if found and null if not
        return StatusType::FAILURE;
    }

    //subtract team games played from individual's.
    newPlayer.subtractIndividualGamesPlayed(teamNode->getKey().getGames());

    //set ptr of the team
    newPlayer.setPtrTeam(teamNode);

    // add player to tree
    StatusType res = m_playersAVLTree->insert(newPlayer);


    if(res == StatusType::SUCCESS){

        m_numOfPlayers+=1;

        // add 1 to num of team players
        teamNode->m_key.increaseNumPlayers();

        //todo: check if team is valid and add to the tree
        if(teamNode->getKey().getNumPlayers()==11 && teamNode->m_key.getNumGoalKeepers() > 0){
            ValidTeams validTeamObj(teamId, findTeam(teamId, m_teamsAVLTree->getRoot()));
            m_validTeams->insert(validTeamObj);
        }


        teamNode->m_key.addGoals(goals);
        teamNode->m_key.addCards(cards);
        if(newPlayer.isGoalKeeper()){
            teamNode->m_key.increaseGoalKeeper();
        }


        // create rank node
        RankPlayerData playerRank(playerId, goals, cards, m_playersAVLTree->find(newPlayer));
        // add to all players tree
        m_allPlayersRankTree->insert(playerRank);
        // update rank node in player's node
        m_playersAVLTree->find(newPlayer)->m_key.m_PtrRankAllPlayersTree =  m_allPlayersRankTree->find(playerRank);

        //add to team rank tree
        teamNode->m_key.getPtrRankTree()->insert(playerRank);
        m_playersAVLTree->find(newPlayer)->m_key.m_PtrRankTeamPlayerTree = teamNode->getKey().getPtrRankTree()->find(playerRank);



        try {
            // insert node to all players list
            LinkedListNode<RankPlayerData>* nodeToInsertAllPlayersList = new LinkedListNode<RankPlayerData>(playerRank);
            addToRankLinkedList(playerRank, m_allPlayersRankLinkedList.get(), m_allPlayersRankTree.get(), nodeToInsertAllPlayersList);
            m_allPlayersRankTree->find(playerRank)->m_key.setPtrRankPlayerList(nodeToInsertAllPlayersList);



            // insert node to team's list
            LinkedListNode<RankPlayerData>* nodeToInsertTeamList = new LinkedListNode<RankPlayerData>(playerRank);
            addToRankLinkedList(playerRank, teamNode->getKey().getPtrRankLinkedList(), teamNode->getKey().getPtrRankTree(), nodeToInsertTeamList);
            teamNode->getKey().getPtrRankTree()->find(playerRank)->m_key.setPtrRankPlayerList(nodeToInsertTeamList);

        }
        catch(std::bad_alloc& e){

            //todo: reverse all actions if fails

            return StatusType::ALLOCATION_ERROR;
        }

    }

    return res;
}


StatusType world_cup_t::addToRankLinkedList(const RankPlayerData& playerRank, LinkedList<RankPlayerData>* rankList, AvlTree<RankPlayerData>* rankTree, LinkedListNode<RankPlayerData>* nodeToInsert) {
    //find the node and check if player is left son or right
    bool isPlayerLeft = false;
    Node<RankPlayerData>* rankNode = rankTree->find(playerRank);
    Node<RankPlayerData>* parent = rankNode->getParent();


    if(parent) {
        isPlayerLeft = rankNode->isLeftNew(parent);
    }


//    LinkedListNode<RankPlayerData> nodeInsertToList(playerRank);
    if(isPlayerLeft && parent) {
        rankList->insertBefore(parent->getKey().getPtrRankPlayerList(), nodeToInsert);
    }
    else if(!(isPlayerLeft) && parent){
        rankList->insertAfter(parent->getKey().getPtrRankPlayerList(), nodeToInsert);
    }
    else {
        rankList->insertAfter(rankList->getStart(), nodeToInsert);
    }

    return StatusType::SUCCESS;
}


StatusType world_cup_t::remove_player(int playerId)
{

	return StatusType::SUCCESS;
}

StatusType world_cup_t::update_player_stats(int playerId, int gamesPlayed, int scoredGoals, int cardsReceived)
{

	// TODO: Your code goes here
	return StatusType::SUCCESS;
}

StatusType world_cup_t::play_match(int teamId1, int teamId2)
{
    if (teamId1 <= 0 || teamId2 <= 0 || teamId1 == teamId2) {
        return StatusType::INVALID_INPUT;
    }
    // Save both teams
    Node<TeamData>* team1 = findTeam(teamId1, m_teamsAVLTree->getRoot());
    if (!team1) {
        return StatusType::FAILURE;
    }
    Node<TeamData>* team2 = findTeam(teamId2, m_teamsAVLTree->getRoot());
    if (!team2) {
        return  StatusType::FAILURE;
    }

    if (team1->m_key.getNumPlayers() < 11 || team1->m_key.getNumGoalKeepers() == 0 ||
        team2->m_key.getNumPlayers() < 11 || team2->m_key.getNumGoalKeepers() == 0) {
        return StatusType::FAILURE;
    }

    int team1Score = team1->getKey().getTeamPoints() + team1->getKey().getGoals() - team1->getKey().getCard();
    int team2Score = team2->getKey().getTeamPoints() + team2->getKey().getGoals() - team2->getKey().getCard();

    if (team1Score > team2Score) {
        team1->m_key.m_points+=3;
    }
    else if (team2Score > team1Score) {
        team2->m_key.m_points+=3;
    }
    else {
        team1->m_key.m_points+=1;
        team2->m_key.m_points+=1;
    }

    team1->m_key.m_gamesPlayed++;
    team2->m_key.m_gamesPlayed++;

    return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_num_played_games(int playerId)
{
    if (playerId <= 0) {
        return StatusType::INVALID_INPUT;
    }

    Node<PlayerData>* player = findPlayer(playerId, m_playersAVLTree->getRoot());
    if (!player) {
        return StatusType::FAILURE;
    }

    int playerGames = player->getKey().getIndividualGamesPlayed();
    int teamGames = player->m_key.getPtrTeam()->getKey().getGames();

    return playerGames + teamGames;
}

output_t<int> world_cup_t::get_team_points(int teamId)
{
	if(teamId<=0){
        return StatusType::INVALID_INPUT;
    }
    Node<TeamData>* team = findTeam(teamId, m_teamsAVLTree->getRoot());
    if(!team){
        return StatusType::FAILURE;
    }
	return team->getKey().m_points;
}


//todo: check why ptr in end and start of teams' list not null

StatusType world_cup_t::unite_teams(int teamId1, int teamId2, int newTeamId)
{
    if (teamId1 <= 0 || teamId2 <= 0 || newTeamId <= 0 || teamId1 == teamId2) {
        return StatusType::INVALID_INPUT;
    }
    // creates object to find
    TeamData team1(teamId1, 0);
    // find the object
    Node<TeamData>* nodeTeam1 = m_teamsAVLTree->find(team1);
    if (nodeTeam1 == nullptr) {
        return StatusType::FAILURE;
    }

    TeamData team2(teamId2, 0);
    Node<TeamData>* nodeTeam2 = m_teamsAVLTree->find(team2);
    if (nodeTeam2 == nullptr) {
        return StatusType::FAILURE;
    }

    TeamData newTeam(newTeamId, 0);
    if (newTeamId != teamId1 || newTeamId != teamId2) {
        Node<TeamData>* nodeNewTeam = m_teamsAVLTree->find(newTeam);
        if (nodeNewTeam) {
            return StatusType::FAILURE;
        }
    }

    int newTeamPoints = nodeTeam1->getKey().getTeamPoints() + nodeTeam2->getKey().getTeamPoints();
    StatusType result = add_team(newTeamId, newTeamPoints);
    if (result != StatusType::SUCCESS) {
        return result;
    }
    Node<TeamData>* nodeNewTeam = m_teamsAVLTree->find(newTeam);

    int newTeamSize = nodeTeam1->getKey().getNumPlayers() + nodeTeam2->getKey().getNumPlayers();
    nodeNewTeam->m_key.setNumPlayers(newTeamSize);

    int newTeamGoalKeepers = nodeTeam1->getKey().getNumGoalKeepers() + nodeTeam2->getKey().getNumGoalKeepers();
    nodeNewTeam->m_key.setNumGoalKeepers(newTeamGoalKeepers);

    int newTeamGoals = nodeTeam1->getKey().getGoals() + nodeTeam2->getKey().getGoals();
    nodeNewTeam->m_key.setNumGoals(newTeamGoals);

    int newTeamCards = nodeTeam1->getKey().getCard() + nodeTeam2->getKey().getCard();
    nodeNewTeam->m_key.setNumCards(newTeamCards);

    LinkedList<RankPlayerData>* playersTeam1 = nodeTeam1->getKey().getPtrRankLinkedList();
    LinkedListNode<RankPlayerData>* playerTeam1 = playersTeam1->getStart()->getNext();
    int gamesPlayed = nodeTeam1->getKey().getGames();
    while (playerTeam1 != playersTeam1->getEnd()) {
        playerTeam1->getData().getPlayerPtr()->m_key.increaseIndividualGamesPlayer(gamesPlayed);
        playerTeam1->getData().getPlayerPtr()->m_key.setTeamID(newTeamId);
        playerTeam1->getData().getPlayerPtr()->m_key.setPtrTeam(nodeNewTeam);
    }
    playerTeam1 = nullptr;

    LinkedList<RankPlayerData>* playersTeam2 = nodeTeam2->getKey().getPtrRankLinkedList();
    LinkedListNode<RankPlayerData>* playerTeam2 = playersTeam2->getStart()->getNext();
    gamesPlayed = nodeTeam2->getKey().getGames();
    while (playerTeam2 != playersTeam2->getEnd()) {
        playerTeam2->getData().getPlayerPtr()->m_key.increaseIndividualGamesPlayer(gamesPlayed);
        playerTeam2->getData().getPlayerPtr()->m_key.setTeamID(newTeamId);
        playerTeam2->getData().getPlayerPtr()->m_key.setPtrTeam(nodeNewTeam);
    }
    playerTeam2 = nullptr;



    uniteLists(nodeTeam1->getKey().getPtrRankLinkedList()->getStart(),
               nodeTeam2->getKey().getPtrRankLinkedList()->getStart(),
               nodeNewTeam->getKey().getPtrRankLinkedList()->getStart(),
                nodeNewTeam->getKey().getPtrRankLinkedList()->getEnd());

    if (nodeNewTeam->getKey().getPtrRankLinkedList()->countNodes() != newTeamSize) {
        return StatusType::FAILURE;
    }

    RankPlayerData nullRank(-1, -1, -1, nullptr);
    buildEmptyTree(newTeamSize, nullRank, *nodeNewTeam->m_key.getPtrRankTree());
    updateEmptyTree(*nodeNewTeam->m_key.getPtrRankTree(), *nodeNewTeam->m_key.getPtrRankLinkedList());

    return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_top_scorer(int teamId)
{
	if(teamId==0){
        return StatusType::INVALID_INPUT;

    } else if(teamId < 0){
        // find the last node in all players' rank list
        LinkedListNode<RankPlayerData>* topScorer = m_allPlayersRankLinkedList->getEnd()->getPrevious();
        return topScorer->getData().getPlayerID();
    }

    Node<TeamData>* team = findTeam(teamId, m_teamsAVLTree->getRoot());
    if(!team || team->getKey().getNumPlayers() == 0){
        return StatusType::FAILURE;
    }

    // return top scorer of the team
    // find the last node in the team's rank list
   LinkedListNode<RankPlayerData>* teamTopScorer = team->getKey().getPtrRankLinkedList()->getEnd()->getPrevious();
   return teamTopScorer->getData().getPlayerID();

}

output_t<int> world_cup_t::get_all_players_count(int teamId)
{

    if(teamId == 0){
        return StatusType::INVALID_INPUT;
    }

    // return total num of players
    else if(teamId<0){
        return m_numOfPlayers;
    }

    // return num of players in team
    Node<TeamData>* team = findTeam(teamId, m_teamsAVLTree->getRoot());
    if(!team){
        return StatusType::FAILURE;
    }
    return team->getKey().getNumPlayers();

}

StatusType world_cup_t::get_all_players(int teamId, int *const output)
{

    if(!output || teamId == 0){
        return StatusType::INVALID_INPUT;
    }

    else if(teamId < 0){
        if(m_numOfPlayers == 0){
            return StatusType::FAILURE;
        }

    }

    else{
        Node<TeamData>* team = findTeam(teamId, m_teamsAVLTree->getRoot());
        if(!team || team->m_key.getNumPlayers() == 0){
            return StatusType::FAILURE;
        }

    }

	return StatusType::SUCCESS;
}


// todo: create function
void listToArr(LinkedList<RankPlayerData>* list, int *const output){

}

output_t<int> world_cup_t::get_closest_player(int playerId, int teamId)
{
	// TODO: Your code goes here
	return 1006;
}

output_t<int> world_cup_t::knockout_winner(int minTeamId, int maxTeamId)
{
	// TODO: Your code goes here
	return 2;
}

