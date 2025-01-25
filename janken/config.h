#ifndef CONF_H
#define CONF_H

//include
#include <stdio.h>

//define
#define DESCPRIOT "janken game!"
#define HANDS_SELECT "## YOUR hands_select 0:LOCK,1:PAPER,2:SCISSORS ##"
#define GAME_SELECT "## game_select 0:NOT_AGEIN,1:AGEIN ##"
#define ENE_SELECT "## select enemys 1:ONE,2:TWO,3:THREE ##"
#define FINISH_GAME "finish!"
#define ENE 10 //相手の数
#undef SINGLE
#define MUL
#define MAX 4
//Variable
int input_array[MAX];

//static
static const int hands_num = 3;
static char HAND_ENG[4][10] = {"LOCK","PAPER","SCISSORS","IGNORE"};
static char RES_ENG[4][10] = {"LOSE","DRAW","WIN","NOT"};

//enum
typedef enum {FALSE,TRUE} boolean;
typedef enum {ONE = 1,TWO,THREE} enemys;
typedef enum {LOSE,DRAW,WIN,NOT} results;
typedef enum {LOCK,PAPER,SCISSORS,IGNORE} hands;

//struct
typedef struct player{
	boolean persist;
	results result;
	hands hand;
	enemys enemy;
}player,*p_player;

//function phototype
extern void my_hands(p_player);
extern void persist_janken(p_player);
extern void ene_hands(p_player);
#ifdef SINGLE
extern void show_hands(p_player,p_player);
extern void result_janken(p_player,p_player);
#else //SINGLE
extern void select_enemys(p_player);
extern void show_hands(p_player);
extern void hand_input(p_player);
extern boolean result_janken(p_player);
#endif//SINGLE

#endif//CONF_H