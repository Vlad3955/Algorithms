#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define true 1 == 1
#define false 1 != 1

typedef int boolean;

typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
} BinTreeIntNode;



BinTreeIntNode* treeInsert(BinTreeIntNode *t, int data) {
    BinTreeIntNode *newNode;
    newNode = (BinTreeIntNode*) malloc(sizeof(BinTreeIntNode));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    BinTreeIntNode *current = t;
    BinTreeIntNode *parent = t;
    if (t == NULL) {
        t = newNode;
    } else {
        while (current->key != data) {
            parent = current;
            if (current->key > data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    return t;
                }
            } else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    return t;
                }
            }
        }
    }
    return t;
}


void printBinTree(BinTreeIntNode *root) {
    if (root) {
        printf("%d", root->key);
        if (root->left || root->right) {
            printf("(");
            if (root->left)
                printBinTree(root->left);
            else
                printf("NULL");
            printf(",");
            if (root->right)
                printBinTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

// Task 1
int countNodes(BinTreeIntNode* t)
{
    if (t == NULL)
    {
        return 0;
    }
    return countNodes(t->left) + countNodes(t->right) + 1;
}

boolean balanced(BinTreeIntNode* t)
{
    if (abs(countNodes(t->left)- countNodes(t->right)) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void deleteBinTree(BinTreeIntNode *t)
{
    if (t == NULL)
    {
        return;
    }
    deleteBinTree(t->right);
    deleteBinTree(t->left);
    free(t);
}

#define TREES 50
#define NODES 1000

// Task 2
#define NODES2 10

boolean binSearch(BinTreeIntNode *root, int value)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->key == value)
    {
        return true;
    }
    BinTreeIntNode *current = root;
    while (current->key != value)
    {
        if (value < current->key)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
        if (current == NULL)
        {
            return false;
        }
    }
}

boolean binSearch2(BinTreeIntNode *root, int value)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->key == value)
    {
        return true;
    }
    else
    {
        return (binSearch(root->left, value) || binSearch(root->right, value));
    }

}

int main()
{
  // Task 1
  BinTreeIntNode *tree = NULL;
  srand(time(NULL));
//  int balancedCount = 0;
//  for (int i = 0 ; i < TREES; ++i)
//  {
//     tree = NULL;
//     for (int j = 0; j < NODES; ++j)
//     {
//         if (tree == NULL)
//         {
//             tree = treeInsert(tree, rand()% 100);
//         }
//         else
//         {
//             treeInsert(tree, rand() % 100);
//         }
//     }
//     if (balanced(tree))
//     {
//         balancedCount++;
//     }
//     deleteBinTree(tree);
//  }
//  printf("Balanced: %d%%", 100 * balancedCount/TREES);


  for (int j = 0; j < NODES2; ++j)
     {
         if (tree == NULL)
         {
             tree = treeInsert(tree, rand()% 10);
         }
         else
         {
             treeInsert(tree, rand() % 10);
         }
     }
     printf("Enter the number you are looking for:\n");
     int value;
     scanf("%d", &value);
     if (binSearch2(tree, value))
     {
         printf("The number %d is in the tree\n", value);
     }
     else
     {
         printf("The number %d is not in the tree\n", value);
     }
     printBinTree(tree);
     printf("\n\n");


  return 0;
}
