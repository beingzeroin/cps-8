#include "LLNode.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

LLNode* createLLNode(ElementType data)
{
    LLnode* t = malloc(sizeof(LLNode));
    t->data=data;
    t->next=NULL;
    return t;
}

LLNode* insertInBegin(LLNode *head, ElementType data)
{
    if(s->top==NULL)
        return NULL;
    s->top = createLLNode(data);
    return s->top;
}

LLNode* deleteFirstNode(LLNode *head)
{
    if (head==NUll)
        return NULL;
    LLnode *t = head->next;
    free(head);
    return t;
}

LLNode* destroyAllNodes(LLNode *head)
{
   LLnode *n;
   while(head!=NULL)
   {

       n=head->next;
       free(head);
       head=n;
   }
   return NULL;
}

