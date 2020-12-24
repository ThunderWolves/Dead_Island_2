#include "iGraphics.h"
#include<bits/stdc++.h>
using namespace std;
int ENEMY_SEEING_RANGE = 400;
const int number_of_enemy = 3;
int desktop_hor = 800, desktop_ver = 500;
long long int TIME_NOW = 0;
#include <windows.h>
bool jump = false;
int r = 0,g = 255, b = 0;
int FLOOR = 0;
bool RUN_STATUS = false;
bool NIN_SHOW = false, NIN_THROW = false;
int FACE = 1; //0 mane bam , 1 mane dane
int nin_face = 0;
int GIRL_X = 0, GIRL_Y = FLOOR;
int jumppic_index = 0, idle_index = 0;
int NINCAKU_X , NINCAKU_Y;
int nin_throw_idx = 0;
int RunPicIndex1=0;
int RunPicIndex2=0;
int TIME_TO_STOP = 0;
int jumppic_indexr = 0, idle_indexr = 0, nin_throw_idxr = 0;
char jumppic[12][100] = {"jump\\1.bmp","jump\\2.bmp","jump\\3.bmp","jump\\4.bmp","jump\\5.bmp","jump\\6.bmp","jump\\7.bmp","jump\\8.bmp","jump\\9.bmp",
"jump\\10.bmp"};
char idlepic[12][100] = {"idle\\0.bmp","idle\\1.bmp","idle\\2.bmp","idle\\3.bmp","idle\\4.bmp","idle\\5.bmp","idle\\6.bmp","idle\\7.bmp","idle\\8.bmp","idle\\9.bmp"};

char Ninchaku_throw[12][100] = {"atnin\\0.bmp","atnin\\1.bmp","atnin\\2.bmp","atnin\\3.bmp","atnin\\4.bmp","atnin\\5.bmp","atnin\\6.bmp","atnin\\7.bmp","atnin\\8.bmp",
"atnin\\9.bmp",};
char LeftRun[10][100]={"left\\1.bmp","left\\2.bmp","left\\3.bmp","left\\4.bmp","left\\5.bmp","left\\6.bmp","left\\7.bmp","left\\8.bmp","left\\9.bmp","left\\10.bmp"};
char RunningPic[10][100]={"run\\1.bmp","run\\2.bmp","run\\3.bmp","run\\4.bmp","run\\5.bmp","run\\6.bmp","run\\7.bmp","run\\8.bmp","run\\9.bmp","run\\10.bmp"};

char jumppicr[11][100] = {"jumpr\\1.bmp","jumpr\\1.bmp","jumpr\\2.bmp","jumpr\\3.bmp","jumpr\\4.bmp","jumpr\\5.bmp","jumpr\\6.bmp","jumpr\\7.bmp","jumpr\\8.bmp",
"jumpr\\9.bmp","jumpr\\10.bmp"};
char Ninchaku_throwr[12][100] = {"atninr\\0.bmp","atninr\\1.bmp","atninr\\2.bmp","atninr\\3.bmp","atninr\\4.bmp","atninr\\5.bmp","atninr\\6.bmp","atninr\\7.bmp","atninr\\8.bmp",
"atninr\\9.bmp",};
char idlepicr[12][100] = {"idler\\0.bmp","idler\\1.bmp","idler\\2.bmp","idler\\3.bmp","idler\\4.bmp","idler\\5.bmp","idler\\6.bmp","idler\\7.bmp","idler\\8.bmp","idler\\9.bmp"};
char t1enmy[5][12][100] = { {"t1\\idle\\1.bmp","t1\\idle\\2.bmp","t1\\idle\\3.bmp","t1\\idle\\4.bmp","t1\\idle\\5.bmp","t1\\idle\\6.bmp","t1\\idle\\7.bmp","t1\\idle\\8.bmp"},
                {"t1\\walk\\1.bmp","t1\\walk\\2.bmp","t1\\walk\\3.bmp","t1\\walk\\4.bmp","t1\\walk\\5.bmp","t1\\walk\\6.bmp"},
                {"t1\\run\\2.bmp","t1\\run\\3.bmp","t1\\run\\4.bmp","t1\\run\\5.bmp","t1\\run\\6.bmp","t1\\run\\7.bmp","t1\\run\\8.bmp","t1\\run\\9.bmp","t1\\run\\10.bmp"},
                {"t1\\atk\\1.bmp","t1\\atk\\2.bmp","t1\\atk\\3.bmp","t1\\atk\\4.bmp","t1\\atk\\5.bmp","t1\\atk\\6.bmp"},
                {"t1\\ded\\1.bmp","t1\\ded\\2.bmp","t1\\ded\\3.bmp","t1\\ded\\4.bmp","t1\\ded\\5.bmp","t1\\ded\\6.bmp","t1\\ded\\7.bmp","t1\\ded\\8.bmp"} };
