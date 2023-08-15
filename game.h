#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 4
#define COL 4

//初始化棋盘
void Initboard(char board[ROW][COL], int row, int col);

//打印棋盘
void DispalyBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void Player1(char board[ROW][COL], int row, int col);
void Computer(char board[ROW][COL], int row, int col);

//判断输赢
char Is_win(char board[ROW][COL], int row, int col);