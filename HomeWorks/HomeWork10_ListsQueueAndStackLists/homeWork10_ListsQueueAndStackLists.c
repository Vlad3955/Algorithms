#include <stdio.h>
#include <stdlib.h>

#define true 1 == 1
#define false 1 != 1

typedef int boolean;

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

// �������� ��������� ������ �� ��������
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

// ������ ������� � ����������� ������������������ ����
// Task1
#define T char
boolean pushOneLinkStack(List *stack, T value) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        printf("Stack overflow \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
}
T popOneLinkStack(List *stack) {
    if (stack->size == 0) {
        printf("Stack is empty \n");
        return -1;
    }
    Node *tmp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    return data;
}



#define VARIANTS 3
int braceCorrect(char* braceExpr)
{
    char braces[][2] = {{'(', ')'},{'{', '}'},{'[', ']'}};
    List *braceStack = (List*) malloc(sizeof(List));
    init(braceStack);
    int countIdx = 0;
    while (*braceExpr != '\0')
    {
        for (int i = 0; i < VARIANTS; ++i)
        {
            if (*braceExpr == braces[i][0])
            {
                pushOneLinkStack(braceStack, i);
            }
        }
        for (int i = 0; i < VARIANTS; ++i)
        {
            if (*braceExpr == braces[i][1])
            {
                if (braceStack->size == 0)
                {
                    return countIdx;
                }
                if (i == braceStack->head->dat)
                {
                    popOneLinkStack(braceStack);
                }
                else
                {
                    return countIdx;
                }
            }
        }
        braceExpr++;
        countIdx++;
    }
    if (braceStack->size != 0)
    {
        return braceStack->head->dat;
    }
    return -1;
}


// Task2
void copyList(List* lst, List* lst2)
{
    if (lst == NULL)
    {
        lst2->head = NULL;
        lst2->size = 0;
        return;
    }
    Node* newLst = (Node*) malloc(sizeof(Node));
    lst2->head = newLst;
    Node* current = lst->head;
    while (current->next != NULL)
    {
       newLst->dat = current->dat;
       current = current->next;
       newLst->next = (Node*) malloc(sizeof(Node));
       newLst = newLst->next;
       lst2->size++;
    }
    newLst->dat = current->dat;
    newLst->next = NULL;
    lst2->size++;
}

// Task3
boolean is_Sort(List* lst)
{
    Node* current = lst->head;
    while (current->next != NULL)
    {
        if (current->dat > current->next->dat)
        {
            return false;
        }
        current = current->next;
    }
    return true;
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



int main()
{
  // Task 1
  printf(") : %d \n", braceCorrect(")"));
  printf("( : %d \n", braceCorrect("("));
  printf("[2/{5*(4+7)}] : %d \n", braceCorrect("[2/{5*(4+7)}]"));

  // Task 2 & 3
  /*
  List* lst = (List*) malloc(sizeof(List));
  init(lst);
  ins(lst, 1);
  ins(lst, 22);
  ins(lst, 3);
  ins(lst, 4);
  ins(lst, 6);
  ins(lst, 10);
  printList(lst);
  List* lst2 = (List*) malloc(sizeof(List));
  init(lst2);
  copyList(lst, lst2);
  printList(lst2);
  int x = is_Sort(lst);
  printf("%s", x ? "true" : "false");
  */

  return 0;
}
