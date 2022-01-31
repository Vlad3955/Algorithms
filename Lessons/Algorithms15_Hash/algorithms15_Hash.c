#include <stdio.h>
#include <stdlib.h>

#define true 1 == 1
#define false 1 != 1
#define T char

typedef int boolean;

// CHAIN METHOD
//==========================================
typedef int K;
typedef int htIndex;// hash-table index

typedef struct OneLinkNode {
    int dat;
    struct OneLinkNode *next;
} OneLinkNode;

int htSize; //global var hash-table size

htIndex hash(T data)
{
    return data % htSize;
}

boolean insertNode(OneLinkNode** table, K data)
{
    OneLinkNode *p, *p0;

    htIndex bucket = hash(data);
    p = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    if (p == NULL)
    {
        printf("Out of memory! \n");
        return false;
    }

    p0 = table[bucket];
    table[bucket] = p;
    p->next = p0;
    p->dat = data;
    return true;
}

OneLinkNode* findNode(OneLinkNode** table, K data)
{
    OneLinkNode *p = table[hash(data)];
    while (p && !(p->dat == data))
    {
        p = p->next;
    }
    return p;
}

void deleteNode(OneLinkNode** table, K data)
{
    OneLinkNode *parent, *current;
    parent = NULL;
    htIndex bucket = hash(data);
    current = table[bucket];
    while (current && !(current->dat == data))
    {
        parent = current;
        current = current->next;
    }
    if (!current)
    {
        printf("Value not found \n");
        return;
    }
    if (parent)
    {
        parent->next = current->next;
    }
    else
    {
        table[bucket] = current->next;
    }
    free(current);
}

void printTable(OneLinkNode** table, int size)
{
    OneLinkNode *p;
    for (int i = 0; i < size; ++i)
    {
        p = table[i];
        while (p)
        {
            printf("%5d", p->dat);
            p = p->next;
        }
        printf("\n");
    }
    printf("\n");
}

void fillIntRandom(int* array, int size, int border) {
    for (int i = 0; i < size; ++i)
        *(array + i) = rand() % border;
}

// for search
void printOneLinkIntNode(OneLinkNode *n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%d]", n->dat);
}
//=====================================================

// OPEN ADDRESSING
//=====================================================
typedef struct
{
    int data;
    int key;
} KeyNode;

KeyNode** hashTableOA;
int hashTableSize;

KeyNode *nullItem;

int hashFunc(int key)
{
    return key % hashTableSize;
}

KeyNode* createNode(int data)
{
    KeyNode *p = (KeyNode*) malloc(sizeof(KeyNode));
    if (!p)
    {
        printf("Out of memory \n");
        return NULL;
    }
    p->data = data;
    p->key = data;
    return p;
}

void initTable(int size, int idx)
{
    for (int i = idx; i < size; ++i)
    {
        hashTableOA[i] = NULL;
    }
}

boolean isFull()
{
    for (int i = 0; i < hashTableSize; ++i)
    {
        if (hashTableOA[i] == NULL || hashTableOA[i] == nullItem)
        {
            return false;
        }
    }
    return true;
}

boolean insertNodeOA(int data);

void increaseCapacity()
{
    hashTableSize *= 2;
    KeyNode** oldHashTable = hashTableOA;
    hashTableOA = (KeyNode**) calloc(hashTableSize, sizeof(KeyNode*));
    int i;
    for (i = 0; i < hashTableSize / 2; ++i)
    {
        insertNodeOA(oldHashTable[i]->data);
    }
    initTable(hashTableSize, i);
    free(oldHashTable);
}

int linearProbe(int val)
{
    ++val;
    val %= hashTableSize;
    return val;
}

int quadProbe(int val, int step)
{
    val += step * step;
    val %= hashTableSize;
    return val;
}

int hashFuncDbl(int key)
{
    return 19 - key % 19;
}

boolean insertNodeOA(int data)
{
    KeyNode *node = createNode(data);
    if (!node)
    {
        return false;
    }

    int hashVal = hashFunc(node->key);
    if (isFull())
    {
        increaseCapacity();
    }
    //int step = 0;
    int step = hashFuncDbl(node->key);
    while (hashTableOA[hashVal] && hashTableOA[hashVal] != nullItem)
    {
        //hashVal = linearProbe(hashVal);
        //hashVal = quadProbe(hashVal, ++step);
        hashVal += step;
        hashVal %= hashTableSize;
    }
    hashTableOA[hashVal] = node;
    return true;
}

KeyNode* findNodeOA(int data)
{
    int key = data;
    int hashVal = hashFunc(key);
    //int step = 0;
    int step = hashFuncDbl(key);
    while (hashTableOA[hashVal])
    {
        if (hashTableOA[hashVal]->key == key)
        {
            return hashTableOA[hashVal];
        }
        //hashVal = linearProbe(hashVal);
        //hashVal = quadProbe(hashVal, ++step);
        hashVal += step;
        hashVal %= hashTableSize;
    }
    return NULL;
}

KeyNode* deleteNodeOA(int data)
{
    int key = data;
    int hashVal = hashFunc(key);
    //int step = 0;
    int step = hashFuncDbl(key);
    while (hashTableOA[hashVal])
    {
        if (hashTableOA[hashVal]->key == key)
        {
            KeyNode *tmp = hashTableOA[hashVal];
            hashTableOA[hashVal] = nullItem;
            return tmp;
        }
        //hashVal = linearProbe(hashVal);
        //hashVal = quadProbe(hashVal, ++step);
        hashVal += step;
        hashVal %= hashTableSize;
    }
    return NULL;
}

void printNode(KeyNode *n)
{
    if (!n)
    {
        printf("[*,*]");
        return;
    }
    printf("[k = %d, d = %d]", n->key, n->data);
}

void printTbl()
{
    for (int i = 0; i < hashTableSize; ++i)
    {
        printNode(hashTableOA[i]);
    }
    printf("\n");
}
//=====================================================


int main()
{
  // CHAIN METHOD
  //===================================================
//  htSize = 8;
//  int* arr;
//  const int SZ = 20;
//  arr = (int*) malloc(sizeof(int) * SZ);
//  fillIntRandom(arr, SZ, 100);
//
//  OneLinkNode** hashTable = (OneLinkNode**) calloc(htSize, sizeof(OneLinkNode*));
//  for (int i = 0; i < SZ; ++i)
//  {
//      insertNode(hashTable, arr[i]);
//  }
//  printTable(hashTable, htSize);
//  printf("\n");
//
//  // for search
//  printOneLinkIntNode(findNode(hashTable, 40));
//  printOneLinkIntNode(findNode(hashTable, 41));
//  printf("\n");

  // delete
//  for (int i = 0; i < SZ / 2; ++i)
//  {
//      deleteNode(hashTable, arr[i]);
//  }
//  printTable(hashTable, htSize);
  //=================================================

  // OPEN ADDRESSING
  //=================================================
  hashTableSize = 25;
  hashTableOA = (KeyNode**) calloc(hashTableSize, sizeof(KeyNode*));
  nullItem = createNode(-1);

  insertNodeOA(10);
  insertNodeOA(10);
  insertNodeOA(20);
  insertNodeOA(30);
  insertNodeOA(75);
  insertNodeOA(57);
  insertNodeOA(50);
  insertNodeOA(60);
  insertNodeOA(70);
  insertNodeOA(100);
  insertNodeOA(125);
  insertNodeOA(1);
  printTbl();

  // Delete
  deleteNodeOA(10);
  deleteNodeOA(20);
  printTbl();

  // Search
  printNode(findNodeOA(25));
  printNode(findNodeOA(125));
  //==================================================

  return 0;
}
