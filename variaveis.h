#define TELA_X 800
#define TELA_Y 600

#define LINHAS 24
#define COLUNAS 32

#define COLISAO_UP_LEFT mapa[mapa_id][(pos_y+5)/PIXELS][(pos_x+5)/PIXELS]
#define COLISAO_UP_RIGHT mapa[mapa_id][(pos_y+5)/PIXELS][(pos_x+20)/PIXELS]
#define COLISAO_DOWN_LEFT mapa[mapa_id][(pos_y+25)/PIXELS][(pos_x+5)/PIXELS]
#define COLISAO_DOWN_RIGHT mapa[mapa_id][(pos_y+25)/PIXELS][(pos_x+20)/PIXELS]

#define GRAMA 0
#define CHAO 2
#define PEDRA 4
#define SAVE 7
#define EPORTAL 8
#define SPORTAL 9
#define PAREDE 11
#define BEIRA 12
#define AGUA 13
#define ARVORE 14
#define MURO 15
#define BOSS 16
#define NPC 20
#define NPC1 21
#define NPC2 22
#define NPC3 23
#define NPC4 24
#define NPC5 25
#define NPC6 26
#define NPC7 27
#define NPC8 28
#define NPC9 29
#define NPC_V 30

#define PIXELS 25

#define VEL 1

#define DROP_POT 10 //drop = 1/VALOR
#define DROP_MANA 7 //drop = 1/VALOR
#define LOSE 0
#define WIN 1
#define BATTLE 2
#define MEU_TURNO 0
#define MOB_TURNO 1

#define TOTAL_MAPAS 6

typedef struct { //Estrutura dos status do personagem
    int ATK;
    int DEF;
    int LIFE;
    int MANA;
    int EXP;
    int MAGIC;
    int LVL;
    int POT;
    int GOLD;
}PERSONAGEM;

typedef struct { //Estrutura dos monstros do jogo
    char *NOME;
    int ATK;
    int LIFE;
    int EXP;
    int GOLD;
}MONSTRO;

BITMAP* buffer;

SAMPLE* sel_sound;

volatile int menu = TRUE;
volatile int jogo = FALSE;
volatile int battle = FALSE;
volatile int fechar = FALSE;;
volatile int contador = 0;
volatile int battle_timer = 0;

int anterior_UP, anterior_DOWN, anterior_LEFT, anterior_RIGHT, anterior_ENTER, anterior_ENTER_PAD, anterior_SPACE, anterior_ESC;//variaaveis de controle de entrada do teclado
int** mapa[TOTAL_MAPAS];
int mapa_id;
int pos_x, pos_y;
int dir = 0;

PERSONAGEM max_stat = {11,9,60,5,10,21,1,0,0};//Declaração do status de "base" do personagem(ataque, defesa, vida maxima, mana maxima, exp limite, mataque, lvl )

PERSONAGEM stat = {0,0,60,5,0,0,0,0,0};//Declaração do status de "ação" do personagem(vida, mana, exp ganha, pot, gold)


