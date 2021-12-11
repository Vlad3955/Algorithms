#include <stdio.h>

int main()
{
    int result = 1;
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    if (num > 1)
    {
        for(int i = 2; i < num; i++)
        {
            if(num % i == 0)
            {
                result = 0;
            }
        }
    }
    else
    {
        result = 0;
    }

    if(result == 0)
    {
        printf("This is a not prime number!\n");
    }
    else
    {
        printf("This is a prime number!\n");
    }
    return 0;
}
