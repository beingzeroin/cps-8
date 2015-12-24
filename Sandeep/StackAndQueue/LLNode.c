#include "LLNode.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

LLNode* createLLNode(ElementType data)
{
    LLNode *t  = malloc(sizeof(LLNode));
    t->next = NULL;
    t->data = data;
    return t;
}

LLNode* insertInBegin(LLNode *head, ElementType data)
{
    LLNode *t = createLLNode(data);
    //if(head==NULL)
    //  return t;
    t->next = head;
    return t;
}

LLNode* deleteFirstNode(LLNode *head)
{
    if(head==NULL)
        return NULL;
    LLNode *t = head->next;
    free(head);
    return t;
}

LLNode* destroyAllNodes(LLNode *head)
{
    LLNode *n;
    while(head!=NULL)
    {
        n = head->next;
        free(head);
        head=n;
    }
    return NULL;
}
