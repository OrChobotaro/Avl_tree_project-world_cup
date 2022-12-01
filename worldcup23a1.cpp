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
            //LinkedListNode<RankPlayerData>* nodeToInsertAllPlayersList = new LinkedListNode<RankPlayerData>
                    (playerRank);
            LinkedListNode<RankPlayerData>* nodeToInsertAllPlayersList = addToRankLinkedList(playerRank, m_allPlayersRankLinkedList.get(),
                                                           m_allPlayersRankTree.get());
            LinkedListNode<RankPlayerData>* nodeToInsertTeamList = addToRankLinkedList(playerRank, teamNode->getKey().getPtrRankLinkedList(),
                                                                                       teamNode->getKey().getPtrRankTree());
            // add to all players tree
            m_allPlayersRankTree->insert(playerRank);

            //add to team rank tree
            teamNode->m_key.getPtrRankTree()->insert(playerRank);
            m_allPlayersRankTree->find(playerRank)->m_key.setPtrRankPlayerList(nodeToInsertAllPlayersList);



            // insert node to team's list
            //LinkedListNode<RankPlayerData>* nodeToInsertTeamList = new LinkedListNode<RankPlayerData>(playerRank);

            teamNode->getKey().getPtrRankTree()->find(playerRank)->m_key.setPtrRankPlayerList(nodeToInsertTeamList);

        }
        catch(std::bad_alloc& e){

            //todo: reverse all actions if fails

            return StatusType::ALLOCATION_ERROR;
        }

    }

    return res;
}


LinkedListNode<RankPlayerData>* world_cup_t::addToRankLinkedList(const RankPlayerData& playerRank, LinkedList<RankPlayerData>* rankList,
                                   AvlTree<RankPlayerData>* rankTree) {
    LinkedListNode<RankPlayerData>* nodeToInsert = new LinkedListNode<RankPlayerData>(playerRank);
    //find the node and check if player is left son or right
    bool isPlayerLeft = false;
    Node<RankPlayerData>* rankNode = rankTree->find(playerRank);
    Node<RankPlayerData>* parent = rankTree->find(playerRank);


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

    return nodeToInsert;
}


