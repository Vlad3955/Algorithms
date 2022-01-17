#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define true 1 == 1
#define false 1 != 1

typedef int boolean;

#define SZ 40
int cursor = -1;
int Stack[SZ];



#define N 6
int matrix[N][N] = {
     {0, 1, 1, 0, 0, 0},
     {0, 0, 0, 1, 1, 1},
     {0, 0, 0, 0, 0, 1},
     {1, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 1, 0},
};
int visited[N] = {0};

void depthTravers(int st)
{
    int r;
    printf("%d ", st);

    visited[st] = 1;
    for (r = 0; r < N; ++r)
    {
        if (matrix[st][r] == 1 && !visited[r])
        {
            depthTravers(r);
        }
    }
}

void resetArr()
{
    for (int i = 0; i < N; ++i)
    {
        visited[i] = 0;
    }
}



int main()
{
  depthTravers(0);
  resetArr();
  printf("\n");


  return 0;
}
