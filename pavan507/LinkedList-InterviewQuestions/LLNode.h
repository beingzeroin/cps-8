#ifndef LLNODE_H_INCLUDED
#define LLNODE_H_INCLUDED

#include<stdbool.h>

typedef struct n LLNode;
struct n
{
    int data;
    LLNode *next;
};

LLNode *createLLNode(int data);
LLNode *insertInBegin(LLNode *h, int data);
void traverse(LLNode *h);
LLNode *findLastNode(LLNode *h);
LLNode *insertInEnd(LLNode *h, int data);
LLNode *deleteNodeWithValue(LLNode *h, int data);
LLNode *createSerialList(int s, int e);
int countLinkedListNodes(LLNode *h);
LLNode *searchNodeWithValue(LLNode *h, int data);
LLNode *getKthFromBeginning(LLNode *h, int k);

// Interview Questions
LLNode *findIntersectionPoint(LLNode *h1, LLNode *h2);

LLNode *getKthNodeFromEnd(LLNode *h, int k);

LLNode *reverseLinkedList(LLNode *h);
LLNode *insertSorted(LLNode *h, int data);
bool hasCycle(LLNode *h);
LLNode *findMiddleNode(LLNode *h);

// Unit Tests
void intersectionUnitTests();
void kthNodeFromEndUnitTests();

#endif // LLNODE_H_INCLUDED
