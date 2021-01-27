#include "iGraphics.h"
#include<bits/stdc++.h>
#include <mmsystem.h>
#include <windows.h>
#include "SFML/Audio.hpp"
using namespace std;
int hate_gulli = -110;
int game_state = 0;
int hate_gulli_left = -100;
int act_ashiq = 0;
int ashiq_image_index = 0;
int hasnain_dead_music = 0;
sf::Music sounds[20];
int throw_music_on = 0, sward_music= 0;
bool shim_dead_sound=0,off_game_sound=0,pirat_sword_sound=0,keo_toroal_mare=0;
bool act_zombie=0;//start- shimla
int  act_zombie_index=0;//end- shimla
int GRAVITY_SPEED = 40, base = 0,touch_sound=0,touch_continue=0;
int ENEMY_SEEING_RANGE = 300,SWAT_POSY = 600;
int act_farhan = 0, farhan_image_index = 0;
int MAX_NINCHUK = 3, GIRL_JUMP_Y = 35;
const int number_of_enemy = 1; ///////////////////////////////////////////////////////////
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng_as uniform_int_distribution<int>(0, number_of_enemy)(rng)
#define rng_pk uniform_int_distribution<int>(0, 200)(rng)
int life_left=10;
int SWAT_POSX = 100;
int desktop_hor = 1300, desktop_ver = 700;
long long int TIME_NOW = 0;
int throwing_now = 0;
bool jump = false;
int r = 0,g = 255, b = 0;
int tolowar_dmg = 0;
int FLOOR[20][1400][1000]; // game_state & x,y,
bool NIN_THROW = false;
bool RUN_STATUS = false, ZOMBIE_DONE = false;
int NIN_COUNT = 0, UNLOCKED_CHARACTER = 1, press_n = 0;
int FACE = 1; //0 mane bam , 1 mane dane
int GIRL_X = 0, GIRL_Y = 700;
char image_fix[20][20];
vector<int>chakus_in_dead_body;
int jumppic_index = 0, idle_index = 0;
int nin_throw_idx = 0, music = 1;
int done = 0;
int RunPicIndex1=0;
int RunPicIndex2=0;
int TIME_TO_STOP = 0;
int freez = 0;
int sara_idle_index = 0;
int jumppic_indexr = 0, idle_indexr = 0, nin_throw_idxr = 0;
int hasnain_dead = 0,case_ache = 1,sara_x = 1100, sara_y = 60, sara_index = 0;

int ashiq_video_on = 0, press_g = 0, ashiq_video_index = 0;
int dead_shim_indexr=0;
char ashiq_video[200][30] = {"ashiq_video\\ashiq (1).bmp","ashiq_video\\ashiq (2).bmp","ashiq_video\\ashiq (3).bmp","ashiq_video\\ashiq (4).bmp","ashiq_video\\ashiq (5).bmp","ashiq_video\\ashiq (6).bmp","ashiq_video\\ashiq (7).bmp","ashiq_video\\ashiq (8).bmp","ashiq_video\\ashiq (9).bmp","ashiq_video\\ashiq (10).bmp","ashiq_video\\ashiq (11).bmp","ashiq_video\\ashiq (12).bmp","ashiq_video\\ashiq (13).bmp","ashiq_video\\ashiq (14).bmp","ashiq_video\\ashiq (15).bmp","ashiq_video\\ashiq (16).bmp","ashiq_video\\ashiq (17).bmp","ashiq_video\\ashiq (18).bmp","ashiq_video\\ashiq (19).bmp","ashiq_video\\ashiq (20).bmp","ashiq_video\\ashiq (21).bmp","ashiq_video\\ashiq (22).bmp","ashiq_video\\ashiq (23).bmp","ashiq_video\\ashiq (24).bmp","ashiq_video\\ashiq (25).bmp","ashiq_video\\ashiq (26).bmp","ashiq_video\\ashiq (27).bmp","ashiq_video\\ashiq (28).bmp","ashiq_video\\ashiq (29).bmp","ashiq_video\\ashiq (30).bmp","ashiq_video\\ashiq (31).bmp","ashiq_video\\ashiq (32).bmp","ashiq_video\\ashiq (33).bmp","ashiq_video\\ashiq (34).bmp","ashiq_video\\ashiq (35).bmp","ashiq_video\\ashiq (36).bmp","ashiq_video\\ashiq (37).bmp","ashiq_video\\ashiq (38).bmp","ashiq_video\\ashiq (39).bmp","ashiq_video\\ashiq (40).bmp","ashiq_video\\ashiq (41).bmp","ashiq_video\\ashiq (42).bmp","ashiq_video\\ashiq (43).bmp","ashiq_video\\ashiq (44).bmp","ashiq_video\\ashiq (45).bmp","ashiq_video\\ashiq (46).bmp","ashiq_video\\ashiq (47).bmp","ashiq_video\\ashiq (48).bmp","ashiq_video\\ashiq (49).bmp","ashiq_video\\ashiq (50).bmp","ashiq_video\\ashiq (51).bmp","ashiq_video\\ashiq (52).bmp","ashiq_video\\ashiq (53).bmp","ashiq_video\\ashiq (54).bmp","ashiq_video\\ashiq (55).bmp","ashiq_video\\ashiq (56).bmp","ashiq_video\\ashiq (57).bmp","ashiq_video\\ashiq (58).bmp","ashiq_video\\ashiq (59).bmp","ashiq_video\\ashiq (60).bmp","ashiq_video\\ashiq (61).bmp","ashiq_video\\ashiq (62).bmp","ashiq_video\\ashiq (63).bmp","ashiq_video\\ashiq (64).bmp","ashiq_video\\ashiq (65).bmp","ashiq_video\\ashiq (66).bmp","ashiq_video\\ashiq (67).bmp","ashiq_video\\ashiq (68).bmp","ashiq_video\\ashiq (69).bmp","ashiq_video\\ashiq (70).bmp","ashiq_video\\ashiq (71).bmp","ashiq_video\\ashiq (72).bmp","ashiq_video\\ashiq (73).bmp","ashiq_video\\ashiq (74).bmp","ashiq_video\\ashiq (75).bmp","ashiq_video\\ashiq (76).bmp","ashiq_video\\ashiq (77).bmp","ashiq_video\\ashiq (78).bmp","ashiq_video\\ashiq (79).bmp","ashiq_video\\ashiq (80).bmp","ashiq_video\\ashiq (81).bmp","ashiq_video\\ashiq (82).bmp","ashiq_video\\ashiq (83).bmp","ashiq_video\\ashiq (84).bmp","ashiq_video\\ashiq (85).bmp","ashiq_video\\ashiq (86).bmp","ashiq_video\\ashiq (87).bmp","ashiq_video\\ashiq (88).bmp","ashiq_video\\ashiq (89).bmp","ashiq_video\\ashiq (90).bmp","ashiq_video\\ashiq (91).bmp","ashiq_video\\ashiq (92).bmp","ashiq_video\\ashiq (93).bmp","ashiq_video\\ashiq (94).bmp","ashiq_video\\ashiq (95).bmp","ashiq_video\\ashiq (96).bmp","ashiq_video\\ashiq (97).bmp","ashiq_video\\ashiq (98).bmp","ashiq_video\\ashiq (99).bmp","ashiq_video\\ashiq (100).bmp","ashiq_video\\ashiq (101).bmp","ashiq_video\\ashiq (102).bmp","ashiq_video\\ashiq (103).bmp","ashiq_video\\ashiq (104).bmp","ashiq_video\\ashiq (105).bmp","ashiq_video\\ashiq (106).bmp","ashiq_video\\ashiq (107).bmp","ashiq_video\\ashiq (108).bmp","ashiq_video\\ashiq (109).bmp","ashiq_video\\ashiq (110).bmp","ashiq_video\\ashiq (111).bmp","ashiq_video\\ashiq (112).bmp","ashiq_video\\ashiq (113).bmp","ashiq_video\\ashiq (114).bmp","ashiq_video\\ashiq (115).bmp","ashiq_video\\ashiq (116).bmp","ashiq_video\\ashiq (117).bmp","ashiq_video\\ashiq (118).bmp","ashiq_video\\ashiq (119).bmp","ashiq_video\\ashiq (120).bmp","ashiq_video\\ashiq (121).bmp","ashiq_video\\ashiq (122).bmp","ashiq_video\\ashiq (123).bmp","ashiq_video\\ashiq (124).bmp","ashiq_video\\ashiq (125).bmp","ashiq_video\\ashiq (126).bmp","ashiq_video\\ashiq (127).bmp","ashiq_video\\ashiq (128).bmp","ashiq_video\\ashiq (129).bmp","ashiq_video\\ashiq (130).bmp","ashiq_video\\ashiq (131).bmp","ashiq_video\\ashiq (132).bmp","ashiq_video\\ashiq (133).bmp","ashiq_video\\ashiq (134).bmp","ashiq_video\\ashiq (135).bmp","ashiq_video\\ashiq (136).bmp","ashiq_video\\ashiq (137).bmp","ashiq_video\\ashiq (138).bmp","ashiq_video\\ashiq (139).bmp","ashiq_video\\ashiq (140).bmp","ashiq_video\\ashiq (141).bmp","ashiq_video\\ashiq (142).bmp","ashiq_video\\ashiq (143).bmp","ashiq_video\\ashiq (144).bmp","ashiq_video\\ashiq (145).bmp","ashiq_video\\ashiq (146).bmp","ashiq_video\\ashiq (147).bmp","ashiq_video\\ashiq (148).bmp","ashiq_video\\ashiq (149).bmp","ashiq_video\\ashiq (150).bmp","ashiq_video\\ashiq (151).bmp","ashiq_video\\ashiq (152).bmp","ashiq_video\\ashiq (153).bmp","ashiq_video\\ashiq (154).bmp","ashiq_video\\ashiq (155).bmp"};
char dead_shim[10][30]={"dead\\1.bmp","dead\\2.bmp","dead\\3.bmp","dead\\4.bmp","dead\\5.bmp","dead\\6.bmp","dead\\7.bmp","dead\\8.bmp","dead\\9.bmp","dead\\10.bmp"};
int teacher_index=0;//edit-shimla
int dead_shim_index=0;//edit-shimla
char farhan[160][20] = {"Farhan\\(1).bmp","Farhan\\(2).bmp","Farhan\\(3).bmp","Farhan\\(4).bmp","Farhan\\(5).bmp","Farhan\\(6).bmp","Farhan\\(7).bmp","Farhan\\(8).bmp","Farhan\\(9).bmp","Farhan\\(10).bmp","Farhan\\(11).bmp","Farhan\\(12).bmp","Farhan\\(13).bmp","Farhan\\(14).bmp","Farhan\\(15).bmp","Farhan\\(16).bmp","Farhan\\(17).bmp","Farhan\\(18).bmp","Farhan\\(19).bmp","Farhan\\(20).bmp","Farhan\\(21).bmp","Farhan\\(22).bmp","Farhan\\(23).bmp","Farhan\\(24).bmp","Farhan\\(25).bmp","Farhan\\(26).bmp","Farhan\\(27).bmp","Farhan\\(28).bmp","Farhan\\(29).bmp","Farhan\\(30).bmp","Farhan\\(31).bmp","Farhan\\(32).bmp","Farhan\\(33).bmp","Farhan\\(34).bmp","Farhan\\(35).bmp","Farhan\\(36).bmp","Farhan\\(37).bmp","Farhan\\(38).bmp","Farhan\\(39).bmp","Farhan\\(40).bmp","Farhan\\(41).bmp","Farhan\\(42).bmp","Farhan\\(43).bmp","Farhan\\(44).bmp","Farhan\\(45).bmp","Farhan\\(46).bmp","Farhan\\(47).bmp","Farhan\\(48).bmp","Farhan\\(49).bmp","Farhan\\(50).bmp","Farhan\\(51).bmp","Farhan\\(52).bmp","Farhan\\(53).bmp","Farhan\\(54).bmp","Farhan\\(55).bmp","Farhan\\(56).bmp","Farhan\\(57).bmp","Farhan\\(58).bmp","Farhan\\(59).bmp","Farhan\\(60).bmp","Farhan\\(61).bmp","Farhan\\(62).bmp","Farhan\\(63).bmp","Farhan\\(64).bmp","Farhan\\(65).bmp","Farhan\\(66).bmp","Farhan\\(67).bmp","Farhan\\(68).bmp","Farhan\\(69).bmp","Farhan\\(70).bmp","Farhan\\(71).bmp","Farhan\\(72).bmp","Farhan\\(73).bmp","Farhan\\(74).bmp","Farhan\\(75).bmp","Farhan\\(76).bmp","Farhan\\(77).bmp","Farhan\\(78).bmp","Farhan\\(79).bmp","Farhan\\(80).bmp","Farhan\\(81).bmp","Farhan\\(82).bmp","Farhan\\(83).bmp","Farhan\\(84).bmp","Farhan\\(85).bmp","Farhan\\(86).bmp","Farhan\\(87).bmp","Farhan\\(88).bmp","Farhan\\(89).bmp","Farhan\\(90).bmp","Farhan\\(91).bmp","Farhan\\(92).bmp","Farhan\\(93).bmp","Farhan\\(94).bmp","Farhan\\(95).bmp","Farhan\\(96).bmp","Farhan\\(97).bmp","Farhan\\(98).bmp","Farhan\\(99).bmp","Farhan\\(100).bmp","Farhan\\(101).bmp","Farhan\\(102).bmp","Farhan\\(103).bmp","Farhan\\(104).bmp","Farhan\\(105).bmp","Farhan\\(106).bmp","Farhan\\(107).bmp","Farhan\\(108).bmp","Farhan\\(109).bmp","Farhan\\(110).bmp","Farhan\\(111).bmp","Farhan\\(112).bmp","Farhan\\(113).bmp","Farhan\\(114).bmp","Farhan\\(115).bmp","Farhan\\(116).bmp","Farhan\\(117).bmp","Farhan\\(118).bmp","Farhan\\(119).bmp","Farhan\\(120).bmp","Farhan\\(121).bmp","Farhan\\(122).bmp","Farhan\\(123).bmp","Farhan\\(124).bmp","Farhan\\(125).bmp","Farhan\\(126).bmp","Farhan\\(127).bmp","Farhan\\(128).bmp","Farhan\\(129).bmp","Farhan\\(130).bmp","Farhan\\(131).bmp","Farhan\\(132).bmp","Farhan\\(133).bmp","Farhan\\(134).bmp","Farhan\\(135).bmp","Farhan\\(136).bmp","Farhan\\(137).bmp","Farhan\\(138).bmp","Farhan\\(139).bmp","Farhan\\(140).bmp","Farhan\\(141).bmp","Farhan\\(142).bmp","Farhan\\(143).bmp","Farhan\\(144).bmp","Farhan\\(145).bmp","Farhan\\(146).bmp","Farhan\\(147).bmp","Farhan\\(148).bmp","Farhan\\(149).bmp","Farhan\\(150).bmp","Farhan\\(151).bmp","Farhan\\(152).bmp"};
char dead_shimr[10][30]={"deadr\\1.bmp","deadr\\2.bmp","deadr\\3.bmp","deadr\\4.bmp","deadr\\5.bmp","deadr\\6.bmp","deadr\\7.bmp","deadr\\8.bmp","deadr\\9.bmp","deadr\\10.bmp"};
char teacher_cku[8][30]={"teacher\\1.bmp","teacher\\2.bmp","teacher\\3.bmp","teacher\\4.bmp","teacher\\5.bmp","teacher\\6.bmp","teacher\\7.bmp","teacher\\8.bmp"};// edit- shimla
int hat_mstr=0;//edit- shimla
char jumppic[12][20] = {"jump\\1.bmp","jump\\2.bmp","jump\\3.bmp","jump\\4.bmp","jump\\5.bmp","jump\\6.bmp","jump\\7.bmp","jump\\8.bmp","jump\\9.bmp",
"jump\\10.bmp"};
char idlepic[12][20] = {"idle\\0.bmp","idle\\1.bmp","idle\\2.bmp","idle\\3.bmp","idle\\4.bmp","idle\\5.bmp","idle\\6.bmp","idle\\7.bmp","idle\\8.bmp","idle\\9.bmp"};

