#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
#include <math.h>

// Функции заполнения и вывода одно/двумерных мвссивов и функции swap
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


// QUICKSORT FAST


int median (int* a, int* b, int* c)
{

    if (*a > *b)
    {
       int t = *a;
       *a = *b;
       *b = t;
    }
    if (*b > *c)
    {
        int t = *b;
        *b = *c;
        *c = t;
    }
    if (*a > *b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }
    return *b;
}

void qsf(int* arr, int first, int last)
{
    if (last > 10)
    {
        int i = first;
        int j = last;
        int x = median(&arr[first], &arr[(first + last) / 2], &arr[last]);

    do {
        while (arr[i] < x)
        {
            i++;
        }
        while (arr[j] > x)
        {
            j--;
        }
        if (i <= j)
        {
            swapInt(&arr[i], &arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

      if (i < last)
      {
          qsf(arr, i, last);
      }
      if (first < j)
      {
          qsf(arr, first, j);
      }
    }
    else
    {
       int temp, pos;
        for (int i = first; i <= last; ++i)
        {
           temp = arr[i];
           pos = i - 1;
           while (pos >= 0 && arr[pos] > temp)
           {
              arr[pos + 1] = arr[pos];
              pos--;
           }
           arr[pos + 1] = temp;
        }
    }

}

// BUCKETSORT
void bucketSort(int* arr, int len)
{
    const int max = len;
    const int b = 10;

    int buckets[b][max + 1];
    for (int i = 0; i < b; ++i)
    {
        buckets[i][max] = 0;
    }

        for (int digit = 1; digit < 1000000000; digit *= 10)
        {
            int evenArray[max];
            int evenCounter = 0;

            for (int i = 0; i < max; ++i)
            {
                if (arr[i] % 2 != 0)
                {
                    continue;
                }
                evenArray[evenCounter++] = i;
                int d = (arr[i] / digit) % b;

                /*
                int counter = buckets[d][max];
                buckets[d][counter] = arr[i];
                counter++;
                buckets[d][max] = counter;
                */

                // тоже что и закоментированый код
                buckets[d][buckets[d][max]++] = arr[i];
             }

             int idx = 0;
             for (int i = 0; i < b; ++i)
             {
                for ( int j = 0; j < buckets[i][max]; ++j)
                {
                    arr[evenArray[idx++]] = buckets[i][j];
                    //idx++;
                }
                 buckets[i][max] = 0;
             }
        }
}



int main()
{
  setlocale(LC_ALL, "rus");

  // QUICKSORT and SORTINSERTS
  const int SZ = 20;
  int arr[SZ];
  fillIntRandom(arr, SZ, 100);
  printIntArray(arr, SZ, 3);
  qsf(arr, 0, SZ - 1);
  //bucketSort(arr, SZ);
  printIntArray(arr, SZ, 3);

  // QUICKSORT FAST
  return 0;
}
