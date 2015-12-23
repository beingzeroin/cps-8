#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
typedef struct n llnode;
struct n
{

    int data;
    llnode *next;
};
int countNode(llnode *h)
{
    int c=0;
    llnode *temp=h;
    while(temp!=NULL)
    {

        c++;
        temp=temp->next;
    }
    return c;

}
llnode *getKthNodeFromEnd(llnode *h,int k)
{
    int i,j;
    if(h==NULL)
        return h;

    j=countNode(h);
    if(j<k)
        return NULL;
    llnode *fast=h,*slow=h;
    for(i=1;i<k;i++)
        fast=fast->next;
    while(fast->next!=NULL)
    {

        fast=fast->next;
        slow=slow->next;
    }
    return slow;

}
llnode *createllnode(int data)
{
    llnode *temp=malloc(sizeof(llnode));
    temp->data=data;
    temp->next=NULL;
    return temp;

}
llnode *insertInBegin(llnode *h,int data)
{
    llnode *temp=createllnode(data);
    temp->next=h;
    //h=temp;
    return temp;

}
llnode *insertInEnd(llnode *h,int data)
{
    llnode *newNode=createllnode(data);
    llnode *temp=h;
    if(h==NULL)
    return newNode;
    while(temp->next!=NULL)
    {

        temp=temp->next;
    }
    temp->next=newNode;


    return h;
}
llnode *insertInMiddle(llnode *h,int data,int pos)
{
    int i;
    llnode *temp=h,*t;
    t=createllnode(data);
    for(i=1;i<=pos;i++)
        temp=temp->next;
        t->next=temp->next;
        temp->next=t;

    return h;



}
llnode *deleteNodeWithValue(llnode *h,int val)
{
    llnode *curr,*prev=NULL,*temp,*t;
    if(h==NULL)
        return h;
    curr=h;
    prev=curr;
    curr=curr->next;
    if(h->data==val)
    {

    free(h);
        return curr;
    }
    else
    {
        while(curr->data!=val)
        {

            curr=curr->next;
            prev=prev->next;
            if(curr==NULL)
                return h;
        }
        if(curr->next!=NULL)
        {
            prev->next=curr->next;
            free(curr);
            return h;
        }
        else
        {

            prev->next=NULL;
            free(curr);
            return h;
        }
    }


}
llnode *getKthNodeFromBeginning(llnode *h,int k)
{

    int i;
    for(i=1;i<k;i++)
        h=h->next;
    return h;
}
llnode *createSerialLinkedList(llnode *h,int n)
{
int i;
    for(i=1;i<=n;i++)
    {

       h=insertInEnd(h,i);
    }
    return h;
}
bool hasCycle(llnode *h)
{
    llnode *fast=h,*slow=h;
    fast=fast->next;
    while(fast->data!=slow->data)
    {
        fast=fast->next;
        if(fast->next==NULL)
            return false;
        fast=fast->next;
        if(fast->next==NULL)
            return false;
            slow=slow->next;



    }
    return true;

}
llnode *insertSort(llnode *h,int data)
{
    llnode *temp=h,*prev=NULL;
    llnode *newnode=createllnode(data);
    if(h==NULL)
        return newnode;
    while(temp->data<=data)
    {

    prev=temp;
    if(temp->next==NULL)
    {
        temp->next=newnode;
        return h;

    }
    temp=temp->next;
    }
    if(temp==h)
    {
        newnode->next=temp;
        return newnode;

    }
    prev->next=newnode;
    newnode->next=temp;
    return h;

}
llnode *reverseLinkedList(llnode *h)
{
    llnode *c,*n,*p;
    p=NULL;
    c=h;
    //n=c->next;
    while(c!=NULL)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
        //if(c==NULL)
          //  break;
        //n=n->next;

    }
    return p;

}
void traverse(llnode *h)
{
    llnode *temp=h;
    while(temp!=NULL)
    {

        printf("%d ",temp->data);
        temp=temp->next;
    }
    //printf("%d",temp->data);
    printf("\n");

}
llnode *findLastNode(llnode *h)
{
    llnode *t=h;
    while(t->next!=NULL)
        t=t->next;
    return t;

}
/*void hasCycleUnitTests()
{

    llnode *h=createSerialLinkedList(1,10);
    assert(hasCycle(h)==1)
    llnode *randomNode;
    llnode *lastNode=findLastNode(h);
}*/
int main()
{
    llnode *h=NULL;
   // h=deleteNodeWithValue(h,3);
    //traverse(h);
    h=createSerialLinkedList(h,10);
    traverse(h);
    h=insertSort(h,2);
    traverse(h);
    //h=reverseLinkedList(h);
    //traverse(h);


   /* llnode *knode=getKthNodeFromEnd(NULL,1);
    if(knode==NULL)
    printf("PASS");
    else
    printf("%d\n",knode->data);*/
    /*int cycle=hasCycle(h);
    if(cycle==1)
        printf("list has cycle\n");
    else
        printf("doesnt have cycle\n");*/
    //h=deleteNodeWithValue(h,10);
    //traverse(h);
    //h=deleteNodeWithValue(h,1);
    //traverse(h);
   // h=deleteNodeWithValue(h,4);
    //traverse(h);
    //h=deleteNodeWithValue(h,12);
    //traverse(h);
    /*h=insertInBegin(h,5);
    h=insertInBegin(h,4);
    h=insertInBegin(h,3);
    h=insertInBegin(h,2);
    h=insertInBegin(h,1);
    traverse(h);
    printf("\n");
   h=insertInEnd(h,6);*/
    //traverse(h);
    return 0;
}