char Ninchaku_throw[12][20] = {"atnin\\0.bmp","atnin\\1.bmp","atnin\\2.bmp","atnin\\3.bmp","atnin\\4.bmp","atnin\\5.bmp","atnin\\6.bmp","atnin\\7.bmp","atnin\\8.bmp",
"atnin\\9.bmp",};
char LeftRun[10][20]={"left\\1.bmp","left\\2.bmp","left\\3.bmp","left\\4.bmp","left\\5.bmp","left\\6.bmp","left\\7.bmp","left\\8.bmp","left\\9.bmp","left\\10.bmp"};
char RunningPic[10][20]={"run\\1.bmp","run\\2.bmp","run\\3.bmp","run\\4.bmp","run\\5.bmp","run\\6.bmp","run\\7.bmp","run\\8.bmp","run\\9.bmp","run\\10.bmp"};

char jumppicr[11][20] = {"jumpr\\1.bmp","jumpr\\1.bmp","jumpr\\2.bmp","jumpr\\3.bmp","jumpr\\4.bmp","jumpr\\5.bmp","jumpr\\6.bmp","jumpr\\7.bmp","jumpr\\8.bmp",
"jumpr\\9.bmp","jumpr\\10.bmp"};
char Ninchaku_throwr[12][20] = {"atninr\\0.bmp","atninr\\1.bmp","atninr\\2.bmp","atninr\\3.bmp","atninr\\4.bmp","atninr\\5.bmp","atninr\\6.bmp","atninr\\7.bmp","atninr\\8.bmp",
"atninr\\9.bmp",};
char idlepicr[12][20] = {"idler\\0.bmp","idler\\1.bmp","idler\\2.bmp","idler\\3.bmp","idler\\4.bmp","idler\\5.bmp","idler\\6.bmp","idler\\7.bmp","idler\\8.bmp","idler\\9.bmp"};
char t1enmy[5][14][20] = { {"t1\\idle\\1.bmp","t1\\idle\\2.bmp","t1\\idle\\3.bmp","t1\\idle\\4.bmp","t1\\idle\\5.bmp","t1\\idle\\6.bmp","t1\\idle\\7.bmp","t1\\idle\\8.bmp"},
                {"t1\\walk\\1.bmp","t1\\walk\\2.bmp","t1\\walk\\3.bmp","t1\\walk\\4.bmp","t1\\walk\\5.bmp","t1\\walk\\6.bmp"},
                {"t1\\run\\2.bmp","t1\\run\\3.bmp","t1\\run\\4.bmp","t1\\run\\5.bmp","t1\\run\\6.bmp","t1\\run\\7.bmp","t1\\run\\8.bmp","t1\\run\\9.bmp","t1\\run\\10.bmp"},
                {"t1\\atk\\1.bmp","t1\\atk\\2.bmp","t1\\atk\\3.bmp","t1\\atk\\4.bmp","t1\\atk\\5.bmp","t1\\atk\\6.bmp"},
                {"t1\\ded\\1.bmp","t1\\ded\\2.bmp","t1\\ded\\3.bmp","t1\\ded\\4.bmp","t1\\ded\\5.bmp","t1\\ded\\6.bmp","t1\\ded\\7.bmp","t1\\ded\\8.bmp","t1\\ded\\9.bmp","t1\\ded\\10.bmp","t1\\ded\\11.bmp","t1\\ded\\12.bmp"} };
