#include "iGraphics.h"
#include<bits/stdc++.h>
#include <mmsystem.h>
using namespace std;
int GRAVITY_SPEED = 40, base= 0,touch_sound=0,touch_continue=0;
int ENEMY_SEEING_RANGE = 300;
int MAX_NINCHUK = 3, GIRL_JUMP_Y = 50;
const int number_of_enemy = 1;
int life_left=10;
int desktop_hor = 1300, desktop_ver = 700;
long long int TIME_NOW = 0;
#include <windows.h>
int throwing_now = 0;
bool jump = false;
int r = 0,g = 255, b = 0;
int tolowar_dmg = 0;
int FLOOR[20][1400][1000]; // game_state & x,y,
bool NIN_THROW = false;
bool RUN_STATUS = false;
int NIN_COUNT = 0, UNLOCKED_CHARACTER = 1;
int FACE = 1; //0 mane bam , 1 mane dane
int GIRL_X = 0, GIRL_Y = 100;
vector<int>chakus_in_dead_body;
int jumppic_index = 0, idle_index = 0;
int nin_throw_idx = 0, music = 1;
int RunPicIndex1=0;
int RunPicIndex2=0;
int TIME_TO_STOP = 0;
int jumppic_indexr = 0, idle_indexr = 0, nin_throw_idxr = 0;

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

struct enemy1{
    int type;
    int chaku;
    int state; //0 idle 1 walking 2 running 3 damage 4 dead
    int walking_range, face;
    int base;
    int posx, posy, image_index;
};
struct arm1{
    int state = 0;
    int posx, posy;
    int face;
};
arm1 ninchuk[30];
enemy1 jombie[number_of_enemy];
// for handeling button, change by farhan
char button[10][30] = {"mainmenu\\play.bmp", "mainmenu\\setting.bmp", "mainmenu\\about.bmp"}; // for home page button
// for homemenu image
int game_state = 4;
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
    // for handeling button, change by farhan
    if(game_state == 0) {
        iShowBMP(0, 0, "mainmenu\\menu.bmp");
        for(int i = 0; i < 3; i++) {
            iShowBMP2(bCordinate[i].x, bCordinate[i].y, button[i], 255);
        }
    } // end here
    else if(game_state == 1){ // fy farhan
        iShowBMP(0,0,"bk\\0.bmp");
        show_jombie();
        show_girl();
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
    }
    else if(game_state == 4){
        iShowBMP(0,0,"bk\\4.bmp");
        show_jombie();
        show_girl();
    }
}
#include "functions.hpp"
void place_floor(){
    for(int i = 1; i <= 13; i++){
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
                if(i == 4){
                    FLOOR[i][j][k] = 81;
                    if(j >= 50 && j <= 370){
                        if( k >= 444){
                            FLOOR[i][j][k] = 444;
                        }
                    }
                    if(j >= 390 && j <= 645){
                        if( k >= 384){
                            FLOOR[i][j][k] = 384;
                        }
                    }
                    if(j >= 915 && j <= 1200){
                        if( k >= 344){
                            FLOOR[i][j][k] = 344;
                        }
                    }
                    if(j >= 600 && j <= 915){
                        if( k >= 239){
                            FLOOR[i][j][k] = 239;
                        }
                    }
                    //onest = 50, oneen = 370;
                    //twost = 390, twoen = 645;
                    //threest = 600, threeen = 915;
                    //fourst = 915, fouren = 1200;
                    //floor = 81;
                    //one = 444;
                    //two = 384;
                    //three = 239;
                    //four = 344;
                }
            }
        }
    }
}
void place_enemy(){
    int dif = (desktop_hor-500)/number_of_enemy;
    for(int i = 0; i < number_of_enemy; i++){
        jombie[i].type = base+(rand()%UNLOCKED_CHARACTER);
        jombie[i].image_index = rand()%6;
        if(i&1) jombie[i].base = 400+(i*dif);
        else jombie[i].base = 400+(i*dif);
        jombie[i].chaku = 0;
        jombie[i].face = rand()%2;
        jombie[i].image_index = 0;
        jombie[i].state = i%2;
        jombie[i].posx = jombie[i].base;
        jombie[i].posy = FLOOR[game_state][0][0];
        jombie[i].walking_range = 200;
        if(jombie[i].type > 1){
            jombie[i].posy -= 10;
        }
    }
}
#include "ikeyboard.hpp";
int main()
{
    // for homemenu, by farhan, start
    srand(time(NULL));
    place_floor();
     int sum  = 100;
    for(int i = 2; i >= 0; i--) {
        bCordinate[i].x = desktop_hor-250;
        bCordinate[i].y = sum;
        sum += 170;
    }
    // end, farhan
    GIRL_X = 1200;
    GIRL_Y = FLOOR[game_state][0][0];
    place_enemy();
    if(music){
        PlaySound("start.wav", NULL, SND_LOOP | SND_ASYNC);
    }
    iSetTimer(10, change);
    //GetDesktopResolution(desktop_hor, desktop_ver);
    iInitialize(desktop_hor, desktop_ver, "Demo!");
    return 0;
}
