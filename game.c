#include "game.h"

void Initboard(char board[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            board[i][j] = ' ';
        }
    }
}

void DispalyBoard(char board[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf(" %c ", board[i][j]);
            if (j < col - 1) printf("|");
        }
        printf("\n");
        if (i < row - 1) {
            for (int K = 0; K < col; K++) {
                printf("---");
                if (K < col - 1) printf("·");
        }
        }
        if (i < row - 1) printf("\n");
    }
}

void Player1(char board[ROW][COL], int row, int col) {
    int x, y;
    printf("player1下棋\n");
    while (1) {
        printf("请输入坐标:");
        scanf("%d%d", &x, &y);
        //坐标判断
        if(x<1 || x > row || y < 1 || y > col) {
            printf("坐标非法\n");
            continue;
        }
        if(board[x-1][y-1] != ' ') {
            printf("该坐标已被占领\n");
            continue;
        }
        board[x-1][y-1] = '*';
        break;
    }
    
}

void Computer(char board[ROW][COL], int row, int col) {
    int x, y;
    printf("computer下棋\n");
    while (1){
        x = rand() % row;//随机生成0-2
        y = rand() % col;
        if (board[x][y] != ' ') continue;
        board[x][y] = '#';
        break;
    }
}

//* 玩家赢
//# 电脑输
//E 平局
//C 继续
char Is_win(char board[ROW][COL], int row, int col) {
    //判断行,先将每行加起来然后除以列数进行判断
    for (int i = 0; i < row; i++){ 
        int sum_row = 0;
        for (int j = 0; j < col; j++) {
            sum_row += board[i][j];
        }
        if (sum_row / row == board[i][0] && sum_row / row != 32) return board[i][0];
    }
    //判断列,通过判断每个元素是否相等来实现
    for (int i = 0; i < col; i++) {
        int allElementsSame = 1;
        int is_blank = 0;
        for(int j = 0; j < row; j++){
            if (board[j][i] == ' ') {
                is_blank = 1;
                break;
            }
            if(board[0][i] != board[j][i]) {
                    allElementsSame = 0;
                    break;
                }
        }
        if (is_blank) continue;
        if (allElementsSame) {
            return board[0][i];
        }
    }

    //判断对角线
    //第一条对角线
    int sum=0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if(i == j) {
                sum += board[i][j];
            }
        }
    }
    if(sum / row == board[0][0] && sum / row != 32) {
        return board[0][0];
    }
    //第二条对角线
    int sum2 = 0;
    for (int i =0; i < row; i++){
        for(int j = 0; j < col; j++){
            if (i + j == row - 1) sum2 += board[i][j];
        }
    }
    if (sum2 / row == board[0][row - 1] && sum2 / row != 32) {
        return board[0][row - 1];
    }

    //判断平局
    int flag = 1;
    for(int i = 0; i < row; i++){
        for (int j =0; j < col; j++) {
            if (board[i][j] == ' ') {
                flag = 0;
                break;
            }
        }
    }
    if (flag) return 'E';

    return 'C';
}


