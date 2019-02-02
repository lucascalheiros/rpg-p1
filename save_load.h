int save_game(){
    if(mapa[mapa_id][(pos_y+13)/PIXELS][(pos_x+13)/PIXELS] == SAVE ){
        FILE *save;
        save = fopen("save/save.dat", "wb");
        fprintf(save, "%d %d %d %d %d %d %d %d %d", pos_x, pos_y, mapa_id, stat.LIFE, stat.MANA, stat.POT, stat.EXP, max_stat.LVL, stat.GOLD );
        fclose(save);
    }
}

int load_game(){

        FILE *save;
        save = fopen("save/save.dat", "rb");
        fscanf(save, "%d %d %d %d %d %d %d %d %d", &pos_x, &pos_y, &mapa_id, &stat.LIFE, &stat.MANA, &stat.POT, &stat.EXP, &max_stat.LVL, &stat.GOLD );
        fclose(save);
}
