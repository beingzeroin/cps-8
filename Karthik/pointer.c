#include <stdio.h>
#include <stdlib.h>
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
LLNode *insertInBegin(LLNode *h,int data)
{
    LLNode *newHead;
    newHead=createLLNode(data);
    newHead->next=h;
    return newHead;
}

//LlNode *insertInEnd(LLNode *h,int data);

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
    traverse(head);
    return 0;
}
