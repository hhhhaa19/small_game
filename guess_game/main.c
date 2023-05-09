#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void menu(void);
extern void guess_judge(int rad);
int main()
{
	srand((unsigned int)time(NULL));
	int a = 1;
	do
	{
		menu();
		scanf("%d", &a);
		if (a == 0)
			break;
		int rad = rand() % 100 + 1;
		guess_judge(rad);

	} while (a == 1);

	

	return 0;
}