char t1enmyr[5][14][20] = { {"t1\\idler\\1.bmp","t1\\idler\\2.bmp","t1\\idler\\3.bmp","t1\\idler\\4.bmp","t1\\idler\\5.bmp","t1\\idler\\6.bmp","t1\\idler\\7.bmp","t1\\idler\\8.bmp"},
                {"t1\\walkr\\1.bmp","t1\\walkr\\2.bmp","t1\\walkr\\3.bmp","t1\\walkr\\4.bmp","t1\\walkr\\5.bmp","t1\\walkr\\6.bmp"},
                {"t1\\runr\\2.bmp","t1\\runr\\3.bmp","t1\\runr\\4.bmp","t1\\runr\\5.bmp","t1\\runr\\6.bmp","t1\\runr\\7.bmp","t1\\runr\\8.bmp","t1\\runr\\9.bmp","t1\\runr\\10.bmp"},
                {"t1\\atkr\\1.bmp","t1\\atkr\\2.bmp","t1\\atkr\\3.bmp","t1\\atkr\\4.bmp","t1\\atkr\\5.bmp","t1\\atkr\\6.bmp"},
                {"t1\\dedr\\1.bmp","t1\\dedr\\2.bmp","t1\\dedr\\3.bmp","t1\\dedr\\4.bmp","t1\\dedr\\5.bmp","t1\\dedr\\6.bmp","t1\\dedr\\7.bmp","t1\\dedr\\8.bmp","t1\\dedr\\9.bmp","t1\\dedr\\10.bmp","t1\\dedr\\11.bmp","t1\\dedr\\12.bmp"} };
char t2enemy[5][14][20] = { {"grl\\idle\\1.bmp","grl\\idle\\2.bmp","grl\\idle\\3.bmp","grl\\idle\\4.bmp","grl\\idle\\5.bmp","grl\\idle\\6.bmp","grl\\idle\\7.bmp","grl\\idle\\8.bmp"},
                {"grl\\walk\\1.bmp","grl\\walk\\2.bmp","grl\\walk\\3.bmp","grl\\walk\\4.bmp","grl\\walk\\5.bmp","grl\\walk\\6.bmp"},
                {"grl\\run\\2.bmp","grl\\run\\3.bmp","grl\\run\\4.bmp","grl\\run\\5.bmp","grl\\run\\6.bmp","grl\\run\\7.bmp","grl\\run\\8.bmp","grl\\run\\9.bmp","grl\\run\\10.bmp"},
                {"grl\\atk\\1.bmp","grl\\atk\\2.bmp","grl\\atk\\3.bmp","grl\\atk\\4.bmp","grl\\atk\\5.bmp","grl\\atk\\6.bmp"},
                {"grl\\ded\\1.bmp","grl\\ded\\2.bmp","grl\\ded\\3.bmp","grl\\ded\\4.bmp","grl\\ded\\5.bmp","grl\\ded\\6.bmp","grl\\ded\\7.bmp","grl\\ded\\8.bmp","grl\\ded\\9.bmp","grl\\ded\\10.bmp","grl\\ded\\11.bmp","grl\\ded\\12.bmp"} };
char num[6][20] = {"num\\0.bmp","num\\1.bmp","num\\2.bmp","num\\3.bmp","num\\4.bmp","num\\5.bmp"};
char t2enemyr[5][14][20] = {{"grl\\idler\\1.bmp","grl\\idler\\2.bmp","grl\\idler\\3.bmp","grl\\idler\\4.bmp","grl\\idler\\5.bmp","grl\\idler\\6.bmp","grl\\idler\\7.bmp","grl\\idler\\8.bmp"},
                {"grl\\walkr\\1.bmp","grl\\walkr\\2.bmp","grl\\walkr\\3.bmp","grl\\walkr\\4.bmp","grl\\walkr\\5.bmp","grl\\walkr\\6.bmp"},
                {"grl\\runr\\2.bmp","grl\\runr\\3.bmp","grl\\runr\\4.bmp","grl\\runr\\5.bmp","grl\\runr\\6.bmp","grl\\runr\\7.bmp","grl\\runr\\8.bmp","grl\\runr\\9.bmp","grl\\runr\\10.bmp"},
                {"grl\\atkr\\1.bmp","grl\\atkr\\2.bmp","grl\\atkr\\3.bmp","grl\\atkr\\4.bmp","grl\\atkr\\5.bmp","grl\\atkr\\6.bmp"},
                {"grl\\dedr\\1.bmp","grl\\dedr\\2.bmp","grl\\dedr\\3.bmp","grl\\dedr\\4.bmp","grl\\dedr\\5.bmp","grl\\dedr\\6.bmp","grl\\dedr\\7.bmp","grl\\dedr\\8.bmp","grl\\dedr\\9.bmp","grl\\dedr\\10.bmp","grl\\dedr\\11.bmp","grl\\dedr\\12.bmp"} };
bool toroal=0;
int one = 1; //default = 1;
int toroal_index=0,toroal_indexr=0;
char toroal_pic[15][25]={"toroal\\1.bmp","toroal\\2.bmp","toroal\\3.bmp","toroal\\4.bmp","toroal\\5.bmp","toroal\\6.bmp","toroal\\7.bmp","toroal\\8.bmp","toroal\\9.bmp","toroal\\10.bmp"};
char toroal_picr[15][25]={"toroalr\\1.bmp","toroalr\\2.bmp","toroalr\\3.bmp","toroalr\\4.bmp","toroalr\\5.bmp","toroalr\\6.bmp","toroalr\\7.bmp","toroalr\\8.bmp","toroalr\\9.bmp","toroalr\\10.bmp"};
int sizt1[5] = {8,6,9,6,12};
char p1[5][14][30] = { {"pirate\\p1\\idle\\1.bmp","pirate\\p1\\idle\\2.bmp","pirate\\p1\\idle\\3.bmp","pirate\\p1\\idle\\4.bmp","pirate\\p1\\idle\\5.bmp","pirate\\p1\\idle\\6.bmp","pirate\\p1\\idle\\7.bmp"},
                {"pirate\\p1\\walk\\1.bmp","pirate\\p1\\walk\\2.bmp","pirate\\p1\\walk\\3.bmp","pirate\\p1\\walk\\4.bmp","pirate\\p1\\walk\\5.bmp","pirate\\p1\\walk\\6.bmp","pirate\\p1\\walk\\7.bmp"},
                {"pirate\\p1\\run\\1.bmp","pirate\\p1\\run\\2.bmp","pirate\\p1\\run\\3.bmp","pirate\\p1\\run\\4.bmp","pirate\\p1\\run\\5.bmp","pirate\\p1\\run\\6.bmp","pirate\\p1\\run\\7.bmp"},
                {"pirate\\p1\\atk\\1.bmp","pirate\\p1\\atk\\2.bmp","pirate\\p1\\atk\\3.bmp","pirate\\p1\\atk\\4.bmp","pirate\\p1\\atk\\5.bmp","pirate\\p1\\atk\\6.bmp","pirate\\p1\\atk\\7.bmp"},
                {"pirate\\p1\\ded\\1.bmp","pirate\\p1\\ded\\2.bmp","pirate\\p1\\ded\\3.bmp","pirate\\p1\\ded\\4.bmp","pirate\\p1\\ded\\5.bmp","pirate\\p1\\ded\\6.bmp","pirate\\p1\\ded\\7.bmp"} };

char p1r[5][14][30] = { {"pirate\\p1\\idler\\1.bmp","pirate\\p1\\idler\\2.bmp","pirate\\p1\\idler\\3.bmp","pirate\\p1\\idler\\4.bmp","pirate\\p1\\idler\\5.bmp","pirate\\p1\\idler\\6.bmp","pirate\\p1\\idler\\7.bmp"},
                {"pirate\\p1\\walkr\\1.bmp","pirate\\p1\\walkr\\2.bmp","pirate\\p1\\walkr\\3.bmp","pirate\\p1\\walkr\\4.bmp","pirate\\p1\\walkr\\5.bmp","pirate\\p1\\walkr\\6.bmp","pirate\\p1\\walkr\\7.bmp"},
                {"pirate\\p1\\runr\\1.bmp","pirate\\p1\\runr\\2.bmp","pirate\\p1\\runr\\3.bmp","pirate\\p1\\runr\\4.bmp","pirate\\p1\\runr\\5.bmp","pirate\\p1\\runr\\6.bmp","pirate\\p1\\runr\\7.bmp"},
                {"pirate\\p1\\atkr\\1.bmp","pirate\\p1\\atkr\\2.bmp","pirate\\p1\\atkr\\3.bmp","pirate\\p1\\atkr\\4.bmp","pirate\\p1\\atkr\\5.bmp","pirate\\p1\\atkr\\6.bmp","pirate\\p1\\atkr\\7.bmp"},
                {"pirate\\p1\\dedr\\1.bmp","pirate\\p1\\dedr\\2.bmp","pirate\\p1\\dedr\\3.bmp","pirate\\p1\\dedr\\4.bmp","pirate\\p1\\dedr\\5.bmp","pirate\\p1\\dedr\\6.bmp","pirate\\p1\\dedr\\7.bmp"} };

