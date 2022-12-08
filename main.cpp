

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


*//*


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

*/


int main(){

    world_cup_t wc;
    wc.add_team(1,101);
    wc.add_team(2,991);
    wc.add_team(3,3958);
    wc.add_team(4,6421);
    wc.add_team(5,6511);
    wc.add_team(6,1990);
    wc.add_team(7,5245);
    wc.add_team(8,2689);
    wc.add_team(9,10645);
    wc.add_team(10,6329);
    wc.add_team(11,12243);
    wc.add_team(12,1180);
    wc.add_team(13,6735);
    wc.add_team(14,249);
    wc.add_team(15,11286);
    wc.add_team(16,3218);
    wc.add_team(17,2386);
    wc.add_team(18,8717);
    wc.add_team(19,8494);
    wc.add_team(20,11674);
    wc.add_player(1,8,9579,6918,10296,true);
    wc.add_player(2,10,10140,55,4715,true);
    wc.add_player(3,13,6771,9666,2950,true);
    wc.add_player(4,8,8984,2562,4447,true);
    wc.add_player(5,11,10176,7065,5960,false);
    wc.add_player(6,7,7991,11143,1272,false);
    wc.add_player(7,9,5420,1059,4053,true);
    wc.add_player(8,6,316,1351,7822,true);
    wc.add_player(9,5,3768,5407,1937,true);
    wc.add_player(10,10,4705,6048,5204,true);
    wc.add_player(11,6,1761,9451,10682,true);
    wc.add_player(12,7,2731,8675,7357,true);
    wc.add_player(13,8,5141,10407,620,true);
    wc.add_player(14,15,12143,4308,11045,false);
    wc.add_player(15,20,334,4118,396,true);
    wc.add_player(16,4,10842,5503,8630,true);
    wc.add_player(17,14,2779,6339,2884,true);
    wc.add_player(18,5,11686,5488,2794,true);
    wc.add_player(19,13,12009,4630,1078,true);
    wc.add_player(20,9,3727,611,10776,true);
    wc.add_player(21,17,10640,7547,11354,true);
    wc.add_player(22,14,3405,9037,9990,true);
    wc.add_player(23,14,11904,9693,10653,true);
    wc.add_player(24,17,903,7830,8414,true);
    wc.add_player(25,6,9699,3188,5866,false);
    wc.add_player(26,5,9203,5243,7335,false);
    wc.add_player(27,12,9267,2737,11421,true);
    wc.add_player(28,1,9579,2710,7124,true);
    wc.add_player(29,16,786,6060,215,true);
    wc.add_player(30,3,1494,1714,7811,true);
    wc.add_player(31,9,21,10437,8103,true);
    wc.add_player(32,19,5756,3999,10074,true);
    wc.add_player(33,16,9482,12145,9189,true);
    wc.add_player(34,15,3790,883,1942,true);
    wc.add_player(35,8,1507,8549,6292,true);
    wc.add_player(36,2,10234,2072,2645,false);
    wc.add_player(37,6,3996,2091,6871,true);
    wc.add_player(38,18,12345,9468,5644,false);
    wc.add_player(39,9,10679,4038,260,true);
    wc.add_player(40,20,4813,11646,11297,true);
    wc.add_player(41,14,9871,1271,5968,true);
    wc.add_player(42,19,9016,5716,1345,true);
    wc.add_player(43,18,6892,7735,12242,false);
    wc.add_player(44,4,3482,5803,10971,true);
    wc.add_player(45,19,18,4733,2520,true);
    wc.add_player(46,3,1692,8489,5828,false);
    wc.add_player(47,12,8058,29,9894,true);
    wc.add_player(48,8,2572,5175,11622,true);
    wc.add_player(49,11,9395,3565,7014,true);
    wc.add_player(50,18,11798,763,7082,false);
    wc.add_player(51,17,273,4648,3344,true);
    wc.add_player(52,20,1777,3010,7497,true);
    wc.add_player(53,20,9257,5986,10327,true);
    wc.add_player(54,1,2161,3103,553,true);
    wc.add_player(55,18,8184,6048,5633,true);
    wc.add_player(56,16,5228,2342,11572,true);
    wc.add_player(57,6,336,3687,6533,true);
    wc.add_player(58,17,5677,4189,5682,true);
    wc.add_player(59,10,9511,7427,5934,true);
    wc.add_player(60,5,177,8230,2975,false);
    wc.add_player(61,4,7365,7451,2397,true);
    wc.add_player(62,4,626,5832,4659,true);
    wc.add_player(63,14,3725,5238,5463,true);
    wc.add_player(64,5,7452,3811,11789,true);
    wc.add_player(65,19,797,11871,10439,true);
    wc.add_player(66,7,11877,11800,8734,true);
    wc.add_player(67,16,11554,4515,8927,false);
    wc.add_player(68,1,6936,6649,4466,true);
    wc.add_player(69,6,1100,10654,2705,true);
    wc.add_player(70,19,1915,4083,10503,true);
    wc.add_player(71,9,10088,12344,739,false);
    wc.add_player(72,1,12065,3282,5090,false);
    wc.add_player(73,8,3493,10140,7207,true);
    wc.add_player(74,15,11546,11034,7924,true);
    wc.add_player(75,12,5635,11039,9561,false);
    wc.add_player(76,5,3486,214,6105,true);
    wc.add_player(77,14,3154,2232,10348,true);
    wc.add_player(78,9,7855,6654,8432,true);
    wc.add_player(79,20,6648,2085,1961,true);
    wc.add_player(80,2,5101,12022,9696,true);
    wc.add_player(81,20,861,11564,7811,true);
    wc.add_player(82,15,3271,6215,10985,true);
    wc.add_player(83,1,11110,1283,3870,false);
    wc.add_player(84,3,2717,7203,10748,true);
    wc.add_player(85,11,7859,5091,7607,false);
    wc.add_player(86,9,3602,2782,9249,true);
    wc.add_player(87,11,7975,12225,3994,true);
    wc.add_player(88,16,3405,4476,3762,true);
    wc.add_player(89,7,5633,10287,5418,true);
    wc.add_player(90,3,10846,1080,4620,true);
    wc.add_player(91,9,597,360,9680,true);
    wc.add_player(92,11,6029,2978,5151,true);
    wc.add_player(93,8,3247,212,6439,true);
    wc.add_player(94,4,10904,743,2593,true);
    wc.add_player(95,17,4289,3549,8325,true);
    wc.add_player(96,9,10963,5421,7971,true);
    wc.add_player(97,5,12310,7935,7982,true);
    wc.add_player(98,16,2316,10898,2648,true);
    wc.add_player(99,15,1586,8062,2379,true);
    wc.add_player(100,5,533,12245,3533,true);
    wc.add_player(101,17,5125,4346,6503,true);
    wc.add_player(102,10,3564,2914,12059,true);
    wc.add_player(103,19,11459,10796,7058,false);
    wc.add_player(104,17,6499,9587,9194,true);
    wc.add_player(105,20,3335,9466,3266,true);
    wc.add_player(106,14,644,10198,4989,false);
    wc.add_player(107,17,11159,11769,457,true);
    wc.add_player(108,14,9255,8618,5874,true);
    wc.add_player(109,12,1381,9858,7041,true);
    wc.add_player(110,15,3782,3087,11790,true);
    wc.add_player(111,6,668,96,2174,false);
    wc.add_player(112,3,2799,4174,11453,true);
    wc.add_player(113,14,7453,12294,8443,true);
    wc.add_player(114,6,5979,5714,4211,true);
    wc.add_player(115,5,2816,1703,8134,false);
    wc.add_player(116,15,5419,3853,8793,true);
    wc.add_player(117,7,5471,3643,1191,true);
    wc.add_player(118,19,2617,11789,10915,true);
    wc.add_player(119,6,1187,8265,6400,true);
    wc.add_player(120,16,7177,7397,4545,true);
    wc.add_player(121,2,9794,2415,4800,true);
    wc.add_player(122,11,3657,1578,5969,true);
    wc.add_player(123,18,5078,4610,1604,true);
    wc.add_player(124,17,3175,4122,5075,true);
    wc.add_player(125,16,12187,2289,608,true);
    wc.add_player(126,3,12151,857,3924,true);
    wc.add_player(127,7,8235,6048,5408,true);
    wc.add_player(128,9,3153,3202,9200,true);
    wc.add_player(129,6,178,6634,12045,true);
    wc.add_player(130,7,9262,3418,4037,true);
    wc.add_player(131,17,4209,7859,11491,true);
    wc.add_player(132,16,1028,2283,6218,true);
    wc.add_player(133,8,7578,5873,5694,true);
    wc.add_player(134,18,8263,3272,1953,false);
    wc.add_player(135,19,292,10501,923,true);
    wc.add_player(136,20,937,10217,11086,true);
    wc.add_player(137,15,8417,2680,2861,true);
    wc.add_player(138,15,5380,10056,7864,true);
    wc.add_player(139,15,11725,4179,5159,false);
    wc.add_player(140,13,456,11542,1983,true);
    wc.add_player(141,15,7405,6545,11972,true);
    wc.add_player(142,10,9616,1500,3241,true);
    wc.add_player(143,16,7835,7005,3149,false);
    wc.add_player(144,20,12164,7795,6134,true);
    wc.add_player(145,5,3411,2092,1900,false);
    wc.add_player(146,10,6949,11358,9283,true);
    wc.add_player(147,15,9669,2560,2365,true);
    wc.add_player(148,10,9295,2343,10248,true);
    wc.add_player(149,18,322,1339,9033,true);
    wc.add_player(150,1,3029,10813,3448,true);
    wc.add_player(151,17,3582,7330,8601,true);
    wc.add_player(152,20,6348,10885,9058,true);
    wc.add_player(153,5,5582,1450,9115,true);
    wc.add_player(154,16,11752,12011,8707,true);
    wc.add_player(155,17,230,4456,3385,true);
    wc.add_player(156,10,7710,10589,11879,true);
    wc.add_player(157,5,10338,6381,9245,true);
    wc.add_player(158,14,9104,7300,9403,true);
    wc.add_player(159,8,2538,9171,10573,true);
    wc.add_player(160,11,10005,2402,7906,true);
    wc.add_player(161,1,6655,3840,10720,true);
    wc.add_player(162,5,11383,4170,6045,true);
    wc.add_player(163,15,6972,9713,5027,true);
    wc.add_player(164,8,1098,1818,1895,true);
    wc.add_player(165,1,9535,8577,1340,true);
    wc.add_player(166,12,4012,1175,514,true);
    wc.add_player(167,10,8995,5002,11994,true);
    wc.add_player(168,10,2816,2248,2994,true);
    wc.add_player(169,5,4004,8569,9795,true);
    wc.add_player(170,2,4278,10118,2433,true);
    wc.add_player(171,17,4361,9379,2012,true);
    wc.add_player(172,10,170,1497,4358,true);
    wc.add_player(173,1,6433,1897,5508,true);
    wc.add_player(174,11,736,11835,10152,false);
    wc.add_player(175,7,4396,2103,9687,true);
    wc.add_player(176,8,6762,6274,5767,true);
    wc.add_player(177,17,2267,7788,3270,true);
    wc.add_player(178,16,12297,3272,2446,true);
    wc.add_player(179,18,3299,5200,10524,true);
    wc.add_player(180,17,9673,6353,12287,true);
    wc.add_player(181,4,10261,8271,2544,true);
    wc.add_player(182,3,666,10634,7848,true);
    wc.add_player(183,20,6993,2679,6253,true);
    wc.add_player(184,16,6209,8910,9621,true);
    wc.add_player(185,4,9997,5290,2836,true);
    wc.add_player(186,10,1533,8330,7433,false);
    wc.add_player(187,13,12337,10009,7181,true);
    wc.add_player(188,15,5561,2410,10722,true);
    wc.add_player(189,6,1595,5494,301,true);
    wc.add_player(190,14,11165,9423,11408,true);
    wc.add_player(191,5,8172,2995,9194,true);
    wc.add_player(192,6,2471,5768,4540,false);
    wc.add_player(193,2,2087,8983,6655,true);
    wc.add_player(194,11,4474,5223,11866,true);
    wc.add_player(195,6,9138,1739,1506,true);
    wc.add_player(196,9,3838,797,6581,false);
    wc.add_player(197,10,994,5436,3601,true);
    wc.add_player(198,14,8724,6485,831,false);
    wc.add_player(199,1,9548,5363,4580,true);
    wc.add_player(200,1,4270,8856,7269,true);
    wc.remove_player(36);
    wc.get_num_played_games(35);
    wc.add_team(3,8930);
    wc.get_all_players_count(18);
    wc.add_team(6,10602);
    wc.remove_team(6);
    wc.get_closest_player(58,17);
    wc.add_team(6,2166);
    wc.remove_team(8);
    wc.update_player_stats(29,11662,4570,10202);
    wc.play_match(9,20);
    wc.add_team(17,9015);
    wc.get_top_scorer(15);
    wc.get_num_played_games(78);
    wc.unite_teams(4,18,14);
    wc.unite_teams(19,4,15);
    wc.knockout_winner(19,20);
    wc.knockout_winner(14,25);
    wc.knockout_winner(14,15);
    wc.knockout_winner(24,25);
    wc.knockout_winner(24,15);
//    wc.get_all_players(2);
    wc.unite_teams(6,19,11);
    wc.get_num_played_games(116);
    wc.update_player_stats(111,10984,7496,12251);
    wc.play_match(14,15);
    wc.unite_teams(17,17,1);
    wc.remove_team(10);
//    wc.get_all_players(8);
    wc.get_top_scorer(4);
    wc.get_closest_player(28,1);
    wc.knockout_winner(18,18);
    wc.knockout_winner(13,23);
    wc.knockout_winner(13,13);
    wc.knockout_winner(23,23);
    wc.knockout_winner(23,13);
    wc.play_match(17,19);
    wc.unite_teams(7,20,13);
    wc.knockout_winner(11,17);
    wc.knockout_winner(6,22);
    wc.knockout_winner(6,12);
    wc.knockout_winner(16,22);
    wc.knockout_winner(16,12);
    wc.update_player_stats(120,10162,2788,6189);
    wc.play_match(5,7);
    wc.get_top_scorer(14);
    wc.add_player(15,18,9450,12336,7858,true);
    wc.add_team(18,5500);
//    wc.get_all_players(9);
    wc.get_top_scorer(6);
    wc.remove_player(83);
    wc.play_match(1,12);
    wc.add_team(17,11178);
    wc.remove_player(19);
    wc.update_player_stats(12,8718,9564,5403);
    wc.add_team(2,8318);
    wc.add_player(30,1,9052,6981,3662,true);
    wc.add_player(91,13,6849,11458,9050,false);
    wc.update_player_stats(153,8518,4601,11088);
    wc.unite_teams(8,13,3);
//    wc.get_all_players(3);
    wc.unite_teams(19,13,3);
    wc.play_match(16,7);
    wc.update_player_stats(96,10252,6648,10244);
    wc.update_player_stats(87,2391,9716,4026);
    wc.remove_team(2);
    wc.get_num_played_games(34);
    wc.knockout_winner(14,19);
    wc.knockout_winner(9,24);
    wc.knockout_winner(9,14);
    wc.knockout_winner(19,24);
    wc.knockout_winner(19,14);
    wc.get_team_points(12);
    wc.remove_player(179);
    wc.knockout_winner(20,20);
    wc.knockout_winner(15,25);
    wc.knockout_winner(15,15);
    wc.knockout_winner(25,25);
    wc.knockout_winner(25,15);
    wc.add_team(1,9887);
    wc.get_closest_player(68,1);
    wc.get_top_scorer(11);
    wc.play_match(3,5);
    wc.update_player_stats(43,7395,5774,1782);
    wc.get_num_played_games(54);
    wc.knockout_winner(18,20);
    wc.knockout_winner(13,25);
    wc.knockout_winner(13,15);
    wc.knockout_winner(23,25);
    wc.knockout_winner(23,15);
    wc.get_team_points(1);
    wc.unite_teams(8,11,14);
    wc.knockout_winner(10,11);
    wc.knockout_winner(5,16);
    wc.knockout_winner(5,6);
    wc.knockout_winner(15,16);
    wc.knockout_winner(15,6);
    wc.remove_player(117);
//    wc.get_all_players(15);
    wc.unite_teams(17,13,12);
//    wc.get_all_players(10);
    wc.unite_teams(3,16,8);
    wc.unite_teams(18,8,19);
    wc.update_player_stats(97,3274,2077,7434);
    wc.knockout_winner(13,16);
    wc.knockout_winner(8,21);
    wc.knockout_winner(8,11);
    wc.knockout_winner(18,21);
    wc.knockout_winner(18,11);
    wc.knockout_winner(5,5);
    wc.knockout_winner(0,10);
    wc.knockout_winner(0,0);
    wc.knockout_winner(10,10);
    wc.knockout_winner(10,0);
    wc.add_team(8,7666);
    wc.get_top_scorer(6);
    wc.get_top_scorer(20);
    wc.knockout_winner(16,16);
    wc.knockout_winner(11,21);
    wc.knockout_winner(11,11);
    wc.knockout_winner(21,21);
    wc.knockout_winner(21,11);
    wc.update_player_stats(197,5698,10893,5147);
    wc.remove_team(15);
    wc.knockout_winner(5,5);
    wc.knockout_winner(0,10);
    wc.knockout_winner(0,0);
    wc.knockout_winner(10,10);
    wc.knockout_winner(10,0);
    wc.add_player(93,15,11398,3573,9334,true);
    wc.unite_teams(6,20,2);
    wc.play_match(15,16);
    wc.knockout_winner(19,19);
    wc.knockout_winner(14,24);
    wc.knockout_winner(14,14);
    wc.knockout_winner(24,24);
    wc.knockout_winner(24,14);
    wc.knockout_winner(3,13);
    wc.knockout_winner(-2,18);
    wc.knockout_winner(-2,8);
    wc.knockout_winner(8,18);
    wc.knockout_winner(8,8);
    wc.get_top_scorer(7);
    wc.knockout_winner(11,14);
    wc.knockout_winner(6,19);
    wc.knockout_winner(6,9);
    wc.knockout_winner(16,19);
    wc.knockout_winner(16,9);
    wc.remove_player(165);
    wc.unite_teams(20,9,11);
    wc.play_match(5,13);
    wc.play_match(19,14);
    wc.get_all_players_count(8);
    wc.add_team(3,11808);
    wc.get_team_points(2);
    wc.get_team_points(20);
    wc.get_num_played_games(3);
    wc.update_player_stats(7,4486,4126,1838);
    wc.get_all_players_count(1);
    wc.get_team_points(8);
    wc.knockout_winner(2,15);
    wc.knockout_winner(-3,20);
    wc.knockout_winner(-3,10);
    wc.knockout_winner(7,20);
    wc.knockout_winner(7,10);
    wc.get_top_scorer(16);
    wc.get_top_scorer(6);
    wc.get_all_players_count(3);
    wc.add_team(5,7941);
    wc.add_player(151,20,4638,1711,1128,true);
    wc.play_match(19,12);
    wc.get_team_points(7);
    wc.add_team(19,8267);
//    wc.get_all_players(3);
    wc.play_match(12,16);
    wc.remove_team(10);
    wc.add_team(1,11369);
    wc.play_match(10,15);
//    wc.get_all_players(6);
    wc.get_closest_player(8,6);
    wc.update_player_stats(157,8983,11474,4743);
    wc.add_player(129,11,2399,6358,8812,true);
    wc.get_num_played_games(60);
    wc.get_all_players_count(5);
    wc.add_team(19,4663);
    wc.get_num_played_games(69);
    wc.get_closest_player(167,10);
//    wc.get_all_players(16);
    wc.play_match(4,1);
//    wc.get_all_players(7);
    wc.add_player(2,18,2755,9538,6899,true);
    wc.unite_teams(7,2,13);
    wc.knockout_winner(12,17);
    wc.knockout_winner(7,22);
    wc.knockout_winner(7,12);
    wc.knockout_winner(17,22);
    wc.knockout_winner(17,12);
    wc.remove_player(112);
    wc.get_closest_player(145,5);
    wc.knockout_winner(15,17);
    wc.knockout_winner(10,22);
    wc.knockout_winner(10,12);
    wc.knockout_winner(20,22);
    wc.knockout_winner(20,12);
    wc.add_team(8,460);
    wc.get_all_players_count(9);
    wc.remove_player(60);
    wc.remove_team(4);
    wc.get_closest_player(171,17);
    wc.get_num_played_games(169);
    wc.add_team(6,4474);
    wc.unite_teams(2,4,10);
    wc.remove_team(11);
    wc.play_match(17,1);
    wc.unite_teams(13,16,13);
    wc.remove_player(154);
    wc.add_player(54,3,11243,8704,120,true);
    wc.get_closest_player(191,5);
    wc.update_player_stats(71,2305,5516,9217);
    wc.remove_team(1);
    wc.get_all_players_count(6);
    wc.get_top_scorer(4);

}