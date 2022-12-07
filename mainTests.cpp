//#include <iostream>
//#include "worldcup23a1.h"
//
//void theirTest();
//int unit_test();
//
//int main()
//{
//    int a = unit_test();
//    if(a != 0)
//        std::cout << "problem with test " << a << std::endl;
//    return 0;
//}
//
//int unit_test()
//{
//    world_cup_t *obj;
//    try
//    {
//        obj = new world_cup_t();
//    }
//    catch (std::bad_alloc &e)
//    {
//        std::cout << "shit happens yo" << std::endl;
//    }
//
//    if(obj->add_team(0,1) != StatusType::INVALID_INPUT) return 101;
//    if(obj->add_team(3,0) != StatusType::SUCCESS) return 102;
//    if(obj->add_team(-5,1) != StatusType::INVALID_INPUT) return 103;
//    if(obj->add_team(1,-10) != StatusType::INVALID_INPUT) return 104;
//    if(obj->add_team(1,2) != StatusType::SUCCESS) return 105;
//    if(obj->add_team(2,4) != StatusType::SUCCESS) return 106;
//    if(obj->add_team(1,57) != StatusType::FAILURE) return 107;
//    if(obj->add_team(2, -10) != StatusType::INVALID_INPUT) return 108;
//    if(obj->add_team(4, 50) != StatusType::SUCCESS) return 109;
//    if(obj->add_team(5, 50) != StatusType::SUCCESS) return 110;
//    if(obj->add_team(6, 100) != StatusType::SUCCESS) return 111;
//    if(obj->add_team(7, 1) != StatusType::SUCCESS) return 112;
//    if(obj->add_team(8, 1) != StatusType::SUCCESS) return 113;
//
//
//    std::cout << "test 1 success" << std::endl;
//
//    if(obj->add_player(101,1,4,13,1,true) != StatusType::SUCCESS) return 201;
//    if(obj->add_player(102,1,5,2,4,false) != StatusType::SUCCESS) return 202;
//    if(obj->add_player(201,2,0,0,0,false) != StatusType::SUCCESS) return 203;
//    if(obj->add_player(202,2,0,0,0,false) != StatusType::SUCCESS) return 204;
//    if(obj->add_player(203,2,0,0,0,false) != StatusType::SUCCESS) return 205;
//    if(obj->add_player(204,2,0,0,0,false) != StatusType::SUCCESS) return 206;
//    if(obj->add_player(205,2,0,0,0,true) != StatusType::SUCCESS) return 207;
//    if(obj->add_player(301,3,0,0,0,false) != StatusType::SUCCESS) return 208;
//    if(obj->add_player(302,3,0,0,0,false) != StatusType::SUCCESS) return 209;
//    if(obj->add_player(303,3,0,0,0,false) != StatusType::SUCCESS) return 210;
//    if(obj->add_player(304,3,0,0,0,false) != StatusType::SUCCESS) return 211;
//    if(obj->add_player(305,3,0,0,0,false) != StatusType::SUCCESS) return 212;
//    if(obj->add_player(306,3,0,0,0,false) != StatusType::SUCCESS) return 213;
//    if(obj->add_player(307,3,0,0,0,false) != StatusType::SUCCESS) return 214;
//    if(obj->add_player(308,3,0,0,0,false) != StatusType::SUCCESS) return 215;
//    if(obj->add_player(309,3,0,0,0,false) != StatusType::SUCCESS) return 216;
//    if(obj->add_player(310,3,0,0,0,false) != StatusType::SUCCESS) return 217;
//    if(obj->add_player(311,3,0,0,0,true) != StatusType::SUCCESS) return 218;
//    if(obj->add_player(401,4,0,0,0,false) != StatusType::SUCCESS) return 219;
//    if(obj->add_player(402,4,0,0,0,true) != StatusType::SUCCESS) return 220;
//    if(obj->add_player(403,4,0,0,0,true) != StatusType::SUCCESS) return 221;
//    if(obj->add_player(404,4,0,0,0,false) != StatusType::SUCCESS) return 222;
//    if(obj->add_player(405,4,0,0,0,false) != StatusType::SUCCESS) return 223;
//    if(obj->add_player(406,4,0,0,0,false) != StatusType::SUCCESS) return 224;
//    if(obj->add_player(407,4,0,0,0,true) != StatusType::SUCCESS) return 225;
//    if(obj->add_player(408,4,0,0,0,false) != StatusType::SUCCESS) return 226;
//    if(obj->add_player(409,4,0,0,0,false) != StatusType::SUCCESS) return 227;
//    if(obj->add_player(410,4,0,0,0,false) != StatusType::SUCCESS) return 228;
//    if(obj->add_player(411,4,0,0,0,false) != StatusType::SUCCESS) return 229;
//
//    if(obj->add_player(0,0,0,0,0,false) != StatusType:: INVALID_INPUT) return 230;
//    if(obj->add_player(1,0,0,0,0,false) != StatusType:: INVALID_INPUT) return 231;
//    if(obj->add_player(1,-1,0,0,0,false) != StatusType::INVALID_INPUT) return 232;
//    if(obj->add_player(1,10,0,0,0,false) != StatusType::FAILURE) return 233;
//    if(obj->add_player(0,1,0,0,0,false) != StatusType:: INVALID_INPUT) return 234;
//    if(obj->add_player(1,1,-5,0,0,false) != StatusType::INVALID_INPUT) return 235;
//    if(obj->add_player(1,1,0,1,0,false) != StatusType:: INVALID_INPUT) return 236;
//    if(obj->add_player(1,1,0,0,1,true) != StatusType:: INVALID_INPUT) return 237;
//    if(obj->add_player(1,1,1,-5,0,false) != StatusType::INVALID_INPUT) return 238;
//    if(obj->add_player(1,1,1,0,-5,false) != StatusType::INVALID_INPUT) return 239;
//    if(obj->add_player(-1,1,0,0,0,false) != StatusType::INVALID_INPUT) return 240;
//    if(obj->add_player(1,1,0,1,1,false) != StatusType:: INVALID_INPUT) return 241;
//    if(obj->add_player(101,1,0,0,0,false) != StatusType::FAILURE) return 242;
//    if(obj->add_player(102,1,1,0,0,true) != StatusType::FAILURE) return 243;
//    if(obj->add_player(102,1,1,1,0,false) != StatusType::FAILURE) return 244;
//    if(obj->add_player(101,1,1,0,1,false) != StatusType::FAILURE) return 245;
//    if(obj->add_player(101,1,1,1,1,false) != StatusType::FAILURE) return 246;
//    if(obj->add_player(101,1,0,0,0,true) != StatusType::FAILURE) return 247;
//    if(obj->add_player(1,69,0,0,0,false) != StatusType::FAILURE) return 250;
//
//    if(obj->add_player(501,5,0,0,0,false) != StatusType::SUCCESS) return 251;
//    if(obj->add_player(502,5,0,0,0,false) != StatusType::SUCCESS) return 252;
//    if(obj->add_player(503,5,0,0,0,false) != StatusType::SUCCESS) return 253;
//    if(obj->add_player(504,5,0,0,0,false) != StatusType::SUCCESS) return 254;
//    if(obj->add_player(505,5,0,0,0,false) != StatusType::SUCCESS) return 255;
//    if(obj->add_player(506,5,0,0,0,false) != StatusType::SUCCESS) return 256;
//    if(obj->add_player(507,5,0,0,0,false) != StatusType::SUCCESS) return 257;
//    if(obj->add_player(508,5,0,0,0,false) != StatusType::SUCCESS) return 258;
//    if(obj->add_player(509,5,0,0,0,false) != StatusType::SUCCESS) return 259;
//    if(obj->add_player(510,5,0,0,0,false) != StatusType::SUCCESS) return 260;
//    if(obj->add_player(511,5,0,0,0,true) != StatusType::SUCCESS) return 271;
//    if(obj->add_player(601,6,0,0,0,false) != StatusType::SUCCESS) return 272;
//    if(obj->add_player(602,6,0,0,0,false) != StatusType::SUCCESS) return 273;
//    if(obj->add_player(603,6,0,0,0,false) != StatusType::SUCCESS) return 274;
//    if(obj->add_player(604,6,0,0,0,false) != StatusType::SUCCESS) return 275;
//    if(obj->add_player(605,6,0,0,0,false) != StatusType::SUCCESS) return 276;
//    if(obj->add_player(606,6,0,0,0,false) != StatusType::SUCCESS) return 277;
//    if(obj->add_player(607,6,0,0,0,false) != StatusType::SUCCESS) return 278;
//    if(obj->add_player(608,6,0,0,0,false) != StatusType::SUCCESS) return 279;
//    if(obj->add_player(609,6,0,0,0,false) != StatusType::SUCCESS) return 280;
//    if(obj->add_player(610,6,0,0,0,false) != StatusType::SUCCESS) return 281;
//    if(obj->add_player(611,6,0,0,0,false) != StatusType::SUCCESS) return 282;
//
//    std::cout << "test 2 success" << std::endl;
//
//    if(obj->update_player_stats(1337,0,0,0) != StatusType::FAILURE) return 301;
//    if(obj->update_player_stats(0,0,0,0) != StatusType::INVALID_INPUT) return 302;
//    if(obj->update_player_stats(1337,1,1,1) != StatusType::FAILURE) return 303;
//    if(obj->update_player_stats(0,1,1,1) != StatusType::INVALID_INPUT) return 304;
//    if(obj->update_player_stats(-1,0,0,0) != StatusType::INVALID_INPUT) return 305;
//    if(obj->update_player_stats(101,-1,0,0) != StatusType::INVALID_INPUT) return 306;
//    if(obj->update_player_stats(101,0,-1,0) != StatusType::INVALID_INPUT) return 307;
//    if(obj->update_player_stats(101,-1,-1,-1) != StatusType::INVALID_INPUT) return 308;
//    if(obj->update_player_stats(101,0,0,-1) != StatusType::INVALID_INPUT) return 309;
//    if(obj->update_player_stats(101,-1,0,-1) != StatusType::INVALID_INPUT) return 310;
//    if(obj->update_player_stats(101,0,-1,-1) != StatusType::INVALID_INPUT) return 311;
//
//    if(obj->update_player_stats(101,1,0,0) != StatusType::SUCCESS) return 312;
//    if(obj->update_player_stats(101,0,1,0) != StatusType::SUCCESS) return 313;
//    if(obj->update_player_stats(101,0,0,1) != StatusType::SUCCESS) return 314;
//    if(obj->update_player_stats(101,1,1,0) != StatusType::SUCCESS) return 315;
//    if(obj->update_player_stats(101,1,0,1) != StatusType::SUCCESS) return 316;
//    if(obj->update_player_stats(101,0,1,1) != StatusType::SUCCESS) return 317;
//    if(obj->update_player_stats(101,1,1,1) != StatusType::SUCCESS) return 318;
//
//    if(obj->update_player_stats(102,4,5,9) != StatusType::SUCCESS) return 319;
//
//    std::cout << "test 3 success" << std::endl;
//
//    if(obj->play_match(-1,-1) != StatusType::INVALID_INPUT) return 401;
//    if(obj->play_match(-2,1) !=  StatusType::INVALID_INPUT) return 402;
//    if(obj->play_match(1,-5) !=  StatusType::INVALID_INPUT) return 403;
//    if(obj->play_match(0,2) !=   StatusType::INVALID_INPUT) return 404;
//    if(obj->play_match(1,0) !=   StatusType::INVALID_INPUT) return 405;
//    if(obj->play_match(1,1) !=   StatusType::INVALID_INPUT) return 406;
//    if(obj->play_match(0,0) !=   StatusType::INVALID_INPUT) return 407;
//    if(obj->play_match(3,3) != StatusType::INVALID_INPUT) return 408;
//    if(obj->play_match(500,0) != StatusType::INVALID_INPUT) return 409;
//    if(obj->play_match(-3,422222) != StatusType::INVALID_INPUT) return 410;
//
//    if(obj->play_match(546,645) != StatusType::FAILURE) return 411;
//    if(obj->play_match(234,1) != StatusType::FAILURE) return 412;
//    if(obj->play_match(4,1233131) != StatusType::FAILURE) return 413;
//    if(obj->play_match(1,2) != StatusType::FAILURE) return 414;
//    if(obj->play_match(1,4) != StatusType::FAILURE) return 415;
//    if(obj->play_match(3,2) != StatusType::FAILURE) return 416;
//    if(obj->play_match(2,1) != StatusType::FAILURE) return 417;
//    if(obj->play_match(6,4) != StatusType::FAILURE) return 418;
//    if(obj->play_match(5,6) != StatusType::FAILURE) return 419;
//    if(obj->play_match(1,6) != StatusType::FAILURE) return 420;
//
//    std::cout << "test 4 success" << std::endl;
//
//    if(obj->get_num_played_games(99999).status() != StatusType::FAILURE) return 501;
//    if(obj->get_num_played_games(0).status() != StatusType::INVALID_INPUT) return 502;
//    if(obj->get_num_played_games(-5).status() != StatusType::INVALID_INPUT) return 503;
//    if(obj->get_num_played_games(101).status() != StatusType::SUCCESS) return 504;
//    if(obj->get_num_played_games(408).status() != StatusType::SUCCESS) return 505;
//    if(obj->get_num_played_games(69).status() != StatusType::FAILURE) return 506;
//
//    if(obj->get_team_points(457).status() != StatusType::FAILURE) return 507;
//    if(obj->get_team_points(1337).status() != StatusType::FAILURE) return 508;
//    if(obj->get_team_points(0).status() != StatusType::INVALID_INPUT) return 509;
//    if(obj->get_team_points(-14).status() != StatusType::INVALID_INPUT) return 510;
//    if(obj->get_team_points(-2).status() != StatusType::INVALID_INPUT) return 511;
//    if(obj->get_team_points(1).status() != StatusType::SUCCESS) return 512;
//    if(obj->get_team_points(5).status() != StatusType::SUCCESS) return 513;
//    if(obj->get_team_points(3).status() != StatusType::SUCCESS) return 514;
//
//    if(obj->get_top_scorer(0).status() != StatusType::INVALID_INPUT) return 515;
//    if(obj->get_top_scorer(10000).status() != StatusType::FAILURE) return 516;
//    if(obj->get_top_scorer(69).status() != StatusType::FAILURE) return 517;
//    if(obj->get_top_scorer(-1).status() != StatusType::SUCCESS) return 518;
//    if(obj->get_top_scorer(-5).status() != StatusType::SUCCESS) return 519;
//    if(obj->get_top_scorer(1).status() != StatusType::SUCCESS) return 520;
//    if(obj->get_top_scorer(4).status() != StatusType::SUCCESS) return 521;
//    if(obj->get_top_scorer(7).status() != StatusType::FAILURE) return 522;
//    if(obj->get_top_scorer(8).status() != StatusType::FAILURE) return 523;
//
//    if(obj->get_all_players_count(0).status() != StatusType::INVALID_INPUT) return 524;
//    if(obj->get_all_players_count(10060).status() != StatusType::FAILURE) return 525;
//    if(obj->get_all_players_count(69).status() != StatusType::FAILURE) return 526;
//    if(obj->get_all_players_count(-1).status() != StatusType::SUCCESS) return 527;
//    if(obj->get_all_players_count(7).status() != StatusType::SUCCESS) return 528;
//    if(obj->get_all_players_count(4).status() != StatusType::SUCCESS) return 529;
//
//
//    std::cout << "test 5 success" << std::endl;
//    //todo add real play matches, and check num played games, team points and get top scorer and all player count
//
//    std::cout << "test 6 not made yet" << std::endl;
//
//    //int *allPlayers = new int(obj->get_all_players_count(-1).ans());
//    int allPlayers[51];
//    int arr[2];
//
//    if(obj->get_all_players(0, nullptr) != StatusType::INVALID_INPUT) return 701;
//    if(obj->get_all_players(0, arr) != StatusType::INVALID_INPUT) return 702;
//    if(obj->get_all_players(1, nullptr) != StatusType::INVALID_INPUT) return 704;
//    if(obj->get_all_players(1, arr) != StatusType::SUCCESS) return 705;
//    if(obj->get_all_players(437, arr) != StatusType::FAILURE) return 706;
//    if(obj->get_all_players(8, arr) != StatusType::FAILURE) return 707;
//    if(obj->get_all_players(-1, allPlayers) != StatusType::SUCCESS) return 708;
//    //delete allPlayers;
//
//    std::cout << "test 7 success" << std::endl;
//
//    if(obj->get_closest_player(0,0).status() != StatusType::   INVALID_INPUT) return 801;
//    if(obj->get_closest_player(0,1).status() != StatusType::   INVALID_INPUT) return 802;
//    if(obj->get_closest_player(-1,1).status() != StatusType::  INVALID_INPUT) return 803;
//    if(obj->get_closest_player(101,0).status() != StatusType:: INVALID_INPUT) return 804;
//    if(obj->get_closest_player(101,-1).status() != StatusType::INVALID_INPUT) return 805;
//    if(obj->get_closest_player(404,1).status() != StatusType::FAILURE) return 806;
//    if(obj->get_closest_player(101,1).status() != StatusType::SUCCESS) return 807;
//    if(obj->get_closest_player(102,1).status() != StatusType::SUCCESS) return 808;
//    if(obj->get_closest_player(204,2).status() != StatusType::SUCCESS) return 809;
//
//    if(obj->get_closest_player(101,1).ans() != 102) return 810;
//
////    if(obj->get_closest_player(102,1).ans() != 611 /*may be changed*/) return 811;
//
//    std::cout << "test 8 success" << std::endl;
//
//    if(obj->knockout_winner(0,0).status() != StatusType::FAILURE) return 901;
//    if(obj->knockout_winner(-1,0).status() != StatusType::INVALID_INPUT) return 902;
//    if(obj->knockout_winner(0,-1).status() != StatusType::INVALID_INPUT) return 903;
//    if(obj->knockout_winner(-1,-1).status() != StatusType::INVALID_INPUT) return 904;
//    if(obj->knockout_winner(4,2).status() != StatusType::INVALID_INPUT) return 905;
//    if(obj->knockout_winner(10,5).status() != StatusType::INVALID_INPUT) return 906;
//    if(obj->knockout_winner(1000,10000).status() != StatusType::FAILURE) return 907;
//    if(obj->knockout_winner(4,-6).status() != StatusType::INVALID_INPUT) return 908;
//    if(obj->knockout_winner(-2,5).status() != StatusType::INVALID_INPUT) return 909;
//    if(obj->knockout_winner(4,0).status() != StatusType::INVALID_INPUT) return 910;
//    if(obj->knockout_winner(0,5).status() != StatusType::SUCCESS) return 911;
//    if(obj->knockout_winner(1,8).status() != StatusType::SUCCESS) return 912;
//    if(obj->knockout_winner(5,5).status() != StatusType::SUCCESS) return 913;
//    if(obj->knockout_winner(3,3).status() != StatusType::SUCCESS) return 914;
//    if(obj->knockout_winner(1,2).status() != StatusType::FAILURE) return 915;
//    if(obj->knockout_winner(1,3).status() != StatusType::SUCCESS) return 916;
//
//    if(obj->knockout_winner(5,5).ans() != 5) return 917;
//    if(obj->knockout_winner(3,3).ans() != 3) return 918;
//    if(obj->knockout_winner(1,3).ans() != 3) return 919;
//
//    std::cout << "test 9 success" << std::endl;
//
//    if(obj->unite_teams(0,0,0) != StatusType::INVALID_INPUT) return 1001;
//    if(obj->unite_teams(1,0,0) != StatusType::INVALID_INPUT) return 1001;
//    if(obj->unite_teams(0,1,0) != StatusType::INVALID_INPUT) return 1001;
//    if(obj->unite_teams(0,0,1) != StatusType::INVALID_INPUT) return 1001;
//    if(obj->unite_teams(1,2,0) != StatusType::INVALID_INPUT) return 1001;
//    if(obj->unite_teams(0,2,1) != StatusType::INVALID_INPUT) return 1001;
//    if(obj->unite_teams(2,0,1) != StatusType::INVALID_INPUT) return 1001;
//    if(obj->unite_teams(1,1,4444) != StatusType::INVALID_INPUT) return 1001;
//    if(obj->unite_teams(2,2,4444) != StatusType::INVALID_INPUT) return 1001;
//    if(obj->unite_teams(456,457,123) != StatusType::FAILURE) return 1001;
//    if(obj->unite_teams(3,4,1) != StatusType::FAILURE) return 1001;
//    if(obj->unite_teams(2,69999,1400) != StatusType::FAILURE) return 1001;
//    if(obj->unite_teams(-1,4,89) != StatusType::INVALID_INPUT) return 1001;
//    if(obj->unite_teams(1,-4,89) != StatusType::INVALID_INPUT) return 1001;
//    if(obj->unite_teams(1,4,-56) != StatusType::INVALID_INPUT) return 1001;
//    if(obj->unite_teams(56677,2,809) != StatusType::FAILURE) return 1001;
//    if(obj->unite_teams(5,6,8) != StatusType::FAILURE) return 1001;
//
//    //TODO check successses
//    std::cout << "test 10 success" << std::endl;
//    //TODO update all returns and tests
//
//    if(obj->remove_team(1) != StatusType::FAILURE) return 1101;
//    if(obj->remove_team(3) != StatusType::FAILURE) return 1102;
//    if(obj->remove_team(4) != StatusType::FAILURE) return 1103;
//
//    if(obj->remove_player(101) != StatusType::SUCCESS) return 1104;
//
//    if(obj->remove_team(1) != StatusType::FAILURE) return 1105;
//
//
//    if(obj->remove_player(102) != StatusType::SUCCESS) return 1106;
//    if(obj->remove_player(201) != StatusType::SUCCESS) return 1107;
//    if(obj->remove_player(202) != StatusType::SUCCESS) return 1108;
//    if(obj->remove_player(203) != StatusType::SUCCESS) return 1109;
//    if(obj->remove_player(204) != StatusType::SUCCESS) return 1110;
//    if(obj->remove_player(205) != StatusType::SUCCESS) return 1111;
//    if(obj->remove_player(301) != StatusType::SUCCESS) return 1112;
//    if(obj->remove_player(302) != StatusType::SUCCESS) return 1113;
//    if(obj->remove_player(303) != StatusType::SUCCESS) return 1114;
//    if(obj->remove_player(304) != StatusType::SUCCESS) return 1115;
//    if(obj->remove_player(305) != StatusType::SUCCESS) return 1116;
//    if(obj->remove_player(306) != StatusType::SUCCESS) return 1117;
//    if(obj->remove_player(307) != StatusType::SUCCESS) return 1118;
//    if(obj->remove_player(308) != StatusType::SUCCESS) return 1119;
//    if(obj->remove_player(309) != StatusType::SUCCESS) return 1120;
//    if(obj->remove_player(310) != StatusType::SUCCESS) return 1121;
//    if(obj->remove_player(311) != StatusType::SUCCESS) return 1122;
//    if(obj->remove_player(401) != StatusType::SUCCESS) return 1123;
//    if(obj->remove_player(402) != StatusType::SUCCESS) return 1124;
//    if(obj->remove_player(403) != StatusType::SUCCESS) return 1125;
//    if(obj->remove_player(404) != StatusType::SUCCESS) return 1126;
//    if(obj->remove_player(405) != StatusType::SUCCESS) return 1127;
//    if(obj->remove_player(406) != StatusType::SUCCESS) return 1128;
//    if(obj->remove_player(407) != StatusType::SUCCESS) return 1129;
//    if(obj->remove_player(408) != StatusType::SUCCESS) return 1130;
//    if(obj->remove_player(409) != StatusType::SUCCESS) return 1131;
//    if(obj->remove_player(410) != StatusType::SUCCESS) return 1132;
//    if(obj->remove_player(411) != StatusType::SUCCESS) return 1133;
//    if(obj->remove_player(501) != StatusType::SUCCESS) return 1134;
//    if(obj->remove_player(502) != StatusType::SUCCESS) return 1135;
//    if(obj->remove_player(503) != StatusType::SUCCESS) return 1136;
//    if(obj->remove_player(504) != StatusType::SUCCESS) return 1137;
//    if(obj->remove_player(505) != StatusType::SUCCESS) return 1138;
//    if(obj->remove_player(506) != StatusType::SUCCESS) return 1139;
//    if(obj->remove_player(507) != StatusType::SUCCESS) return 1140;
//    if(obj->remove_player(508) != StatusType::SUCCESS) return 1141;
//    if(obj->remove_player(509) != StatusType::SUCCESS) return 1142;
//    if(obj->remove_player(510) != StatusType::SUCCESS) return 1143;
//    if(obj->remove_player(511) != StatusType::SUCCESS) return 1144;
//    if(obj->remove_player(601) != StatusType::SUCCESS) return 1145;
//    if(obj->remove_player(602) != StatusType::SUCCESS) return 1146;
//    if(obj->remove_player(603) != StatusType::SUCCESS) return 1147;
//    if(obj->remove_player(604) != StatusType::SUCCESS) return 1148;
//    if(obj->remove_player(605) != StatusType::SUCCESS) return 1149;
//    if(obj->remove_player(606) != StatusType::SUCCESS) return 1150;
//    if(obj->remove_player(607) != StatusType::SUCCESS) return 1151;
//    if(obj->remove_player(608) != StatusType::SUCCESS) return 1152;
//    if(obj->remove_player(609) != StatusType::SUCCESS) return 1153;
//    if(obj->remove_player(610) != StatusType::SUCCESS) return 1154;
//    if(obj->remove_player(611) != StatusType::SUCCESS) return 1155;
//
//    if(obj->remove_player(0) != StatusType::INVALID_INPUT) return 1156;
//    if(obj->remove_player(-5) != StatusType::INVALID_INPUT) return 1157;
//    if(obj->remove_player(100000) != StatusType::FAILURE) return 1158;
//
//    std::cout << "test 11 success" << std::endl;
//
//    //no players tests
//    if(obj->get_top_scorer(-1).status() != StatusType::FAILURE) return 1201;
//    if(obj->get_all_players(-10, arr) != StatusType::FAILURE) return 1202;
//
//    obj->add_player(101,1,0,0,0,false);
//    if(obj->get_closest_player(101,1).status() != StatusType::FAILURE) return 1203;
//    obj->remove_player(101);
//
//    std::cout << "test 12 success" << std::endl;
//
//
//    if(obj->remove_team(0) != StatusType::INVALID_INPUT) return 1301;
//    if(obj->remove_team(-1) != StatusType::INVALID_INPUT) return 1302;
//    if(obj->remove_team(-999999) != StatusType::INVALID_INPUT) return 1303;
//    if(obj->remove_team(2) != StatusType::SUCCESS) return 1304;
//    if(obj->remove_team(10) != StatusType::FAILURE) return 1305;
//    if(obj->remove_team(1) != StatusType::SUCCESS) return 1306;
//    if(obj->remove_team(1) != StatusType::FAILURE) return 1307;
//    if(obj->remove_team(3) != StatusType::SUCCESS) return 1308;
//    if(obj->remove_team(4) != StatusType::SUCCESS) return 1309;
//    if(obj->remove_team(5) != StatusType::SUCCESS) return 1310;
//    if(obj->remove_team(6) != StatusType::SUCCESS) return 1311;
//
//    std::cout << "test 13 success" << std::endl;
//
//    delete obj;
//    std::cout << "All tests passed!" << std::endl;
//    return 0;
//}
//
//void theirTest()
//{
//    world_cup_t *obj = new world_cup_t();
//    obj->add_team(1, 10000);
//    obj->add_team(2, 20000);
//    obj->add_team(3, 30000);
//    obj->add_team(4, 40000);
//    obj->add_player(1001, 1, 10, 0, 0, false);
//    obj->add_player(1002, 1, 10, 0, 0, false);
//    obj->add_player(1003, 1, 10, 0, 0, false);
//    obj->add_player(1004, 1, 10, 0, 2, false);
//    obj->add_player(1005, 1, 10, 0, 0, false);
//    obj->add_player(1006, 1, 10, 4, 3, false);
//    obj->add_player(1007, 1, 10, 0, 0, false);
//    obj->add_player(1008, 1, 10, 0, 0, true);
//    obj->add_player(1009, 1, 10, 0, 0, false);
//    obj->add_player(1010, 1, 10, 0, 0, false);
//    obj->add_player(1011, 1, 10, 0, 0, false);
//    obj->add_player(1012, 1, 10, 0, 0, false);
//    obj->add_player(2001, 2, 20, 0, 0, false);
//    obj->add_player(2002, 2, 20, 0, 0, false);
//    obj->add_player(2003, 2, 20, 0, 0, false);
//    obj->add_player(2004, 2, 20, 0, 0, false);
//    obj->add_player(2005, 2, 20, 0, 0, false);
//    obj->add_player(2006, 2, 20, 0, 0, false);
//    obj->add_player(2007, 2, 20, 0, 0, false);
//    obj->add_player(2008, 2, 20, 6, 4, true);
//    obj->add_player(2009, 2, 20, 0, 0, false);
//    obj->add_player(2010, 2, 0, 0, 0, false);
//    obj->add_player(2011, 2, 20, 0, 0, false);
//    obj->add_player(3001, 3, 30, 0, 0, false);
//    obj->add_player(3002, 3, 30, 0, 0, false);
//    obj->add_player(3003, 3, 30, 0, 0, false);
//    obj->add_player(3004, 3, 30, 0, 0, false);
//    obj->add_player(3005, 3, 30, 2, 0, false);
//    obj->add_player(3006, 3, 30, 0, 0, false);
//    obj->add_player(3007, 3, 30, 0, 0, false);
//    obj->add_player(3008, 3, 30, 0, 0, false);
//    obj->add_player(3009, 3, 30, 0, 2, false);
//    obj->add_player(3010, 3, 30, 0, 0, true);
//    obj->add_player(3011, 3, 30, 0, 0, true);
//    obj->add_player(4001, 4, 2, 1, 2, false);
//    obj->add_player(4002, 4, 2, 2, 2, false);
//    obj->update_player_stats(3011,2,1,1);
//    obj->play_match(2,3);
//    obj->play_match(1,2);
//    obj->get_num_played_games(2003);
//    obj->get_team_points(3);
//    obj->unite_teams(1, 2, 2);
//    obj->get_top_scorer(-1);
//    obj->get_all_players_count(3);
//
//    //checks get all players
//    output_t<int> count = obj->get_all_players_count(4);
//    // Allocate if okay
//    int *out_mem = nullptr;
//    if (count.status() == StatusType::SUCCESS && (count.ans() > 0)) {
//        out_mem = new int[count.ans()];
//        for (int i = 0; i < count.ans(); ++i) out_mem[i] = -1;
//    }
//    // Call function
//
//    if(out_mem == nullptr) throw std::logic_error("no maarah");
//    obj->get_all_players(4, out_mem);
//
//    delete[] out_mem;
//
//    obj->get_closest_player(2008, 2);
//    obj->knockout_winner(0, 3);
//    obj->remove_team(2);
//    obj->remove_player(3008);
//    delete obj;
//}