
#include "worldcup23a1.h"
/*



int main () {
    world_cup_t wc1;
    StatusType result1 = wc1.add_team(1, 1000);
    StatusType result = wc1.add_player(1001, 1, 10, 0, 0, false);

    int x = 4;

    wc1.add_player(2009, 2, 20, 0, 0, false);
    wc1.add_player(2010, 2, 0, 0, 0, false);
    wc1.add_player(2011, 2, 20, 0, 0, false);
    wc1.add_player(3001, 3, 30, 0, 0, false);
    wc1.add_player(3002, 3, 30, 0, 0, false);
    wc1.add_player(3003, 3, 30, 0, 0, false);
    wc1.add_player(3004, 3, 30, 0, 0, false);
    wc1.add_player(3005, 3, 30, 2, 0, false);
    wc1.add_player(3006, 3, 30, 0, 0, false);
    wc1.add_player(3007, 3, 30, 0, 0, false);
    wc1.add_player(3008, 3, 30, 0, 0, false);
    wc1.add_player(3009, 3, 30, 0, 2, false);
    wc1.add_player(3010, 3, 30, 0, 0, true);
    wc1.add_player(3011, 3, 30, 0, 0, true);
    wc1.add_player(4001, 4, 2, 1, 2, false);
    wc1.add_player(4002, 4, 2, 2, 2, false);




    wc1.add_team(1, 10000);
    wc1.add_team(2, 20000);
    wc1.add_team(3, 30000);
    wc1.add_team(4, 40000);
    wc1.add_player(1001 ,1 ,10 ,0 ,0, false);
    wc1.add_player(1002, 1, 10, 0, 0, false);
    wc1.add_player(1003, 1, 10, 0, 0, false);
    wc1.add_player( 1004, 1, 10, 0 ,2, false);
    wc1.add_player( 1005, 1, 10, 0, 0, false);
    wc1.add_player( 1006 ,1 ,10, 4, 3, false);
    wc1.add_player( 1007 ,1 ,10, 0, 0 ,false);
    wc1.add_player( 1008 ,1, 10 ,0, 0, true);
    wc1.add_player( 1009 ,1, 10, 0 ,0 ,false);
    wc1.add_player( 1010 ,1 ,10 ,0 ,0, false);
    wc1.add_player( 1011 ,1 ,10, 0 ,0, false);
    wc1.add_player( 1012, 1 ,10, 0 ,0 ,false);
    wc1.add_player( 2001 ,2 ,20, 0 ,0, false);
    wc1.add_player( 2002 ,2 ,20, 0 ,0, false);
    wc1.add_player( 2003 ,2 ,20, 0 ,0, false);
    wc1.add_player( 2004 ,2 ,20, 0 ,0, false);
    wc1.add_player( 2005 ,2 ,20, 0 ,0, false);
    wc1.add_player( 2006 ,2 ,20, 0 ,0, false);
    wc1.add_player( 2007 ,2 ,20, 0 ,0, false);
    wc1.add_player( 2008 ,2, 20, 6, 4, true);
    wc1.add_player(2009, 2, 20, 0, 0, false);
    wc1.add_player(2010, 2, 0, 0, 0, false);
    wc1.add_player(2011, 2, 20, 0, 0, false);
    wc1.add_player(3001, 3, 30, 0, 0, false);
    wc1.add_player(3002, 3, 30, 0, 0, false);
    wc1.add_player(3003, 3, 30, 0, 0, false);
    wc1.add_player(3004, 3, 30, 0, 0, false);
    wc1.add_player(3005, 3, 30, 2, 0, false);
    wc1.add_player(3006, 3, 30, 0, 0, false);
    wc1.add_player(3007, 3, 30, 0, 0, false);
    wc1.add_player(3008, 3, 30, 0, 0, false);
    wc1.add_player(3009, 3, 30, 0, 2, false);
    wc1.add_player(3010, 3, 30, 0, 0, true);
    wc1.add_player(3011, 3, 30, 0, 0, true);
    wc1.add_player(4001, 4, 2, 1, 2, false);
    wc1.add_player(4002, 4, 2, 2, 2, false);
    wc1.remove_player(4001);
    wc1.remove_player(4002);
    wc1.remove_team(4);

    wc1.update_player_stats( 3011, 2 ,1 ,1);
//    wc1.play_match( 2, 3);
//    wc1.play_match (1 ,2);
//    wc1.get_num_played_games( 2003);
//    wc1.get_team_points (3);
    wc1.unite_teams (1, 2 , 2);
//    wc1.get_top_scorer (-1);
//    wc1.get_all_players_count( 3);
////    wc1.get_all_players (4);
//    wc1.get_closest_player (2008, 2);
//    wc1.knockout_winner (0 ,3);
//    wc1.remove_team (2);
//    wc1.remove_player (3008);


    int allPlayers[36];
    wc1.get_all_players(-1, allPlayers);

    return 0;
}*/






