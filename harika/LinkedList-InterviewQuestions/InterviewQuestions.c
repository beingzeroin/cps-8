#include "LLNode.h"
#include <stdlib.h>
#include <stdbool.h>

LLNode *findIntersectionPoint(LLNode *h1, LLNode *h2)
{
    // TODO:  Implement This Function
    return NULL;

}

LLNode *getKthNodeFromEnd(LLNode *h, int k)
{
    LLNode *c,*p;
	p=h;
	c=h;
	int count=1;
	if(p==NULL)			//linked list is empty
		return NULL;
	while(count!=k-1)
	{
	    if(c->next!=NULL)
        {
            c=c->next;
            count+=1;
        }
		if(c==NULL)		//if 15th node is needed whenwe haveonly 10
			return NULL;
	}
	while(c->next!=NULL)
	{
	    if(p->next!=NULL)
        {
            p=p->next;
            c=c->next;
        }
	}
	return p;
    /*int i;
    LLNode *f=h,*s=h;
   //if(h==NULL)
    //return NULL;
    for(i=1;i<k;i++)
    {
        f=f->next;
        if(f==NULL)
           return NULL;
    }

    while(f->next!=NULL)
    {
        f=f->next;
        s=s->next;
    }
// TODO:  Implement this Function
    return s;*/
}

LLNode *reverseLinkedList(LLNode *h)
{
    LLNode *c,*p,*n;
	c=h;
	p=NULL;
	n=c->next;
	while(c!=NULL)
	{
		n=c->next;
		c->next=p;
		p=c;
		c=n;

	}
	return p;

}
LLNode *insertSorted(LLNode *h, int data)
{
    return NULL;
}
bool hasCycle(LLNode *h)
{
    LLNode *s,*f;
	s=h;
	f=h;
	f=f->next;
	f=f->next;
	if(s==NULL)
		return NULL;
	while(s!=NULL && f!=NULL)
	{
		if(s->next=f->next)
			return true;
		else if(s->next==NULL||f->next==NULL)
			return false;
		else
			s=s->next;
			f=f->next;
			f=f->next;
	}
	return false;
}
LLNode *findMiddleNode(LLNode *h)//
{
    LLNode *temp;
	temp=h;
	if(temp==NULL)
		return temp;
	int len=1;
	while(temp->next!=NULL)
	{
		len+=1;
		temp=temp->next;
	}
	if((len+1)%2!=0)
	{
		int c=len/2;
		int count=1;
		LLNode *temp1;
		temp1=h;
		while(count!=c-1&&temp->next!=NULL)
		{
			temp=temp->next;
			count+=1;
		}
		return temp;
	}
	else
	{
		printf("Even");
	}
}