char p2[5][14][30] = { {"pirate\\p2\\idle\\1.bmp","pirate\\p2\\idle\\2.bmp","pirate\\p2\\idle\\3.bmp","pirate\\p2\\idle\\4.bmp","pirate\\p2\\idle\\5.bmp","pirate\\p2\\idle\\6.bmp","pirate\\p2\\idle\\7.bmp"},
                {"pirate\\p2\\walk\\1.bmp","pirate\\p2\\walk\\2.bmp","pirate\\p2\\walk\\3.bmp","pirate\\p2\\walk\\4.bmp","pirate\\p2\\walk\\5.bmp","pirate\\p2\\walk\\6.bmp","pirate\\p2\\walk\\7.bmp"},
                {"pirate\\p2\\run\\1.bmp","pirate\\p2\\run\\2.bmp","pirate\\p2\\run\\3.bmp","pirate\\p2\\run\\4.bmp","pirate\\p2\\run\\5.bmp","pirate\\p2\\run\\6.bmp","pirate\\p2\\run\\7.bmp"},
                {"pirate\\p2\\atk\\1.bmp","pirate\\p2\\atk\\2.bmp","pirate\\p2\\atk\\3.bmp","pirate\\p2\\atk\\4.bmp","pirate\\p2\\atk\\5.bmp","pirate\\p2\\atk\\6.bmp","pirate\\p2\\atk\\7.bmp"},
                {"pirate\\p2\\ded\\1.bmp","pirate\\p2\\ded\\2.bmp","pirate\\p2\\ded\\3.bmp","pirate\\p2\\ded\\4.bmp","pirate\\p2\\ded\\5.bmp","pirate\\p2\\ded\\6.bmp","pirate\\p2\\ded\\7.bmp"} };
char p2r[5][14][30] = { {"pirate\\p2\\idler\\1.bmp","pirate\\p2\\idler\\2.bmp","pirate\\p2\\idler\\3.bmp","pirate\\p2\\idler\\4.bmp","pirate\\p2\\idler\\5.bmp","pirate\\p2\\idler\\6.bmp","pirate\\p2\\idler\\7.bmp"},
                {"pirate\\p2\\walkr\\1.bmp","pirate\\p2\\walkr\\2.bmp","pirate\\p2\\walkr\\3.bmp","pirate\\p2\\walkr\\4.bmp","pirate\\p2\\walkr\\5.bmp","pirate\\p2\\walkr\\6.bmp","pirate\\p2\\walkr\\7.bmp"},
                {"pirate\\p2\\runr\\1.bmp","pirate\\p2\\runr\\2.bmp","pirate\\p2\\runr\\3.bmp","pirate\\p2\\runr\\4.bmp","pirate\\p2\\runr\\5.bmp","pirate\\p2\\runr\\6.bmp","pirate\\p2\\runr\\7.bmp"},
                {"pirate\\p2\\atkr\\1.bmp","pirate\\p2\\atkr\\2.bmp","pirate\\p2\\atkr\\3.bmp","pirate\\p2\\atkr\\4.bmp","pirate\\p2\\atkr\\5.bmp","pirate\\p2\\atkr\\6.bmp","pirate\\p2\\atkr\\7.bmp"},
                {"pirate\\p2\\dedr\\1.bmp","pirate\\p2\\dedr\\2.bmp","pirate\\p2\\dedr\\3.bmp","pirate\\p2\\dedr\\4.bmp","pirate\\p2\\dedr\\5.bmp","pirate\\p2\\dedr\\6.bmp","pirate\\p2\\dedr\\7.bmp"} };

char bos[5][14][30] = { {"has\\idle\\1.bmp","has\\idle\\2.bmp","has\\idle\\3.bmp","has\\idle\\4.bmp","has\\idle\\5.bmp","has\\idle\\6.bmp","has\\idle\\7.bmp","has\\idle\\8.bmp","has\\idle\\9.bmp","has\\idle\\10.bmp" },
                {"has\\walk\\1.bmp","has\\walk\\2.bmp","has\\walk\\3.bmp","has\\walk\\4.bmp","has\\walk\\5.bmp","has\\walk\\6.bmp","has\\walk\\7.bmp"},
                {"has\\run\\1.bmp","has\\run\\2.bmp","has\\run\\3.bmp","has\\run\\4.bmp","has\\run\\5.bmp","has\\run\\6.bmp","has\\run\\7.bmp","has\\run\\8.bmp","has\\run\\9.bmp","has\\run\\10.bmp" },
                {"has\\atk\\1.bmp","has\\atk\\2.bmp","has\\atk\\3.bmp","has\\atk\\4.bmp","has\\atk\\5.bmp","has\\atk\\6.bmp","has\\atk\\7.bmp","has\\atk\\8.bmp","has\\atk\\9.bmp","has\\atk\\10.bmp" },
                {"has\\ded\\1.bmp","has\\ded\\2.bmp","has\\ded\\3.bmp","has\\ded\\4.bmp","has\\ded\\5.bmp","has\\ded\\6.bmp","has\\ded\\7.bmp","has\\ded\\8.bmp","has\\ded\\9.bmp","has\\ded\\10.bmp" } };
char bosr[5][14][30] = { {"has\\idler\\1.bmp","has\\idler\\2.bmp","has\\idler\\3.bmp","has\\idler\\4.bmp","has\\idler\\5.bmp","has\\idler\\6.bmp","has\\idler\\7.bmp","has\\idler\\8.bmp","has\\idler\\9.bmp","has\\idler\\10.bmp" },
                {"has\\walkr\\1.bmp","has\\walkr\\2.bmp","has\\walkr\\3.bmp","has\\walkr\\4.bmp","has\\walkr\\5.bmp","has\\walkr\\6.bmp","has\\walkr\\7.bmp"},
                {"has\\runr\\1.bmp","has\\runr\\2.bmp","has\\runr\\3.bmp","has\\runr\\4.bmp","has\\runr\\5.bmp","has\\runr\\6.bmp","has\\runr\\7.bmp","has\\runr\\8.bmp","has\\runr\\9.bmp","has\\runr\\10.bmp" },
                {"has\\atkr\\1.bmp","has\\atkr\\2.bmp","has\\atkr\\3.bmp","has\\atkr\\4.bmp","has\\atkr\\5.bmp","has\\atkr\\6.bmp","has\\atkr\\7.bmp","has\\atkr\\8.bmp","has\\atkr\\9.bmp","has\\atkr\\10.bmp" },
                {"has\\dedr\\1.bmp","has\\dedr\\2.bmp","has\\dedr\\3.bmp","has\\dedr\\4.bmp","has\\dedr\\5.bmp","has\\dedr\\6.bmp","has\\dedr\\7.bmp","has\\dedr\\8.bmp","has\\dedr\\9.bmp","has\\dedr\\10.bmp" } };

char sara_idle[20][30] = {"sara\\idle\\1.bmp", "sara\\idle\\2.bmp", "sara\\idle\\3.bmp", "sara\\idle\\4.bmp", "sara\\idle\\5.bmp", "sara\\idle\\6.bmp", "sara\\idle\\7.bmp", "sara\\idle\\8.bmp", "sara\\idle\\9.bmp", "sara\\idle\\10.bmp", "sara\\idle\\11.bmp", "sara\\idle\\12.bmp", "sara\\idle\\13.bmp", "sara\\idle\\14.bmp", "sara\\idle\\15.bmp", "sara\\idle\\16.bmp"};
char sara_run[20][30] = {"sara\\run\\1.bmp", "sara\\run\\2.bmp", "sara\\run\\3.bmp", "sara\\run\\4.bmp", "sara\\run\\5.bmp", "sara\\run\\6.bmp", "sara\\run\\7.bmp", "sara\\run\\8.bmp", "sara\\run\\9.bmp", "sara\\run\\10.bmp", "sara\\run\\11.bmp", "sara\\run\\12.bmp", "sara\\run\\13.bmp", "sara\\run\\14.bmp", "sara\\run\\15.bmp", "sara\\run\\16.bmp", "sara\\run\\17.bmp", "sara\\run\\18.bmp", "sara\\run\\19.bmp", "sara\\run\\20.bmp"};

