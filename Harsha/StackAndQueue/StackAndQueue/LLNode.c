#include "LLNode.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

LLNode* createLLNode(ElementType data)
{
    LLnode *t=malloc(sizeof(LLnode));
    t->next=head;
    return t;
}

LLNode* insertInBegin(LLNode *head, ElementType data)
{
    LLNode *t = createLLNode(data);
    t->next = h;
    return t;

}

LLNode* deleteFirstNode(LLNode *head)
{
    if(head==NULL)
        return NULL;
    LLnode *t=head->next;
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
