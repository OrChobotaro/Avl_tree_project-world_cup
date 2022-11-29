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


StatusType world_cup_t::add_player(int playerId, int teamId, int gamesPlayed,
                                   int goals, int cards, bool goalKeeper)
{

    // check if playerID invalid
    if(playerId<=0 || teamId<=0 || gamesPlayed<=0 || goals<0 || cards <0){
        return StatusType::INVALID_INPUT;
    }

    // create new player object
    PlayerData newPlayer(playerId, teamId, gamesPlayed, goals, cards, goalKeeper);


    // create team object to find
    TeamData teamToFind(teamId, 0);
    // find the team on teams' tree
    Node<TeamData>* teamNode = m_teamsAVLTree->find(teamToFind);

    if(!teamNode){ // find returns node if found and null if not
        return StatusType::FAILURE;
    }


    //subtract team games played from individual's.
    newPlayer.subtractIndividualGamesPlayed(teamNode->getKey().getGames());

    // add team to tree
    StatusType res = m_playersAVLTree->insert(newPlayer);


    if(res == StatusType::SUCCESS){
        // add 1 to num of players
        teamNode->getKey().increaseNumPlayers();

        // todo: update rest of the data



        //todo: add to all players rank tree
        // find the node in the players tree

        // create rank node
        RankPlayerData playerRank(playerId, goals, cards, m_playersAVLTree->find(newPlayer));
        // add to tree
        m_allPlayersRankTree->insert(playerRank);

        //todo: add to team rank tree


        try {
            // insert node to all players list
            LinkedListNode<RankPlayerData>* nodeToInsertAllPlayersList = new LinkedListNode<RankPlayerData>(playerRank);
            addToRankLinkedList(playerRank, m_allPlayersRankLinkedList.get(), m_allPlayersRankTree.get(), nodeToInsertAllPlayersList);
            m_allPlayersRankTree->find(playerRank)->m_key.setPtrRankPlayerList(nodeToInsertAllPlayersList);

            // insert node to team's list
//            LinkedListNode<RankPlayerData>* nodeToInsertTeamList = new LinkedListNode<RankPlayerData>(playerRank);
//            addToRankLinkedList(playerRank, teamNode->getKey().getPtrRankLinkedList(), teamNode->getKey().getPtrRankTree(), nodeToInsertTeamList);
//            m_allPlayersRankTree->find(playerRank)->m_key.setPtrRankPlayerTree(nodeToInsertTeamList);

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
//    else{
//        LinkedListNode<RankPlayerData>* parent = rankList->getStart();
//    }


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
	// TODO: Your code goes here
	return StatusType::SUCCESS;
}

StatusType world_cup_t::update_player_stats(int playerId, int gamesPlayed,
                                        int scoredGoals, int cardsReceived)
{
	// TODO: Your code goes here
	return StatusType::SUCCESS;
}

StatusType world_cup_t::play_match(int teamId1, int teamId2)
{
	// TODO: Your code goes here
	return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_num_played_games(int playerId)
{
	// TODO: Your code goes here
	return 22;
}

output_t<int> world_cup_t::get_team_points(int teamId)
{
	// TODO: Your code goes here
	return 30003;
}

StatusType world_cup_t::unite_teams(int teamId1, int teamId2, int newTeamId)
{
	// TODO: Your code goes here

	return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_top_scorer(int teamId)
{
	// TODO: Your code goes here
	return 2008;
}

output_t<int> world_cup_t::get_all_players_count(int teamId)
{
	// TODO: Your code goes here
    static int i = 0;
    return (i++==0) ? 11 : 2;
}

StatusType world_cup_t::get_all_players(int teamId, int *const output)
{
	// TODO: Your code goes here
    output[0] = 4001;
    output[1] = 4002;
	return StatusType::SUCCESS;
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

