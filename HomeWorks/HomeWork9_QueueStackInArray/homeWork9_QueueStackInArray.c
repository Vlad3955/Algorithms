#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define true 1 == 1
#define false 1 != 1

typedef int boolean;

// Task1
#define SZ 10


typedef struct {
    int pr;
    int dat;
} Node;

Node* arr[SZ];
int head;
int tail;
int items;


void init()
{
    for (int i = 0; i < SZ; ++i)
    {
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}


void ins2 (int pr, int dat)
{
    Node *node = (Node*) malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;

        arr[tail++] = node;
        items++;
}



Node* rem2()
{
    if (items == 0)
    {
        return NULL;
    }
    else
    {
       int i;
       Node* min = arr[0];
       for (i = head; i < tail; ++i)
       {
          if (arr[i]->pr < min->pr)
          {
              min = arr[i];
          }
       }
          Node *tmp = min;
          min = NULL;
          items--;
          return tmp;
    }
}



void printQueue()
{
    printf("[ ");
    for (int i = 0; i < SZ; ++i)
    {
        if (arr[i] == NULL)
        {
            printf("[*, *] ");
        }
        else
        {
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
        }
    }
    printf(" ]\n");
    printf("\n\n");
}


// Task2

#define T int
#define SIZE 50

int cursor = -1;
T Stack[SIZE];

boolean push(T dec)
{
    if (cursor < SIZE)
    {
        int mod, bin;
        while (dec)
        {
            mod = dec % 2;
            dec /= 2;
            Stack[++cursor] = 10 * bin + mod;
        }
        return true;
    }
    else
    {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

T pop()
{
    if ( cursor != - 1)
    {
        return Stack[cursor--];
    }
    else
    {
        printf("%s \n", "Stack id empty");
        return -1;
    }
}



int main()
{
  // Task1
  /*
  init();
  ins2(6, 100);
  ins2(3, 22);
  ins2(4, 33);
  ins2(2, 44);
  ins2(3, 55);
  ins2(4, 66);
  ins2(5, 77);
  ins2(1, 88);
  ins2(2, 99);
  ins2(1, 11);
  printQueue();


  for (int i = 0; i < 1; ++i)
  {
      Node* n = rem2();
      printf("pr = %d, dat = %d \n", n->pr, n->dat);
  }
  printQueue();
  */

  // Task2
  push(61);
  while (cursor != -1)
  {
      printf("%d ", pop());
  }
  return 0;
}