char sara_idler[20][30] = {"sara\\idler\\1.bmp", "sara\\idler\\2.bmp", "sara\\idler\\3.bmp", "sara\\idler\\4.bmp", "sara\\idler\\5.bmp", "sara\\idler\\6.bmp", "sara\\idler\\7.bmp", "sara\\idler\\8.bmp", "sara\\idler\\9.bmp", "sara\\idler\\10.bmp", "sara\\idler\\11.bmp", "sara\\idler\\12.bmp", "sara\\idler\\13.bmp", "sara\\idler\\14.bmp", "sara\\idler\\15.bmp", "sara\\idler\\16.bmp"};
char sara_runr[20][30] = {"sara\\runr\\1.bmp", "sara\\runr\\2.bmp", "sara\\runr\\3.bmp", "sara\\runr\\4.bmp", "sara\\runr\\5.bmp", "sara\\runr\\6.bmp", "sara\\runr\\7.bmp", "sara\\runr\\8.bmp", "sara\\runr\\9.bmp", "sara\\runr\\10.bmp", "sara\\runr\\11.bmp", "sara\\runr\\12.bmp", "sara\\runr\\13.bmp", "sara\\runr\\14.bmp", "sara\\runr\\15.bmp", "sara\\runr\\16.bmp", "sara\\runr\\17.bmp", "sara\\runr\\18.bmp", "sara\\runr\\19.bmp", "sara\\runr\\20.bmp"};
int emoji_ind[] = {130, 100, 140, 120, 145, 170, 140};
int SWAT_COME = 0;
int pos[14]={0,1,0,1,1,1,1,0,1,0,0,0,0,0},cnt5=0,cnt6=0, cnt8=-1, cnt9 = 0,cnt10 = 0;
struct enemy1{
    int type, showoff = 0;
    int chaku;
    int state; //0 idle 1 walking 2 running 3 damage 4 dead
    int walking_range, face;
    int base;
    int posx, posy, image_index;
};
set<int>ase, show;
struct arm1{
    int state = 0;
    int posx, posy;
    int face;
};
struct boss{
    int MAX_LIFE = 10;
    int state, seeing_range = 600;
    int feel_range = 200,calcu_x;
    int posx, posy, face, chaku = 0;
    int image_index;
    int base;
    int life = MAX_LIFE;
};
boss hasnain;
arm1 bullet[300];
arm1 ninchuk[30];
enemy1 jombie[number_of_enemy];
// for handeling button, change by farhan
int end_name [] = {-100, -300, -400, -500, -600};
int name_dekha = 0;
char button[10][30] = {"mainmenu\\play.bmp", "mainmenu\\setting.bmp", "mainmenu\\about.bmp"}; // for home page button
// for homemenu image
char act_zombiePic[482][50]={"act_zombie\\(1).bmp","act_zombie\\(2).bmp","act_zombie\\(3).bmp","act_zombie\\(4).bmp","act_zombie\\(5).bmp","act_zombie\\(6).bmp","act_zombie\\(7).bmp","act_zombie\\(8).bmp","act_zombie\\(9).bmp","act_zombie\\(10).bmp","act_zombie\\(11).bmp","act_zombie\\(12).bmp","act_zombie\\(13).bmp","act_zombie\\(14).bmp","act_zombie\\(15).bmp","act_zombie\\(16).bmp","act_zombie\\(17).bmp","act_zombie\\(18).bmp","act_zombie\\(19).bmp","act_zombie\\(20).bmp","act_zombie\\(21).bmp","act_zombie\\(22).bmp","act_zombie\\(23).bmp","act_zombie\\(24).bmp","act_zombie\\(25).bmp","act_zombie\\(26).bmp","act_zombie\\(27).bmp","act_zombie\\(28).bmp","act_zombie\\(29).bmp","act_zombie\\(30).bmp","act_zombie\\(31).bmp","act_zombie\\(32).bmp","act_zombie\\(33).bmp","act_zombie\\(34).bmp","act_zombie\\(35).bmp","act_zombie\\(36).bmp","act_zombie\\(37).bmp","act_zombie\\(38).bmp","act_zombie\\(39).bmp","act_zombie\\(40).bmp","act_zombie\\(41).bmp","act_zombie\\(42).bmp","act_zombie\\(43).bmp","act_zombie\\(44).bmp","act_zombie\\(45).bmp","act_zombie\\(46).bmp","act_zombie\\(47).bmp","act_zombie\\(48).bmp","act_zombie\\(49).bmp","act_zombie\\(50).bmp","act_zombie\\(51).bmp","act_zombie\\(52).bmp","act_zombie\\(53).bmp","act_zombie\\(54).bmp","act_zombie\\(55).bmp","act_zombie\\(56).bmp","act_zombie\\(57).bmp","act_zombie\\(58).bmp","act_zombie\\(59).bmp","act_zombie\\(60).bmp","act_zombie\\(61).bmp","act_zombie\\(62).bmp","act_zombie\\(63).bmp","act_zombie\\(64).bmp","act_zombie\\(65).bmp","act_zombie\\(66).bmp","act_zombie\\(67).bmp","act_zombie\\(68).bmp","act_zombie\\(69).bmp","act_zombie\\(70).bmp","act_zombie\\(71).bmp","act_zombie\\(72).bmp","act_zombie\\(73).bmp","act_zombie\\(74).bmp","act_zombie\\(75).bmp","act_zombie\\(76).bmp","act_zombie\\(77).bmp","act_zombie\\(78).bmp","act_zombie\\(79).bmp","act_zombie\\(80).bmp","act_zombie\\(81).bmp","act_zombie\\(82).bmp","act_zombie\\(83).bmp","act_zombie\\(84).bmp","act_zombie\\(85).bmp","act_zombie\\(86).bmp","act_zombie\\(87).bmp","act_zombie\\(88).bmp","act_zombie\\(89).bmp","act_zombie\\(90).bmp","act_zombie\\(91).bmp","act_zombie\\(92).bmp","act_zombie\\(93).bmp","act_zombie\\(94).bmp","act_zombie\\(95).bmp","act_zombie\\(96).bmp","act_zombie\\(97).bmp","act_zombie\\(98).bmp","act_zombie\\(99).bmp","act_zombie\\(100).bmp","act_zombie\\(101).bmp","act_zombie\\(102).bmp","act_zombie\\(103).bmp","act_zombie\\(104).bmp","act_zombie\\(105).bmp","act_zombie\\(106).bmp","act_zombie\\(107).bmp","act_zombie\\(108).bmp","act_zombie\\(109).bmp","act_zombie\\(110).bmp","act_zombie\\(111).bmp","act_zombie\\(112).bmp","act_zombie\\(113).bmp","act_zombie\\(114).bmp","act_zombie\\(115).bmp","act_zombie\\(116).bmp","act_zombie\\(117).bmp","act_zombie\\(118).bmp","act_zombie\\(119).bmp","act_zombie\\(120).bmp","act_zombie\\(121).bmp","act_zombie\\(122).bmp","act_zombie\\(123).bmp","act_zombie\\(124).bmp","act_zombie\\(125).bmp","act_zombie\\(126).bmp","act_zombie\\(127).bmp","act_zombie\\(128).bmp","act_zombie\\(129).bmp","act_zombie\\(130).bmp","act_zombie\\(131).bmp","act_zombie\\(132).bmp","act_zombie\\(133).bmp","act_zombie\\(134).bmp","act_zombie\\(135).bmp","act_zombie\\(136).bmp","act_zombie\\(137).bmp","act_zombie\\(138).bmp","act_zombie\\(139).bmp","act_zombie\\(140).bmp","act_zombie\\(141).bmp","act_zombie\\(142).bmp","act_zombie\\(143).bmp","act_zombie\\(144).bmp","act_zombie\\(145).bmp","act_zombie\\(146).bmp","act_zombie\\(147).bmp","act_zombie\\(148).bmp","act_zombie\\(149).bmp","act_zombie\\(150).bmp","act_zombie\\(151).bmp","act_zombie\\(152).bmp","act_zombie\\(153).bmp","act_zombie\\(154).bmp","act_zombie\\(155).bmp","act_zombie\\(156).bmp","act_zombie\\(157).bmp","act_zombie\\(158).bmp","act_zombie\\(159).bmp","act_zombie\\(160).bmp","act_zombie\\(161).bmp","act_zombie\\(162).bmp","act_zombie\\(163).bmp","act_zombie\\(164).bmp","act_zombie\\(165).bmp","act_zombie\\(166).bmp","act_zombie\\(167).bmp","act_zombie\\(168).bmp","act_zombie\\(169).bmp","act_zombie\\(170).bmp","act_zombie\\(171).bmp","act_zombie\\(172).bmp","act_zombie\\(173).bmp","act_zombie\\(174).bmp","act_zombie\\(175).bmp","act_zombie\\(176).bmp","act_zombie\\(177).bmp","act_zombie\\(178).bmp","act_zombie\\(179).bmp","act_zombie\\(180).bmp","act_zombie\\(181).bmp","act_zombie\\(182).bmp","act_zombie\\(183).bmp","act_zombie\\(184).bmp","act_zombie\\(185).bmp","act_zombie\\(186).bmp","act_zombie\\(187).bmp","act_zombie\\(188).bmp","act_zombie\\(189).bmp","act_zombie\\(190).bmp","act_zombie\\(191).bmp","act_zombie\\(192).bmp","act_zombie\\(193).bmp","act_zombie\\(194).bmp","act_zombie\\(195).bmp","act_zombie\\(196).bmp","act_zombie\\(197).bmp","act_zombie\\(198).bmp","act_zombie\\(199).bmp","act_zombie\\(200).bmp","act_zombie\\(201).bmp","act_zombie\\(202).bmp","act_zombie\\(203).bmp","act_zombie\\(204).bmp","act_zombie\\(205).bmp","act_zombie\\(206).bmp","act_zombie\\(207).bmp","act_zombie\\(208).bmp","act_zombie\\(209).bmp","act_zombie\\(210).bmp","act_zombie\\(211).bmp","act_zombie\\(212).bmp","act_zombie\\(213).bmp","act_zombie\\(214).bmp","act_zombie\\(215).bmp","act_zombie\\(216).bmp","act_zombie\\(217).bmp","act_zombie\\(218).bmp","act_zombie\\(219).bmp","act_zombie\\(220).bmp","act_zombie\\(221).bmp","act_zombie\\(222).bmp","act_zombie\\(223).bmp","act_zombie\\(224).bmp","act_zombie\\(225).bmp","act_zombie\\(226).bmp","act_zombie\\(227).bmp","act_zombie\\(228).bmp","act_zombie\\(229).bmp","act_zombie\\(230).bmp","act_zombie\\(231).bmp","act_zombie\\(232).bmp","act_zombie\\(233).bmp","act_zombie\\(234).bmp","act_zombie\\(235).bmp","act_zombie\\(236).bmp","act_zombie\\(237).bmp","act_zombie\\(238).bmp","act_zombie\\(239).bmp","act_zombie\\(240).bmp","act_zombie\\(241).bmp","act_zombie\\(242).bmp","act_zombie\\(243).bmp","act_zombie\\(244).bmp","act_zombie\\(245).bmp","act_zombie\\(246).bmp","act_zombie\\(247).bmp","act_zombie\\(248).bmp","act_zombie\\(249).bmp","act_zombie\\(250).bmp","act_zombie\\(251).bmp","act_zombie\\(252).bmp","act_zombie\\(253).bmp","act_zombie\\(254).bmp","act_zombie\\(255).bmp","act_zombie\\(256).bmp","act_zombie\\(257).bmp","act_zombie\\(258).bmp","act_zombie\\(259).bmp","act_zombie\\(260).bmp","act_zombie\\(261).bmp","act_zombie\\(262).bmp","act_zombie\\(263).bmp","act_zombie\\(264).bmp","act_zombie\\(265).bmp","act_zombie\\(266).bmp","act_zombie\\(267).bmp","act_zombie\\(268).bmp","act_zombie\\(269).bmp","act_zombie\\(270).bmp","act_zombie\\(271).bmp","act_zombie\\(272).bmp","act_zombie\\(273).bmp","act_zombie\\(274).bmp","act_zombie\\(275).bmp","act_zombie\\(276).bmp","act_zombie\\(277).bmp","act_zombie\\(278).bmp","act_zombie\\(279).bmp","act_zombie\\(280).bmp","act_zombie\\(281).bmp","act_zombie\\(282).bmp","act_zombie\\(283).bmp","act_zombie\\(284).bmp","act_zombie\\(285).bmp","act_zombie\\(286).bmp","act_zombie\\(287).bmp","act_zombie\\(288).bmp","act_zombie\\(289).bmp","act_zombie\\(290).bmp","act_zombie\\(291).bmp","act_zombie\\(292).bmp","act_zombie\\(293).bmp","act_zombie\\(294).bmp","act_zombie\\(295).bmp","act_zombie\\(296).bmp","act_zombie\\(297).bmp","act_zombie\\(298).bmp","act_zombie\\(299).bmp","act_zombie\\(300).bmp","act_zombie\\(301).bmp","act_zombie\\(302).bmp","act_zombie\\(303).bmp","act_zombie\\(304).bmp","act_zombie\\(305).bmp","act_zombie\\(306).bmp","act_zombie\\(307).bmp","act_zombie\\(308).bmp","act_zombie\\(309).bmp","act_zombie\\(310).bmp","act_zombie\\(311).bmp","act_zombie\\(312).bmp","act_zombie\\(313).bmp","act_zombie\\(314).bmp","act_zombie\\(315).bmp","act_zombie\\(316).bmp","act_zombie\\(317).bmp","act_zombie\\(318).bmp","act_zombie\\(319).bmp","act_zombie\\(320).bmp","act_zombie\\(321).bmp","act_zombie\\(322).bmp","act_zombie\\(323).bmp","act_zombie\\(324).bmp","act_zombie\\(325).bmp","act_zombie\\(326).bmp","act_zombie\\(327).bmp","act_zombie\\(328).bmp","act_zombie\\(329).bmp","act_zombie\\(330).bmp","act_zombie\\(331).bmp","act_zombie\\(332).bmp","act_zombie\\(333).bmp","act_zombie\\(334).bmp","act_zombie\\(335).bmp","act_zombie\\(336).bmp","act_zombie\\(337).bmp","act_zombie\\(338).bmp","act_zombie\\(339).bmp","act_zombie\\(340).bmp","act_zombie\\(341).bmp","act_zombie\\(342).bmp","act_zombie\\(343).bmp","act_zombie\\(344).bmp","act_zombie\\(345).bmp","act_zombie\\(346).bmp","act_zombie\\(347).bmp","act_zombie\\(348).bmp","act_zombie\\(349).bmp","act_zombie\\(350).bmp","act_zombie\\(351).bmp","act_zombie\\(352).bmp","act_zombie\\(353).bmp","act_zombie\\(354).bmp","act_zombie\\(355).bmp","act_zombie\\(356).bmp","act_zombie\\(357).bmp","act_zombie\\(358).bmp","act_zombie\\(359).bmp","act_zombie\\(360).bmp","act_zombie\\(361).bmp","act_zombie\\(362).bmp","act_zombie\\(363).bmp","act_zombie\\(364).bmp","act_zombie\\(365).bmp","act_zombie\\(366).bmp","act_zombie\\(367).bmp","act_zombie\\(368).bmp","act_zombie\\(369).bmp","act_zombie\\(370).bmp","act_zombie\\(371).bmp","act_zombie\\(372).bmp","act_zombie\\(373).bmp","act_zombie\\(374).bmp","act_zombie\\(375).bmp","act_zombie\\(376).bmp","act_zombie\\(377).bmp","act_zombie\\(378).bmp","act_zombie\\(379).bmp","act_zombie\\(380).bmp","act_zombie\\(381).bmp","act_zombie\\(382).bmp","act_zombie\\(383).bmp","act_zombie\\(384).bmp","act_zombie\\(385).bmp","act_zombie\\(386).bmp","act_zombie\\(387).bmp","act_zombie\\(388).bmp","act_zombie\\(389).bmp","act_zombie\\(390).bmp","act_zombie\\(391).bmp","act_zombie\\(392).bmp","act_zombie\\(393).bmp","act_zombie\\(394).bmp","act_zombie\\(395).bmp","act_zombie\\(396).bmp","act_zombie\\(397).bmp","act_zombie\\(398).bmp","act_zombie\\(399).bmp","act_zombie\\(400).bmp","act_zombie\\(401).bmp","act_zombie\\(402).bmp","act_zombie\\(403).bmp","act_zombie\\(404).bmp","act_zombie\\(405).bmp","act_zombie\\(406).bmp","act_zombie\\(407).bmp","act_zombie\\(408).bmp","act_zombie\\(409).bmp","act_zombie\\(410).bmp","act_zombie\\(411).bmp","act_zombie\\(412).bmp","act_zombie\\(413).bmp","act_zombie\\(414).bmp","act_zombie\\(415).bmp","act_zombie\\(416).bmp","act_zombie\\(417).bmp","act_zombie\\(418).bmp","act_zombie\\(419).bmp","act_zombie\\(420).bmp","act_zombie\\(421).bmp","act_zombie\\(422).bmp","act_zombie\\(423).bmp","act_zombie\\(424).bmp","act_zombie\\(425).bmp","act_zombie\\(426).bmp","act_zombie\\(427).bmp","act_zombie\\(428).bmp","act_zombie\\(429).bmp","act_zombie\\(430).bmp","act_zombie\\(431).bmp","act_zombie\\(432).bmp","act_zombie\\(433).bmp","act_zombie\\(434).bmp","act_zombie\\(435).bmp","act_zombie\\(436).bmp","act_zombie\\(437).bmp","act_zombie\\(438).bmp","act_zombie\\(439).bmp","act_zombie\\(440).bmp","act_zombie\\(441).bmp","act_zombie\\(442).bmp","act_zombie\\(443).bmp","act_zombie\\(444).bmp","act_zombie\\(445).bmp","act_zombie\\(446).bmp","act_zombie\\(447).bmp","act_zombie\\(448).bmp","act_zombie\\(449).bmp","act_zombie\\(450).bmp","act_zombie\\(451).bmp","act_zombie\\(452).bmp","act_zombie\\(453).bmp","act_zombie\\(454).bmp","act_zombie\\(455).bmp","act_zombie\\(456).bmp","act_zombie\\(457).bmp","act_zombie\\(458).bmp","act_zombie\\(459).bmp","act_zombie\\(460).bmp","act_zombie\\(461).bmp","act_zombie\\(462).bmp","act_zombie\\(463).bmp","act_zombie\\(464).bmp","act_zombie\\(465).bmp","act_zombie\\(466).bmp","act_zombie\\(467).bmp","act_zombie\\(468).bmp","act_zombie\\(469).bmp","act_zombie\\(470).bmp","act_zombie\\(471).bmp","act_zombie\\(472).bmp","act_zombie\\(473).bmp","act_zombie\\(474).bmp","act_zombie\\(475).bmp","act_zombie\\(476).bmp","act_zombie\\(477).bmp","act_zombie\\(478).bmp","act_zombie\\(479).bmp","act_zombie\\(480).bmp","act_zombie\\(481).bmp","act_zombie\\(482).bmp"};



