#include "iGraphics.h"
#include<bits/stdc++.h>
using namespace std;
int desktop_hor = 900, desktop_ver = 600;
long long int TIME_NOW = 0;
#include <windows.h>
bool jump = false;
int r = 0,g = 255, b = 0;
int FLOOR = 0;
bool NIN_SHOW = false, NIN_THROW = false;
int FACE = 0; //0 mane bam , 1 mane dane
int GIRL_X = 0, GIRL_Y = FLOOR;
int jumppic_index = 0, idle_index = 0;
int NINCAKU_X , NINCAKU_Y;
int nin_throw_idx = 0;
char jumppic[12][100] = {"jump\\1.bmp","jump\\2.bmp","jump\\3.bmp","jump\\4.bmp","jump\\5.bmp","jump\\6.bmp","jump\\7.bmp","jump\\8.bmp","jump\\9.bmp",
"jump\\10.bmp"};
char idlepic[12][100] = {"t1\\idle\\(1).bmp","idle\\1.bmp","idle\\2.bmp","idle\\3.bmp","idle\\4.bmp","idle\\5.bmp","idle\\6.bmp","idle\\7.bmp","idle\\8.bmp","idle\\9.bmp"};

char Ninchaku_throw[12][100] = {"atnin\\0.bmp","atnin\\1.bmp","atnin\\2.bmp","atnin\\3.bmp","atnin\\4.bmp","atnin\\5.bmp","atnin\\6.bmp","atnin\\7.bmp","atnin\\8.bmp",
"atnin\\9.bmp",};

#include "functions.hpp"
void iDraw()
{
    //place your drawing codes here
    iClear();
    iShowBMP(0,0,"jump\\0.bmp");
    if(jump){
        iShowBMP2(GIRL_X,GIRL_Y,jumppic[jumppic_index],255);
    }
    else if(NIN_THROW){
        iShowBMP2(GIRL_X, GIRL_Y, Ninchaku_throw[nin_throw_idx], 255);
    }
    else{
        iShowBMP2(GIRL_X, GIRL_Y, idlepic[idle_index],255);
    }
    if(NIN_SHOW){
            NINCAKU_Y = GIRL_Y + 75;
        iShowBMP2(NINCAKU_X, NINCAKU_Y, "atnin\\x.bmp", 255);
    }
}
/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //printf("x = %d, y= %d\n",mx,my);
    //place your codes here
}
/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {

    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
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
            NINCAKU_X = GIRL_X + 120;
        NINCAKU_Y =GIRL_Y +75;
        NIN_THROW = true;
    }
    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    //place your codes for other keys here
}

void change(){
    TIME_NOW ++;
    if(TIME_NOW > 1e18) TIME_NOW = 0;
    if(TIME_NOW%6 == 0){
            //normal moves
        if(jump){
            jumppic_index++;
            if(jumppic_index <= 5){
                GIRL_X += 20;
                GIRL_Y += 20;
            }
            else if(jumppic_index == 10){
                GIRL_Y -= 20;
                jumppic_index = 0;
                jump = false;
            }
            else{
                GIRL_X += 20;
                GIRL_Y -= 20;
            }
            GIRL_X = min(GIRL_X,desktop_hor-100);
        }
        else{
            idle_index++;
            if(idle_index > 9) idle_index = 0;
        }
        if(NIN_THROW){
            nin_throw_idx++;
            if(nin_throw_idx == 8){
                NIN_SHOW = true;
            }
            if(nin_throw_idx == 10){
                NIN_THROW = false;
                nin_throw_idx = 0;
            }
        }
    }
    else if(TIME_NOW == 2){
    }
    else if(TIME_NOW){
        if(NIN_SHOW){
            NINCAKU_X += 15;
            if(NINCAKU_X > desktop_hor){
                NIN_SHOW = FALSE;
            }
        }
    }
}
int main()
{
    iSetTimer(10, change);
    //place your own initialization codes here.
    //GetDesktopResolution(desktop_hor, desktop_ver);
    iInitialize(desktop_hor, desktop_ver, "Demo!");
    return 0;
}