/*

#include "avlTree.h"


int main(){

    AvlTree<int> tree;

    tree.insert(3);
    tree.insert(5);
    tree.insert(6);
    tree.insert(8);
    tree.insert(7);
    tree.insert(10);
    tree.insert(2);
    tree.insert(4);


    Node<int>* node2 = tree.find(5);
    Node<int>* node1 = tree.find(7);


    //node1 - parent
    //node2 - son

    node1->switchCloseNodes(node2);
    if(tree.getRoot() == node1){
        tree.setRoot(node2);
    } else if(tree.getRoot() == node2){
        tree.setRoot(node1);
    }


    node1->switchNodes(node2);

    return 0;
}


*/

#include "worldcup23a1.h"

int main(){

    world_cup_t *obj = new world_cup_t();
    int playerId = 1;
    StatusType res;
    for (int teamId = 1; teamId < 10; teamId += 2)
    {
        res = obj->add_team(teamId, 1000 / ((6 - teamId) * (6 - teamId)));
//        REQUIRE(res == StatusType::SUCCESS);

        for (int startingId = playerId; playerId < startingId + 10 + teamId; ++playerId)
        {
            res = obj->add_player(playerId, teamId, 1, playerId, 3, true);
//            REQUIRE(res == StatusType::SUCCESS);
        }
        ++playerId;
    }
    // Strengths team1:73 team3:319 team5:1485 team7:1816 team9:1384

    res = obj->add_team(4, 1000000);
//    REQUIRE(res == StatusType::SUCCESS);

    output_t<int> res1 = obj->knockout_winner(8, 9);
//    REQUIRE(res1.status() == StatusType::SUCCESS);
//    REQUIRE(res1.ans() == 9);

    output_t<int> res2 = obj->knockout_winner(1, 1);
//    REQUIRE(res2.status() == StatusType::SUCCESS);
//    REQUIRE(res2.ans() == 1);

    output_t<int> res3 = obj->knockout_winner(2, 4);
//    REQUIRE(res3.status() == StatusType::SUCCESS);
//    REQUIRE(res3.ans() == 3);

    output_t<int> res4 = obj->knockout_winner(3, 9);
//    REQUIRE(res4.status() == StatusType::SUCCESS); // todo: problem here
//    REQUIRE(res4.ans() == 7);

    output_t<int> res5 = obj->knockout_winner(2, 8);
//    REQUIRE(res5.status() == StatusType::SUCCESS);
//    REQUIRE(res5.ans() == 7);

    output_t<int> res6 = obj->knockout_winner(0, 5);
//    REQUIRE(res6.status() == StatusType::SUCCESS);
//    REQUIRE(res6.ans() == 5);

    output_t<int> res7 = obj->knockout_winner(1, 9);
//    REQUIRE(res7.status() == StatusType::SUCCESS);
//    REQUIRE(res7.ans() == 7);

    res = obj->add_player(999, 3, 1, 3000, 200, false);
//    REQUIRE(res == StatusType::SUCCESS);
    // Strengths team1:73 team3:3119 team5:1485 team7:1816 team9:1384

    output_t<int> res8 = obj->knockout_winner(1, 999);
//    REQUIRE(res8.status() == StatusType::SUCCESS);
//    REQUIRE(res8.ans() == 7);

    res = obj->add_player(998, 3, 1, 2000, 0, false);
//    REQUIRE(res == StatusType::SUCCESS);
    // Strengths team1:73 team3: 5119 team5:1485 team7:1816 team9:1384

    output_t<int> res9 = obj->knockout_winner(0, 13);
//    REQUIRE(res9.status() == StatusType::SUCCESS);
//    REQUIRE(res9.ans() == 3);

    res = obj->add_player(997, 3, 1, 1, 5001, false);
//    REQUIRE(res == StatusType::SUCCESS);
    // Strengths team1:73 team3:119 team5:1485 team7:1816 team9:1384

    output_t<int> res9andahalf = obj->knockout_winner(0, 13);
//    REQUIRE(res9andahalf.status() == StatusType::SUCCESS);
//    REQUIRE(res9andahalf.ans() == 7);

    res = obj->update_player_stats(79, 1, 10000, 0);
//    REQUIRE(res == StatusType::SUCCESS);
    // Strengths team1:73 team3:119 team5:1485 team7:1816 team9:11384

    output_t<int> res10 = obj->knockout_winner(1, 9);
//    REQUIRE(res10.status() == StatusType::SUCCESS);

//    REQUIRE(res10.ans() == 9);

    delete obj;
    return 0;


}

