#include "LLNode.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

LLNode* createLLNode(ElementType data)
{
    //assert(false);
    LLNode *t=malloc(sizeof(LLNode));
    t->data=data;
    return t;
}

LLNode* insertInBegin(LLNode *head, ElementType data)
{
    //assert(false);
    LLNode *newNode=createLLNode(data);
    newNode->next=head;
    head=newNode;
    return head;
}

LLNode* deleteFirstNode(LLNode *head)
{
   // assert(false);
   if(head==NULL)
    return head;
   LLNode *t=head->next;
   free(head);
   return t;

   // return NULL;
}

LLNode* destroyAllNodes(LLNode *head)
{
   //assert(false);
   //return NULL;
   LLNode *temp;
   while(head!=NULL)
   {

       temp=head->next;
       free(head);
       head=temp;
   }
   return NULL;
}
