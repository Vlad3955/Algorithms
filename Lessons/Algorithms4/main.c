#include <stdio.h>
#include <stdlib.h>


void rec(int a)
{
    printf("%5d", a);
    if (a > 0)
    {
        rec(a - 1);
    }
}

// Сумма разрядов числа(цикл)
int sumDigitsIterative(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Сумм разрядов числа(рекурсия)
int sumDigitsRecursive(int num)
{
    if (num > 0)
    {
        return num % 10 + sumDigitsRecursive(num / 10);
    }
    else
    {
        return 0;
    }
}

// Число Фабианчи
int fib(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

// Факториал числа сложность линейная(O(n))
int recFactorial(int n)
{
    if (n <= 0)
    {
        return 1;
    }
    return n * recFactorial(n - 1);
}

int iterFactorial(int n)
{
    if (n < 0)
    {
        return -1;
    }
    int result = 1;
    for (int i = 1; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

// Триугольные числа
int triangle(int n)
{
    int result = 0;
    if (n == 1)
    {
        result += 1;
    }
    else
    {
        result += n + triangle(n - 1);
    }
}

void printPyramid(int n)
{
    int i = 1;
    while (i <= n)
    {
        int amnt = i;
        char shift[5];
        sprintf(shift, "%%%dd", n + 1 - i);
        printf(shift, i);
        while (--amnt != 0)
        {
            printf("%2d", i);
        }
        printf("\n");
        i++;
    }
}

void printTriangle(int n)
{
    int prev = 0;
    while (n > 0)
    {
        prev++;
        n -= prev;
        printf("%s%d", (prev > 1) ? " + " : "", prev);
    }
}

// Анаграмма
void rotate(char* word, int size, int n)
{
    int i;
    int pos = size - n;
    char temp = word[pos];
    for (i = pos + 1; i < size; ++i)
    {
        word[i - 1] = word[i];
    }
    word[i - 1] = temp;
}

void display(char* word, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%c", word[i]);
    }
    printf("\n");
}

void getAnagram(char* word, int size, int n)
{
    if (n == 1)
    {
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        getAnagram(word, size, n - 1);
        if (n == 2)
        {
            display(word, size);
        }
        rotate(word, size, n);
    }
}

// Ханойские башни
int operation = 0;
void put(int from, int to)
{
    printf("%d -> %d | ", from, to);
    if ((++operation % 5) == 0)
    {
        printf("\n");
    }
}

void hanoi(int from, int to, int n)
{
    int temp = from ^ to;
    if (n == 1)
    {
        put(from, to);
    }
    else
    {
        hanoi(from, temp, n - 1);
        put(from, to);
        hanoi(temp, to, n - 1);
    }
}

// Динамическое программирование, задача о 8и ферзях
#define HEIGHT 8
#define WIDTH 8
#define QUEENS 8
// + к задаче про коня
#define KNIGHTS HEIGHT * WIDTH - 1

int board[HEIGHT][WIDTH];

void annull()
{
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            board[i][j] = 0;
        }
    }
}

void printBoard()
{
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            printf("%3d", board[i][j]);
        }
        printf("\n");
    }
}

int checkQueen(int x, int y)
{
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
           if (board[i][j] != 0)
           {
               if (!(i == x && j == y))
               {
                   if (i - x == 0 || j - y == 0)
                   {
                       return 0;
                   }
                   if (abs(i - x) == abs(j - y))
                   {
                       return 0;
                   }
               }
           }
        }
    }
    return 1;
}

int checkBoard()
{
     for (int y = 0; y < HEIGHT; ++y)
    {
        for (int x = 0; x < WIDTH; ++x)
        {
            if (board[y][x] != 0)
            {
                if (checkQueen(y, x) == 0)
                {
                     return 0;
                }
            }
        }
    }
    return 1;
}

int queens(int n)
{
    if(checkBoard() == 0)
    {
        return 0;
    }
    if (n == QUEENS + 1)
    {
        return 1;
    }
    for (int y = 0; y < HEIGHT; ++y)
    {
        for (int x = 0; x < WIDTH; ++x)
        {
            if (board[y][x] == 0)
            {
                board[y][x] = n;
                if (queens(n + 1))
                {
                     return 1;
                }
                board[y][x] = 0;
            }
        }
    }
    return 0;
}

