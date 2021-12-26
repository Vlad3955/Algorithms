#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
#include <math.h>

// ‘ункции заполнени€ и вывода одно/двумерных мвссивов и функции swap
void swapInt(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void swapDbl(double *a, double *b) {
    double t = *a;
    *a = *b;
    *b = t;
}

void fillIntRandom(int* array, int size, int border) {
    srand(time(NULL));
    for (int i = 0; i < size; ++i)
        *(array + i) = rand() % border;
}

void printIntArray(int* array, int size, int offset) {
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < size; ++i) {
        printf(format, array[i]);
        if (i != size - 1)
            printf(",");
    }
    printf("\n");
}

int get2dInt(int** array, const int row, const int col) {
    return *((*(array + row)) + col);

}
void set2dInt(int** array, const int row, const int col, int value) {
    *((*(array + row)) + col) = value;
}

int** init2dIntArray(int** array, const int row, const int col) {

    int * line = (int*) calloc(sizeof(int), row*col);
    array = (int**) calloc(sizeof(int*), row);
    for (int i = 0; i < row; ++i) {
        *(array + i) = &line[i*col];
    }

    return array;

}

void fill2dIntArray(int** array, const int row, const int col) {
    srand(time(NULL));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            //int value = ((i + 1) * (j + 1));
            int value = rand() % 50;
            set2dInt(array, i, j, value);
        }
    }
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

// ѕриорететна€ и двусторонн€€ очереди
#define SZ 10

// —труктура чтобы элемент мог обладать 2м€ параметрами
typedef struct
{
    int pr; // приоритет
    int dat; // данные
} Node; // tipedef позвол€ет назвать структуру как Node

Node* arr[SZ];
int head;
int tail;
int items;

// инициал. нул€ми массив типа ноуд и переменные
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

void ins (int pr, int dat)
{
    Node *node = (Node*) malloc(sizeof(Node)); // сущьность типа ноуд представл€юща€ собой элемент вставки принимающа€ в себ€ значени€ передоваемых параметров
    node->dat = dat;
    node->pr = pr;
    int flag; // переменна€ указывающа€ на место вставки

    if (items == 0) // если очередь пуста€ добавим элемент в конец
    {
        arr[tail++] = node;
        items++;
    }
    else if (items == SZ) // если полна€ вывод текста
    {
        printf("%s \n", "Queue is full");
        return;
    }
    else // ищем куда вставить элемент
    {
        int i = 0;
        int idx = 0;
        Node *tmp;
        for (i = head; i < tail; ++i)
        {
            idx = i % SZ;
            if (arr[idx]->pr > pr) // если приоретет выше чем у вставл€емого break
            {
                break;
            }
            else // дошли до конца и не нашли больше idx++
            {
                idx++; // в обоих случа€х idx укажет на место вставки элемента
            }
        }
        // если место вставки внутри очереди то все элементы включа€ то место на которое указывает флаг нужно сдвинуть в право
        flag = idx % SZ; // переменна€ указывающа€ на место вставки
        i++; // теперь i имеет следующий индекс после флага
        while (i <= tail)
        {
            idx = i % SZ; // idx так же теперь указывает на следующий элемент
            tmp = arr[idx]; // записываем его во вспомог переменную
            arr[idx] = arr[flag];
            arr[flag] = tmp;
            i++; // и на каждой итерации перекидываем элементы до хвоста
        }
        arr[flag] = node; // сейчас здесь находитс€ последний элемент очереди,замен€ем на вставл€емое значение
        items++;
        tail++;
    }

}

Node* rem()
{
    if (items == 0)
    {
        return NULL;
    }
    else
    {
        int idx = head++ % SZ;
        Node *tmp = arr[idx];
        arr[idx] = NULL;
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
}

int main()
{
  setlocale(LC_ALL, "rus");
  init();
  ins(1, 11);
  ins(3, 22);
  ins(4, 33);
  ins(2, 44);
  ins(3, 55);
  ins(4, 66);
  ins(5, 77);
  ins(1, 88);
  ins(2, 99);
  ins(6, 100);
  printQueue();
  for (int i = 0; i < 7; ++i)
  {
      Node* n = rem();
      printf("pr = %d, dat = %d \n", n->pr, n->dat);
  }
  printQueue();

  ins(1, 110);
  ins(3, 120);
  ins(6, 130);
  printQueue();
  return 0;
}
