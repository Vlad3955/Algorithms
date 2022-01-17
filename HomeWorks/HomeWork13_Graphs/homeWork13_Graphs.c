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

// Task 1
boolean push(int n)
{
    if (cursor < N)
    {
        Stack[++cursor] = n;
        return true;
    }
    else
    {
        printf("overflow");
        return false;
    }
}

int pop()
{
    if (cursor != -1)
    {
       return Stack[cursor--];
    }
    else
    {
        printf("is empty");
        return -1;
    }
}

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
    push(st);
    visited[st] = 1;
    for (int r = 0; r < N; ++r)
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

void printPop()
{
   while (cursor != -1)
  {
      printf("%d ", pop());
  }
  printf("\n");
}

// Task 2
void apexCount(int* n)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (matrix[j][i] == 1 && i != j)
            {
                n[i]++;
            }
        }
    }
}

void adjCount(int st, int* n)
{
    visited[st] = 1;
    for (int i = 0; i < N; ++i)
    {
        if (matrix[st][i] && st != i)
        {
            n[st]++;
            if (!visited[i])
            {
                adjCount(i, n);
            }
        }
    }
}

int main()
{
  // Task 1
  depthTravers(0);
  resetArr();
  printPop();

  // Task 2
  int* peaks = (int*) malloc(sizeof(int));
  for (int i = 0; i < N; ++i)
  {
      peaks[i] = 0;
  }

  apexCount(peaks);
  printf("\n");

  for (int i = 0; i < N; ++i)
  {
      printf("%d ", peaks[i]);
  }

  printf("\n");

  resetArr();

  for (int i = 0; i < N; ++i)
  {
      peaks[i] = 0;
  }

  adjCount(0, peaks);
  printf("\n");

  for (int i = 0; i < N; ++i)
  {
      printf("%d ", peaks[i]);
  }

  return 0;
}
