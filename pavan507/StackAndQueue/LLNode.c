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
LLNode *insertInEnd(LLNode *head,ElementType data)
{
    LLNode *newNode=createLLNode(data);
    LLNode *temp=head;
    if(head==NULL)
    return newNode;
    while(temp->next!=NULL)
    {

        temp=temp->next;
    }
    temp->next=newNode;


    return head;
}
LLNode* deleteLastNode(LLNode *head)
{
    if(head==NULL)
        return head;
    LLNode* temp1=head;
    if(temp1->next==NULL)
    {


        free(head);
    return NULL;
    }
    LLNode* temp2=head->next;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
        temp1=temp1->next;

    }
    return temp1;


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
