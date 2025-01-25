#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"

void select_enemys(p_player me){
	boolean select_ = FALSE;
	while(select_ == FALSE){
		printf("%s\n",ENE_SELECT);
		scanf("%d",&select_);
		if ((select_ >= ONE) && (select_ <= THREE)){
            me->enemy = select_;
			select_ = TRUE;
		}
		else {select_ = FALSE;}
	}
    printf("(enemy num) = (%d)\n",me->enemy);
}
void show_hands(p_player players){
    switch(players->hand){
        case LOCK:printf("(%s)\n",HAND_ENG[0]);break;
        case PAPER:printf("(%s)\n",HAND_ENG[1]);break;
        case SCISSORS:printf("(%s)\n",HAND_ENG[2]);break;
        default:printf("(%s)\n",HAND_ENG[3]);break;
    }
}
void my_hands(p_player me){
	int hands_ = IGNORE;
	while(hands_ == IGNORE){
		printf("%s\n",HANDS_SELECT);
		scanf("%d",&hands_);
		if ((hands_ >SCISSORS) || (hands_ < LOCK))hands_ = IGNORE;
		else me->hand = hands_;
	}
    printf("(me->hand)=");
    show_hands(me);
}
void ene_hands(p_player ene){ene->hand = rand() % hands_num;}
void hand_input(p_player me){input_array[0] = me->hand;}
boolean result_janken(p_player me){
    //手が連続している==あいこ
    int draw_frag;
    for (int i = 0; i < me->enemy; i++)if (input_array[0] == input_array[i+1])draw_frag++;
    if (draw_frag == me->enemy){me->result = DRAW;return TRUE;}
    
    //手が不連続だが手の種類は2種類
    int same_frag,different_flag;
    for (int i = 0; i < me->enemy; i++){
        if (me->enemy == 1){return FALSE;}
        else if (me->enemy == 2){
            if (input_array[0] == input_array[1])
            {
                /* code */
            }
            
        }
    }
    //手が不連続（全て違う）==あいこ
}

int main(){
    printf("%s\n",DESCPRIOT);//ゲームスタート
	p_player me;
	me = (p_player) malloc (sizeof(player));//メモリの動的確保
    select_enemys(me);//相手の数を決定する
    
    p_player ene[ENE];//相手の数分構造体を用意する
    for (int i = 0;i < me->enemy;i++){ene[i] = (p_player) malloc (sizeof(player));}//メモリの動的確保

    me->persist = TRUE;
    srand((unsigned int)time(NULL));//乱数の種の設定
    
    while (me->persist == TRUE)
    {
        my_hands(me);//自分の手の選択
        for (int i = 0;i < me->enemy;i++){ene_hands(ene[i]);printf("(ene[%d]->hand)=",i);show_hands(ene[i]);}//相手の手の選択
        hand_input(me);//自分の手を格納する
        for (int i = 0;i < me->enemy;i++){input_array[i + 1] = ene[i]->hand;}//相手の手の格納
        result_janken(me);//じゃんけんの結果の判定
        me->persist = FALSE;
    }

    printf("%s\n",FINISH_GAME);//GAME終了
    free(me);//自分のメモリの解放
    for (int i = 0; i < me->enemy;i++){free(ene[i]);}//相手のメモリの解放

    return 0;
}