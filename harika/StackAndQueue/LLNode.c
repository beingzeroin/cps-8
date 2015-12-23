#include "LLNode.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

LLNode* createLLNode(ElementType data)
{
    LLNode *temp=malloc(sizeof(struct LLNode));
    temp->data=data;
    temp->next=NULL;
    return temp;
}

LLNode* insertInBegin(LLNode *head, ElementType data)
{
    LLNode *temp=malloc(sizeof(struct LLNode));
    temp->data=data;
    temp->next=head;
    return temp;
}
LLNode* insertInEnd(LLNode *head,ElementType data)
{
    LLNode *temp=malloc(sizeof(struct LLNode));
    LLNode *newtemp=malloc(sizeof(struct LLNode));
    temp=head;
    if(temp==NULL)
    {
        temp->data=data;
        temp->next=NULL;
        temp=head;
        return temp;
    }
    else
    {
        while(temp->next!=NULL)
        {
            if(temp->next!=NULL)
                temp=temp->next;
        }
        temp->next=newtemp;
        newtemp->next=NULL;
        newtemp->data=data;
        return newtemp;
    }
}

LLNode* deleteFirstNode(LLNode *head)
{
    LLNode *temp=malloc(sizeof(struct LLNode));
    temp=head;
    if(temp->next==NULL)
        return NULL;
    head=head->next;
    return head;

}

LLNode* destroyAllNodes(LLNode *head)
{
   while(head!=NULL){
        deleteFirstNode(head);
        head=head->next;
   }
}
