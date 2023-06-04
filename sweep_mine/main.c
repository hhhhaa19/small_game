#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"
int main()
{
	
	int judge = 0;
	do
	{
		menu();
		scanf("%d", &judge);
		if(1==judge)
		game();
	} while (judge);
	printf("game over\n");

	return 0;
}