//farhan
char shimla_glid[15][30] = {"glide\\(1).bmp", "glide\\(2).bmp","glide\\(3).bmp","glide\\(4).bmp","glide\\(5).bmp","glide\\(6).bmp","glide\\(7).bmp","glide\\(8).bmp","glide\\(9).bmp","glide\\(10).bmp",};
char shimla_glidr[15][30] = {"glider\\(1).bmp", "glider\\(2).bmp","glider\\(3).bmp","glider\\(4).bmp","glider\\(5).bmp","glider\\(6).bmp","glider\\(7).bmp","glider\\(8).bmp","glider\\(9).bmp","glider\\(10).bmp",};
int glid_index = 0, glid_on = 0;
int glid_indexr = 0;



struct buttonCordinate {
    int x;
    int y;
}bCordinate[3];
// end here, by farhan
#include "show_girl.hpp";

void iDraw()
{
    //place your drawing codes here
    iClear();


    //farhan



    if(act_zombie){
        iShowBMP(0,0,act_zombiePic[act_zombie_index]);
        iShowBMP2(0,636, "bk\\not.bmp",255);
        return;
    }
    if(act_farhan){
        iShowBMP(0,0,farhan[min(farhan_image_index, 151)]);
        return;
    }
    if(act_ashiq){
        iShowBMP(0,0,ashiq_video[ashiq_image_index]);
        return;
    }
    if(game_state == -1) {
        iShowBMP2(0, 0, "bk\\set_back.bmp", 0);
        iShowBMP2(650, 300, "bk\\close.bmp", 0);
        iShowBMP2(1300-149, 0, "music_on_off\\back.bmp", 0);
        if(music == 1) {
            iShowBMP2(450, 300, "music_on_off\\music.bmp", 0);
        } else if(music == 0) {
            iShowBMP2(450, 300, "music_on_off\\music_off.bmp", 0);
        }
    }
    else if(game_state == -2) {
        iShowBMP2(0, 0, "bk\\ins2.bmp", 255);
        iShowBMP2(0, 0, "bk\\ins.bmp", 255);
        iShowBMP2(1300-149, 0, "music_on_off\\back.bmp", 0);
    }
    else if(game_state == 0) {
        iShowBMP(0, 0, "mainmenu\\menu.bmp");
        for(int i = 0; i < 3; i++) {
            iShowBMP2(bCordinate[i].x, bCordinate[i].y, button[i], 255);
        }
    } // end here
    else if(game_state == 1){ // fy farhan
        if(one == 1){
            iShowBMP(0,0,"bk\\one.bmp");
            return;
        }
        else if(one == 2){
            iShowBMP(0,0,"bk\\cout.bmp");
            return;
        }
        iShowBMP(0,0,"bk\\0.bmp");
        show_jombie();
        show_girl();
        if(pos[game_state]){//-start - shimla
            freez = 1;
        iShowBMP2(0,0,"conversation\\1.bmp",255);
        }//end - shimla
    }
    else if(game_state == 2){
        iShowBMP(0,0,"bk\\1.bmp");
        show_jombie();
        show_girl();
        iShowBMP2(450,161,"bk\\brg.bmp",255);
    }
    else if(game_state == 3){
        iShowBMP(0,0,"bk\\3.bmp");
        show_jombie();
        show_girl();
        iShowBMP2(0,135,"bk\\f1.bmp",255);
        if(pos[game_state]){//start - shimla
        freez = 1;
        iShowBMP2(0,0,"conversation\\3.bmp",255);//end - shimla
        }
    }
    else if(game_state == 4){
        iShowBMP(0,0,"bk\\4.bmp");
        show_jombie();
        if(!jump){
                show_girl();
                iShowBMP2(82,220,"bk\\thik.bmp",255);
        }
        else {
                iShowBMP2(82,220,"bk\\thik.bmp",255);
                show_girl();
        }
        if(pos[game_state]){//start - shimla
        freez = 1;
        iShowBMP2(0,0,"conversation\\4.bmp",255); }

    }
    else if(game_state == 5){
        iShowBMP(0,0,"bk\\bg.bmp");
        iShowBMP2(100,60,"bk\\gorto.bmp", 255);
        show_jombie();
        show_girl();
        if(pos[game_state]){//start - shimla
        freez = 1;
        iShowBMP2(0,0,"conversation\\8.bmp",255);
        iShowBMP2(1200, 140, sara_idler[sara_idle_index], 255);
        iShowBMP2(1170, 100,"bk\\case.bmp", 255);
        }
        else if(cnt5==0)
        {
        freez = 1;
          iShowBMP2(0,0,"conversation\\9.bmp",255);
          iShowBMP2(1200, 140, sara_idler[sara_idle_index], 255);
        iShowBMP2(1170, 100,"bk\\case.bmp", 255);
        }//end - shimla
        iShowBMP2(35,10,"bk\\gto.bmp",255);
        iShowBMP2(0,0,"bk\\gto2.bmp",255); // end -shimla
        if(SWAT_COME){
            print_swat();
        }
    }
    else if(game_state == 6){
        iShowBMP(0,0,"bk\\bg.bmp");
        iShowBMP2(100,60,"bk\\gorto.bmp", 255);
        show_jombie();
        show_girl();
        print_swat();
        if(pos[game_state]){//start - shimla
        freez = 1;
        iShowBMP2(0,0,"conversation\\10.bmp",255); }
        else if(cnt6==0)
        {
            freez = 1;
          iShowBMP2(0,0,"conversation\\11.bmp",255);
        }
        else if(cnt6==1){ freez = 1;
        iShowBMP2(0,0,"conversation\\12.bmp",255);}
        else if(cnt6==2) { freez = 1;
        iShowBMP2(0,0,"conversation\\13.bmp",255);}
        else if(cnt6==3) { freez = 1;
        iShowBMP2(0,0,"conversation\\14.bmp",255);}
        else if(cnt6==4) { freez = 1;
        iShowBMP2(0,0,"conversation\\15.bmp",255);}
        else if(cnt6==5) { freez = 1;
        iShowBMP2(0,0,"conversation\\16.bmp",255);}
        else if(cnt6==6) { freez = 1;
        iShowBMP2(0,0,"conversation\\17.bmp",255);}
        else if(cnt6 == 7){
            iShowBMP2(0,0,"conversation\\n.bmp", 255);
        }
            // end - shimla
        iShowBMP2(35,10,"bk\\gto.bmp",255);
        iShowBMP2(0,0,"bk\\gto2.bmp",255); // end -shimla
    }
    else if(game_state == 7){
        iShowBMP(0,0,"bk\\8.bmp");
        show_jombie();
        show_girl();
        iShowBMP2(0,250, "bk\\81.bmp",255);
    }
    else if(game_state == 8){
         iShowBMP(0,0,"bk\\9.bmp");
        show_jombie();
        if(ZOMBIE_DONE){
            //print ashiq here
            if(GIRL_X >= 1050){
                iShowBMP2(GIRL_X - 200, GIRL_Y-10, "bk\\ass.bmp",255);
                FACE = 0;
            }
            else {
                iShowBMP2(GIRL_X + 100, GIRL_Y-10, "bk\\as.bmp",255);
            }
            show_girl();
            if(pos[game_state]){ freez = 1;
            iShowBMP2(0,0,"conversation\\18.bmp",255);}
            else if(cnt8 == -1){
                freez = 1;
                iShowBMP2(0,0,"conversation\\19.bmp", 255);
            }
            else if(cnt8==0) { freez = 1;
            iShowBMP2(0,0,"conversation\\20.bmp",255);}
            else if(cnt8==1) { freez = 1;
            iShowBMP2(0,0,"conversation\\21.bmp",255);}
            else if(cnt8==2) { freez = 1;
            iShowBMP2(0,0,"conversation\\22.bmp",255);}
            else if(cnt8==3) { freez = 1;
            iShowBMP2(0,0,"conversation\\23.bmp",255);}
            else if(cnt8==4) { freez = 1;
            iShowBMP2(0,0,"conversation\\24.bmp",255);}
            else if(cnt8==5) { freez = 1;
            iShowBMP2(0,0,"conversation\\25.bmp",255);}
            else if(cnt8==6) { freez = 1;
            iShowBMP2(0,0,"conversation\\26.bmp",255);}
            else if(cnt8==7) { freez = 1;
            iShowBMP2(0,0,"conversation\\27.bmp",255);}
            else if(cnt8==8) { freez = 1;
            iShowBMP2(0,0,"conversation\\28.bmp",255);}
            else if(cnt8==9) { freez = 1;
            iShowBMP2(0,0,"conversation\\29.bmp",255);}
            else if(cnt8==10) { freez = 1;
            iShowBMP2(0,0,"conversation\\s.bmp",255);}
            else if(cnt8 == 11){
            iShowBMP2(0,0,"conversation\\n.bmp", 255);
            }
        }
        else show_girl();
    }
    else if(game_state == 9){
        iShowBMP(0,0,"bk\\trn.bmp");
        show_girl();
        iShowBMP2(50,380,teacher_cku[teacher_index],255);
        if(cnt9 == 0){
            iShowBMP2(0,0,"conversation\\30.bmp", 255);
        }
        else if(cnt9 == 1){
            iShowBMP2(0,0,"conversation\\31.bmp",255);
        }
    }
    else if(game_state == 10){
        iShowBMP(0,0,"bk\\15.bmp");
        show_jombie();
        show_girl();
    }
    else if(game_state == 11){
        iShowBMP(0,0,"bk\\11.bmp");
        show_jombie();
        show_girl();
    }
    else if(game_state == 12){
        iShowBMP(0,0,"bk\\12.bmp");
        show_jombie();
        show_girl();
    }
    else if(game_state == 13){
        iShowBMP(0,0,"bk\\13b.bmp");
        show_jombie();
        show_girl();
    }
    else if(game_state == 14){
        iShowBMP(0,0,"bk\\13.bmp");
        show_jombie();
        show_girl();
        if(case_ache == 1) {
            iShowBMP2(1100, 60, sara_idle[sara_idle_index], 255);
            iShowBMP2(1070, 20,"bk\\case.bmp", 255);
        }
        show_jombie();
        show_girl();
        if(case_ache == 0) {
                if(sara_x > GIRL_X + 65) iShowBMP2(sara_x, sara_y, sara_runr[sara_index], 255);
                else iShowBMP2(sara_x, sara_y, sara_idler[sara_idle_index], 255);
        }
        if(cnt10 == 0){ freez = 1;
            iShowBMP2(0,0,"conversation\\32.bmp", 255);
        }
        else if(cnt10 == 1){ freez = 1;
            iShowBMP2(0,0,"conversation\\33.bmp", 255);
        }
        else if(cnt10 == 2){ freez = 1;
            iShowBMP2(0,0,"conversation\\34.bmp", 255);
        }
        if(abs(sara_x-GIRL_X) <= 65 && hasnain.state == 4) {
            iShowBMP2(sara_x - 120, emoji_ind[0], "emoji\\1.bmp", 255);
            iShowBMP2(sara_x - 0, emoji_ind[1], "emoji\\2.bmp", 255);
            iShowBMP2(sara_x - 65, emoji_ind[2], "emoji\\3.bmp", 255);
            iShowBMP2(sara_x - 35, emoji_ind[3], "emoji\\4.bmp", 255);
            iShowBMP2(sara_x + 40, emoji_ind[4], "emoji\\5.bmp", 255);
            iShowBMP2(sara_x + 75, emoji_ind[5], "emoji\\6.bmp", 255);
            iShowBMP2(sara_x + 110, emoji_ind[6], "emoji\\13.bmp", 255);
        }
        if(name_dekha == 25) {
                iShowBMP2(380, end_name[0], "bk\\name1.bmp", 255);
                iShowBMP2(360, end_name[1], "bk\\creator.bmp", 255);
                iShowBMP2(300, end_name[2], "bk\\shimla.bmp", 255);
                iShowBMP2(310, end_name[3], "bk\\farhan.bmp", 255);
                iShowBMP2(290, end_name[4], "bk\\ashiq.bmp", 255);
        }
    }
    else if(game_state==15)//start - shimla
    {
      iShowBMP2(0, 0, "bk\\17.bmp",255);
      show_jombie();
      show_girl();
      iShowBMP2(344,205,"bk\\27.bmp",255);
    }//


}
#include "functions.hpp"
void place_enemy(){
    show.clear();
    for(int i = 0; i < 50; i++){
        ase.insert(i);
    }
    if(game_state == 5 || game_state == 14){
        hasnain.life = hasnain.MAX_LIFE;
        hasnain.posx = 900;
        hasnain.posy = FLOOR[game_state][0][0] ;
        hasnain.face = 0,
        hasnain.chaku = 0;
        hasnain.image_index = 0;
        hasnain.state = 0;
    }
    else hasnain.state = 4;
    int dif = (desktop_hor-500)/number_of_enemy;
    int space = 400;
    if(game_state == 6 ){
        space = 3000;
    }
    for(int i = 0; i < number_of_enemy; i++){
        jombie[i].type = base+(rng_pk%UNLOCKED_CHARACTER);
        //cng here
        jombie[i].image_index = i;
        if(i&1) jombie[i].base = space+(i*dif);
        else jombie[i].base = (i*dif)+space;
        jombie[i].chaku = 0;
        jombie[i].face = rng_pk%2;
        jombie[i].image_index = 0;
        jombie[i].state = i&1;
        int typo = rng_pk%2;
        jombie[i].posx = jombie[i].base;
        if(typo&1 && game_state != 6) jombie[i].posx = min(jombie[i].base + (rng_pk%200), 1200);
        else if(i || (game_state != 5 && game_state != 6) ) {
            jombie[i].posx = max(space,jombie[i].base - (rng_pk%200));
        }
        jombie[i].posx = max(jombie[i].posx, space);
        if(jombie[i].state == 1){
            jombie[i].posx = max(jombie[i].posx, space+200);
        }
        jombie[i].posy = FLOOR[game_state][0][0];
        jombie[i].walking_range = 200;
        if(game_state == 6 || game_state == 9){
            jombie[i].state = 4;
        }
    }
    if(game_state == 4){
        vector<int>sl;
        for(int i = 0; i < number_of_enemy; i++){
            sl.push_back(i);
        }
        shuffle(sl.begin(), sl.end(), rng);
        for(int i = 0; i < min(4, number_of_enemy); i++){
            jombie[i].type = 3;
            jombie[i].walking_range = 75;
            jombie[i].posy = 448;
            jombie[i].state = rng_pk%2;
            if(i == 0){
                jombie[i].base = 140;
                jombie[i].posy = 448;
            }
            if(i == 1){
                jombie[i].base = 410;
                jombie[i].posy = 388;
            }
            if(i == 2){
                jombie[i].base = 970;
                jombie[i].posy = 344;
            }
            if(i == 3){
                jombie[i].base =  650;
                jombie[i].posy = 241;
            }
            jombie[i].posx = jombie[i].base;
            int typo = rng_pk%2;
            if(typo&1) jombie[i].posx = min(jombie[i].base + (rng_pk%75), 1200);
            else jombie[i].posx = jombie[i].base - (rng_pk%75);
        }
        for(int i = 4; i< number_of_enemy; i++){
            jombie[i].type = 2;
        }
    }
    if(game_state == 12){
        vector<int>sl;
        for(int i = 0; i < number_of_enemy; i++){
            sl.push_back(i);
        }
        shuffle(sl.begin(), sl.end(), rng);
        for(int i = 0; i < min(2, number_of_enemy); i++){
            jombie[i].type = 3;
            jombie[i].walking_range = 75;
            jombie[i].posy = 448;
            jombie[i].state = rng_pk%2;
            if(i == 0){
                jombie[i].face = 0;
                jombie[i].type = 3;
                jombie[i].state = 0;
                jombie[i].base = 775;
                jombie[i].posy = 235;
            }
            if(i == 1){
                jombie[i].type = 3;
                jombie[i].face = 0;
                jombie[i].base = 1000;
                jombie[i].posy = 420;
            }
            jombie[i].posx = jombie[i].base;
        }
    }

}
void fix_image(){
    image_fix[4][3] = 5;
    image_fix[4][2] = 15;
    image_fix[10][2] = 10;
    image_fix[12][2] = 20;
    image_fix[13][2] = 20;
}
void place_floor(){
    for(int i = 1; i <= 15; i++){
        for(int j = 0; j <= 1300; j++){
            for(int k = 0; k <= 800; k++){
                if(i == 1){
                    FLOOR[i][j][k] = 100;
                }
                else if(i == 2){
                    FLOOR[i][j][k] = 200;
                }
                else if(i == 3){
                    FLOOR[i][j][k] = 150;
                }
                else if(i == 4){
                    FLOOR[i][j][k] = 81;
                    if(j >= 50 && j <= 370 && k >= 448){
                            FLOOR[i][j][k] = 448;
                    }
                    else if(j >= 390 && j <= 667 && k >= 388){  //bug here
                            FLOOR[i][j][k] = 388;
                    }
                    else if(j >= 915 && j <= 1200 && k >= 344){
                            FLOOR[i][j][k] = 344;
                    }
                    else if(j >= 597 && j <= 915 && k >= 241){
                            FLOOR[i][j][k] = 241;
                    }
                }
                else if(i == 5 || i == 6){
                    FLOOR[i][j][k] = 140;
                    if(j>=120 && j<=280)
                        FLOOR[i][j][k]=0;
                }
                else if(i == 7){
                    FLOOR[i][j][k] = 260;
                    if(j <= 650){
                        int pin = 320 - floor(0.0924*(j));
                        FLOOR[i][j][k] = pin;
                    }
                    if(j >= 650 && j <= 1080){
                        int pin = 258 + floor(0.1*(j-650));
                        FLOOR[i][j][k] = pin;
                    }
                    if(j >= 1070){
                        FLOOR[i][j][k] = 335;
                    }
                }
                else if(i == 12){
                    FLOOR[i][j][k] = 90;
                    if(j >= 650 && j <= 850){
                        int kin = 90 - floor(0.225*(j-650));
                        FLOOR[i][j][k] = kin;
                    }
                    if(j > 850 && j <= 1075){
                        int kin = 45 + floor(0.225*(j-850));
                        FLOOR[i][j][k] = kin;
                    }
                    if(j > 1075 && j <= 1270){
                        int kin = 45+50.625 + floor(0.63782*(j-1075));
                        FLOOR[i][j][k] = kin;
                    }
                    if(j > 1270 && k >= 175 && k < 405){
                        FLOOR[i][j][k] = 175;
                    }
                    if(j >= 810 && j <= 930){
                        if(k >= 143){
                            FLOOR[i][j][k] = 143;
                        }
                    }
                    if(j >= 780 && j <= 955){
                        if(k >= 235){
                            FLOOR[i][j][k] = 235;
                        }
                    }
                    if(j >= 815 && k >= 405){
                        FLOOR[i][j][k] = 405;
                    }
                    if(j >= 1150 && k >= 405){
                        FLOOR[i][j][k] = 420;
                    }
                }
                else if(i == 8){
                    FLOOR[i][j][k] = 150;
                }
                else if(i == 11){
                    FLOOR[i][j][k] = 200;
                }
                else if(i == 13){
                    FLOOR[i][j][k] = 110;
                }
                else if(i==10)// start - shimla
                {
                    if(j<=650){
                       int pin = 275 - floor(0.0924*(j));
                       FLOOR[i][j][k]=pin;
                    }
                    //low 650 - 220
                    else if(j <= 1085){
                        int pin = 220+(.23*(j-650));
                        FLOOR[i][j][k] = pin;
                    }
                    else FLOOR[i][j][k] = 330;
                }
                else if(i == 9){
                    FLOOR[i][j][k] = 390;
                }
                else if(i == 14){
                    FLOOR[i][j][k] = 60;
                }
                else if(i==15)// start- shimla
                {
                   FLOOR[i][j][k] = 280;
                }// end - shimla
            }
        }
    }
}

