
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
            if(NIN_COUNT >= 5 || NIN_THROW) return;
            NIN_THROW = 1;
            NIN_COUNT++;
            for(int i = 0; i < 5; i++){
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
}
