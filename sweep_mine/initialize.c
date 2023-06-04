#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"
void menu(void)
{
	printf("****************************\n");
	printf("****1:paly ****** 0:quit****\n");
	printf("****************************\n");
	printf("游戏规则：在10*10的棋盘中共有10个地雷，在你选择一个地址后会显示周围8个地址的地雷个数\n");
}
void ini_borad(char borad[col+2][row+2])
{
	int x = rand() % 10+1;
	int y = rand() % 10+1;
	int count = 10;
	while (count)
	{
		if (0 == borad[x][y])
		{
			count--;
			borad[x][y] = 1;
		}
		x = rand() % 10+1;
		y = rand() % 10+1;
	}
}
