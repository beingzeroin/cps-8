#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct n LLNode;
struct n
{
    int data;
    LLNode *next;
};

LLNode *reverseRecursive(LLNode *h1, LLNode *p)
{
    if(h1==NULL)
        return NULL
    if(h1->next==NULL)
    {
        h1->next=p;
        return h1;
    }
	LLNode *t=h1->next;
	h1->next=p;
	p=h1;
	h1=t;
	return reverseRecursive(h1,p);
}