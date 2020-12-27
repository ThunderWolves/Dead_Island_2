void iMouseMove(int mx, int my)
{

}
void iMouse(int button, int state, int mx, int my)
{
    // by farhan, start
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        for(int i = 0; i < 3; i++) {
            if(mx >= bCordinate[i].x && mx <= bCordinate[i].x + 149 && my >= bCordinate[i].y && my <= bCordinate[i].y + 150) {
                game_state = 1;
                place_enemy();
                if(music){
                    PlaySound("music.wav", NULL,SND_LOOP | SND_ASYNC);
                }
            }
        }
    }
    // by farhan, end
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
    }
}

void iSpecialKeyboard(unsigned char key)
{
    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
}

void iKeyboard(unsigned char key)
{
    if(key == 'q')
    {
        exit(0);
    }
    if(key == 'm'){
            music ^= 1;
        if(music){
        PlaySound("music.wav", NULL, SND_LOOP | SND_ASYNC);
        }
        else PlaySound(0,0,0);
    }
    if(key == 'w'){
        jump = true;
    }
    if(key == ' '){
            RUN_STATUS = 0;
            if(NIN_COUNT >= MAX_NINCHUK || NIN_THROW) return;
            NIN_THROW = 1;
            NIN_COUNT++;
            for(int i = 0; i < MAX_NINCHUK; i++){
                if(ninchuk[i].state == 1) continue;
                throwing_now = i;
                ninchuk[i].face = FACE;
                if(ninchuk[i].face == 0) ninchuk[i].posx = GIRL_X - 100;
                else ninchuk[i].posx = GIRL_X + 100;
                ninchuk[i].posy = GIRL_Y + 75;
                break;
            }
    }
    if(key=='d')
    {
        NIN_THROW = 0;
        if(NIN_THROW && max(nin_throw_idx, nin_throw_idxr) < 4) return;
        if(jump) return;
        TIME_TO_STOP = TIME_NOW + 20;
        if(TIME_TO_STOP > 1e18) TIME_TO_STOP -= 1e18-1;
        RUN_STATUS = true;
        if(FACE==0)
        {
            FACE=1;
        }
        GIRL_X+=10;
        RunPicIndex1++;
        if(RunPicIndex1>=10)
        RunPicIndex1=0;
        GIRL_X = min(desktop_hor-100, GIRL_X);
        GIRL_X = max(GIRL_X, 0);
    }
    if(key=='a')
    {
        NIN_THROW = 0;
        if(NIN_THROW && max(nin_throw_idx, nin_throw_idxr) < 4) return;
        if(jump) return;
        TIME_TO_STOP = TIME_NOW + 20;
        if(TIME_TO_STOP > 1e18) TIME_TO_STOP -= 1e18-1;
        RUN_STATUS = true;
        if(FACE==1)
        {
            FACE=0;
        }
        GIRL_X-=10;
        RunPicIndex2++;
            if(RunPicIndex2>=10)
                RunPicIndex2=0;
        GIRL_X = min(desktop_hor-100, GIRL_X);
        GIRL_X = max(GIRL_X, 0);
    }
    if(key == 'n'){
        for(int i = 0;i < number_of_enemy; i++){
            if(jombie[i].state != 4){
                return;
            }
        }
        if(GIRL_X >= desktop_hor-150){
            game_state++;
            place_enemy();
            GIRL_X = 0;
            GIRL_Y = FLOOR[game_state][0][0];

        }
    }
}
