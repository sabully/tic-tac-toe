#include "game.h"
#include "game.c"

void menu() {
    printf("******************\n");
    printf("**1.play  0.exit**\n");
    printf("******************\n");
}

void game() {
    char ret = 0;
    char board[ROW][COL] = {0};
    // 初始化棋盘
    Initboard(board, ROW, COL);
    DispalyBoard(board, ROW, COL);
    //下棋
    while(1) {
        Player1(board, ROW,COL);
        DispalyBoard(board, ROW, COL);
        ret = Is_win(board, ROW, COL);
        if (ret != 'C') break;
        Computer(board, ROW,COL);
        DispalyBoard(board, ROW, COL);
        ret = Is_win(board, ROW, COL);
        if (ret != 'C') break;
    }
    switch (ret)
    {
    case '*':
        printf("玩家赢\n");
        break;
    case '#':
        printf("电脑赢\n");
        break;
    case 'E':
        printf("平局\n");
        break;
    }
}

int main() {
    int n;
    srand((unsigned int) time(NULL));//设置随机数的生成起点
    do {
        menu();
        printf("请选择:\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("开始游戏\n");
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("请输入0或者1\n");
            break;
        }
    }while(n);
    return 0;
}