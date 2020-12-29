void show_jombie(){
        for(int i = 0; i < number_of_enemy; i++){
            if(jombie[i].showoff) continue;
            if(jombie[i].type == 0){
                if(jombie[i].face == 1){
                    iShowBMP2(jombie[i].posx, jombie[i].posy, t1enmy[jombie[i].state][jombie[i].image_index], 255);
                }
                else{
                    iShowBMP2(jombie[i].posx, jombie[i].posy, t1enmyr[jombie[i].state][jombie[i].image_index], 255);
                }
            }
            else if(jombie[i].type == 1){
                    if(jombie[i].face == 1){
                        iShowBMP2(jombie[i].posx, jombie[i].posy, t2enemy[jombie[i].state][jombie[i].image_index], 255);
                    }
                    else{
                        iShowBMP2(jombie[i].posx, jombie[i].posy, t2enemyr[jombie[i].state][jombie[i].image_index], 255);
                    }
            }
            else if(jombie[i].type == 2){
                    if(jombie[i].face == 1){
                        iShowBMP2(jombie[i].posx+20, jombie[i].posy, p1[jombie[i].state][jombie[i].image_index], 255);
                    }
                    else{
                        iShowBMP2(jombie[i].posx-20, jombie[i].posy, p1r[jombie[i].state][jombie[i].image_index], 255);
                    }
            }
            else if(jombie[i].type == 3){
                    if(jombie[i].face == 1){
                        iShowBMP2(jombie[i].posx, jombie[i].posy, p2[jombie[i].state][jombie[i].image_index], 255);
                    }
                    else{
                        iShowBMP2(jombie[i].posx, jombie[i].posy, p2r[jombie[i].state][jombie[i].image_index], 255);
                    }
            }

        }
        for(auto a: show){
            if(bullet[a].face){
                iShowBMP2(bullet[a].posx, bullet[a].posy, "bk\\b1.bmp", 255);
            }
            else{
                iShowBMP2(bullet[a].posx, bullet[a].posy, "bk\\b0.bmp", 255);
            }
        }
}

void show_girl(){
    if(RUN_STATUS){
            if(FACE) iShowBMP2(GIRL_X,GIRL_Y,RunningPic[RunPicIndex1],255);
            else iShowBMP2(GIRL_X,GIRL_Y,LeftRun[RunPicIndex2],255);
        }
        else if(NIN_THROW){
            if(FACE == 1)
            iShowBMP2(GIRL_X, GIRL_Y, Ninchaku_throw[nin_throw_idx], 255);
            else iShowBMP2(GIRL_X, GIRL_Y, Ninchaku_throwr[nin_throw_idxr], 255);
        }
        else if(toroal)//start- shimla
        {
            if(FACE == 1)
            iShowBMP2(GIRL_X, GIRL_Y, toroal_pic[toroal_index], 255);
            else iShowBMP2(GIRL_X, GIRL_Y, toroal_picr[toroal_indexr], 255);
        }
        else if(jump){
            if(FACE == 1)
            iShowBMP2(GIRL_X,GIRL_Y,jumppic[jumppic_index],255);
            else iShowBMP2(GIRL_X,GIRL_Y,jumppicr[jumppic_indexr],255);
        }
        else{
            if(FACE == 1)
            iShowBMP2(GIRL_X, GIRL_Y, idlepic[idle_index],255);
            else iShowBMP2(GIRL_X, GIRL_Y, idlepicr[idle_indexr],255);
        }
        for(int nin = 0; nin < MAX_NINCHUK; nin++){
            if(ninchuk[nin].state == 1){
                if(ninchuk[nin].face == 1){
                    iShowBMP2(ninchuk[nin].posx, ninchuk[nin].posy, "atnin//x.bmp", 255);
                }
                else{
                    iShowBMP2(ninchuk[nin].posx, ninchuk[nin].posy, "atninr//x.bmp", 255);
                }
            }
        }
        if(game_state == 11) iShowBMP2(0,0,"bk\\111.bmp",255);
        iShowBMP2(5,desktop_ver-55,"bk//x.bmp",255);
        iShowBMP2(35, desktop_ver-45, num[MAX_NINCHUK-NIN_COUNT], 255);
        for(int i = 1; i <= life_left;i++){
            iShowBMP2(desktop_hor-(i*53), desktop_ver-55,"bk//life.bmp", 255);
        }
}

