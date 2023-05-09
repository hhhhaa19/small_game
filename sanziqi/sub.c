#define _CRT_SECURE_NO_WARNINGS 1
#include "main.h"
void priboard(char  arr[row][col])
{
	int i, j;
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row; j++)
		{
			if (j < row - 1)
				printf(" %c |", arr[i][j]);
			else
				printf(" %c ", arr[i][j]);
		}
		printf("\n");
		if (i < col - 1)
			printf("------------\n");
	}
}

void player(char arr[row][col])
{/*玩家下*/
	int b = 1;
	int a = 1;
	printf("please input where do you want to place your chess pieces,for example (1,2)\n");
	while (getchar() == '\n')
	{
		scanf("%d,%d", &a, &b) ;
		if (a <= 3 && b <= 3)
		{
			if (arr[a - 1][b - 1] != '*' && arr[a - 1][b - 1] != '#')
			{
				arr[a - 1][b - 1] = '*';
				break;
			}
			else
			{
				printf("傻逼，这边下过了\n");
				player(arr);
				break;
			}
		}
		else
			printf("不要超出棋盘\n");
	}
}
void complayer(char arr[row][col])
{
	int x, y;
	x = rand() % 3;
	y = rand() % 3;
	if (arr[x][y] != '*' && arr[x][y] != '#')
	{
		Sleep(1000);
		printf("电脑以随机数的形式下\n");
		arr[x][y] = '#';
	}
	else
	{
		complayer(arr);
	}

}
int outjudge(char arr[row][col], char x)
{
	int i, j;
	int k = 0;
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[2][0] == x)
	{
		return 1;
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] == x)
	{
		return 1;
	}
	for (i = 0; i < row; i++)
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][2] == x)
		{
			return 1;
		}
	for (j = 0; j < col; j++)
		if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[2][j] == x)
		{
			return 1;//someone has win the game
		}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == '#' || arr[i][j] == '*')
			{
				k = k + 1;
			}
		}
	}
	if (k == 9)
	{
		return 3;// tie
	}
	else
		return 2;//continue the game
}
void declare(int x, char y)
{
	switch (x)
	{
	case 1:
		printf("%c win\n", y);
		break;
	case 3:
		printf("平局");
		break;
	default:
		break;
	}
}
void game(char arr[row][col])
{
	intiboard(arr);
	priboard(arr);
	do
	{
		player(arr);
		priboard(arr);
		switch (outjudge(arr, '*'))
		{
		case 2 :
			complayer(arr);
			priboard(arr);
			break;
		default: 
			goto out;
			break;
		}
		
	} while (outjudge(arr, '*') == 2 && outjudge(arr, '#') == 2);
	out:
	declare(outjudge(arr, '#'), '#');
	declare(outjudge(arr, '*'), '*');
}
//outjudge and declare 写得真是一坨狗屎
void intiboard(char  arr[row][col])
{
	int i, j;
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void primenu()
{
	printf("*******************\n");
	printf("**1: play  0:exit**\n");
	printf("*******************\n");
}/*打印菜单*/