#include <stdio.h>
#include <stdlib.h>

// ONELINKLIST

typedef struct Node
{
    int dat;
    struct Node* next;
} Node;

typedef struct
{
    Node* head;
    int size;
} List;

void init(List* lst)
{
    lst->head = NULL;
    lst->size = 0;
}

void ins(List* lst, int data)
{
    Node* new = (Node*) malloc(sizeof(Node));
    new->dat = data;
    new->next = NULL;

    Node* current = lst->head;
    if (current == NULL)
    {
        lst->head = new;
        lst->size++;
        return;
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new;
        lst->size++;
    }
}

// Удаление элементов списка по значению
Node* rm(List* lst, int data)
{
    Node* current = lst->head;
    Node* parent = NULL;
    if (current == NULL)
    {
        return NULL;
    }

    while (current->next != NULL && current->dat != data)
    {
        parent = current;
        current = current->next;
    }
    if (current->dat != data)
    {
        return NULL;
    }
    if (current == lst->head)
    {
        lst->head = current->next;
        lst->size--;
        return current;
    }
    parent->next = current->next;
    lst->size--;
    return current;
}

void printNode(Node* n)
{
    if (n == NULL)
    {
        printf("[]");
        return;
    }
    printf("[%d] ", n->dat);
}

void printList(List* lst)
{
    Node* current = lst->head;
    if (current == NULL)
    {
        printNode(current);
    }
    else
    {
        do
        {
            printNode(current);
            current = current->next;
        }
        while (current != NULL);
    }
    printf(" Size: %d \n", lst->size);
}

// STACK ONELINKLIST

#define T char
#define true 1 == 1
#define false 1 != 1

typedef int boolean;

typedef struct Node
{
    T dat;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    int size;
} Stack;

void init(Stack *st)
{
    st->head = NULL;
    st->size = 0;
}

boolean pushStack(Stack *st, T val)
{
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL)
    {
        printf("is full");
    }
    tmp->dat = val;
    tmp->next = st->head;

    st->head = tmp;
    st->size++;
    return true;
}

T popStack(Stack *st)
{
    if (st->size == 0)
    {
        printf("is empty");
        return -1;
    }
    Node *tmp = st->head;
    T data = st->head->dat;
    st->head = st->head->next;
    free(tmp);
    st->size--;
    return data;
}

void printOneLinkCharNode(Node *n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%c]", n->dat);
}
void printOneLinkCharStack(Stack *st) {
    Node *current = st->head;
    if (current == NULL) {
        printOneLinkCharNode(current);
    } else {
        do {
            printOneLinkCharNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", st->size);
}

int main()
{
  // ONELINKLIST

  List* lst = (List*) malloc(sizeof(List));
  init(lst);
  printList(lst);
  ins(lst, 1);
  printList(lst);
  ins(lst, 10);
  printList(lst);
  printNode(rm(lst, 1)); printf("<- removed node\n");
  printList(lst);
  printNode(rm(lst, 2)); printf("<- removed node\n");
  printList(lst);

  // STACK ONELINKLIST

  Stack *st = (Stack*) malloc(sizeof(Stack));
    init(st);
    pushStack(st, 'a');
    pushStack(st, 'b');
    pushStack(st, 'c');
    pushStack(st, 'd');
    pushStack(st, 'e');
    printOneLinkCharStack(st);
    printf("%c \n", popStack(st));
    printOneLinkCharStack(st);
    printf("%c \n", popStack(st));
    printOneLinkCharStack(st);
    printf("%c \n", popStack(st));
    printOneLinkCharStack(st);
  return 0;
}
