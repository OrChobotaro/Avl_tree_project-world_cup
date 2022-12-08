/*

#include "worldcup23a1.h"
*/
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
}*//*







*/
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
    world_cup_t wc = world_cup_t();
    wc.add_team(1,7277);
    wc.add_team(2,1895);
    wc.add_team(3,3560);
    wc.add_team(4,5071);
    wc.add_team(5,5402);
    wc.add_player(1,4,2020,690,8183,true);
    wc.add_player(2,4,6818,470,593,false);
    wc.add_player(3,2,1789,4025,7020,true);
    wc.add_player(4,5,5907,5576,5004,true);
    wc.add_player(5,4,5426,6988,3645,false);
    wc.add_player(6,3,2705,4044,5810,true);
    wc.add_player(7,1,12276,11256,6737,false);
    wc.add_player(8,1,930,459,8753,true);
    wc.add_player(9,4,10678,3337,2864,true);
    wc.add_player(10,5,1471,6424,4735,true);
    wc.add_player(11,5,7385,68,10873,true);
    wc.add_player(12,5,10896,7033,5250,true);
    wc.add_player(13,4,44,9948,10555,true);
    wc.add_player(14,5,5835,1680,11454,true);
    wc.add_player(15,4,9223,8053,6938,true);
    wc.add_player(16,5,3749,4987,2264,true);
    wc.add_player(17,2,5127,3462,3710,true);
    wc.add_player(18,2,3203,11584,98,false);
    wc.add_player(19,4,11920,407,6910,true);
    wc.add_player(20,3,7544,3892,8069,true);
    wc.add_player(21,3,10550,7617,6324,true);
    wc.add_player(22,3,2211,10797,1603,true);
    wc.add_player(23,3,1424,9016,5136,true);
    wc.add_player(24,3,1550,11130,3458,false);
    wc.add_player(25,4,4145,5426,11568,true);
    wc.add_player(26,2,10228,2145,9742,true);
    wc.add_player(27,3,8243,6452,7573,true);
    wc.add_player(28,4,9292,9624,4340,false);
    wc.add_player(29,5,6202,3761,5116,false);
    wc.add_player(30,4,7779,10448,1749,true);
    wc.add_player(31,3,11957,10061,132,false);
    wc.add_player(32,5,8194,11019,11039,true);
    wc.add_player(33,1,6124,1884,2449,true);
    wc.add_player(34,2,9270,11107,965,true);
    wc.add_player(35,3,8545,11370,1075,false);
    wc.add_player(36,4,8153,10868,2010,false);
    wc.add_player(37,5,1084,2253,9975,true);
    wc.add_player(38,1,6606,7024,11949,true);
    wc.add_player(39,3,6424,8498,6152,true);
    wc.add_player(40,1,11358,3503,11609,true);
    wc.add_team(3,12208);
    wc.get_team_points(2);
    wc.knockout_winner(1,3);
    wc.knockout_winner(-4,8);
    wc.knockout_winner(-4,-2);
    wc.knockout_winner(6,8);
    wc.knockout_winner(6,-2);
    wc.update_player_stats(19,495,3254,7461);
    wc.get_team_points(4);
    wc.update_player_stats(29,4042,4378,9598);
    wc.get_team_points(3);
    wc.get_all_players_count(1);

    wc.get_num_played_games(22);
    wc.get_top_scorer(3);
    wc.get_top_scorer(3);
    wc.add_team(1,3093);
    wc.unite_teams(2,4,5);
    wc.get_num_played_games(8);
    wc.update_player_stats(6,10341,8618,8506);
    wc.unite_teams(1,4,2);
    wc.get_all_players_count(4);
    wc.add_team(3,6338);
    wc.get_num_played_games(17);
    wc.get_num_played_games(32);
    wc.knockout_winner(5,5);
    wc.knockout_winner(0,10);
    wc.knockout_winner(0,0);
    wc.knockout_winner(10,10);
    wc.knockout_winner(10,0);
    wc.remove_player(15);
    wc.update_player_stats(27,11360,8919,423);
    wc.get_team_points(2);
    wc.unite_teams(4,4,5);
    wc.add_player(12,4,11308,11434,10959,true);
    wc.unite_teams(2,4,4);
    wc.play_match(3,4);
    wc.remove_player(1);
    wc.remove_player(2);
    wc.remove_player(3);
    wc.remove_player(4);
    wc.remove_player(5);
    wc.remove_player(6);
    wc.remove_player(7);
    wc.remove_player(8);
    wc.remove_player(9);
    wc.remove_player(10);
    wc.remove_player(11);
    wc.remove_player(12);
    wc.remove_player(13);
    wc.remove_player(14);
    wc.remove_player(16);
    wc.remove_player(17);
    wc.remove_player(18);
    wc.remove_player(19);
    wc.remove_player(20);
    wc.remove_player(21);
    wc.remove_player(22);
    wc.remove_player(23);
    wc.remove_player(24);
    wc.remove_player(25);
    wc.remove_player(26);
    wc.remove_player(27);
    wc.remove_player(28);
    wc.remove_player(29);
    wc.remove_player(30);
    wc.remove_player(31);
    wc.remove_player(32);
    wc.remove_player(33);
    wc.remove_player(34);
    wc.remove_player(35);
    wc.remove_player(36);
    wc.remove_player(37);
    wc.remove_player(38);
    wc.remove_player(39);
    wc.remove_player(40);
    wc.remove_team(1);
    wc.remove_team(3);
    wc.remove_team(5);
    wc.remove_team(4);
    return 0;


}

