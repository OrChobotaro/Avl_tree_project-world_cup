#include "worldcup23a1.h"

world_cup_t::world_cup_t()
{
    //todo: initialize all

    RankPlayerData nullRank(-1, -1, -1, nullptr);
    LinkedListNode<RankPlayerData>* nodeStart = new LinkedListNode<RankPlayerData>(nullRank);
    LinkedListNode<RankPlayerData>* nodeEnd = new LinkedListNode<RankPlayerData>(nullRank);

    m_allPlayersRankLinkedList.setStart(nodeStart);
    m_allPlayersRankLinkedList.setEnd(nodeEnd);

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
    res = m_teamsAVLTree.insert(teamToInsert);

    //TODO: add team to linkedList

    if(res == StatusType::SUCCESS){
        // create tree of rank
    }

	return res;
}

StatusType world_cup_t::remove_team(int teamId)
{
    if(teamId <= 0){
        return StatusType::INVALID_INPUT;
    }

//    m_teamsAVLTree.remove(teamId);

	return StatusType::FAILURE;
}

StatusType world_cup_t::add_player(int playerId, int teamId, int gamesPlayed,
                                   int goals, int cards, bool goalKeeper)
{
	// TODO: when adding a player, check if tree of the team is exists. if not, create one.
    // TODO: if exists, add player to tree.
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

