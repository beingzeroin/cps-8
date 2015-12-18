#include <stdio.h>
#include <stdlib.h>
typedef struct n llnode;
struct n
{

    int data;
    llnode *next;
};
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
llnode *createSerialLinkedList(llnode *h,int n)
{
int i;
    for(i=1;i<=n;i++)
    {

       h=insertInEnd(h,i);
    }
    return h;
}
llnode *findLastNode(llnode *h)
{

    llnode *temp=h;
    while(temp->next!=NULL)
        temp=temp->next;
    return temp;
}
int numOfNodesIn(llnode *h)
{
    int i=0;
 llnode *temp=h;
 while(temp!=NULL)
 {
     i++;
     temp=temp->next;
 }
 return i;
}
llnode *findIntersectionNode(llnode *h1,llnode *h2)
{
    llnode *temp1=h1,*temp2=h2;
    int i,c=0;
    int n1=numOfNodesIn(h1);
    int n2=numOfNodesIn(h2);
    if(n1>n2)
    {
        c=n1-n2;
        for(i=1;i<=c;i++)
             temp1=temp1->next;
    }
    else if(n2>n1)
    {
        c=n2-n1;
        for(i=1;i<=c;i++)
            temp2=temp2->next;
    }
    while(temp1->data!=temp2->data)
    {

        temp1=temp1->next;
        temp2=temp2->next;
    }
    return temp1;

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
int main()
{
    llnode *h1=NULL,*h2=NULL,*last1,*last2;
   // h=deleteNodeWithValue(h,3);
    //traverse(h);
    h1=createSerialLinkedList(h1,10);
    printf("llist one is\n");
    traverse(h1);
    h2=insertInEnd(h2,21);
    h2=insertInEnd(h2,32);
    h2=insertInEnd(h2,23);
    h2=insertInEnd(h2,24);
    h2=insertInEnd(h2,35);
    h2=insertInEnd(h2,8);
    h2=insertInEnd(h2,9);
    h2=insertInEnd(h2,10);
    printf("llist two is\n");
    traverse(h2);
    last1=findLastNode(h1);
    last2=findLastNode(h2);
    //printf("%d\n%d\n",last1->data,last2->data);
    if(last1->data==last2->data)
    {
printf("two lists intersct each other\n");
llnode *inter=findIntersectionNode(h1,h2);
printf("intersection node is\n %d",inter->data);
    }
     else
        printf("doesnt intersect\n");

    return 0;
}
