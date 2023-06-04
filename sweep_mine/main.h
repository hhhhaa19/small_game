#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include<time.h>
#define row 10
#define col 10
extern void game(void);
extern void menu(void);
extern int is_win(char board[col + 2][row + 2], char display[col][row]);
extern int play(char board[col + 2][row + 2], char display[col][row]);
extern void print(char display[col][row]);
extern int judge(char board[col + 2][row + 2], int x, int y);