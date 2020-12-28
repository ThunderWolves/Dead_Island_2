// Get the horizontal and vertical screen sizes in pixel
void GetDesktopResolution(int& horizontal, int& vertical)
{
   RECT desktop;
   // Get a handle to the desktop window
   const HWND hDesktop = GetDesktopWindow();
   // Get the size of screen to the variable desktop
   GetWindowRect(hDesktop, &desktop);
   // The top left corner will have coordinates (0,0)
   // and the bottom right corner will have coordinates
   // (horizontal, vertical)
   horizontal = desktop.right;
   vertical = desktop.bottom;
}

void change(){
    if(game_state < 1) return;
    TIME_NOW ++;
    if(TIME_NOW > 1e18) TIME_NOW = 0;
    if(TIME_NOW%5 == 0){
            //normal moves
        if(jump){
            if(FACE == 1){
                jumppic_index++;
                if(jumppic_index <= 5){
                    GIRL_X += 30;
                    GIRL_Y += 35;
                }
                else if(jumppic_index == 10){
                    GIRL_Y -= 35;
                    GIRL_Y = max(GIRL_Y, FLOOR[game_state][GIRL_X][GIRL_Y]);
                    jumppic_index = 0;
                    jump = false;
                }
                else{
                    GIRL_X += 30;
                    GIRL_Y -= 35;
                    GIRL_Y = max(GIRL_Y, FLOOR[game_state][GIRL_X][GIRL_Y]);
                }
                GIRL_X = min(desktop_hor-80, GIRL_X);
            }
            else{
                jumppic_indexr++;
                if(jumppic_indexr <= 5){
                    GIRL_X -= 30;
                    GIRL_Y += 35;
                }
                else if(jumppic_indexr == 10){
                    GIRL_Y -= 35;
                    jumppic_indexr = 0;
                    jump = false;
                }
                else{
                    GIRL_X -= 30;
                    GIRL_Y -= 35;
                }
            }
            GIRL_X = max(GIRL_X, 0);
        }
        else{
            if(FACE == 1){
                idle_index++;
                if(idle_index > 9) idle_index = 0;
            }
            else{
                idle_indexr++;
                if(idle_indexr > 9) idle_indexr = 0;
            }
        }

        for(int i = 0; i < number_of_enemy; i++){
            if(jombie[i].state == 4 ){
                if(jombie[i].image_index >= 10){
                    jombie[i].image_index = 7;
                    continue;
                }
            }
            jombie[i].image_index++;
            if(jombie[i].image_index >= sizt1[jombie[i].state]){
                if(jombie[i].state == 2) jombie[i].image_index = 3;
                else jombie[i].image_index = 0;
            }
            if(jombie[i].state == 1 || jombie[i].state == 0){
                if(abs(GIRL_X - jombie[i].posx) <= ENEMY_SEEING_RANGE){
                    bool GIRL_ar_dik = 0;
                    if(GIRL_X > jombie[i].posx ){
                        GIRL_ar_dik = 1;
                    }
                    if(GIRL_ar_dik == jombie[i].face){
                        jombie[i].state = 2;
                        jombie[i].image_index = 0;
                    }
                }
            }
            if(jombie[i].state == 2 || jombie[i].state == 3){
                if(abs(GIRL_X - jombie[i].posx) <= 50 && jombie[i].state == 3){
                    continue;
                }
                else if(GIRL_X > jombie[i].posx){
                        jombie[i].face = 1;
                    jombie[i].posx += 15;
                }
                else if(GIRL_X < jombie[i].posx){
                    jombie[i].face = 0;
                    jombie[i].posx -= 15;
                }
                if(abs(GIRL_X - jombie[i].posx) <= 50 && jombie[i].state == 2 ){
                    jombie[i].state = 3;
                    jombie[i].image_index = 0;
                }
                else if(abs(GIRL_X - jombie[i].posx) > 50 && jombie[i].state == 3){
                    jombie[i].state = 2;
                    jombie[i].image_index = 0;
                }
                if(jump){
                    jombie[i].state = 2;
                }
            }
            if(jombie[i].state == 1){
                if(jombie[i].face == 1){
                    jombie[i].posx += 10;
                    jombie[i].posx = min(jombie[i].posx, desktop_hor-50);
                }
                else{
                    jombie[i].posx -= 10;
                    jombie[i].posx = max(jombie[i].posx, 0);
                }
                if(abs(jombie[i].base - jombie[i].posx) >= jombie[i].walking_range){
                    jombie[i].face ^= 1;
                }
                if(jombie[i].posx >= desktop_hor-50){
                    jombie[i].face = 0;
                }
            }
        }

    }
    if(TIME_NOW%15==0 && life_left > 0)
    {
        touch_continue=0;
        for(int i = 0; i < number_of_enemy; i++)
         {
            if(jombie[i].state==3)
            {
                touch_continue=1;
            if(touch_sound==0 && music)
                PlaySound("touch.wav", NULL, SND_LOOP | SND_ASYNC);
            life_left=life_left-1;
            touch_sound=1;
            }
         }
      if(touch_continue==0)
      {
          if(touch_sound==1 && music)
         {
            touch_sound=0;
          PlaySound("music.wav", NULL, SND_LOOP | SND_ASYNC);
         }
      }
    }
    if(TIME_NOW%4==0){
            if(FACE == 1){
                if(NIN_THROW){
                nin_throw_idx++;
                if(nin_throw_idx == 8){
                    NIN_COUNT++;
                    ninchuk[throwing_now].state = 1;
                }
                if(nin_throw_idx == 10){
                    NIN_THROW = false;
                    nin_throw_idx = 0;
                }
                }
                 else if(toroal)//start- shimla
                {
                toroal_index++;
                if(toroal_index== 10){
                    toroal=0;
                    toroal_index=0;
                }
                }
            }
            else{
                if(NIN_THROW){
                    nin_throw_idxr++;
                    if(nin_throw_idxr == 8){
                        NIN_COUNT++;
                        ninchuk[throwing_now].state = 1;
                    }
                    if(nin_throw_idxr == 10){
                    NIN_THROW = false;
                    nin_throw_idxr = 0;
                    }
                }else if(toroal)//start- shimla
                {
                toroal_indexr++;
                if(toroal_indexr== 10){
                    toroal=0;
                    toroal_indexr=0;
                }// end- shimla
               }
            }
    }
    if(TIME_NOW%3 == 0){
        if(GIRL_Y > FLOOR[game_state][GIRL_X][GIRL_Y] && !jump){
            int dif = GIRL_Y - FLOOR[game_state][GIRL_X][GIRL_Y];
            GIRL_Y -= min(dif, GRAVITY_SPEED);
        }
        for(int i = 0; i < MAX_NINCHUK; i++){
            if(ninchuk[i].state != 1) continue;
            if(ninchuk[i].face) ninchuk[i].posx += 51;
            else ninchuk[i].posx -= 51;
            if(ninchuk[i].posx > desktop_hor || ninchuk[i].posx < -100){
                ninchuk[i].state = 0;
                NIN_COUNT--;
            }
            for(int ii = 0; ii < number_of_enemy; ii++){
                if(ninchuk[i].posy > jombie[ii].posy+150+(50*(jombie[ii].state == 1)) || ninchuk[i].posy < jombie[ii].posy) continue;
                if(jombie[ii].state == 4) continue;
                if(GIRL_X <= jombie[ii].posx && ninchuk[i].posx >= jombie[ii].posx ||
                        (GIRL_X >= jombie[ii].posx && ninchuk[i].posx <= jombie[ii].posx)){
                    chakus_in_dead_body.push_back(i);
                    ninchuk[i].state = 2;
                    jombie[ii].state = 4;
                    jombie[ii].chaku = 1;
                    jombie[ii].image_index = 0;
                    goto hell;
                }
            }
            hell:;
        }
        for(int ii = 0; ii < number_of_enemy; ii++){
            if(abs(jombie[ii].posx - GIRL_X) < 50 && jombie[ii].chaku && jombie[ii].state == 4){
                    int km = chakus_in_dead_body.back();
                    ninchuk[km].state = 0;
                    NIN_COUNT--;
                    jombie[ii].chaku = 0;
            }
        }
        for(int ii = 0; ii < number_of_enemy ; ii++){
            if(((GIRL_X+90 >= jombie[ii].posx && GIRL_X<=jombie[ii].posx ) ||(GIRL_X - 60<= jombie[ii].posx && GIRL_X>=jombie[ii].posx)) && jombie[ii].state !=4 && toroal==1)
            {
                if(abs(GIRL_Y - jombie[ii].posy) > 50 || !tolowar_dmg) continue;
                jombie[ii].state=4;
                jombie[ii].image_index = 0;
                tolowar_dmg = 0;
                break;
            }
        }
    }
    if(TIME_NOW == TIME_TO_STOP ){
        RUN_STATUS = false;
    }
}
