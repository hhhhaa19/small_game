#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"
int judge(char board[col+2][row+2], int x, int y)
{
	int i, j;
	int count = 0;
	for (i = y - 1; i <= y + 1; i++)
	{
		for (j = x - 1; j <= x + 1; j++)
		{
			if (1 == board[i][j])
				count++;
		}
	}
	return count+48;
}
void print(char display[col][row])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("|%c ", display[i][j]);
		}
		printf("|");
		printf("\n");
		for (int j = 0; j < col; j++)
		{
			printf("---");
		}
		printf("-");
		printf("\n");
	}
}
int play(char board[col+2][row+2], char display[col][row])
{
	printf("请输入你要检测的位置(行 列)\n");
	int x, y;
	scanf("%d %d", &y, &x);
	if (1 != board[y][x])
	{
		display[y-1][x-1] = judge(board, x, y);
		if (0 == is_win(board, display))
		{	
			return 1;//继续
		}
		else 
		{
			return 2;//赢了
		}
	}
	else
	{
		display[y-1][x-1] = '*';
		return 0;//输了
	}
}
int is_win (char board[col + 2][row + 2], char display[col][row])
{
	int flag = 0;
	int i, j;
	for ( i = 0; i < col; i++)
	{
		for ( j = 0; j < row; j++)
		{
			if (' ' == display[i][j])
			{
				if (1 == board[i + 1][1 + j])
					flag = 1;//赢
				else
					return  0;

			}
		}
	}
	return flag;
}
void game(void)
{
	//生成棋盘
	char board [col+2][row+2] = { 0 };//该棋盘用于储存数据
	char display[col][row] = { 0 };//该棋盘用于展示

	//初始化地雷
	srand((unsigned int)time(NULL));
	ini_borad(board);
	//初始化并打印棋盘
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			display[i][j] = ' ';
		}
	}
	print(display);
	//游戏本体
	while (1==play(board, display))//
	{
		print(display);
	}
	print(display);
//	判断胜负
	if (1 == is_win(board, display))
	{
		printf("You win!\n");
	}
	else
	{
		printf("You lose!\n");
	}
}