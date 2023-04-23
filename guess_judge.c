#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void guess_judge(int rad)
{
	int guess = 0;
	printf("input your guess\n");
	do 
	{
		scanf("%d", &guess);
		if (rad > guess)
		{
			printf("your guess %d is less than target\n", guess);
		}
		else if(rad < guess)
		{
			printf("your guess %d is greater than target\n", guess);
		}
		else
		{
			printf("congratulation ! you are right\n");
		}
	} while (rad != guess);
}