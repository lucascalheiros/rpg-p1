int** carregar_mapa(char* nome_arquivo){
   FILE* f = fopen(nome_arquivo, "r");
   int** matriz;

   if(f != NULL)
   {
     int i, j;

     matriz = (int**) malloc ( LINHAS * sizeof(int*));
     for(i = 0; i <LINHAS; i++)
      matriz[i] = (int*) malloc( COLUNAS * sizeof(int));

     for(i = 0; i < LINHAS; i++)
     {
        for(j = 0; j < COLUNAS; j++)
        {
          fscanf(f, "%d", &matriz[i][j]);
        }
     }

     fclose(f);
   }

   return matriz;
}

void desenhar_mapa(BITMAP* parede, BITMAP* grama, BITMAP* arvore, BITMAP* agua, BITMAP* pedra, BITMAP* pedra2, BITMAP* npc, BITMAP* save, BITMAP* stone, BITMAP* stone2, BITMAP* boss, BITMAP* princesa){
    int i, j;


    for(i = 0; i < LINHAS; i++)
     {
        for(j = 0; j < COLUNAS; j++)
        {
           if(mapa[mapa_id][i][j] == GRAMA || mapa[mapa_id][i][j] == EPORTAL || mapa[mapa_id][i][j] == SPORTAL)
             draw_sprite(buffer, grama, j * PIXELS, i * PIXELS);

           else if(mapa[mapa_id][i][j] == PAREDE)
                draw_sprite(buffer, parede, j * PIXELS, i * PIXELS);

           else if(mapa[mapa_id][i][j] == ARVORE)
                draw_sprite(buffer, arvore, j * PIXELS, i * PIXELS);

           else if(mapa[mapa_id][i][j] == SAVE)
                draw_sprite(buffer, save, j * PIXELS, i * PIXELS);

            else if(mapa[mapa_id][i][j] == CHAO)
                draw_sprite(buffer, pedra2, j * PIXELS, i * PIXELS);

           else if(mapa[mapa_id][i][j] == PEDRA)
                draw_sprite(buffer, pedra, j * PIXELS, i * PIXELS);

            else if(mapa[mapa_id][i][j] == BEIRA)
                draw_sprite(buffer, stone2, j * PIXELS, i * PIXELS);

            else if(mapa[mapa_id][i][j] == AGUA)
                draw_sprite(buffer, agua, j * PIXELS, i * PIXELS);

            else if(mapa[mapa_id][i][j] >= NPC)
                draw_sprite(buffer, npc, j * PIXELS, i * PIXELS);

            else if(mapa[mapa_id][i][j] == MURO)
                draw_sprite(buffer, stone, j * PIXELS, i * PIXELS);

            else if(mapa[mapa_id][i][j] == BOSS)
                draw_sprite(buffer, boss, j * PIXELS, i * PIXELS);

            if(mapa[mapa_id][i][j] == NPC9)
                draw_sprite(buffer, princesa, j * PIXELS, i * PIXELS);

        }
     }
}

int colisao(){
    if((COLISAO_UP_LEFT >= PAREDE && COLISAO_UP_LEFT <= NPC_V) || (COLISAO_UP_RIGHT >= PAREDE && COLISAO_UP_RIGHT <= NPC_V) || (COLISAO_DOWN_LEFT >= PAREDE && COLISAO_DOWN_LEFT <= NPC_V) || (COLISAO_DOWN_RIGHT >= PAREDE && COLISAO_DOWN_RIGHT <= NPC_V))
        return 1;
    else
        return 0;
}

void mov(){
    poll_keyboard();
    if(key[KEY_UP]){
        pos_y-=VEL;
        dir = 1;
        batalha();
        if(colisao())
            pos_y+=VEL;
    }
    if(key[KEY_DOWN]){
        pos_y+=VEL;
        dir = 0;
        batalha();
        if(colisao())
            pos_y-=VEL;
    }
    if(key[KEY_LEFT]){
        pos_x-=VEL;
        dir = 2;
        batalha();
        if(colisao())
            pos_x+=VEL;

    }
    if(key[KEY_RIGHT]){
        pos_x+=VEL;
        dir = 3;
        batalha();
        if(colisao())
            pos_x-=VEL;
    }
}

void troca_mapa(){
    if(mapa[mapa_id][(pos_y+13)/PIXELS][(pos_x)/PIXELS] == EPORTAL){
        mapa_id++;
        pos_x-=764;
    }
    if(mapa[mapa_id][(pos_y+13)/PIXELS][(pos_x+25)/PIXELS] == SPORTAL){
        mapa_id--;
        pos_x+=764;

    }
}

void load_maps(){
    int i;
    char *list_mapas[] = {
        "mapas/vila.txt",
        "mapas/floresta.txt",
        "mapas/floresta2.txt",
        "mapas/floresta3.txt",
        "mapas/castelo.txt",
        "mapas/castelo2.txt"
    };
    for( i = 0 ; i < TOTAL_MAPAS ; i++ )
        mapa[i] = carregar_mapa(list_mapas[i]);
}

