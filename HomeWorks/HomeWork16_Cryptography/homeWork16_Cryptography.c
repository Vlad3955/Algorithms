#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


// Task 1
char* encrypt (char *s, int n)
{
    if (s == NULL)
        return NULL;
    const int len = strlen(s);
    if (len == 0)
        return NULL;
	char *res = (char*) malloc(sizeof(char) * len);
	for (int i = 0; i < len; ++i)
	{
		res[i] = s[i] + (char)n;
	}
	res[len] = 0;
	return res;
}

char* decipher (char *s, int n)
{
    if (s == NULL)
        return NULL;
    const int len = strlen(s);
    if (len == 0)
        return NULL;
	char *res = (char*) malloc(sizeof(char) * len);
	for (int i = 0; i < len; ++i)
	{
		res[i] = s[i] - (char)n;
	}
	res[len] = 0;
	return res;
}

//Task 2

char* reshuffleEncrypt(char* s, int col)
{

    const int num = strlen(s);
	int row = num / col;
	if(num % col != 0)
		row++;
	char* tmp = (char*) malloc(sizeof(char) * (row*col));
    char *res = (char*) malloc(sizeof(char) * (row*col));
	int t = 0;
	for(int i = 0; i < col; ++i)
	{
		for(int j = i; j < row*col; j += col)
		{
			if(j < num)
				tmp[t++] = s[j];
			else
				tmp[t++] = 97 + rand()%26;
		}
	}
	t=0;
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
		{
			res[t++] = tmp[i*col+j];
		}

	free(tmp);
	return res;
}

char* reshuffleDecrypt(char* s, int col)
{

    const int num = strlen(s);
	int row = num / col;
	if(num % col != 0)
		row++;
	char* tmp = (char*) malloc(sizeof(char) * (row*col));
    char *res = (char*) malloc(sizeof(char) * (row*col));
	int t = 0;
	for(int i = 0; i < col; ++i)
	{
		for(int j = i; j < row*col; j += col)
		{
			tmp[j] = s[t++];
		}
	}
	t=0;
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
		{
			if(i*col+j < num)
				res[t++] = tmp[i*col+j];
			else
				res[t++] = '\0';
		}

	free(tmp);
	return res;
}

int main ()
{
    // Task 1
	setlocale(LC_ALL,"Russian");
//	int n;
//	printf("Введите натуральное n: ");
//	scanf("%d", &n);
//	getchar(); //нужен для того, чтобы поймать символ клавиши ENTER, нажатой при вводе числа n
//	if (n < 1) return 0;
//	printf("Чтобы зашифровать текст введите a, расшифровать b: ");
//	char c;
//	scanf("%c", &c, 1);
//	char* s = "Good day!";
//	if (c == 'a')
//         printf("%s", encrypt(s, n));
//    s = encrypt(s, n);
//	if (c == 'b')
//        printf("%s", decipher(s, n));

    // Task 2
    int n;
	printf("Введите натуральное n: ");
	scanf("%d", &n);
	getchar(); //нужен для того, чтобы поймать символ клавиши ENTER, нажатой при вводе числа n
	if (n < 1) return 0;
	printf("Чтобы зашифровать текст введите a, расшифровать b: ");
	char c;
	scanf("%c", &c, 1);
	char* s = "Good day!";
	if (c == 'a')
         printf("%s", reshuffleEncrypt(s, n));
    s = reshuffleEncrypt(s, n);
	if (c == 'b')
        printf("%s", reshuffleDecrypt(s, n));
	return 0;
}
