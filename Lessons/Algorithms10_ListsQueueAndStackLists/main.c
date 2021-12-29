#include <stdio.h>
#include <stdlib.h>

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

int main()
{
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

  return 0;
}
