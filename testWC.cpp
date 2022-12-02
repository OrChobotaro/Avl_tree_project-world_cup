#include <iostream>
using namespace std;

#define RUN_TEST(test) \
do { \
  cout << "     Running " << #test << "... "; \
  if (test()) { \
    cout << "[OK]"; \
  }                    \
    else { \
    cout << "[Error]"; \
  } \
  cout << endl; \
} while(0)


//#define RUN_TEST_GROUP(test) \
//cout << "Running Test Group " << #test << "..." << endl; \
//test()


#include "worldcup23a1.h"


bool test_add_team_valid(){
    world_cup_t wc;
    StatusType s1 = wc.add_team(7, 20);
    StatusType s2 = wc.add_team(6, 45);
    StatusType s3 = wc.add_team(80, 15);
    StatusType s4 = wc.add_team(66, 85);
    numOfNodes(wc.m_teamsAVLTree->getRoot());
    return s1 == StatusType::SUCCESS &&
            s2 == StatusType::SUCCESS &&
            s3 == StatusType::SUCCESS &&
            s4 == StatusType::SUCCESS && wc.m_teamsAVLTree->getHeight() == 2 && numOfNodes(wc.m_teamsAVLTree->getRoot()) == 4;
}


bool test_add_existing_team(){
    world_cup_t wc;
    StatusType s1 = wc.add_team(7, 20);
    StatusType s2 = wc.add_team(7, 45);
    return s1 == StatusType::SUCCESS &&
           s2 == StatusType::FAILURE &&
           wc.m_teamsAVLTree->getHeight() == 0 && numOfNodes(wc.m_teamsAVLTree->getRoot()) == 1;
}

bool test_add_invalid_team(){
    world_cup_t wc;
    StatusType s1 = wc.add_team(7, 20);
    StatusType s2 = wc.add_team(-3, 45);
    StatusType s3 = wc.add_team(8, 20);
    StatusType s4 = wc.add_team(50, -20);
    StatusType s5 = wc.add_team(-50, -20);
    return s1 == StatusType::SUCCESS &&
           s2 == StatusType::INVALID_INPUT &&
           s3 == StatusType::SUCCESS &&
           s4 == StatusType::INVALID_INPUT &&
            s5 == StatusType::INVALID_INPUT &&
           wc.m_teamsAVLTree->getHeight() == 1 && numOfNodes(wc.m_teamsAVLTree->getRoot()) == 2;
}

bool remove_last_existing_team(){
    world_cup_t wc;
    StatusType s1 = wc.add_team(7, 20);
    StatusType s2 = wc.remove_team(7);
    return s1 == StatusType::SUCCESS && s2==StatusType::SUCCESS &&
            wc.m_teamsAVLTree->getHeight() == -1 && numOfNodes(wc.m_teamsAVLTree->getRoot()) == 0 &&
            wc.m_teamsAVLTree->getRoot() == nullptr;
}

bool remove_leaf_existing_team(){
    world_cup_t wc;
    StatusType s1 = wc.add_team(7, 20);
    StatusType s2 = wc.add_team(8, 20);
    StatusType s3 = wc.add_team(9, 20);
    StatusType s4 = wc.remove_team(7);
    return s1 == StatusType::SUCCESS && s2==StatusType::SUCCESS && s3 == StatusType::SUCCESS && s4==StatusType::SUCCESS &&
           wc.m_teamsAVLTree->getHeight() == 1 && numOfNodes(wc.m_teamsAVLTree->getRoot()) == 2;
}

bool remove_root_existing_team(){
    world_cup_t wc;
    StatusType s1 = wc.add_team(7, 20);
    StatusType s2 = wc.add_team(8, 20);
    StatusType s3 = wc.add_team(9, 20);
    StatusType s4 = wc.remove_team(8);
    return s1 == StatusType::SUCCESS && s2==StatusType::SUCCESS && s3 == StatusType::SUCCESS && s4==StatusType::SUCCESS &&
           wc.m_teamsAVLTree->getHeight() == 1 && numOfNodes(wc.m_teamsAVLTree->getRoot()) == 2;
}

