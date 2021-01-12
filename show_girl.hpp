
void print_swat(){
    if(game_state == 6){
        iShowBMP2(350 + 400, SWAT_POSY,"bk/swat/1.bmp", 255);
        iShowBMP2(350 + 100, SWAT_POSY,"bk/swat/3.bmp", 255);
        iShowBMP2(350 + 800, SWAT_POSY,"bk/swat/4.bmp", 255);
        iShowBMP2(350 + 730, SWAT_POSY,"bk/swat/2.bmp", 255);
    }
    if(game_state == 5){
        if(SWAT_POSY > 140){
            iShowBMP2(280, SWAT_POSY+60, "bk//para.bmp", 255);
            iShowBMP2(0, SWAT_POSY+60,"bk/para2.bmp", 255);
            iShowBMP2(230, SWAT_POSY+60,"bk/para.bmp", 255);
            iShowBMP2(160, SWAT_POSY+60,"bk/para.bmp", 255);
        }
        iShowBMP2(300, SWAT_POSY,"bk/swat/1.bmp", 255);
        iShowBMP2(60, SWAT_POSY,"bk/swat/3b.bmp", 255);
        iShowBMP2(450, SWAT_POSY,"bk/swat/4.bmp", 255);
        iShowBMP2(400, SWAT_POSY,"bk/swat/2.bmp", 255);

        if(!press_n){
            iShowBMP2(0,0,"conversation/sw.bmp", 255);
            freez = 1;
        }
        else{
            iShowBMP2(0,0,"conversation/n.bmp", 255);
        }
    }
}
void show_jombie(){
        if(game_state == 5 || game_state == 14){
            int bonus = 0;
            if(hasnain.state == 3 && (hasnain.image_index >= 5 || hasnain.image_index <= 1)){
                bonus = 45;
            }
            if(hasnain.face) iShowBMP2(hasnain.posx+bonus,hasnain.posy, bos[hasnain.state][hasnain.image_index],255);
            else iShowBMP2(hasnain.posx-bonus,hasnain.posy, bosr[hasnain.state][hasnain.image_index],255);
            if(hasnain.state != 4){
                int pk = floor((200.00/hasnain.MAX_LIFE)*hasnain.life);
                iSetColor(255, 0,0);
                iFilledRectangle(hasnain.posx+23,hasnain.posy+200,pk ,10);
            }
        }
        for(int i = 0; i < number_of_enemy; i++){
            if(jombie[i].showoff) continue;
            if(jombie[i].type == 0){
                if(jombie[i].face == 1){
                    iShowBMP2(jombie[i].posx, jombie[i].posy-image_fix[game_state][jombie[i].type], t1enmy[jombie[i].state][jombie[i].image_index], 255);
                }
                else{
                    iShowBMP2(jombie[i].posx, jombie[i].posy-image_fix[game_state][jombie[i].type], t1enmyr[jombie[i].state][jombie[i].image_index], 255);
                }
            }
            else if(jombie[i].type == 1){
                    if(jombie[i].face == 1){
                        iShowBMP2(jombie[i].posx, jombie[i].posy-image_fix[game_state][jombie[i].type], t2enemy[jombie[i].state][jombie[i].image_index], 255);
                    }
                    else{
                        iShowBMP2(jombie[i].posx, jombie[i].posy-image_fix[game_state][jombie[i].type], t2enemyr[jombie[i].state][jombie[i].image_index], 255);
                    }
            }
            else if(jombie[i].type == 2){
                    if(jombie[i].face == 1){
                        iShowBMP2(jombie[i].posx+20, jombie[i].posy-image_fix[game_state][jombie[i].type], p1[jombie[i].state][jombie[i].image_index], 255);
                    }
                    else{
                        iShowBMP2(jombie[i].posx-20, jombie[i].posy-image_fix[game_state][jombie[i].type], p1r[jombie[i].state][jombie[i].image_index], 255);
                    }
            }
            else if(jombie[i].type == 3){
                    if(jombie[i].face == 1){
                        iShowBMP2(jombie[i].posx, jombie[i].posy-15-image_fix[game_state][jombie[i].type], p2[jombie[i].state][jombie[i].image_index], 255);
                    }
                    else{
                        iShowBMP2(jombie[i].posx, jombie[i].posy-15-image_fix[game_state][jombie[i].type], p2r[jombie[i].state][jombie[i].image_index], 255);
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
            else iShowBMP2(GIRL_X-50, GIRL_Y, toroal_picr[toroal_indexr], 255);
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
        if(game_state == 13) iShowBMP2(777,10, "bk\\13bu.bmp",255);
        iShowBMP2(5,desktop_ver-55,"bk//x.bmp",255);
        iShowBMP2(35, desktop_ver-45, num[MAX_NINCHUK-NIN_COUNT], 255);
        for(int i = 1; i <= life_left;i++){
            iShowBMP2(desktop_hor-(i*53), desktop_ver-55,"bk//life.bmp", 255);
        }
}

