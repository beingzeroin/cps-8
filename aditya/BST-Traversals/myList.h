#ifndef MYLIST_H_INCLUDED
#define MYLIST_H_INCLUDED

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "BST.h"

typedef struct list_node node;
typedef BSTNode* dataType;

struct list_node{
    dataType data;
    struct list_node *next;
};
/* Alternate way of typedef
typedef struct list_node{
    dataType data;
    struct list_node *next;
} node;
*/

node* createNode(dataType data);
void traverse(node *root);
node* insertInBeginning(node *root,dataType data);
node* insertInEnding(node *root,dataType data);
node* searchNode(node *root,dataType data);
node* deleteInBeginning(node *root);
node* deleteInEnding(node *root);
node* getLastNode(node *root);
int countNodes(node *root);
node* createRandomList(int size);
void printMiddleElement(node *root);
node* getKthLastElement(node *root,int k);
node* recursiveReverseList(node *root, node *prev);
node* iterativeReverseList(node *root);
// Finding out the merge point of given 2 linked lists
node* createRandomCircularList(int size, int position);
node* getCircularNode(node* root);
void printCircularList(node *root);
void printReverseList(node *root);
node* deleteElementRecursively(node *root, dataType element);
node* deleteTheElement(node *head,node *root, node *prev, dataType element);
node* mergeTwoSortedLists(node *h1, node *h2);
node* alternateMergeLists(node *h1,node *h2);
#endif // MYLIST_H_INCLUDED

