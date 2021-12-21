#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
#include <math.h>

// Функции заполнения и вывода двумерных мвссивов и функции swap
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
            int value = rand() % 10;
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

// сортировка пузырьком двумерного массива
// Вариант 1(Недоработан)
// постоянно выходит за пределы памяти,додумать небыло времени.Рабочий код ниже.
/*void bubbleSort(int** arr, const int row, int col)
{
    bool skip = false;
    while (!skip)
    {
      skip = true;
      for (int i = 0; i < row; i++)
      {
          for (int j = 0; j < col; j++)
          {
              if (arr[i][j] > arr[i][j + 1])
              {
                  swapInt(&arr[i][j], &arr[i][j + 1]);
                  skip = false;
              }
          }
      }
    }
}*/

// Вариант 2
// Этот код подсказал одногруппник
void bubbleSort(int** arr, int len)
{
    for (int i = 0; i < len * len; ++i)
    {
        for (int j = 0; j < len * len - 1; ++j)
        {
            int row = j / len, col = j % len, rowNext = (j + 1) / len, colNext = (j + 1) % len;
            if (arr[row][col] > arr[rowNext][colNext])
            {
                swapInt(&arr[row][col], &arr[rowNext][colNext]);
            }
        }
    }
}

// Функции заполнения и вывода для алгоритма ТПК
void fillTPK(double arr[], int len)
{
    printf("Enter 11 numbers(for example -> 2,3 or 2, and press enter)\n");
    for (int i = 0; i < len; ++i)
    {
        scanf("%lf", &arr[i]);
    }
    printf("\n\n");
}

void printTPK(double arr[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%.1f ", arr[i]);
    }
    printf("\n\n");
}

// Инвертирование массива
void invertTPK(double arr[], int len)
{
    for (int i = 0, j = len - 1; i < j; ++i, --j)
    {
        swapDbl(&arr[i], &arr[j]);
    }
}

// Функция возвращает формулу ТПК
double formTPK(double x)
{
    return sqrt(fabs(x)) + 5.0 * pow(x, 3.0);
}

// Сам алгоритм ТПК
void algTPK(double arr[], int len)
{
    double result = 0.0;
    for (int i = 0; i < len; ++i)
    {
        result = formTPK(arr[i]);
        if (result > 400.0)
        {
            printf("f(%.1f) > 400\n", arr[i]);
        }
        else
        {
            printf("f(%.1f) = %f\n", arr[i], result);
        }
    }
}




int main()
{
  setlocale(LC_ALL, "rus");
  // Task 1
  //Пузырьковая сортировка двумерного массива
  /*const int SIZE = 3;
  int** arrBubble = init2dIntArray(arrBubble, SIZE, SIZE);
  fill2dIntArray(arrBubble, SIZE, SIZE);
  print2dIntArray(arrBubble, SIZE, SIZE, 3);
  printf("\n");
  bubbleSort(arrBubble, SIZE);
  print2dIntArray(arrBubble, SIZE, SIZE, 3);*/


  // Task 3
  // Алгоритм ТПК
  /**/
  const int SIZED = 11;
  double arrTPK[SIZED];
  fillTPK(arrTPK, SIZED);
  printTPK(arrTPK, SIZED);
  invertTPK(arrTPK, SIZED);
  printTPK(arrTPK, SIZED);
  algTPK(arrTPK, SIZED);


  return 0;
}
