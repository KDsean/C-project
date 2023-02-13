#include<stdio.h>
#include<time.h>
#include<stdlib.h>


#define ROW 6
#define COL 6
#define MINE 4
#define ROWS ROW+2
#define COLS COL+2



void chushihua(char board[ROWS][COLS], int cows, int cols, char set);


void dayin(char board[ROWS][COLS], int row, int col);


void buzhi(char mine[ROWS][COLS], int row, int col);


void paica(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);