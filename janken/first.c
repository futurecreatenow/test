#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./config.h"
void persist_janken(p_player me){
	boolean select_ = FALSE;
	while(select_ == FALSE){
		printf("%s\n",GAME_SELECT);
		scanf("%d",&select_);
		if ((select_ == TRUE) || (select_ == FALSE)){
			me->persist = select_;
			select_ = TRUE;
		}
		else {select_ = FALSE;}
	}
}
void result_janken(p_player me,p_player ene){
	if (me->hand == ene->hand){me->result = DRAW;printf("(result)=(%s)\n",RES_ENG[1]);}
	else{
		if (me->hand == LOCK){
			switch(ene->hand){
				case(PAPER):me->result = LOSE;printf("(result)=(%s)\n",RES_ENG[0]);break;
				case(SCISSORS):me->result = WIN;printf("(result)=(%s)\n",RES_ENG[2]);break;
			}
		}else if(me->hand == PAPER){
			switch(ene->hand){
			case(SCISSORS):me->result = LOSE;printf("(result)=(%s)\n",RES_ENG[0]);break;
				case(LOCK):me->result = WIN;printf("(result)=(%s)\n",RES_ENG[2]);break;
			}
		}else if(me->hand == SCISSORS){
			switch(ene->hand){
				case(LOCK):me->result = LOSE;printf("(result)=(%s)\n",RES_ENG[0]);break;
				case(PAPER):me->result = WIN;printf("(result)=(%s)\n",RES_ENG[2]);break;
			}
		}
		//else me->result = NOT;printf("(result)=(%s)\n",RES_ENG[3]);
	}
}
void show_hands(p_player me,p_player ene){
	if (me->hand == LOCK){
		printf("(me->hand)=(%s)\n",HAND_ENG[0]);
		if (ene->hand == LOCK)printf("(ene->hand)=(%s)\n",HAND_ENG[0]);
		else if (ene->hand == PAPER)printf("(ene->hand)=(%s)\n",HAND_ENG[1]);
		else if (ene->hand == SCISSORS)printf("(ene->hand)=(%s)\n",HAND_ENG[2]);
		else printf("%s\n",HAND_ENG[3]);
	}
	else if (me->hand == PAPER){
		printf("(me->hand)=(%s)\n",HAND_ENG[1]);
		if (ene->hand == LOCK)printf("(ene->hand)=(%s)\n",HAND_ENG[0]);
		else if (ene->hand == PAPER)printf("(ene->hand)=(%s)\n",HAND_ENG[1]);
		else if (ene->hand == SCISSORS)printf("(ene->hand)=(%s)\n",HAND_ENG[2]);
		else printf("%s\n",HAND_ENG[3]);
	}
	else if (me->hand == SCISSORS){
		printf("(me->hand)=(%s)\n",HAND_ENG[2]);
		if (ene->hand == LOCK)printf("(ene->hand)=(%s)\n",HAND_ENG[0]);
		else if (ene->hand == PAPER)printf("(ene->hand)=(%s)\n",HAND_ENG[1]);
		else if (ene->hand == SCISSORS)printf("(ene->hand)=(%s)\n",HAND_ENG[2]);
		else printf("%s\n",HAND_ENG[3]);
	}
	else printf("%s\n",HAND_ENG[3]);
}
void ene_hands(p_player ene){ene->hand = rand() % hands_num;}
void my_hands(p_player me){
	int hands_ = IGNORE;
	while(hands_ == IGNORE){
		printf("%s\n",HANDS_SELECT);
		scanf("%d",&hands_);
		if ((hands_ >SCISSORS) || (hands_ < LOCK))hands_ = IGNORE;
		else me->hand = hands_;
	}
}

int main(){
	printf("%s\n",DESCPRIOT);
	p_player me,ene;
	//メモリの動的確保
	me = (p_player) malloc (sizeof(player));
	ene = (p_player) malloc (sizeof(player));
	
	me->persist = TRUE;
	
	
	srand((unsigned int)time(NULL));//乱数の種の設定
	
	while(me->persist == TRUE){
		my_hands(me);
		ene_hands(ene);
		show_hands(me,ene);
		result_janken(me,ene);
		persist_janken(me);
	}
	
	//メモリの解放
	free(me);
}