// + к задаче про коня
int possible[][2] = {
        {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
        {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
};

int isPossible(int x, int y)
{
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && board[y][x] == 0;
}

int knightMove(int x, int y, int move)
{
    int nextX;
    int nextY;
    board[y][x] = move;
    if (move > KNIGHTS)
    {
        return 1;
    }
    for (int i = 0; i < 7; ++i)// 8 - это длинна массива possible
    {
        nextX = x + possible[i][1];
        nextY = y + possible[i][0];
        if (isPossible(nextX, nextY) && knightMove(nextX, nextY, move +1))
            {
                return 1;
            }
    }
    board[y][x] = 0;
    return 0;
}

// Подпоследовательности
// X(1..N) abcbdab
// Y(1..N) bcdb

// LCS(x, y) = LCS(x[1+x], y[1+y]) + 1, если x[i] = y[i]
// LCS(x, y) = максимальное из (LCS(x[i], y[i+1]), LCS(x[i+1], y[i])), если x[i] != y[i]
// LCS(x ,y) = 0 если x = 0, y = 0

int lcs_len(char* a, char* b)
{
    if (*a == '\0' || *b == '\0')
    {
        return 0;
    }
    else if (*a == *b)
    {
        return 1 + lcs_len(a + 1, b + 1);
    }
    else
    {
        int x1 = lcs_len(a + 1, b);
        int x2 = lcs_len(a, b + 1);
        return (x1> x2) ? x1 : x2;
    }
}

//поиск маршрута щахматного коня
// S(m, n) = S(m - 1, n) + S(m. n -1)
// S(m, n) = 1, если одна из координат равна нулю
// S(m, n) = 0, усли m и n это стартовые координаты

int routes(int x, int y)
{
    if (x == 0 && y == 0)
    {
        return 0;
    }
    else if ( x == 0 ^ y == 0)
    {
        return 1;
    }
    else
    {
        return routes(x, y - 1) + routes(x -1, y);
    }
}

int main()
{
    //rec(10);

    // Ниже самма числа рекурсией и итерацией
    //printf("\n %d \n", sumDigitsIterative(12345));
    //printf("%d \n", sumDigitsRecursive(123456));

    // Ниже цикл для чисел Фибианчи(экспоненциальное время выполнения O(n!))
    //for (int i = 0; i < 20; ++i)
    //{
    //    printf("%d ", fib(i));
    //}

    // Ниже факториал числа
    //int input;
    //printf("%s", "Enter number: ");
    //scanf("%d", &input);
    //printf("%d \n", iterFactorial(input));

    // Триугольные числа
    //const int num = 5;
    //printf("%d \n", triangle(num));
    //printPyramid(num);
    //printTriangle(triangle(num));

    // Анаграмма
    //int size = 4;
    //char arr[64];
    //printf("Enter word %d letters long: ", size);
    //scanf("%s", arr);
    //printf("\n");
    //getAnagram(arr, size, size);

    // Ханойские башни
    //int disks = 8;
    //printf("pyramid size = %d \n", disks);
    //hanoi(1, 3, disks);
    //printf("\n operation = %d", operation);

    // Динамическое программирование, задача о 8и ферзях
    //annull();
    //queens(1);
    //printBoard();
    // Задача про коня
    //annull();// обнулили доску
    //knightMove(1, 0, 1);
    //printBoard();

    // Подпоследовательности
    //char* x = "abcbdab";
    //char* y = "bcdb";
    //printf("Длинна наибольшей общей подпоследовательности: %d", lcs_len(x, y));

    // поиск маршрута щахматного коня
    const int sizeX = 5;
    const int sizeY = 5;
    for (int y = 0; y < sizeY; ++y)
    {
         for (int x = 0; x < sizeX; ++x)
         {
             printf("%5d", routes(x, y));
         }
         printf("\n");
    }

    return 0;
}
