#include "LLNode.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

LLNode* createLLNode(ElementType d)
{
    //assert(false);
    LLNode *temp = malloc(sizeof(LLNode));
    temp->data = d;
    temp->next = NULL;
    return temp;
}

LLNode* insertInBegin(LLNode *head, ElementType data)
{
    //assert(false);
    LLNode *temp = createLLNode(data);
    temp->next = head;
    return temp;
}

LLNode* deleteFirstNode(LLNode *head)
{
    //assert(false);
    if(head == NULL)
        return NULL;
    else
    {
        LLNode *t = head->next;
        free(head);
        return t;
    }
}

LLNode* destroyAllNodes(LLNode *head)
{
   //assert(false);
   LLNode *t = head;
   while(head!=NULL)
   {
       t=head;
       head=head->next;
       free(t);
   }
   return NULL;
}
