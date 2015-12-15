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
    printf("\n");
    free(temp);
}
LLNode *createSerialList(int n)
{
    LLNode *head=NULL;
    int i;
    for(i=1;i<=n;i++)
        head=insertInEnd(head,i);
    return head;
}
LLNode *deleteNodeWithValue(LLNode *h,int data)
{
    LLNode *cur=h,*prev=NULL;
    if(cur==NULL)
        return cur;
    else if(cur->data=data)
    {
        h=h->next;
        free(cur);
        free(prev);
        return h;t
    }
    else
    {
        while(cur->data!=data || cur!=NULL)
        {
            prev=cur;
            cur=cur->next;
        }
        if(cur==NULL)
            return h;
        else if(cur->next==NULL)
        {
            prev->next=NULL;
            free(cur);
            return h;
        }
        else
        {
            prev->next=cur->next;
            free(cur);
            return h;
        }
    }
}
int main()
{
    LLNode *head=createSerialList(10);
    traverse(head);
    head=deleteNodeWithValue(head,1);
    traverse(head);
    head=deleteNodeWithValue(head,10);
    traverse(head);
    head=deleteNodeWithValue(head,5);
    traverse(head);
    /*
    head=deleteNodeWithValue(head,15);
    traverse(head);
    head=deleteNodeWithValue(NULL,1);
    traverse(head);

    head=insertInBegin(head,5);
    head=insertInBegin(head,4);
    head=insertInBegin(head,3);
    head=insertInBegin(head,2);
    head=insertInBegin(head,1);
	head=insertInEnd(head,6);
    traverse(head);
    */
    return 0;
}
