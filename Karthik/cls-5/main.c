#include <stdio.h>
#include <stdlib.h>
#include "LLNode.h"
typedef struct n LLNode;
struct n
{
    int data;
    LLNode *next;
};
LLNode *createLLNode(int data)
{
    LLNode *new=malloc(sizeof(LLNode));
    new->data=data;
    new->next=NULL;
    return new;
}
LLNode *findLastNode(LLNode *h)
{
    if(h==NULL)
        return h;
    else
        while(h->next!=NULL)
            h=h->next;
    return h;
}
LLNode *insertInBegin(LLNode *h,int data)
{
    LLNode *newHead;
    newHead=createLLNode(data);
    newHead->next=h;
    return newHead;
}
LLNode *insertInEnd(LLNode *h,int data)
{
	LLNode *temp;
	LLNode *newNode=createLLNode(data);
	if(h==NULL)
		h=newNode;
	else
	{
		temp=findLastNode(h);
		temp->next=newNode;
	}
	return h;
}
void traverse(LLNode *h)
{
    LLNode *temp=h;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    free(temp);
}
int main()
{
    LLNode *head=NULL;
    head=insertInBegin(head,5);
    head=insertInBegin(head,4);
    head=insertInBegin(head,3);
    head=insertInBegin(head,2);
    head=insertInBegin(head,1);
	head=insertInEnd(head,6);
    traverse(head);
    return 0;
}
