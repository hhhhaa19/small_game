#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"
void menu(void)
{
	printf("****************************\n");
	printf("****1:paly ****** 0:quit****\n");
	printf("****************************\n");
	printf("��Ϸ������10*10�������й���10�����ף�����ѡ��һ����ַ�����ʾ��Χ8����ַ�ĵ��׸���\n");
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