void npc_f(BITMAP* npc_bar, int* counter){
    if(mapa[mapa_id][(pos_y-13)/PIXELS][(pos_x+13)/PIXELS] < NPC)
        (*counter)=0;
    if( (anterior_ENTER == 0 && key[KEY_ENTER] != 0) || (anterior_ENTER_PAD == 0 && key[KEY_ENTER_PAD] != 0) )
        (*counter)=1;

    if(mapa[mapa_id][(pos_y-13)/PIXELS][(pos_x+13)/PIXELS] >= NPC){
        if((*counter)>0){
        draw_sprite(buffer, npc_bar,0,0);
            switch(mapa[mapa_id][(pos_y-13)/PIXELS][(pos_x+13)/PIXELS]){
                case NPC:
                    textout_ex(buffer, font, "Ola pequeno aventureiro, monstros nao aparecem neste piso pois esta e uma area segura, ", 20, 20, makecol(0,0,0),-1);
                    textout_ex(buffer, font, "mas se voce sair daqui podera ser surpreendido por Goblins!! Eles sao pequenos mas bastante ", 20, 30, makecol(0,0,0),-1);
                    textout_ex(buffer, font, "perigosos, tente conversar os outros habitantes da vila para saber mais. ", 20, 40, makecol(0,0,0),-1);
                    break;
                case NPC1:
                    textout_ex(buffer, font, "Sabia que se voce for para o leste encontrara algumas florestas! Se voce continuar dara de cara ", 20, 20, makecol(0,0,0),-1);
                    textout_ex(buffer, font, "com um castelo!!! Mas cuidado no caminho monstros perigosos podem aparecer!!!!! ", 20, 30, makecol(0,0,0),-1);
                    textout_ex(buffer, font, "Eu ouvi dizer que existem Orcs, Zombies, Cyclops, Elfos e Fantasmas nesse caminho!!!!!!!!!!!!!!!!! ", 20, 40, makecol(0,0,0),-1);
                    textout_ex(buffer, font, "Cada um mais forte que o outro eu nao me atrevo a sair daqui, nem de Goblins eu consigo vencer!!!!", 20, 50, makecol(0,0,0),-1);
                    break;
                case NPC2:
                    textout_ex(buffer, font, "Algumas pessoas vendem coisas, para comprar basta apertar SPACE mas voce deve ter ouro suficiente!", 20, 20, makecol(0,0,0),-1);
                    textout_ex(buffer, font, "Para salvar o jogo basta andar por cima do simbolo do disquete no mapa! ", 20, 30, makecol(0,0,0),-1);
                    break;
                case NPC3:
                    textout_ex(buffer, font, "Noticias terriveis direto do leste!!!!!!!!!!!!!!!! ", 20, 20, makecol(0,0,0),-1);
                    textout_ex(buffer, font, "Por uma pequena quantia de 50 unidades de ouro voce podera saber do que aconteceu!!!!!!!!!!!!!!!! ", 20, 30, makecol(0,0,0),-1);
                    textprintf_ex(buffer, font, 700, 85, makecol(0,0,0), -1, "GOLD: %d",stat.GOLD);
                    if((*counter)==2){
                        textout_ex(buffer, font, "O senhor do mal invadiu o castelo, ao que parece o rei morreu e a princesa esta presa!!!!!!!!! ", 20, 40, makecol(0,0,0),-1);
                        textout_ex(buffer, font, "Se quiser me dar mais ouro basta continuar apertando SPACE!!! MUAHAHAHAHA ", 20, 50, makecol(0,0,0),-1);
                    }
                    if((anterior_SPACE == 0 && key[KEY_SPACE] != 0) && stat.GOLD >= 50){
                        stat.GOLD-=50;
                        (*counter)=2;
                    }

                    break;
                case NPC4:
                    break;
                case NPC5:
                    break;
                case NPC6:
                    break;
                case NPC7:
                    break;
                case NPC8:
                    break;
                case NPC9:
                    textout_ex(buffer, font, "Meu heroi!!! <3 <3 <3 ", 20, 20, makecol(0,0,0),-1);
                    textout_ex(buffer, font, "Voce me salvou e agora tem a minha eterna gratidao ", 20, 30, makecol(0,0,0),-1);

                    break;
                case NPC_V:
                    textout_ex(buffer, font, "Ola eu sou o vendedor de pocoes ", 20, 20, makecol(0,0,0),-1);
                    textout_ex(buffer, font, "Cada pocao custa a singela quantia de 200 unidades de ouro, aperte SPACE para comprar ", 20, 30, makecol(0,0,0),-1);
                    textprintf_ex(buffer, font, 700, 75, makecol(0,0,0), -1, "POT: %d",stat.POT);
                    textprintf_ex(buffer, font, 700, 85, makecol(0,0,0), -1, "GOLD: %d",stat.GOLD);
                    if((*counter)==2){
                       (*counter)=1;
                       stat.POT++;
                    }
                    if((anterior_SPACE == 0 && key[KEY_SPACE] != 0) && stat.GOLD >= 150){
                        stat.GOLD-=150;
                        (*counter)=2;
                    }
                    break;


            }
        }
    }


}