char t1enmyr[5][12][100] = { {"t1\\idler\\1.bmp","t1\\idler\\2.bmp","t1\\idler\\3.bmp","t1\\idler\\4.bmp","t1\\idler\\5.bmp","t1\\idler\\6.bmp","t1\\idler\\7.bmp","t1\\idler\\8.bmp"},
                {"t1\\walkr\\1.bmp","t1\\walkr\\2.bmp","t1\\walkr\\3.bmp","t1\\walkr\\4.bmp","t1\\walkr\\5.bmp","t1\\walkr\\6.bmp"},
                {"t1\\runr\\2.bmp","t1\\runr\\3.bmp","t1\\runr\\4.bmp","t1\\runr\\5.bmp","t1\\runr\\6.bmp","t1\\runr\\7.bmp","t1\\runr\\8.bmp","t1\\runr\\9.bmp","t1\\runr\\10.bmp"},
                {"t1\\atkr\\1.bmp","t1\\atkr\\2.bmp","t1\\atkr\\3.bmp","t1\\atkr\\4.bmp","t1\\atkr\\5.bmp","t1\\atkr\\6.bmp"},
                {"t1\\dedr\\1.bmp","t1\\dedr\\2.bmp","t1\\dedr\\3.bmp","t1\\dedr\\4.bmp","t1\\dedr\\5.bmp","t1\\dedr\\6.bmp","t1\\dedr\\7.bmp","t1\\dedr\\8.bmp"} };
int sizt1[5] = {8,6,9,6,8};
struct enemy1{
    int state; //0 idle 1 walking 2 running 3 damage 4 dead
    int walking_range, face;
    int base;
    int posx, posy, image_index;
};
enemy1 jombie[number_of_enemy];
#include "functions.hpp"
void iDraw()
{
    //place your drawing codes here
    iClear();
    iShowBMP(0,0,"jump\\0.bmp");
    if(NIN_THROW){
        if(FACE == 1)
        iShowBMP2(GIRL_X, GIRL_Y, Ninchaku_throw[nin_throw_idx], 255);
        else iShowBMP2(GIRL_X, GIRL_Y, Ninchaku_throwr[nin_throw_idxr], 255);
    }
    else if(jump){
        if(FACE == 1)
        iShowBMP2(GIRL_X,GIRL_Y,jumppic[jumppic_index],255);
        else iShowBMP2(GIRL_X,GIRL_Y,jumppicr[jumppic_indexr],255);
    }
    else if(RUN_STATUS){
        if(FACE) iShowBMP2(GIRL_X,GIRL_Y,RunningPic[RunPicIndex1],255);
        else iShowBMP2(GIRL_X,GIRL_Y,LeftRun[RunPicIndex2],255);
    }
    else{
        if(FACE == 1)
        iShowBMP2(GIRL_X, GIRL_Y, idlepic[idle_index],255);
        else iShowBMP2(GIRL_X, GIRL_Y, idlepicr[idle_indexr],255);
    }
    if(NIN_SHOW){
            if(nin_face == 0){
                iShowBMP2(NINCAKU_X, NINCAKU_Y, "atninr\\x.bmp", 255);
            }
            else iShowBMP2(NINCAKU_X, NINCAKU_Y, "atnin\\x.bmp", 255);
    }
    for(int i = 0; i < number_of_enemy; i++){
        if(jombie[i].face == 1)
        iShowBMP2(jombie[i].posx, jombie[i].posy, t1enmy[jombie[i].state][jombie[i].image_index], 255);
        else iShowBMP2(jombie[i].posx, jombie[i].posy, t1enmyr[jombie[i].state][jombie[i].image_index], 255);
    }
}

void iMouseMove(int mx, int my)
{

}
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {

    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
    }
}

void iKeyboard(unsigned char key)
{
    if(key == 'q')
    {
        exit(0);
    }
    if(key == 'w'){
        jump = true;
    }
    if(key == ' '){
            if(NIN_SHOW) return;
            nin_face = FACE;
            if(FACE == 1)
            NINCAKU_X = GIRL_X + 120;
            else NINCAKU_X = GIRL_X - 120;
        NINCAKU_Y =GIRL_Y +75;
        NIN_THROW = true;
    }
    if(key=='d')
    {
        if(jump) return;
        TIME_TO_STOP = TIME_NOW + 20;
        if(TIME_TO_STOP > 1e18) TIME_TO_STOP -= 1e18-1;
        RUN_STATUS = true;
        if(FACE==0)
        {
            FACE=1;
        }
        GIRL_X+=10;
        if(GIRL_X>=900)
        {
            GIRL_X=900;
        }
        RunPicIndex1++;
        if(RunPicIndex1>=10)
        RunPicIndex1=0;
        GIRL_X = min(desktop_hor-100, GIRL_X);
        GIRL_X = max(GIRL_X, 0);
    }
    if(key=='a')
    {
        if(jump) return;
        TIME_TO_STOP = TIME_NOW + 20;
        if(TIME_TO_STOP > 1e18) TIME_TO_STOP -= 1e18-1;
        RUN_STATUS = true;
        if(FACE==1)
        {
            FACE=0;
        }
        GIRL_X-=10;
        if(GIRL_X<0)
            GIRL_X=0;
        RunPicIndex2++;
            if(RunPicIndex2>=10)
                RunPicIndex2=0;
        GIRL_X = min(desktop_hor-100, GIRL_X);
        GIRL_X = max(GIRL_X, 0);
    }
}

void iSpecialKeyboard(unsigned char key)
{
    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
}

void place_enemy(){
    for(int i = 0; i < number_of_enemy; i++){
        jombie[i].base =  500+(rand()%500);
        jombie[i].face = rand()%2;
        jombie[i].image_index = 0;
        jombie[i].state = i%2;
        jombie[i].posx = jombie[i].base;
        jombie[i].posy = FLOOR;
        jombie[i].walking_range = 200;
    }
}

int main()
{
    place_enemy();
    iSetTimer(10, change);
    //GetDesktopResolution(desktop_hor, desktop_ver);
    iInitialize(desktop_hor, desktop_ver, "Demo!");
    return 0;
}

