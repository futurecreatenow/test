#include <stdio.h>
#include <stdlib.h>

// じゃんけんの手を定義
#define ROCK 0
#define PAPER 1
#define SCISSORS 2

// 手の名前を取得する関数
const char* getHandName(int hand) {
    switch (hand) {
        case ROCK: return "グー";
        case PAPER: return "パー";
        case SCISSORS: return "チョキ";
    }
    return "";
}

// 勝者を判定する関数
int getWinner(int* players, int numPlayers) {
    int rockCount = 0, paperCount = 0, scissorsCount = 0;

    // 各手の数を数える
    for (int i = 0; i < numPlayers; i++) {
        if (players[i] == ROCK) rockCount++;
        else if (players[i] == PAPER) paperCount++;
        else if (players[i] == SCISSORS) scissorsCount++;
    }

    // 引き分けの場合
    if ((rockCount > 0 && paperCount > 0 && scissorsCount > 0) || 
        (rockCount == numPlayers) || 
        (paperCount == numPlayers) || 
        (scissorsCount == numPlayers)) {
        return -1;
    }

    // 勝者を決定
    if (rockCount > 0 && scissorsCount > 0 && paperCount == 0) return ROCK;
    if (paperCount > 0 && rockCount > 0 && scissorsCount == 0) return PAPER;
    if (scissorsCount > 0 && paperCount > 0 && rockCount == 0) return SCISSORS;

    return -1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("使用方法: %s プレイヤー数\n", argv[0]);
        return 1;
    }

    int numPlayers = atoi(argv[1]);

    if (numPlayers < 3) {
        printf("プレイヤーは3人以上である必要があります。\n");
        return 1;
    }

    // 動的にプレイヤーの配列を確保
    int* players = (int*)malloc(numPlayers * sizeof(int));

    if (players == NULL) {
        printf("メモリの確保に失敗しました。\n");
        return 1;
    }

    printf("じゃんけんを始めます！\n");

    // プレイヤーの手を入力
    for (int i = 0; i < numPlayers; i++) {
        printf("プレイヤー%dの手を入力 (グー:0, パー:1, チョキ:2): ", i + 1);
        scanf("%d", &players[i]);
    }

    // 勝者を判定
    int winner = getWinner(players, numPlayers);

    // 結果を表示
    if (winner == -1) {
        printf("引き分けです！\n");
    } else {
        printf("勝者は%sです！\n", getHandName(winner));
    }

    // メモリを解放
    free(players);

    return 0;
}
