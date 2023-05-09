#define _CRT_SECURE_NO_WARNINGS 1
#include "main.h"

int main(void)
{
	int a;
	char arr[row][col];
	srand((unsigned int)time(NULL));//create a rand number
	primenu();
	scanf_s("%d", &a);
	switch (a)
	{
	case 0:
		printf("game is over\n");
		break;
	case 1:
		game(arr);
		break;
	default:
		break;
	}
	return 0;
}