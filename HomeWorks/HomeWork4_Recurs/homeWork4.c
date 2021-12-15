#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void transNum(int n)
{
    if (n >= 2)
    {
        transNum(n / 2);
    }
    printf("%d", n % 2);
}

int expon(int a, int b)
{
   if (b == 1)
   {
       return a;
   }
   return a * expon(a, b - 1);
}

int exponExtra(int a, int b)
{
   if (b == 0)
   {
       return 1;
   }
   if (b % 2 != 0)
   {
       return exponExtra(a, b - 1) * a;
   }
   else
   {
       int c = exponExtra(a, b / 2);
       return c * c;
   }
}

#define HEIGHT 5
#define WIDTH 5

int board[HEIGHT][WIDTH];
int i, j;

void chessBoard()
{
    srand(time(NULL));
    for ( i = 0; i < HEIGHT; ++i)
    {
        for ( j = 0; j < WIDTH; ++j)
        {
           if (i == 0 || j == 0)
           {
               board[i][j] = 0;
           }
           else
           {
               board[i][j] = (rand() % 5 == 1) ? 1 : 0;
           }
           printf("%5d", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}



int routes(int x, int y)
{
        if (x == 0 && y == 0 || board[y][x] == 1)
        {
            return 0;
        }
        else if (x == 0 || y == 0)
        {
            return 1;
        }
        else
        {
            return routes(x, y - 1) + routes(x - 1, y);
        }
}


int main()
{
    //transNum(61);
    //printf("%d", expon(2, 10));
    //printf("%d", exponExtra(2, 5));
    chessBoard();
    //const int sizeX = 5;
    //const int sizeY = 5;
    for (int y = 0; y < HEIGHT; ++y)
    {
         for (int x = 0; x < WIDTH; ++x)
         {
             printf("%5d", routes(x, y));
         }
         printf("\n");
    }
    return 0;
}
