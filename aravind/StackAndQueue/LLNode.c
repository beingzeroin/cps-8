#include "LLNode.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

LLNode* createLLNode(ElementType data)
{
    LLNode *a = malloc(sizeof(LLNode));
    a->data = data;
    a->next = NULL;
    return a;
}

LLNode* insertInBegin(LLNode *head, ElementType data)
{
    LLNode *a = createLLNode(data);
    a->next = head;
    return a;
}

LLNode* deleteFirstNode(LLNode *head)
{
    if(head==NULL)
        return head;
    LLNode *t = head->next;
    free(head);
    return t;
}

LLNode* destroyAllNodes(LLNode *head)
{
   LLNode *t = head;
   while(head!=NULL)
   {
       t = head->next;
       free(head);
       head = t;
   }
   return NULL;
}
