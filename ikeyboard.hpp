void iMouseMove(int mx, int my)
{

}
void iMouse(int button, int state, int mx, int my)
{
    // by farhan, start
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(game_state > 0) return;
        for(int i = 0; i < 3; i++) {
            if(mx >= bCordinate[i].x && mx <= bCordinate[i].x + 149 && my >= bCordinate[i].y && my <= bCordinate[i].y + 150) {
                if(i == 1) {
                    game_state = -1;
                    //cout << "settings\n";

                    continue;
                }
                if(i == 2) {
                    game_state = -2;
                    //cout << "information\n";
                    continue;
                }
                game_state = 1;
                place_enemy();
                if(music){
                    PlaySound("music.wav", NULL,SND_LOOP | SND_ASYNC);
                }
            }
        }

        if(game_state == -1) {
            if(mx >= 300 && mx <= 449 && my >= 300 && my <= 450) {
                music ^= 1;
                if(music) {
                    PlaySound("music.wav", NULL, SND_LOOP | SND_ASYNC);
                }
                else {
                    PlaySound(0,0,0);
                }
            }
            else if(mx >= 1300-149 && mx <= 1300 && my >= 0 && my <= 150) {
                game_state = 0;
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
    if(key >= 'A' && key <= 'Z') key = char(key+32);
    if(key == 'p'){
            music ^= 1;
        if(music){
        PlaySound("music.wav", NULL, SND_LOOP | SND_ASYNC);
        }
        else PlaySound(0,0,0);
    }
    if(key == 'f'){
        if(game_state != 6) return;
        act_farhan = 1;
        PlaySound("Farhan//Farhan.wav", NULL, SND_ASYNC);
    }
    if(key == 'h'){
        if(game_state != 8) return;
        act_ashiq = 1;
        PlaySound("ashiq_video//ashiq.wav", NULL, SND_ASYNC);
    }
    if(key == 'q')
    {
        exit(0);
    }
    if(key=='e')// start- shimla
    {
        freez = 0;
        if(pos[game_state]==1)
        pos[game_state]=0;
        else if(cnt5==0 && game_state==5)
            cnt5=-1;
        else if(cnt6<7 && game_state==6 && pos[game_state]==0)
        cnt6++;
        else if(game_state==8 && cnt8<=10 && pos[game_state]==0)
        cnt8++;
        else if(game_state == 9){
            cnt9++;
        }
        else if(game_state == 14){
            cnt10++;
        }
        if(SWAT_COME || (game_state == 6 && cnt6 == 7) || (game_state == 8 && cnt8 == 11)){
            press_n = 1;
        }
    }// end- shimla
    if(freez) return;
    if(key == 'n'){
            if(!press_n){
        for(int i = 0;i < number_of_enemy; i++){
            if(jombie[i].state != 4 && game_state != 9){
                return;
            }
        }
        if(hasnain.state != 4) return;
            }
        if(GIRL_X >= desktop_hor-100|| game_state == 9 || press_n){
                case_ache = 1;
            game_state++;
            GIRL_X = 0;
            GIRL_Y = FLOOR[game_state][0][0];
            if(game_state > 1){
                UNLOCKED_CHARACTER = 2;
            }
            if(game_state <= 3){
                base = 2;
            }
            else if(game_state <= 6){
                FACE = 1;
                SWAT_POSX = 0;
                base = 2;
            }
            else if(game_state == 7){
                    ZOMBIE_DONE = 0;
                base = 0;
            }
            else if(game_state == 8){
                ZOMBIE_DONE = 0;
                base = 2;
            }
            else if(game_state <= 9){
                NIN_COUNT = 0;
                for(int i =0; i < MAX_NINCHUK; i++){
                    ninchuk[i].state = 0;
                }
                chakus_in_dead_body.clear();
                base = 0;
            }
            else if(game_state == 10){
                FACE = 1;
            }
            else if(game_state <= 11){
                base = 0;
            }
            else if(game_state <= 13){
                base = 2;
            }
            if(game_state == 6){
                life_left = 10;
                GIRL_X = 350;
            }
            place_enemy();
            if(game_state == 9){
                FACE = 0;
                GIRL_X = 1045;
            }
        }
        press_n = 0;
    }
    if(press_n || life_left <= 0) return;
    if(key=='m' && game_state>=1)
    {
        toroal=1;
        RUN_STATUS = 0;
        NIN_THROW = 0;tolowar_dmg = 1;
    }
    if(game_state == 9) return;
    if(key == 'w'){
        jump = true;
    }
    if(key == ' '){
            RUN_STATUS = 0;
            if(NIN_COUNT >= MAX_NINCHUK || NIN_THROW) return;
            NIN_THROW = 1;
            for(int i = 0; i < MAX_NINCHUK; i++){
                if(ninchuk[i].state == 1) continue;
                throwing_now = i;
                break;
            }
    }
    if(key=='d')
    {
        GIRL_Y = max(GIRL_Y, FLOOR[game_state][GIRL_X][GIRL_Y]);
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
        if(game_state == 7){
            if(GIRL_Y < 335){
                GIRL_X = min(GIRL_X, desktop_hor-240);
            }
        }
        GIRL_X = min(desktop_hor-100, GIRL_X);
        GIRL_X = max(GIRL_X, 0);
    }
    if(key=='a')
    {
        GIRL_Y = max(GIRL_Y, FLOOR[game_state][GIRL_X][GIRL_Y]);
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

}
