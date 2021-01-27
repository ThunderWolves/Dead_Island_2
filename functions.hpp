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

    //farhan
    if(jump == 0 && GIRL_Y > FLOOR[game_state][GIRL_X][GIRL_Y] + 60)  {
        glid_on = 1;
        if(FACE == 1) {
            glid_index++;
            glid_index %= 10;
        } else {
            glid_indexr++;
            glid_indexr %= 10;
        }

    } else {
        glid_on = 0;
    }


    TIME_NOW ++;
    if(TIME_NOW > 1e18) TIME_NOW = 0;
    if(TIME_NOW%6 == 0){
            if(act_ashiq){
            ashiq_image_index++;
            if(ashiq_image_index >= 152){
                act_ashiq = 0;
                if(music){
                    PlaySound("music.wav", NULL, SND_LOOP | SND_ASYNC);
                }
                else PlaySound(0,0,0);
            }
        return;
    }
            if(act_zombie){
            act_zombie_index++;
            if(act_zombie_index>=481)
            {
                act_zombie=0;
                PlaySound("horror.wav", NULL, SND_LOOP | SND_ASYNC);
            }
            return;
        }
        if((dead_shim_index==2 || dead_shim_indexr==2) && (shim_dead_sound==0))
            {
                shim_dead_sound=1;
                if(off_game_sound==0)
                {
                    off_game_sound=1;
                    PlaySound(0,0,0);
                }
                sounds[4].stop();
                sounds[4].play();
            }
    }
    if(game_state < 1) return;
        if(TIME_NOW%6 == 0){
        if(act_farhan)
            farhan_image_index++;
        if(farhan_image_index >= 154){
            act_farhan = 0;
            if(music)
            PlaySound("music.wav", NULL, SND_LOOP | SND_ASYNC);
            else PlaySound(0,0,0);
        return;
        }
        }
    if(TIME_NOW%5 == 0){
            if(hasnain.state == 4 && hasnain_dead_music == 0 && game_state == 14) {
            //cout << "dead\n";
            hasnain_dead_music = 1;
            sounds[6].stop();
            sounds[6].play();
            //sounds[4].setPlayingOffset(sf::seconds((float)2.0));
        }
            if(life_left<=0 && dead_shim_index<=8 && FACE)
                {
                    dead_shim_index++;
                }
            else if(life_left<=0 && dead_shim_indexr<=8)
                dead_shim_indexr++;

            if(game_state==9 && teacher_index<=6)
            {
                teacher_index++;
            }
            else if(game_state==9 && teacher_index==7)
            {
                if(hat_mstr<=0)
                teacher_index=0;
                hat_mstr++;
            }
       //image index start
       if(sara_x == GIRL_X + 65 && hasnain.state == 4) {
        for(int i = 0; i < 7; i++) {
            emoji_ind[i] += 20;
        }
      }
            sara_idle_index++;
            sara_idle_index %= 16;
        for(int i = 0; i < number_of_enemy; i++){
            jombie[i].image_index++;
            if(jombie[i].state == 4 ){
                if(jombie[i].image_index >= 10){
                    jombie[i].image_index = 7;
                    continue;
                }
            }
            if(jombie[i].image_index >= sizt1[jombie[i].state]){
                if(jombie[i].state == 2) jombie[i].image_index = 3;
                else jombie[i].image_index = 0;
            }
            if(jombie[i].type > 1){
                if(jombie[i].state == 4 && jombie[i].image_index >= 7) jombie[i].image_index = 6;
                else if(jombie[i].image_index >= 7) jombie[i].image_index = 0;
            }
        }
        if(hasnain.image_index == 6 && hasnain.state == 3){ life_left--;
        }
        if(hasnain.state == 3 && hasnain.image_index == 4){
            sounds[7].stop();
            sounds[7].play();
            sounds[7].setPlayingOffset(sf::seconds(float(0.8)));
        }
        hasnain.image_index++;
        if(hasnain.image_index >= 10){
            if(hasnain.state == 4) hasnain.image_index = 9;
            else hasnain.image_index = 0;
        }
    //image index done
        if((SWAT_COME || press_n) && game_state == 5){
            for(int i = 0; i < number_of_enemy; i++){
                if(jombie[i].state != 4){
                    jombie[i].state = 2;
                    jombie[i].face = 1;
                    jombie[i].posx += 20;
                    if(jombie[i].posx > 1350) jombie[i].state = 4;
                }
            }
            hasnain.state = 2;
            hasnain.face = 1;
            hasnain.posx += 20;
            if(hasnain.posx >  1350 ) hasnain.state = 4;
            return;
        }
        if(life_left <= -3 && SWAT_COME == 0 && game_state == 5){
            SWAT_COME = 1;
        }
        if(case_ache == 0) {
          if(sara_x > GIRL_X + 65) sara_x -= min(sara_x - GIRL_X - 65, 20);
          else sara_x = GIRL_X + 65;
          sara_index++;
          sara_index %= 20;
      }
        int has_pas = 80;
        if(abs(hasnain.posy - GIRL_Y) >= 300 && hasnain.state != 4) {
            hasnain.state = 0; hasnain.image_index= 0;
        }
        else if(hasnain.state != 4){
            if(abs(hasnain.posx - GIRL_X) <= hasnain.feel_range && hasnain.state == 0) hasnain.state = 2;
            if(hasnain.posx > GIRL_X-65){
                if(hasnain.state == 3){
                    hasnain.face = 0;
                    if(hasnain.posx - GIRL_X > has_pas){
                        hasnain.state = 2;
                        hasnain.image_index = 0;
                        hasnain.posx -= 10;
                    }
                }
                else if(hasnain.state == 2){
                    hasnain.face = 0;
                    hasnain.posx -= 15;
                }
                else if(hasnain.state == 0){
                    if(hasnain.face == 0){
                        if(hasnain.posx - GIRL_X <= hasnain.seeing_range){
                            hasnain.state = 2;
                            hasnain.image_index = 0;
                        }
                    }
                }
                if(hasnain.posx - GIRL_X <= has_pas && hasnain.state != 3 && hasnain.state <= 3){
                        hasnain.state = 3;
                        hasnain.image_index = 0;
                    }
            }
            else{
                if(hasnain.state == 3){
                    hasnain.face = 1;
                    if(0-hasnain.posx + GIRL_X > has_pas+150){
                        hasnain.state = 2;
                        hasnain.image_index = 0;
                        hasnain.posx += 10;
                    }
                }
                else if(hasnain.state == 2){
                    hasnain.face = 1;
                    hasnain.posx += 15;
                }
                else if(hasnain.state == 0){
                    if(hasnain.face == 1){
                        if(-hasnain.posx + GIRL_X <= hasnain.seeing_range){
                            hasnain.state = 2;
                            hasnain.image_index = 0;
                        }
                    }
                }
                if(-hasnain.posx + GIRL_X <= has_pas+150 && hasnain.state != 3 && hasnain.state <= 3){
                    hasnain.state = 3;
                    hasnain.image_index = 0;
                }
            }
        }


        if(GIRL_X >= 120 && GIRL_X <= 280 && GIRL_Y <= 140 && (game_state == 5 || game_state == 6))
            life_left -= 2;
        GIRL_Y = max(GIRL_Y, FLOOR[game_state][GIRL_X][GIRL_Y]);
        if(jump){
            if(FACE == 1){
                jumppic_index++;
                if(jumppic_index <= 5){
                    GIRL_X += 30;
                    GIRL_Y += GIRL_JUMP_Y;
                }
                else if(jumppic_index == 10){
                    int dif = GIRL_Y - FLOOR[game_state][GIRL_X][GIRL_Y];
                    dif= min(dif, GIRL_JUMP_Y);
                    jumppic_index = 0;
                    jump = false;
                }
                else{
                    int dif = GIRL_Y - FLOOR[game_state][GIRL_X][GIRL_Y];
                    dif= min(dif, GIRL_JUMP_Y);
                    GIRL_X += max(0,dif-5);
                    GIRL_Y -= dif;
                }
                GIRL_X = min(desktop_hor-80, GIRL_X);
            }
            else{
                jumppic_indexr++;
                if(jumppic_indexr <= 5){
                    GIRL_X -= 30;
                    GIRL_Y += GIRL_JUMP_Y;
                }
                else if(jumppic_indexr == 10){
                    int dif = GIRL_Y - FLOOR[game_state][GIRL_X][GIRL_Y];
                    dif= min(dif, GIRL_JUMP_Y);
                    jumppic_indexr = 0;
                    jump = false;
                }
                else{
                    int dif = GIRL_Y - FLOOR[game_state][GIRL_X][GIRL_Y];
                    dif= min(dif, GIRL_JUMP_Y);
                    GIRL_X -= max(0,dif-5);
                    GIRL_Y -= dif;
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
            int chinpin = 0;
            if(jombie[i].type == 3 && jombie[i].face == 1) chinpin = hate_gulli;
            if(jombie[i].type == 3 && jombie[i].face == 0) chinpin = hate_gulli_left;
            jombie[i].posy = max(jombie[i].posy, FLOOR[game_state][jombie[i].posx-chinpin][jombie[i].posy]);
            if( (game_state == 5 || game_state == 6) && jombie[i].posx >= 120 && jombie[i].posx <= 280) {
                jombie[i].state = 4;
                jombie[i].showoff = 1;
            }
            if(jombie[i].state == 1 || jombie[i].state == 0){
                if(abs(GIRL_Y - jombie[i].posy) > 150) goto hell_ya;
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
                if(abs(GIRL_Y - jombie[i].posy) > 150) {
                    jombie[i].base = jombie[i].posx;
                    jombie[i].state = 1;
                    jombie[i].image_index = 0;
                    goto hell_ya;
                }
                if(abs(GIRL_X - jombie[i].posx) <= 50 && jombie[i].state == 3){
                    goto hell_ya;
                }
                if(jombie[i].type == 3){
                    jombie[i].state = 3;
                }
                else if(GIRL_X > jombie[i].posx){
                        jombie[i].face = 1;
                    jombie[i].posx += 15;
                }
                else if(GIRL_X < jombie[i].posx){
                    jombie[i].face = 0;
                    jombie[i].posx -= 15;
                }
                if(abs(GIRL_X - jombie[i].posx) <= 50 && jombie[i].state == 2){
                    if(abs(GIRL_Y - jombie[i].posy) > 50) goto hell_ya;
                    jombie[i].state = 3;
                    jombie[i].image_index = 0;
                }
                else if(abs(GIRL_X - jombie[i].posx) > 50 && jombie[i].state == 3){
                    if(jombie[i].type == 3) continue;
                    jombie[i].state = 2;
                    jombie[i].image_index = 0;
                }
                if(jump){
                    jombie[i].state = 2;
                }
            }
            hell_ya:
            if(jombie[i].state == 3){
                if(GIRL_X > jombie[i].posx){
                    jombie[i].face = 1;
                }
                else jombie[i].face = 0;
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
        keo_toroal_mare=0;
        for(int i = 0; i < number_of_enemy; i++)
         {
            if(jombie[i].state==3 && jombie[i].type != 3 && jombie[i].type != 2)
            {
                touch_continue=1;
            if(touch_sound==0 && music)
                sounds[0].play();
            life_left=life_left-1;
            touch_sound=1;
            }
            if(jombie[i].state==3 && jombie[i].type==2 && pirat_sword_sound==0)
            {
              pirat_sword_sound=1;
              sounds[5].stop();
              sounds[5].play();
            }
            if(jombie[i].state==3 && jombie[i].type==2)
            {keo_toroal_mare=1;
            life_left=max(life_left-1,0);}
         }
         if(keo_toroal_mare==0)
         {
             if(pirat_sword_sound==1 && music)
             {
                 pirat_sword_sound=0;
                 sounds[5].stop();
             }

         }
      if(touch_continue==0)
      {
          if(touch_sound==1 && music)
         {
            touch_sound=0;
            sounds[0].stop();
         }
      }
      int mora = 0;
      for(int i = 0; i < number_of_enemy; i++) {
            if(jombie[i].state == 4) mora++;
      }
      if(number_of_enemy == mora && hasnain.state == 4) {
            case_ache = 0;
      }
    }
    if(TIME_NOW%4==0){
            if(FACE == 1){
                if(NIN_THROW){
                if(!throw_music_on){
                    sounds[1].stop();
                    sounds[1].play();
                   sounds[1].setPlayingOffset(sf::seconds((float)1.7));
                    throw_music_on = 1;
                    }
                nin_throw_idx++;
                if(nin_throw_idx == 8){
                    NIN_COUNT++;
                    ninchuk[throwing_now].state = 1;
                    int i = throwing_now;
                    ninchuk[i].face = FACE;
                    if(ninchuk[i].face == 0) ninchuk[i].posx = GIRL_X - 100;
                    else ninchuk[i].posx = GIRL_X + 100;
                    ninchuk[i].posy = GIRL_Y + 75;
                }
                if(nin_throw_idx == 10){
                    NIN_THROW = false;
                    nin_throw_idx = 0;
                    throw_music_on = 0;
                }
                }
                 else if(toroal)//start- shimla
                {
                toroal_index++;
                if(!sward_music && toroal_index == 3){
                    sward_music = 1;
                    sounds[2].stop();
                    sounds[2].play();
                }
                if(toroal_index== 10){
                    toroal=0;
                    toroal_index=0;
                    throw_music_on = 0;
                    sward_music = 0;
                }
                }
            }
            else{
                if(NIN_THROW){
                    if(!throw_music_on){
                    sounds[1].stop();
                    sounds[1].play();
                    sounds[1].setPlayingOffset(sf::seconds((float)1.7));
                    throw_music_on = 1;
                    }
                    nin_throw_idxr++;
                    if(nin_throw_idxr == 8){
                        NIN_COUNT++;
                        ninchuk[throwing_now].state = 1;
                        int i = throwing_now;
                        ninchuk[i].face = FACE;
                        if(ninchuk[i].face == 0) ninchuk[i].posx = GIRL_X - 100;
                        else ninchuk[i].posx = GIRL_X + 100;
                        ninchuk[i].posy = GIRL_Y + 75;
                    }
                    if(nin_throw_idxr == 10){
                    NIN_THROW = false;
                    nin_throw_idxr = 0;
                    throw_music_on = 0;
                    }
                }else if(toroal)//start- shimla
                {
                toroal_indexr++;
                    if(!sward_music && toroal_indexr == 3){
                    sward_music = 1;
                    sounds[2].stop();
                    sounds[2].play();
                }
                if(toroal_indexr== 10){
                    toroal=0;
                    toroal_indexr=0;
                    sward_music = 0;
                }// end- shimla
               }
            }
    }
    if(TIME_NOW%3 == 0){
            vector<int>temp;
            for(int a:show){
                if(bullet[a].face) bullet[a].posx += 65;
                else bullet[a].posx -= 65;
                if(abs(bullet[a].posx - GIRL_X) <= 66 && bullet[a].posy <= GIRL_Y+125 && bullet[a].posy >= GIRL_Y){
                    bullet[a].state = 0;
                    temp.push_back(a);
                    life_left--;
                }
                else if(bullet[a].posx < -100 || bullet[a].posx > 1400){
                    bullet[a].state = 0;
                    temp.push_back(a);
                }
            }
            for(auto a: temp){
                show.erase(a);
                ase.insert(a);
            }
        for(int i = 0; i < number_of_enemy; i++){
            int chinpin = 0;
            if(jombie[i].type == 3 && jombie[i].face == 1) chinpin = hate_gulli;
            if(jombie[i].type == 3 && jombie[i].face == 0) chinpin = hate_gulli_left;
            if(jombie[i].posy > FLOOR[game_state][jombie[i].posx-chinpin][jombie[i].posy]){
                int dif = jombie[i].posy - FLOOR[game_state][jombie[i].posx-chinpin][jombie[i].posy];
                jombie[i].posy -= min(dif, GRAVITY_SPEED);
            }
        }
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
            if((GIRL_X <= hasnain.posx && ninchuk[i].posx >= hasnain.posx ||
                        (GIRL_X >= hasnain.posx && ninchuk[i].posx <= hasnain.posx)) && hasnain.state != 4 ){
                            ninchuk[i].state = 2;
                            chakus_in_dead_body.push_back(i);
                            hasnain.chaku ++;
                            hasnain.life--;
                            if(hasnain.life <= 0){
                                hasnain.state = 4;
                                hasnain.image_index = 0;
                            }
            }
            for(int ii = 0; ii < number_of_enemy; ii++){
                int ma = jombie[ii].posx;
                if(ninchuk[i].posy > jombie[ii].posy+150 || ninchuk[i].posy < jombie[ii].posy) continue;
                if(jombie[ii].state == 4) continue;
                if(GIRL_X <= jombie[ii].posx && ninchuk[i].posx >= jombie[ii].posx ||
                        (GIRL_X >= jombie[ii].posx && ninchuk[i].posx <= jombie[ii].posx)){
                    chakus_in_dead_body.push_back(i);
                    sounds[3].stop();
                    sounds[3].play();
                    sounds[3].setPlayingOffset(sf::seconds((float)0.1));
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
                    if(abs(GIRL_Y - jombie[ii].posy) > 50) continue;
                    int km = chakus_in_dead_body.back();
                    ninchuk[km].state = 0;
                    NIN_COUNT--;
                    jombie[ii].chaku = 0;
            }
        }
        //tolowar attack
        for(int ii = 0; ii < number_of_enemy ; ii++){
            int bonus = 0;
            if(jombie[ii].face == 1 && jombie[ii].type == 3) bonus = 50;
            if(((GIRL_X+90 >= jombie[ii].posx && GIRL_X<=jombie[ii].posx ) ||(GIRL_X - 100-bonus<= jombie[ii].posx && GIRL_X>=jombie[ii].posx)) && jombie[ii].state !=4 && toroal==1)
            {
                if(abs(GIRL_Y - jombie[ii].posy) > 50 || !tolowar_dmg) continue;
                jombie[ii].state=4;
                jombie[ii].image_index = 0;
                tolowar_dmg = 0;
                break;
            }
        }
        if(((GIRL_X+90 >= hasnain.posx && GIRL_X<=hasnain.posx ) ||(GIRL_X - 220<= hasnain.posx && GIRL_X >= hasnain.posx )) && hasnain.state != 4 && toroal==1){
            if(abs(GIRL_Y - hasnain.posy) > 200 || !tolowar_dmg) {}
            else {
                hasnain.life--;
                tolowar_dmg = 0;
                if(hasnain.life <= 0){
                    hasnain.state = 4; hasnain.image_index = 0;
                }
            }
        }
    }
    if(TIME_NOW%20 == 0){
        for(int i = 0; i <  number_of_enemy; i++){
                if(jombie[i].state == 3 && jombie[i].type == 3){
                    int pic = *ase.begin();
                    ase.erase(ase.begin());
                    show.insert(pic);
                    bullet[pic].state = 1;
                    bullet[pic].face = jombie[i].face;
                    int fic = 40;
                    if(jombie[i].face == 1) fic += 180;
                    bullet[pic].posx = jombie[i].posx+fic;
                    bullet[pic].posy = jombie[i].posy + 75;
                    sounds[8].stop();
                    sounds[8].play();
                 }
            }
    }
    if(TIME_NOW % 10 == 0){
        if(game_state != 8) return;
        bool alive = 0;
        for(int i = 0; i <  number_of_enemy; i++){
                alive |= (jombie[i].state != 4 || jombie[i].image_index < 5);
            }
        if(ZOMBIE_DONE == 0) ZOMBIE_DONE = alive^1;
    }
    if(TIME_NOW == TIME_TO_STOP ){
        RUN_STATUS = false;
    }
    if(SWAT_COME){
                    if(SWAT_POSY > 140){
                        SWAT_POSY -= min(10, SWAT_POSY-140);
                        SWAT_POSX += 3;
                    }
            }
    if(TIME_NOW%3 == 0){
        if(game_state == 14 && case_ache == 0 && GIRL_X + 65 == sara_x) {//
            //end_music = 1;
            if(music && !done){
                //cout << "HEre" << endl;
                done = 1;
                PlaySound("win.wav", NULL, SND_LOOP | SND_ASYNC);
            }
            //if(end_music == 0) end_music = 1;
            //if(end_music == 1) end_music = 2;
            if(name_dekha < 25) {
                name_dekha++;
                    //cout << name_dekha << endl;
            }
            if(name_dekha == 25) {
                for(int i = 0; i < 5; i++) {
                    end_name[i] += 2;
                }
            }
      }
    }


}
