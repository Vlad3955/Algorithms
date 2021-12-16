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

// мой вариант с ограничением по нулевым rows & cols
#define HEIGHT 5
#define WIDTH 5

int board[HEIGHT][WIDTH];
int i, j;

void chessBoard()
{
    srand(time(NULL));
    for (i = 0; i < HEIGHT; ++i)
    {
        for (j = 0; j < WIDTH; ++j)
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

// // Вариант на основе преподавательского с рандомным заполнением препятсвий
/*void chessBoard(int** arr, const int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            arr[i][j] = (rand() % 5 == 1) ? 1 : 0;
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int get2dInt(int** array, const int row, const int col) {
    return *((*(array + row)) + col);

}


int** init2dIntArray(int** array, const int row, const int col) {

    int * line = (int*) calloc(sizeof(int), row*col);
    array = (int**) calloc(sizeof(int*), row);
    for (int i = 0; i < row; ++i) {
        *(array + i) = &line[i*col];
    }

    return array;

}

void print2dIntArray(int** array, const int row, const int col, int offset) {
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf(format, get2dInt(array, i, j));
        }
        printf("\n");
    }
}

int routes(int x, int y, int dArr)
{
        if (get2dInt(dArr, y, x) == 1)
        {
            return 0;
        }
        if (x == 0 && y == 0)
        {
            return 0;
        }
        else if (x == 0)
        {
            if (routes(x, y - 1, dArr) == 0 && y != 1)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else if (y == 0)
        {
             if (routes(x - 1, y, dArr) == 0 && x != 1)
            {
                return 0;
            }
            return 1;
        }
            return routes(x, y - 1, dArr) + routes(x - 1, y, dArr);
}*/

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

    // Вариант на основе преподавательского с рандомным заполнением препятсвий
    /*const int SIZE = 5;
    int** field = init2dIntArray(field, SIZE, SIZE);

    chessBoard(field, SIZE);
    printf("\n");

    for (int y = 0; y < SIZE; ++y)
    {
         for (int x = 0; x < SIZE; ++x)
         {
             printf("%5d", routes(x, y, field));
         }
         printf("\n");
    }*/

    return 0;
}
