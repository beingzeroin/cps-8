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
LLNode *deleteNodeWithValue(LLNode *head,int data)
{
    LLNode *cur=head,*prev=NULL;
    while(cur!=NULL)
    {
        if(cur->data==data)
        {
            if(prev==NULL)
            {
                cur=cur->next;
                return cur;
            }
            else
            {
                prev->next=cur->next;
                free(cur);
                return head;
            }
        }
        prev=cur;
        cur=cur->next;
    }
    if(head==NULL || cur==NULL)
        return head;
}
LLNode *getNodePointer(LLNode *head,int data)
{
	LLNode *cur=head,*prev=NULL;
	if(head==NULL)
		return NULL;
	else
		while(cur!=NULL)
		{
			if(cur->data==data)
				return cur;
			prev=cur;
			cur=cur->next;
		}
	return NULL;
}
int *getListLength(LLNode *head)
{
    LLNode *temp=head;
    int count=0;
    if(head==NULL)
        return 0;
    else
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
    return count;
}
int main()
{
    LLNode *head=createSerialList(10);
    traverse(head);
    return 0;
}