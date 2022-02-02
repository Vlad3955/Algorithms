#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define true 1 == 1
#define false 1 != 1
//#define T char

typedef int boolean;

int charToInt(char *s)
{
    int sum = 0;
	while (*s)
	{
		sum += *s;
		*s++;
	}
	return sum;
}

void countSum(int *den, int* count, int num, int sum)
{
    for (int i = 0; i < num; ++i)
    {
        count[i] = sum / den[i];
        sum -= den[i] * count[i];
    }
}

int main()
{
	printf("abcd - %d", charToInt("abcd"));
	printf("\n");

	int sum = 15;
	int denom[] = {50, 10, 5, 2, 1};
	int number = sizeof(denom) / sizeof(denom[0]);
	int* countCoins = (int*) malloc(number * sizeof(int));
	countSum(denom, countCoins, number, sum);
	printf("%d is sum of: ", sum);
	for (int i = 0; i < number; ++i)
    {
        printf("%d - %d times; ", denom[i], countCoins[i]);
    }
    free(countCoins);
    return 0;
}
