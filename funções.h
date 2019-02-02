//Fun��es battle.h

void update_max_stat(); //fun��o para atualiza��o dos status com base no lvl

void verif_lvl(); //fun��o para atualizar o lvl e status ( chama update_max_stat() )

void mons_sel_f(int* mons_sel_var, int n_mons ); // fun��o para sele��o de alvos durante a batalha

int verif_win_lose(int n_mons, int verif_mons[]); // verifica se venceu, perdeu ou continua em batalha

void drop_system(MONSTRO bmons); // sistema de drop

int battle_run(); // fun��o principal do sistema de batalha

void printf_battle_mons_selection( int mons_sel_var, MONSTRO bmons[], MONSTRO mons[], int mobs[], int n_mons ); // mostra as op��es dos alvos na tela durante a batalha

void printf_battle_status_selection( int battle_var); // mostra os status e as op��es de comando durante a batalha

void printf_you_mobs( int n_mons, int verif_mons[], int batt_anima, BITMAP* mob_pic[], BITMAP* mob_dead_pic[], BITMAP* you, BITMAP* you_dead); // mostra as imagens do personagem e dos monstros na tela

void printf_win_or_lose(int verif_wl_var, int n_mons, BITMAP* venceu, BITMAP* perdeu); // mostra a mensagem de vitoria ou derrota ao fim da batalha

void you_anima(int* batt_anima, BITMAP* atk_pic_anima[], BITMAP* matk_pic_anima[], BITMAP* cura_pic_anima[], BITMAP* pot_pic_anima[], BITMAP* flee_pic_anima[]); // mostra as anima��es de batalha do personagem

//Fun��es init_troca.h

void sair_f(); //fechar o programa caso chamada

void battle_f(); //ativa e desativa o loop de batalha

void jogo_f(); //ativa e desativa o loop de jogo

void menu_f(); //ativa e desativa o loop de menu

void fps_f(); //fun��o para controlar o fps do programa(timer)

void timer_f();  //fun��o para controlar a anima��o de batalha(timer)

void init_fun(); //chama as fun��es de inicializa��o da allegro os timers e o bot�o de fechar

void sel_f(int* sel_var, int n_opc ); //fun��o de sele��o utilizada em todas partes do jogo

void keyboard_fix(); //fun��o de suporte ao controle de entrada do teclado

//Fun��es save_load.h

int save_game();

int load_game();

//Fun��es menu.h

void menu_inicial();

//Fun��es mapa_mov.h

int** carregar_mapa(char* nome_arquivo);

void desenhar_mapa(BITMAP* parede, BITMAP* grama, BITMAP* arvore, BITMAP* agua, BITMAP* pedra, BITMAP* pedra2, BITMAP* npc, BITMAP* save, BITMAP* stone, BITMAP* stone2, BITMAP* boss, BITMAP* princesa);

int colisao();

void mov();

void troca_mapa();

void load_maps();

void npc_f(BITMAP* npc_bar, int* counter);

//Fun��es jogo.h

int novo_jogo();

int batalha();

void printf_menu_jogo_selection( int menu_jogo_var);

void jogo_run();