#include "ikeyboard.hpp";
int main()
{
    //SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
    fix_image();
    //SWAT_POSX = 0;
    //SWAT_POSY = 140;
    srand(time(NULL));
    place_floor();
     int sum  = 100;
    for(int i = 2; i >= 0; i--) {
        bCordinate[i].x = desktop_hor-250;
        bCordinate[i].y = sum;
        sum += 170;
    }
    place_enemy();
    if(music){
        PlaySound("start.wav", NULL, SND_LOOP | SND_ASYNC);
    }
    sounds[0].openFromFile("touch.wav");
    sounds[0].setVolume(45.f);
    sounds[1].openFromFile("knife1.wav");
    sounds[2].openFromFile("sword.wav");
    sounds[3].openFromFile("knife3.wav");
    sounds[4].openFromFile("shim_dead.wav");//shimla/////////////////////////////////////////////////////////////////////
    sounds[5].openFromFile("pirate_sword.wav");
    sounds[6].openFromFile("hasnain_dead.wav");
    sounds[7].openFromFile("hammer.wav");
    sounds[8].openFromFile("pistol.wav");
    iSetTimer(10, change);
    //GetDesktopResolution(desktop_hor, desktop_ver);
    iInitialize(desktop_hor, desktop_ver, "Demo!");
    return 0;
}
