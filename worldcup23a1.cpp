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

    // creating valid teams tree - team with 11 players including a goalkeeper.
    std::shared_ptr<AvlTree<ValidTeams>> validTeamsTree(new AvlTree<ValidTeams>);
    m_validTeams = validTeamsTree;

    // creating valid teams LinkedList - team with 11 players including a goalkeeper.
    std::shared_ptr<LinkedList<ValidTeams>> validTeamsList(new LinkedList<ValidTeams>);
    m_validTeamsLinkedList = validTeamsList;

    ValidTeams nullValidTeam(-1, nullptr);

    LinkedListNode<ValidTeams>* nodeStartValidTeams = new LinkedListNode<ValidTeams>(nullValidTeam);
    LinkedListNode<ValidTeams>* nodeEndValidTeams = new LinkedListNode<ValidTeams>(nullValidTeam);

    m_validTeamsLinkedList->setStart(nodeStartValidTeams);
    m_validTeamsLinkedList->setEnd(nodeEndValidTeams);

    nodeStartValidTeams->setNext(nodeEndValidTeams);
    nodeEndValidTeams->setPrevious(nodeStartValidTeams);


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



StatusType world_cup_t::add_team(int teamId, int points)
{

    if(teamId <= 0 || points <= 0)
        return StatusType::INVALID_INPUT;

    StatusType res;
	TeamData teamToInsert(teamId, points);
    res = m_teamsAVLTree->insert(teamToInsert);

    RankPlayerData nullRank(-1, -1, -1, nullptr);
    if(res == StatusType::SUCCESS){

        // creates linked list for ranking players in team
        std::shared_ptr<LinkedList<RankPlayerData>> newList(new LinkedList<RankPlayerData>(nullRank));
        m_teamsAVLTree->find(teamToInsert)->m_key.setPtrRankList(newList);

        // creates avl tree for ranking players in team
        std::shared_ptr<AvlTree<RankPlayerData>> newTree(new AvlTree<RankPlayerData>);
        m_teamsAVLTree->find(teamToInsert)->m_key.setPtrRankTree(newTree);

        // creates avl tree for saving the id of players
        std::shared_ptr<AvlTree<PlayerID>> newIDTree(new AvlTree<PlayerID>);
        m_teamsAVLTree->find(teamToInsert)->m_key.setPtrIDTree(newIDTree);
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


        teamNode->m_key.addGoals(goals);
        teamNode->m_key.addCards(cards);
        if(newPlayer.isGoalKeeper()){
            teamNode->m_key.increaseGoalKeeper();
        }


        // create playerID node
        PlayerID playerIDObj(playerId, m_playersAVLTree->find(newPlayer));
        teamNode->m_key.getPtrIDTree()->insert(playerIDObj);

        // create rank node
        RankPlayerData playerRank(playerId, goals, cards, m_playersAVLTree->find(newPlayer));


        try {
            // insert node to all players list
            LinkedListNode<RankPlayerData>* nodeToInsertAllPlayersList = addToRankLinkedList(playerRank,
                     m_allPlayersRankLinkedList.get(), m_allPlayersRankTree.get());

            // insert node to team's list
            LinkedListNode<RankPlayerData>* nodeToInsertTeamList = addToRankLinkedList(playerRank,
                       teamNode->getKey().getPtrRankLinkedList(), teamNode->getKey().getPtrRankTree());


            // add to all players tree
            m_allPlayersRankTree->insert(playerRank);
            // update rank node in player's node
            m_playersAVLTree->find(newPlayer)->m_key.m_PtrRankAllPlayersTree =  m_allPlayersRankTree->find(playerRank);

            //add to team rank tree
            teamNode->m_key.getPtrRankTree()->insert(playerRank);
            m_playersAVLTree->find(newPlayer)->m_key.m_PtrRankTeamPlayerTree = teamNode->getKey().getPtrRankTree()->find(playerRank);

            m_allPlayersRankTree->find(playerRank)->m_key.setPtrRankPlayerList(nodeToInsertAllPlayersList);
            teamNode->getKey().getPtrRankTree()->find(playerRank)->m_key.setPtrRankPlayerList(nodeToInsertTeamList);


            if(teamNode->getKey().getNumPlayers()==11 && teamNode->m_key.getNumGoalKeepers() > 0){
                ValidTeams validTeamObj(teamId, findTeam(teamId, m_teamsAVLTree->getRoot()));
                LinkedListNode<ValidTeams>* nodeToInsertValidTeamsList = addToValidTeamsLinkedList(validTeamObj,
                                                           m_validTeamsLinkedList.get(), m_validTeams.get());
                nodeToInsertValidTeamsList->m_data.setPtrLinkedList(nullptr);
                m_validTeams->insert(validTeamObj);
                Node<ValidTeams>* nodeToInsertValidTeamsTree = m_validTeams.get()->find(validTeamObj);
                nodeToInsertValidTeamsTree->m_key.setPtrLinkedList(nodeToInsertValidTeamsList);
            }
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
//    Node<RankPlayerData>* rankNode = rankTree->find(playerRank);
    Node<RankPlayerData>* parent = rankTree->findParentBeforeInsert(playerRank);


    if(parent) {
        if(parent->getKey() > playerRank){
            isPlayerLeft = true;
        }
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




LinkedListNode<ValidTeams>* world_cup_t::addToValidTeamsLinkedList(const ValidTeams& validTeamsKey, LinkedList<ValidTeams>* list,
                                                                 AvlTree<ValidTeams>* tree) {
    LinkedListNode<ValidTeams>* nodeToInsert = new LinkedListNode<ValidTeams>(validTeamsKey);
    //find the node and check if player is left son or right
    bool isPlayerLeft = false;
    Node<ValidTeams>* parent = tree->findParentBeforeInsert(validTeamsKey);


    if(parent) {
        if(parent->getKey() > validTeamsKey){
            isPlayerLeft = true;
        }
    }

    if(isPlayerLeft && parent) {
        list->insertBefore(parent->getKey().getPtrLinkedList(), nodeToInsert);
    }
    else if(!(isPlayerLeft) && parent){
        list->insertAfter(parent->getKey().getPtrLinkedList(), nodeToInsert);
    }
    else {
        list->insertAfter(list->getStart(), nodeToInsert);
    }

    return nodeToInsert;
}





StatusType world_cup_t::remove_player(int playerId)
{

    if(playerId <=0){
        return StatusType::INVALID_INPUT;
    }
    Node<PlayerData>* playerToRemove = findPlayer(playerId, m_playersAVLTree->getRoot());
    if(!playerToRemove){
        return StatusType::FAILURE;
    }
    Node<TeamData>* playerTeam = playerToRemove->getKey().getPtrTeam();
    RankPlayerData rankPlayer = playerToRemove->getKey().getPtrRankTeamPlayerTree()->getKey();

    LinkedListNode<RankPlayerData>* nodeToDeleteLinkedListTeam = playerToRemove->getKey().getPtrRankTeamPlayerTree()
            ->getKey().getPtrRankPlayerList();
    playerToRemove->getKey().getPtrRankTeamPlayerTree()->m_key.setPtrRankPlayerList(nullptr);
    playerTeam->getKey().getPtrRankLinkedList()->deleteNode(nodeToDeleteLinkedListTeam);

//    Node<RankPlayerData>* nodeToDeleteRankTreeTeam = playerToRemove->getKey().getPtrRankTeamPlayerTree();
    playerToRemove->m_key.setPtrRankTeamPlayerTree(nullptr);
    playerTeam->getKey().getPtrRankTree()->remove(rankPlayer);

    LinkedListNode<RankPlayerData>* nodeToDeleteLinkedListAllPlayers = playerToRemove->getKey()
            .getPtrRankAllPlayersTree()->getKey().getPtrRankPlayerList();
    playerToRemove->getKey().getPtrRankAllPlayersTree()->m_key.setPtrRankPlayerList(nullptr);
    m_allPlayersRankLinkedList->deleteNode(nodeToDeleteLinkedListAllPlayers);

//    Node<RankPlayerData>* nodeToDeleteRankTreeAllPlayers = playerToRemove->getKey().getPtrRankAllPlayersTree();
    playerToRemove->m_key.setPtrRankAllPlayersTree(nullptr);
    m_allPlayersRankTree->remove(rankPlayer);

    PlayerID playerID = findIDPlayerKey(playerId, playerTeam->getKey().getPtrIDTree()->getRoot());
    playerTeam->m_key.m_ptrIDTree->remove(playerID);


    int newNumGoals = playerTeam->getKey().getGoals() - playerToRemove->getKey().getGoals();
    playerTeam->m_key.setNumGoals(newNumGoals);

    int newNumCards = playerTeam->getKey().getCard() - playerToRemove->getKey().getCards();
    playerTeam->m_key.setNumCards(newNumCards);

    int newNumPlayersInTeam = playerTeam->getKey().getNumPlayers() - 1;
    playerTeam->m_key.setNumPlayers(newNumPlayersInTeam);

    int newNumGoalKeepers = playerTeam->getKey().getNumGoalKeepers() - playerToRemove->getKey().isGoalKeeper();
    playerTeam->m_key.setNumGoals(newNumGoalKeepers);

    m_numOfPlayers -= 1;

    // find the team on the valid team
    Node<ValidTeams>* team = findValidTeam(playerTeam->getKey().getTeamID(), m_validTeams.get()->getRoot());
    if(team){
        // if team exist in the valid teams tree, remove if not valid anymore.
        if (newNumPlayersInTeam < 11 || newNumGoalKeepers <= 0 ) {
            LinkedListNode<ValidTeams>* nodeToDeleteList = team->getKey().getPtrLinkedList();
            team->m_key.setPtrLinkedList(nullptr);
            team->m_key.setPtrTeamData(nullptr);
            m_validTeams->remove(team->getKey());

            nodeToDeleteList->m_data.setPtrTeamData(nullptr);
            m_validTeamsLinkedList->deleteNode(nodeToDeleteList);
            ///////todo:check that the TeamData doesn't have a PTR to ValidTeamPtr
        }
    }



    playerToRemove->m_key.setPtrTeam(nullptr);
    m_playersAVLTree->remove(findPlayerKey(playerId, m_playersAVLTree->getRoot()));




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


    LinkedListNode<RankPlayerData>* listTeamNode = playerNode->m_key.getPtrRankTeamPlayerTree()->getKey().getPtrRankPlayerList();
    LinkedList<RankPlayerData>* teamList = teamNode->getKey().getPtrRankLinkedList();

    teamNode->getKey().getPtrRankTree()->remove(oldRankPlayerData);
    LinkedListNode<RankPlayerData>* listNode = playerNode->m_key.getPtrRankAllPlayersTree()->getKey().getPtrRankPlayerList();
    m_allPlayersRankLinkedList->deleteNode(listNode);
    m_allPlayersRankTree->remove(oldRankPlayerData);
    teamList->deleteNode(listTeamNode);


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

    PlayerID nullPlayerID(-1, nullptr);
    std::shared_ptr<LinkedList<PlayerID>> listTeam1 = AVLTreeToLinkedListPlayerID(nodeTeam1->getKey().getPtrIDTree(),
                                                              nullPlayerID, nodeTeam1->getKey().getNumPlayers());
//    LinkedListNode<PlayerID>* startNodeList1 = listTeam1->getStart();
//    LinkedListNode<PlayerID>* endNodeList1 = listTeam1->getStart();
    std::shared_ptr<LinkedList<PlayerID>> listTeam2 = AVLTreeToLinkedListPlayerID(nodeTeam2->getKey().getPtrIDTree(),
                                                              nullPlayerID, nodeTeam2->getKey().getNumPlayers());
//    LinkedListNode<PlayerID>* startNodeList2 = listTeam2->getStart();
//    LinkedListNode<PlayerID>* endNodeList2 = listTeam2->getStart();

    std::shared_ptr<LinkedList<PlayerID>> listNewTeam(new LinkedList<PlayerID>);
    LinkedListNode<PlayerID>* nodeStart = new LinkedListNode<PlayerID>(nullPlayerID);
    LinkedListNode<PlayerID>* nodeEnd = new LinkedListNode<PlayerID>(nullPlayerID);
    nodeStart->setNext(nodeEnd);
    nodeEnd->setPrevious(nodeStart);
    listNewTeam->setStart(nodeStart);
    listNewTeam->setEnd(nodeEnd);


    uniteLists(listTeam1.get()->getStart(), listTeam2.get()->getStart(), nodeStart, nodeEnd);


    try {
        buildEmptyTreePlayerID(newTeamSize, nullPlayerID, *nodeNewTeam->m_key.getPtrIDTree());
        updateEmptyTreePlayerID(*nodeNewTeam->m_key.getPtrIDTree(), *listNewTeam.get());
    }
    catch (std::bad_alloc& e) {
        /////////// The UniteTeam suppose to split, and the players will return to their old teams
        /////////The Problem: we already merged the lists...
        return StatusType::ALLOCATION_ERROR;
    }


    nodeTeam1->m_key.setNumPlayers(0);
    nodeTeam2->m_key.setNumPlayers(0);

    ////////////////////////////////////todo: the tree & LinkedList are sharedPtr, suppose to be deleted
/*    nodeTeam1->m_key.setPtrRankTree(nullptr);
    nodeTeam2->m_key.setPtrRankTree(nullptr);
    nodeTeam1->m_key.setPtrRankList(nullptr);
    nodeTeam2->m_key.setPtrRankList(nullptr);
    nodeTeam1->m_key.setPtrIDTree(nullptr);
    nodeTeam2->m_key.setPtrIDTree(nullptr);*/

    StatusType removeTeam1 = remove_team(teamId1);
    StatusType removeTeam2 = remove_team(teamId2);
    if (removeTeam1 != StatusType::SUCCESS || removeTeam2 != StatusType::SUCCESS) {
        /////////// The UniteTeam suppose to split, and the players will return to their old teams
        /////////The Problem: we already merged the lists...
        return StatusType::FAILURE;
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
        listToArr(m_allPlayersRankLinkedList.get(), m_numOfPlayers, output);
    }

    else{
        Node<TeamData>* team = findTeam(teamId, m_teamsAVLTree->getRoot());
        if(!team || team->m_key.getNumPlayers() == 0){
            return StatusType::FAILURE;
        }
        LinkedList<RankPlayerData>* list = team->m_key.getPtrRankLinkedList();
        listToArr(list, team->m_key.getNumPlayers(), output);
    }

	return StatusType::SUCCESS;
}


// todo: create function
void world_cup_t::listToArr(LinkedList<RankPlayerData>* list, int size ,int *output){
    LinkedListNode<RankPlayerData>* node = list->getStart()->getNext();

    for(int i=0; i<size; i++){
        output[i] = node->m_data.getPlayerID();
        node = node->getNext();
    }
}

output_t<int> world_cup_t::get_closest_player(int playerId, int teamId)
{
    if(playerId <= 0 || teamId <= 0) {
        return StatusType::INVALID_INPUT;
    }

    Node<TeamData>* teamNode = findTeam(teamId, m_teamsAVLTree->getRoot());
    if (!teamNode) {
        return StatusType::FAILURE;
    }
    Node<PlayerID>* playerIDNode = findIDPlayer(playerId, teamNode->getKey().getPtrIDTree()->getRoot());
    if (!playerIDNode) {
        return StatusType::FAILURE;
    }

    Node<PlayerData>* playerNode = playerIDNode->getKey().getPtrPlayer();
    LinkedListNode<RankPlayerData>* playerLinkedList = playerNode->getKey().getPtrRankAllPlayersTree()->getKey().getPtrRankPlayerList();

    int playerGoals = playerLinkedList->getData().getGoals();
    int playerCards = playerLinkedList->getData().getCards();

    LinkedListNode<RankPlayerData>* playerBefore = playerLinkedList->getPrevious();
    int playerBeforeGoals = playerBefore->getData().getGoals();
    int playerBeforeCards = playerBefore->getData().getCards();
    int playerBeforeID = playerBefore->getData().getPlayerID();

    LinkedListNode<RankPlayerData>* playerAfter = playerLinkedList->getNext();
    int playerAfterGoals = playerAfter->getData().getGoals();
    int playerAfterCards = playerAfter->getData().getCards();
    int playerAfterID = playerAfter->getData().getPlayerID();

    if (playerBefore == m_allPlayersRankLinkedList->getStart() || playerAfter != m_allPlayersRankLinkedList->getEnd()) {
        return playerAfter->getData().getPlayerID();
    }
    else if (playerBefore != m_allPlayersRankLinkedList->getStart() || playerAfter ==
    m_allPlayersRankLinkedList->getEnd()) {
        return playerBefore->getData().getPlayerID();
    }

    if ((playerAfterGoals - playerGoals) > (playerGoals - playerBeforeGoals)) {
        return playerBefore->getData().getPlayerID();
    }
    else if ((playerAfterGoals - playerGoals) < (playerGoals - playerBeforeGoals)) {
        return playerAfter->getData().getPlayerID();
    }
    else {
        if ((playerAfterCards - playerCards) > (playerCards - playerBeforeCards)) {
            return playerBefore->getData().getPlayerID();
        }
        else if ((playerAfterCards - playerCards) < (playerCards - playerBeforeCards)) {
            return playerAfter->getData().getPlayerID();
        }
        else {
            if ((playerAfterID - playerId) > (playerId - playerBeforeID)) {
                return playerBefore->getData().getPlayerID();
            }
            else if ((playerAfterID - playerId) < (playerId - playerBeforeID)) {
                return playerAfter->getData().getPlayerID();
            }
            else {
                if (playerBeforeID < playerAfterID) {
                    return playerAfter->getData().getPlayerID();
                }
                else if (playerBeforeID > playerAfterID) {
                    return playerBefore->getData().getPlayerID();
                }
                else {
                    return StatusType::FAILURE;
                }
            }
        }
    }



	// TODO: Your code goes here
	return 1006;
}

output_t<int> world_cup_t::knockout_winner(int minTeamId, int maxTeamId)
{

    if(minTeamId < 0 || maxTeamId < 0 || maxTeamId<minTeamId){
        return StatusType::INVALID_INPUT;
    }
    ValidTeams minObjToSearch(minTeamId, nullptr);
    ValidTeams maxObjToSearch(maxTeamId, nullptr);

    LinkedListNode<ValidTeams>* minNode(nullptr);

    Node<ValidTeams>* tempNodeMin = m_validTeams->find(minObjToSearch);
    if(tempNodeMin){
        minNode = tempNodeMin->m_key.getPtrLinkedList();
    }
    else {
        Node<ValidTeams>* parentMinNode = m_validTeams->findParentBeforeInsert(minObjToSearch);
        if(parentMinNode->m_key.getTeamId() < minTeamId){
            // minNode == node after the parent
            minNode = parentMinNode->m_key.getPtrLinkedList()->getNext();
        } else {
            minNode = parentMinNode->m_key.getPtrLinkedList();
        }
    }

    LinkedListNode<ValidTeams>* maxNode(nullptr);
    Node<ValidTeams>* tempNodeMax = m_validTeams->find(maxObjToSearch);

    if(tempNodeMax){
        maxNode = tempNodeMax->m_key.getPtrLinkedList();
    }
    else {
        LinkedListNode<ValidTeams>* currTemp = minNode;

        while(currTemp->m_data.getTeamId() < maxTeamId && currTemp != m_validTeamsLinkedList->getEnd()){
            currTemp = currTemp->getNext();
        }
        maxNode = currTemp->getPrevious();
    }



    std::shared_ptr<LinkedList<ValidTeams>> knockoutList;

    LinkedListNode<ValidTeams>* temp = minNode;
    while(temp->getPrevious()!=maxNode){
        int points = temp->m_data.getPtrTeamData()->getKey().getTeamPoints();
        int goals = temp->m_data.getPtrTeamData()->getKey().getGoals();
        int cards = temp->m_data.getPtrTeamData()->getKey().getCard();

        int rank = points + goals - cards;

        temp->m_data.setTotalRank(rank);
        temp = temp->getNext();
    }


    try {
        knockoutList = copyList(minNode, maxNode);

    }     catch (std::bad_alloc& e){
    return StatusType::ALLOCATION_ERROR;
}

    if(knockoutList->countNodes() == 0){
        return StatusType::FAILURE;
    }


        LinkedListNode<ValidTeams>* endNode = knockoutList->getEnd();

        while(knockoutList->countNodes() > 1){
            LinkedListNode<ValidTeams>* currNode = knockoutList->getStart()->getNext();
            while(currNode!= endNode){
                if(currNode->getNext()->getData().getTeamId() == knockoutList->getEnd()->getData().getTeamId()){
                    break;
                }
                LinkedListNode<ValidTeams>* firstTeam = currNode;
                currNode = currNode->getNext();
                LinkedListNode<ValidTeams>* secondTeam = currNode;
                currNode = currNode->getNext();
                int firstTeamRank = firstTeam->getData().getTotalRank();
                int secondTeamRank = secondTeam->getData().getTotalRank();

                if(firstTeamRank > secondTeamRank){
                    firstTeam->m_data.setTotalRank(secondTeamRank);
                    firstTeam->m_data.setTotalRank(3);
                    m_validTeamsLinkedList->deleteNode(secondTeam);

                } else if (firstTeamRank < secondTeamRank){
                    secondTeam->m_data.setTotalRank(firstTeamRank);
                    secondTeam->m_data.setTotalRank(3);
                    m_validTeamsLinkedList->deleteNode(firstTeam);

                }else {
                    if(firstTeam->getData().getTeamId() > secondTeam->getData().getTeamId()){
                        firstTeam->m_data.setTotalRank(secondTeamRank);
                        firstTeam->m_data.setTotalRank(3);
                        m_validTeamsLinkedList->deleteNode(secondTeam);

                    } else {
                        secondTeam->m_data.setTotalRank(firstTeamRank);
                        secondTeam->m_data.setTotalRank(3);
                        m_validTeamsLinkedList->deleteNode(firstTeam);

                    }
                }
            }
        }

	return knockoutList->getStart()->getNext()->getData().getTeamId();
}


// check what happens if min == max
std::shared_ptr<LinkedList<ValidTeams>> world_cup_t::copyList(LinkedListNode<ValidTeams>* minNode, LinkedListNode<ValidTeams>* maxNode){
    LinkedListNode<ValidTeams>* currNodeOriginalList = minNode;

    // create new start and end nodes
    ValidTeams nullNode(-1, nullptr);
    LinkedListNode<ValidTeams>* newStart;
    LinkedListNode<ValidTeams>* newEnd;

    try{
        newStart = new LinkedListNode<ValidTeams>(nullNode);
        newEnd = new LinkedListNode<ValidTeams>(nullNode);

    } catch (std::bad_alloc& e){
        throw e;
    }

    // create copied list
    std::shared_ptr<LinkedList<ValidTeams>> knockOutList(new LinkedList<ValidTeams>);


    knockOutList->setStart(newStart);

    LinkedListNode<ValidTeams>* currNodeNewList = knockOutList->getStart();

    // coping ID, total rank, else nullptr.
    while(currNodeOriginalList->getPrevious() != maxNode){
        LinkedListNode<ValidTeams>* newNode;
        try{
            newNode = new LinkedListNode<ValidTeams>(nullNode);
        } catch(std::bad_alloc& e){
//            knockOutList->clearList(knockOutList->getStart(), currNodeNewList);
            knockOutList->setEnd(newEnd);
            currNodeNewList->setNext(newEnd);
            newEnd->setPrevious(currNodeNewList);
            throw e;
        }
        currNodeNewList->setNext(newNode);
        newNode->setPrevious(currNodeNewList);
        currNodeNewList = currNodeNewList->getNext();
        currNodeNewList->m_data.setTeamID(currNodeOriginalList->m_data.getTeamId());
        currNodeNewList->m_data.setTotalRank(currNodeOriginalList->m_data.getTotalRank());
        currNodeNewList->m_data.setPtrLinkedList(nullptr);
        // todo: update ptrRankTeam to null with setter
        currNodeOriginalList = currNodeOriginalList->getNext();
    }

    knockOutList->setEnd(newEnd);
    currNodeNewList->setNext(newEnd);
    newEnd->setPrevious(currNodeNewList);
    return knockOutList;
}


//void calcWinnerAux(Node<ValidTeams>* node, LinkedListNode<ValidTeams>** listNode){
//
//    if(node== nullptr){
//        return;
//    }
//
//    calcWinnerAux(node->getLeft(), listNode);
//
//    calcWinnerAux(node->getRight(), listNode);
//
//    if(node->isLeaf()){
//        node->m_key = (*listNode)->m_data;
//    }
//    else {
//        if(!node->getRight()){
//            node->m_key = node->getLeft()->m_key;
//        }
//        else if(!node->getLeft()) {
//            node->m_key = node->getRight()->m_key;
//        }
//        else {
//            if(node->getRight()->getKey().getTotalRank() > node->getLeft()->getKey().getTotalRank()){
//                node->m_key = node->getRight()->m_key;
//                node->m_key.setTotalRank(3);
//                node->m_key.setTotalRank(node->getLeft()->m_key.getTotalRank());
//            }
//        }
//    }
//}
