#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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
        if (items < SZ)
        {
            arr[tail++] = node;
            items++;
        }
        else
        {
            printf("Is full \n");
        }
}


// до урока были некоторые ошибки в коде,работал некорректно
Node* rem2()
{
    if (items == 0)
    {
        printf("Is empty \n");
        return NULL;
    }
    else
    {
       int idx;
       int min = arr[0];
       for (int i = 0; i < items; ++i)
       {
          if (arr[i]->pr < min)
          {
              min = arr[i]->pr;
              idx = i;
          }
       }
          Node *tmp = arr[idx];
          while (idx < items)
          {
              arr[idx] = arr[idx + 1];
              idx++;
          }
          items--;
          tail--;
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

boolean push(T data)
{
    if (cursor < SIZE)
    {
        Stack[++cursor] = data;
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

void decBin(int num)
{
    while (num >= 1)
    {
        push(num % 2);
        num /= 2;
    }
}

int main()
{
  setlocale(LC_ALL, "rus");
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
  // Почемуто заканчивает с ошибкой когда таск 1 раскоменчен ошибку
  // Task2
  decBin(61);
  while (cursor != -1)
  {
      printf("%d ", pop());
  }
  return 0;
}
