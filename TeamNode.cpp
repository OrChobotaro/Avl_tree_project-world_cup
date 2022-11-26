#include "TeamNode.h"

TeamNode::TeamNode(int teamID, int points) :
        Node<int>(teamID), m_points(points), m_numPlayers(0), m_numGoalKeepers(0), m_goals(0), m_cards(0),
        m_gamesPlayed(0) {}
//todo: add to initialization list highestRankPlayer, ptr to linked list
