#include <allegro.h>
#include <stdio.h>

#include "variaveis.h"
#include "funções.h"
#include "init_troca.h"
#include "menu.h"
#include "mapa_mov.h"
#include "battle.h"
#include "jogo.h"
#include "save_load.h"

int main(){
    init_fun();
    srand(time(NULL));
    buffer = create_bitmap(SCREEN_W+200, SCREEN_H);
    load_maps();



    while(!fechar){
        if(menu){
            set_window_title("RPG - Menu");
            menu_inicial();
        }
       if(jogo){
            set_window_title("RPG - Jogo");
            jogo_run();

        }
    }

  return 0;
}END_OF_MAIN();