StatusType world_cup_t::remove_player(int playerId)
{

    Node<PlayerData>* playerToRemove = findPlayer(playerId, m_playersAVLTree->getRoot());
    Node<TeamData>* playerTeam = playerToRemove->getKey().getPtrTeam();
    RankPlayerData rankPlayer = playerToRemove->getKey().getPtrRankTeamPlayerTree()->getKey();

    LinkedListNode<RankPlayerData>* nodeToDeleteLinkedListTeam = playerToRemove->getKey().getPtrRankTeamPlayerTree()
            ->getKey().getPtrRankPlayerList();
    playerToRemove->getKey().getPtrRankTeamPlayerTree()->m_key.setPtrRankPlayerList(nullptr);
    playerTeam->getKey().getPtrRankLinkedList()->deleteNode(nodeToDeleteLinkedListTeam);

    Node<RankPlayerData>* nodeToDeleteRankTreeTeam = playerToRemove->getKey().getPtrRankTeamPlayerTree();
    playerToRemove->m_key.setPtrRankTeamPlayerTree(nullptr);
    playerTeam->getKey().getPtrRankTree()->remove(rankPlayer);

    LinkedListNode<RankPlayerData>* nodeToDeleteLinkedListAllPlayers = playerToRemove->getKey()
            .getPtrRankAllPlayersTree()->getKey().getPtrRankPlayerList();
    playerToRemove->getKey().getPtrRankAllPlayersTree()->m_key.setPtrRankPlayerList(nullptr);
    m_allPlayersRankLinkedList->deleteNode(nodeToDeleteLinkedListAllPlayers);

    Node<RankPlayerData>* nodeToDeleteRankTreeAllPlayers = playerToRemove->getKey().getPtrRankAllPlayersTree();
    playerToRemove->m_key.setPtrRankAllPlayersTree(nullptr);
    m_allPlayersRankTree->remove(rankPlayer);

    int newNumGoals = playerTeam->getKey().getGoals() - playerToRemove->getKey().getGoals();
    playerTeam->m_key.setNumGoals(newNumGoals);

    int newNumCards = playerTeam->getKey().getCard() - playerToRemove->getKey().getCards();
    playerTeam->m_key.setNumCards(newNumCards);

    int newNumPlayersInTeam = playerTeam->getKey().getNumPlayers() - 1;
    playerTeam->m_key.setNumPlayers(newNumPlayersInTeam);

    int newNumGoalKeepers = playerTeam->getKey().getNumGoalKeepers() - playerToRemove->getKey().isGoalKeeper();
    playerTeam->m_key.setNumGoals(newNumGoalKeepers);

    m_numOfPlayers += 1;




/*	//find player in players' tree
    Node<PlayerData>* playerToRemove = findPlayer(playerId, m_playersAVLTree->getRoot());

    if(!playerToRemove){
        return StatusType::FAILURE;
    }

    //find team in from pointer in player
    Node<TeamData>* teamOfPlayer = playerToRemove->m_key.getPtrTeam();

    //decrease number of goalkeepers
    if(playerToRemove->m_key.isGoalKeeper()){
        teamOfPlayer->m_key.decreaseGoalKeeper();
    }

    //decrease number of card
    teamOfPlayer->m_key.subtractCards(playerToRemove->getKey().getCards());

    //decrease number of goals
    teamOfPlayer->m_key.subtractGoals(playerToRemove->getKey().getGoals());

    //remove player from team's rank tree
    //todo: save linked list node address and assign to null before deleting
    RankPlayerData rankPlayerToRemove(playerId, 0, 0, nullptr);
    teamOfPlayer->m_key.m_ptrRankTree->remove(rankPlayerToRemove);*/

    //remove player from team's rank list

    //remove player from all rank tree

    //remove player from all rank list

    //remove player from all players tree

    //check if team still valid, if not - remove

    //is success, remove 1 from total players

    //todo: if not success, reverse all (keep the data of the player and add it again)


	return StatusType::SUCCESS;
}



