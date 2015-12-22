#include "LLNode.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

LLNode *createLLNode(int data)// Allocate - put data and null
{
    // Allocate Node on Heap
    LLNode *t = malloc(sizeof(LLNode));

    // Init Memory
    t->data = data;
    t->next = NULL;


    // Return the address
    return t;
}
// NULL
LLNode *insertInBegin(LLNode *h, int data)
{
    LLNode *t = createLLNode(data);
    t->next = h;
    return t;

}
void traverse(LLNode *h)
{
    LLNode *c = h;

    while(c!=NULL)
    {
        printf("%d ", c->data);
        c = c->next;
    }

}
LLNode *findLastNode(LLNode *h)
{

	while(h->next!=NULL)
	{
		h = h->next;
	}
	return h;
}
LLNode *insertInEnd(LLNode *h, int data)
{
	LLNode *t = createLLNode(data);
	// TODO:  Empty List
	if(h==NULL)
		return t;
	LLNode *l = findLastNode(h);

	l->next = t;

	return h;
}

LLNode *deleteNodeWithValue(LLNode *h, int data)
{
    LLNode* c=h, *p=NULL;

    while(c!=NULL)
    {
        if(c->data==data)
        {
            if(p==NULL)
            {
                c = c->next;
                free(h);
                return c;
            }
            p->next = c->next;
            free(c);
            return h;
        }
        p = c;
        c = c->next;
    }
    return h;
}

LLNode *createSerialList(int s, int e)
{
    int i;
    LLNode *h = NULL;
    for(i=s;i<=e;i++)
        h = insertInEnd(h, i);

    return h;
}
int countLinkedListNodes(LLNode *h)
{
    int c = 0;

    while(h!=NULL){
        c++;
        h = h->next;
    }

    return c;
}

LLNode *searchNodeWithValue(LLNode *h, int data)
{
    while(h!=NULL)
    {
        if(h->data==data)
            return h;
        h = h->next;
    }
    return NULL;
}



