#include "LLNode.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

LLNode* createLLNode(ElementType data)
{
    LLNode *newNode=malloc(sizeof(LLNode));
    newNode->data=data;
    newNode->next=NULL;
    //assert(false);
    return newNode;
}

LLNode* insertInBegin(LLNode *head, ElementType data)
{
    //assert(false);
    LLNode *newHead=createLLNode(data);
    newHead->next=head;
    //head=newHead;
    return newHead;
}

LLNode* deleteFirstNode(LLNode *head)
{
    if(head==NULL)
        return NULL;
    else
    {
        LLNode *temp=head->next;
        free(head);
        return temp;
    }
}

LLNode* destroyAllNodes(LLNode *head)
{
   LLNode *prev=NULL;
   while(head!=NULL)
   {
       prev=head;
       head=head->next;
       free(prev);
   }
   return NULL;
}