StatusType world_cup_t::update_player_stats(int playerId, int gamesPlayed, int scoredGoals, int cardsReceived)
{
    if (playerId <= 0 || gamesPlayed < 0 || scoredGoals < 0 || cardsReceived < 0) {
        return StatusType::INVALID_INPUT;
    }
    Node<PlayerData>* playerNode = findPlayer(playerId, m_playersAVLTree->getRoot());
    Node<TeamData>* teamNode = findTeam(playerNode->getKey().getTeamID(), m_teamsAVLTree->getRoot());
    RankPlayerData oldRankPlayerData = playerNode->getKey().getPtrRankTeamPlayerTree()->getKey();
    int oldIndividualGames = playerNode->getKey().getIndividualGamesPlayed();

    teamNode->getKey().getPtrRankTree()->remove(oldRankPlayerData);
    m_allPlayersRankTree->remove(oldRankPlayerData);
    teamNode->getKey().getPtrRankLinkedList()->deleteNode(playerNode->m_key.getPtrRankTeamPlayerTree()->getKey()
    .getPtrRankPlayerList());
    m_allPlayersRankLinkedList->deleteNode(playerNode->m_key.getPtrRankAllPlayersTree()->getKey()
    .getPtrRankPlayerList());



    int newGamesPlayed = oldIndividualGames + gamesPlayed;
    playerNode->m_key.setIndividualGamesPlayed(newGamesPlayed);
    int newGoals = oldRankPlayerData.getGoals() + scoredGoals;
    playerNode->m_key.setGoals(newGoals);
    int newCards = oldRankPlayerData.getCards() + cardsReceived;
    playerNode->m_key.setCards(newCards);

    RankPlayerData newRankData(playerId, newGoals, newCards, oldRankPlayerData.getPlayerPtr());

    try {
        teamNode->m_key.getPtrRankTree()->insert(newRankData);
        Node<RankPlayerData>* newNodeTeamTree = teamNode->m_key.getPtrRankTree()->find(newRankData);
        playerNode->m_key.setPtrRankTeamPlayerTree(newNodeTeamTree);

        m_allPlayersRankTree->insert(newRankData);
        Node<RankPlayerData>* newNodeAllPlayersTree = m_allPlayersRankTree->find(newRankData);
        playerNode->m_key.setPtrRankAllPlayersTree(newNodeAllPlayersTree);


        LinkedListNode<RankPlayerData>* newNodeTeamList = addToRankLinkedList(newRankData, teamNode->getKey()
        .getPtrRankLinkedList(), teamNode->getKey().getPtrRankTree());
        LinkedListNode<RankPlayerData>* newNodeAllPlayersList = addToRankLinkedList(newRankData, teamNode->getKey()
        .getPtrRankLinkedList(), teamNode->getKey().getPtrRankTree());

        newNodeTeamTree->m_key.setPtrRankPlayerList(newNodeTeamList);
        newNodeAllPlayersTree->m_key.setPtrRankPlayerList(newNodeAllPlayersList);

        newNodeTeamList->m_data.setPtrRankPlayerTree(newNodeTeamTree);
        newNodeAllPlayersList->m_data.setPtrRankPlayerTree(newNodeAllPlayersTree);
    }
    catch (const std::bad_alloc& e) {
        ////////////////////////////todo
        return StatusType::FAILURE;
    }

    int newTotGoals = teamNode->getKey().getGoals() + scoredGoals;
    teamNode->m_key.setNumGoals(newTotGoals);

    int newTotCards = teamNode->getKey().getCard() +cardsReceived;
    teamNode->m_key.setNumCards(newTotCards);

/*    RankPlayerData newRankDataForTeamTree(newRankData);
    newRankDataForTeamTree.setPtrRankPlayerList(playerNode->getKey().getPtrRankTeamPlayerTree()->getKey()
                                                        .getPtrRankPlayerList());

    RankPlayerData newRankDataForAllPlayersTree(newRankData);
    newRankDataForAllPlayersTree.setPtrRankPlayerList(playerNode->getKey().getPtrRankAllPlayersTree()->getKey()
                                                              .getPtrRankPlayerList());

    RankPlayerData newRankDataForTeamLinkedList(newRankData);
    newRankDataForTeamLinkedList.setPtrRankPlayerTree(playerNode->get)*/

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
    Node<TeamData>* nodeTeam1 = findTeam(teamId1, m_teamsAVLTree->getRoot());
    if (nodeTeam1 == nullptr) {
        return StatusType::FAILURE;
    }

    Node<TeamData>* nodeTeam2 = findTeam(teamId2, m_teamsAVLTree->getRoot());
    if (nodeTeam2 == nullptr) {
        return StatusType::FAILURE;
    }

    if (newTeamId != teamId1 || newTeamId != teamId2) {
        Node<TeamData>* nodeNewTeam = findTeam(newTeamId, m_teamsAVLTree->getRoot());
        if (nodeNewTeam) {
            return StatusType::FAILURE;
        }
    }

    int newTeamPoints = nodeTeam1->getKey().getTeamPoints() + nodeTeam2->getKey().getTeamPoints();
    int newTeamSize = nodeTeam1->getKey().getNumPlayers() + nodeTeam2->getKey().getNumPlayers();
    int newTeamGoalKeepers = nodeTeam1->getKey().getNumGoalKeepers() + nodeTeam2->getKey().getNumGoalKeepers();
    int newTeamGoals = nodeTeam1->getKey().getGoals() + nodeTeam2->getKey().getGoals();
    int newTeamCards = nodeTeam1->getKey().getCard() + nodeTeam2->getKey().getCard();

    StatusType result = add_team(newTeamId, newTeamPoints);
    if (result != StatusType::SUCCESS) {
        return result;
    }

    Node<TeamData>* nodeNewTeam = findTeam(newTeamId, m_teamsAVLTree->getRoot());

    LinkedList<RankPlayerData>* playersTeam1 = nodeTeam1->getKey().getPtrRankLinkedList();
    LinkedListNode<RankPlayerData>* playerTeam1 = playersTeam1->getStart()->getNext();
    int gamesPlayed = nodeTeam1->getKey().getGames();
    while (playerTeam1 != playersTeam1->getEnd()) {
        playerTeam1->getData().getPlayerPtr()->m_key.increaseIndividualGamesPlayer(gamesPlayed);
        playerTeam1->getData().getPlayerPtr()->m_key.setTeamID(newTeamId);
        playerTeam1->getData().getPlayerPtr()->m_key.setPtrTeam(nodeNewTeam);
        playerTeam1 = playerTeam1->getNext();
    }
    playerTeam1 = nullptr;

    LinkedList<RankPlayerData>* playersTeam2 = nodeTeam2->getKey().getPtrRankLinkedList();
    LinkedListNode<RankPlayerData>* playerTeam2 = playersTeam2->getStart()->getNext();
    gamesPlayed = nodeTeam2->getKey().getGames();
    while (playerTeam2 != playersTeam2->getEnd()) {
        playerTeam2->getData().getPlayerPtr()->m_key.increaseIndividualGamesPlayer(gamesPlayed);
        playerTeam2->getData().getPlayerPtr()->m_key.setTeamID(newTeamId);
        playerTeam2->getData().getPlayerPtr()->m_key.setPtrTeam(nodeNewTeam);
        playerTeam2 = playerTeam2->getNext();
    }
    playerTeam2 = nullptr;


    uniteLists(nodeTeam1->getKey().getPtrRankLinkedList()->getStart(),
               nodeTeam2->getKey().getPtrRankLinkedList()->getStart(),
               nodeNewTeam->getKey().getPtrRankLinkedList()->getStart(),
                nodeNewTeam->getKey().getPtrRankLinkedList()->getEnd());


    nodeTeam1->m_key.setNumPlayers(0);
    nodeTeam2->m_key.setNumPlayers(0);

    ////////////////////////////////////todo: the tree & LinkedList are sharedPtr, suppose to be deleted
    nodeTeam1->m_key.setPtrRankTree(nullptr);
    nodeTeam2->m_key.setPtrRankTree(nullptr);
    nodeTeam1->m_key.setPtrRankList(nullptr);
    nodeTeam1->m_key.setPtrRankList(nullptr);

    StatusType removeTeam1 = remove_team(teamId1);
    StatusType removeTeam2 = remove_team(teamId2);
    if (removeTeam1 != StatusType::SUCCESS || removeTeam2 != StatusType::SUCCESS) {
        /////////// The UniteTeam suppose to split, and the players will return to their old teams
        /////////The Problem: we already merged the lists...
        return StatusType::FAILURE;
    }

    nodeNewTeam->m_key.setNumPlayers(newTeamSize);
    nodeNewTeam->m_key.setNumGoalKeepers(newTeamGoalKeepers);
    nodeNewTeam->m_key.setNumGoals(newTeamGoals);
    nodeNewTeam->m_key.setNumCards(newTeamCards);

    if (nodeNewTeam->getKey().getPtrRankLinkedList()->countNodes() != newTeamSize) {
        return StatusType::FAILURE;
    }

    RankPlayerData nullRank(-1, -1, -1, nullptr);
    try {
        buildEmptyTree(newTeamSize, nullRank, *nodeNewTeam->m_key.getPtrRankTree());
        updateEmptyTree(*nodeNewTeam->m_key.getPtrRankTree(), *nodeNewTeam->m_key.getPtrRankLinkedList());
    }
    catch (std::bad_alloc& e) {
        /////////// The UniteTeam suppose to split, and the players will return to their old teams
        /////////The Problem: we already merged the lists...
        return StatusType::ALLOCATION_ERROR;
    }

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

