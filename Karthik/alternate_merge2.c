#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct n LLNode;
struct n
{
    int data;
    LLNode *next;
};
LLNode *alternateMerge(LLNode *h1, LLNode *h2)
{
	if(h1==NULL)
	    return h2;
	if(h1==NULL)
	    return h1;
	h1->next=alternateMerge(h2,h1->next);
	return h1;
}