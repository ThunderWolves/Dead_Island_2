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
        for(int nin = 0; nin < 5; nin++){
            if(ninchuk[nin].state == 1){
                if(ninchuk[nin].face == 1){
                    iShowBMP2(ninchuk[nin].posx, ninchuk[nin].posy, "atnin//x.bmp", 255);
                }
                else{
                    iShowBMP2(ninchuk[nin].posx, ninchuk[nin].posy, "atninr//x.bmp", 255);
                }
            }
        }
        iShowBMP2(5,desktop_ver-55,"bk//x.bmp",255);
        iShowBMP2(35, desktop_ver-45, num[5-NIN_COUNT], 255);
        for(int i = 1; i <= life_left;i++){
            iShowBMP2(desktop_hor-(i*53), desktop_ver-55,"bk//life.bmp", 255);
        }
}

