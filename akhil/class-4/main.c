#include <stdio.h>
#include <stdlib.h>

typedef struct n LLnode;
struct n
{
    int data;
    LLnode *next;

};
LLnode *getkthnodefromend(LLnode *h,int k)
{
    LLnode *t=h,*s=h;
    int count,i;
    if h=NULL
        return NULL;
    for(i=1;i<k;i++)
    {
        f=f->next;
        if(f==NULL)
            return NULL;
    }

    while(t->next!=NULL)
    {
        t=t->next;
        s=s->next;

    }






    return NULL;
}

/*bool hascycle(LLnode *h)
{
LLnode *f=h,*s=h;

if(h=NULL)
    return false;
 do
 {
if(f->next!=NULL)
{
   f=f->next;
   if(f->next!=NULL)
        f=f->next;
   else
    return false;

}
 else
        return false;


 }while(f=)
}*/

LLnode *reveresellist(LLnode *h)
{
    c=h;
    p=NULL;
    n=c->next;

    while(c!=NULL)
    {
        c->next=p
        p=c;
        c=n;
        n=n->next;


    }
    return p;
}

LLnode *createLLnode(int data)
{
    LLnode *temp = malloc(sizeof(LLnode));//allocate node on heap
    //init memory
    temp->data=data;
    temp->next=NULL;
    return temp;
}
LLnode *insertInBegin(LLnode *h,int data)
{
    LLnode *temp = createLLnode(data);
    temp->next=h;
    return temp;
}

void traverse(LLnode *h)
{
    LLnode *c=h;
    while(c!=NULL)
    {
        printf("%d ",c->data);
        c=c->next;

    }
}

/*LLnode *insertInEnd(LLnode *h,int data)
{
    LLnode *temp = createLLnode(data);
    temp->next=NULL;
    return temp;
}*/
/*LLnode *findLastnode(LLnode *h)
{
    LLnode *t
}*/
LLnode *deleteNodeWithValue(LLnode *h,int data)
{
    LLnode *current;
    LLnode *prev=NULL;
   if(current=NULL)

       return current;
    while(current->data=data)
    {
        current->next=prev->next;
        current=current->next;
    }
    if(current->data=data){
         prev->next=current->next;
        delete(current);
    }

    return h;
}

/*LLnode *createSerialList(int n)
{
    int i;
    LLnode *h=NULL;
    for(i=1;i<n;i++)
    {

    }
}*/
int main()
{
    LLnode *head = NULL;

    head =deleteNodeWithValue(head,2);
    head =deleteNodeWithValue(head,1);


    head = insertInBegin(head,5);
    head = insertInBegin(head,4);
    head = insertInBegin(head,3);
    head = insertInBegin(head,2);
    head = insertInBegin(head,1);



    traverse(head);
    reveresellist(head);
    tarverse(head);

    return 0;
}
