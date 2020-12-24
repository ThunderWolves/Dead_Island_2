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
    TIME_NOW ++;
    if(TIME_NOW > 1e18) TIME_NOW = 0;
    if(TIME_NOW%6 == 0){
            //normal moves
        if(jump){
            if(FACE == 1){
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
                GIRL_X = min(desktop_hor-100, GIRL_X);
            }
            else{
                jumppic_indexr++;
                if(jumppic_indexr <= 5){
                    GIRL_X -= 20;
                    GIRL_Y += 20;
                }
                else if(jumppic_indexr == 10){
                    GIRL_Y -= 20;
                    jumppic_indexr = 0;
                    jump = false;
                }
                else{
                    GIRL_X -= 20;
                    GIRL_Y -= 20;
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
                if(jombie[i].image_index >= 7){
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
                if(abs(GIRL_X - jombie[i].posx) < 100){
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
                if(abs(GIRL_X - jombie[i].posx) < 100 && jombie[i].state == 2){
                    jombie[i].state = 3;
                    jombie[i].image_index = 0;
                }
                else if(abs(GIRL_X - jombie[i].posx) > 100 && jombie[i].state == 3){
                    jombie[i].state = 2;
                    jombie[i].image_index = 0;
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
            }
        }

    }
    else if(TIME_NOW%4==0){
            if(FACE == 1){
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
            else{
                if(NIN_THROW){
                    nin_throw_idxr++;
                    if(nin_throw_idxr == 8){
                        NIN_SHOW = true;
                    }
                    if(nin_throw_idxr == 10){
                    NIN_THROW = false;
                    nin_throw_idxr = 0;
                }
                }

                }
    }
    else if(TIME_NOW%3 == 0){
        if(NIN_SHOW){
                if(nin_face == 1)
            NINCAKU_X += 51;
            else NINCAKU_X -= 51;
            if(NINCAKU_X > desktop_hor || NINCAKU_X < -100){
                NIN_SHOW = FALSE;
            }
            for(int i = 0; i < number_of_enemy; i++){
                if(jombie[i].state == 4) continue;
                if(jombie[i].posx + 10 <= NINCAKU_X ){
                    NIN_SHOW = false;
                    jombie[i].state = 4;
                    jombie[i].image_index = 0;
                }
            }
        }
    }
    if(TIME_NOW == TIME_TO_STOP ){
        RUN_STATUS = false;
    }
}