bool test_add_player(){
    world_cup_t wc;
    StatusType s0 = wc.add_team(5, 70);
    StatusType s1 = wc.add_player(8, 5, 6, 7, 5, false);
    StatusType s2 = wc.add_player(6, 5, 7, 7, 1, true);
    StatusType s3 = wc.add_player(9, 5, 6, 9, 5, false);
    return s0 == StatusType::SUCCESS && s1 == StatusType::SUCCESS && s2 == StatusType::SUCCESS && s3 == StatusType::SUCCESS &&
        wc.m_playersAVLTree->getHeight() == 1 && numOfNodes(wc.m_playersAVLTree->getRoot()) == 3 && wc.m_allPlayersRankTree->getHeight() == 1 &&
        numOfNodes(wc.m_allPlayersRankTree->getRoot()) == 3 && wc.m_allPlayersRankLinkedList.get()->countNodes() == 3 &&
        findTeam(5, wc.m_teamsAVLTree->getRoot())->getKey().getNumGoalKeepers() == 1;
}

bool test_add_player_till_valid_team(){
    world_cup_t wc;
    StatusType s0 = wc.add_team(5, 70);
    StatusType s1 = wc.add_player(8, 5, 6, 7, 5, false);
    StatusType s2 = wc.add_player(6, 5, 7, 7, 1, true);
    StatusType s3 = wc.add_player(9, 5, 6, 9, 5, false);
    StatusType s4 = wc.add_player(1, 5, 7, 7, 1, true);
    StatusType s5 = wc.add_player(2, 5, 6, 9, 5, false);
    StatusType s6 = wc.add_player(7, 5, 7, 7, 1, true);
    StatusType s7 = wc.add_player(10, 5, 6, 9, 5, false);
    StatusType s8 = wc.add_player(15, 5, 7, 7, 1, true);
    StatusType s9 = wc.add_player(25, 5, 6, 9, 5, false);
    StatusType s10 = wc.add_player(16, 5, 7, 7, 1, true);
    StatusType s11 = wc.add_player(26, 5, 6, 9, 5, false);
    return s0 == StatusType::SUCCESS && s1 == StatusType::SUCCESS && s2 == StatusType::SUCCESS && s3 == StatusType::SUCCESS
/*&&
           wc.m_playersAVLTree->getHeight() == 1*/
 && numOfNodes(wc.m_playersAVLTree->getRoot()) == 11
/*&& wc.m_allPlayersRankTree->getHeight() == 1*/
 &&
           numOfNodes(wc.m_allPlayersRankTree->getRoot()) == 11 && wc.m_allPlayersRankLinkedList.get()->countNodes() == 11 &&
           findTeam(5, wc.m_teamsAVLTree->getRoot())->getKey().getNumGoalKeepers() == 5 && numOfNodes(wc.m_validTeams->getRoot()) == 1;
}


bool test_add_2_players_with_same_id_diff_teams(){
    world_cup_t wc;
    StatusType s0 = wc.add_team(5, 70);
    StatusType s1 = wc.add_team(6, 70);
    StatusType s4 = wc.add_player(8, 6, 6, 7, 5, false);
    StatusType s2 = wc.add_player(8, 5, 7, 7, 1, true);
    return s0 == StatusType::SUCCESS && s1 == StatusType::SUCCESS && s2 == StatusType::FAILURE && s4 == StatusType::SUCCESS &&
           wc.m_playersAVLTree->getHeight() == 0 && numOfNodes(wc.m_playersAVLTree->getRoot()) == 1 && wc.m_allPlayersRankTree->getHeight() == 0 &&
           numOfNodes(wc.m_allPlayersRankTree->getRoot()) == 1 && wc.m_allPlayersRankLinkedList.get()->countNodes() == 1 &&
           findTeam(5, wc.m_teamsAVLTree->getRoot())->getKey().getNumGoalKeepers() == 0 && numOfNodes(findTeam(6, wc.m_teamsAVLTree->getRoot())->m_key.getPtrIDTree()->getRoot())== 1;
}


bool test_remove_player(){
    world_cup_t wc;
    StatusType s0 = wc.add_team(57, 70);
    StatusType s1 = wc.add_player(1, 57, 3,3,3,true);
    StatusType s2 = wc.add_player(2, 57, 3,3,3,true);

    StatusType s3 = wc.remove_player(2);

    return s3 == StatusType::SUCCESS && wc.m_playersAVLTree->getHeight() == 0 && wc.m_playersAVLTree->getHeight() == 0 &&
            numOfNodes(wc.m_teamsAVLTree->getRoot()) == 1 && numOfNodes(wc.m_playersAVLTree->getRoot()) == 1 && wc.m_allPlayersRankLinkedList->countNodes() == 1
            && findTeam(57, wc.m_teamsAVLTree->getRoot())->m_key.getPtrRankLinkedList()->countNodes() == 1;
}

bool test_remove_from_valid_teams(){
    world_cup_t wc;
    StatusType s0 = wc.add_team(5, 70);
    StatusType s1 = wc.add_player(8, 5, 6, 7, 5, false);
    StatusType s2 = wc.add_player(6, 5, 7, 7, 1, true);
    StatusType s3 = wc.add_player(9, 5, 6, 9, 5, false);
    StatusType s4 = wc.add_player(1, 5, 7, 7, 1, true);
    StatusType s5 = wc.add_player(2, 5, 6, 9, 5, false);
    StatusType s6 = wc.add_player(7, 5, 7, 7, 1, true);
    StatusType s7 = wc.add_player(10, 5, 6, 9, 5, false);
    StatusType s8 = wc.add_player(15, 5, 7, 7, 1, true);
    StatusType s9 = wc.add_player(25, 5, 6, 9, 5, false);
    StatusType s10 = wc.add_player(16, 5, 7, 7, 1, true);
    StatusType s11 = wc.add_player(26, 5, 6, 9, 5, false);

    StatusType s12 = wc.remove_player(9);

    return s12== StatusType::SUCCESS && numOfNodes(wc.m_validTeams->getRoot()) == 0 && wc.m_validTeams->getHeight() == -1;
}

bool test_remove_2_times_same_player(){
    world_cup_t wc;
    StatusType s0 = wc.add_team(5, 70);
    StatusType s1 = wc.add_player(9, 5, 6, 7, 5, false);
    StatusType s2 = wc.add_player(6, 5, 7, 7, 1, true);

    StatusType s12 = wc.remove_player(9);
    StatusType s13 = wc.remove_player(9);

    return s12 == StatusType::SUCCESS && s13 == StatusType::FAILURE && wc.m_playersAVLTree->getHeight() == 0
    && numOfNodes(wc.m_playersAVLTree->getRoot()) == 1 && numOfNodes(findTeam(5,wc.m_teamsAVLTree->getRoot())) == 1;
}




int main2() {
    RUN_TEST(test_add_team_valid);
    RUN_TEST(test_add_existing_team);
    RUN_TEST(test_add_invalid_team);
    RUN_TEST(remove_last_existing_team);
    RUN_TEST(remove_leaf_existing_team);
    RUN_TEST(remove_root_existing_team);
    RUN_TEST(test_add_player);
    RUN_TEST(test_add_player_till_valid_team);
    RUN_TEST(test_add_2_players_with_same_id_diff_teams);
    RUN_TEST(test_remove_player);
    RUN_TEST(test_remove_from_valid_teams);
    RUN_TEST(test_remove_2_times_same_player);
    return 0;
}
