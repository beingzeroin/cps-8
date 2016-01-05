#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node ln;
ln *createNode(int d)
{
    ln *t=malloc(sizeof(ln));
    t->data=d;
    t->next=NULL;
    return t;
}

ln *insertInBegin(int d,ln *p)
{
    ln *t;
    t=createNode(d);
    t->next=p;
    return t;
}

ln *insertAtEnd(int d,ln *p)
{
    ln *t=p;
    ln *n;
    n=createNode(d);
    if(t==NULL)
        n=t;
    else
    {
        while(t->next!=NULL)
        {
            t=t->next;
        }
     t->next=n;
    }
    return n;
}

void traverse(ln *p)
{
    ln *t=p;
    while(t!=NULL)
    {
        printf("%d  ",t->data);
        t=t->next;
    }
}

ln *deletellnode(ln *h,int d)
{
     ln *p,*c;
     c=h;
     p=h;
     while(c->data!=d&&c!=NULL)
     {
         p=c;
         c=c->next;
     }

     if(c->next!=NULL)
     {
         c=c->next;

         if(p==NULL)
            h=c;

         else
         p->next=c;

     }
     else
     {
         if(c=h)
            free(c);
         else
         {
                   p->next=NULL;
                   free(c);
         }
     }

        //delete(p->next);
     return p;
}
ln *getKthnodefromtheend(ln *h,int k)
{
    ln *t,*v;
    int count=0;
    t=v=h;
    if(h==NULL)
        printf("\n empty list!!!");
    while(t->next!=NULL)
    {
        t=t->next;
        count++;
        if(count>=k)
        {
            v=v->next;
        }
    }
    return v;
}
bool hascycle(ln *h)
{
    ln *s,*f;
    int c=0;
    s=f=h;
    while(f->next!=NULL)
    {
        f=f->next;
        c++;
        if(c==2)
        {
            s=s->next;
            c=0;
        }
        else if(f==s)
        {
            return true;
        }
    }
    return false;
}
ln *reversell(ln *h)
{
    ln *c,*p,*n;
    p=h;
    c=p->next;
    n=c->next;
    while(c!=NULL)
    {
        c->next=p;
        p=c;
        c=n;
        if(n->next!=NULL)
            n=n->next;
    }
    return c;
}
int main()
{
    int ch,d,b;
    ln *h,*t,*i,*k,*rn;
    h=NULL;
    t=NULL;
    k=NULL;
    rn=NULL;
    /*printf("1.INSERT AT FIRST\n2.INSERT AT END\n3.DELETE\n4.DISPLAY\n5.QUIT");
    do
    {
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch)
    {
        case 1:printf("Enter the data\n");
                scanf("%d",&d);
                h=insertInBegin(d,h);
                break;
        case 2:printf("Enter the data\n");
                scanf("%d",&d);
                t=insertAtEnd(d,h);
                break;
        case 3:printf("Enter the data you need to delete\n");
                scanf("%d",&d);
                i=deletellnode(h,d);
                break;
        case 4:printf("Data in the Linked List:  ");
                traverse(h);
                break;
        case 5:exit(0);
    }
    }while(ch!=5);*/
    h=insertInBegin(5,h);
    h=insertInBegin(4,h);
    h=insertInBegin(3,h);
    h=insertInBegin(2,h);
    h=insertInBegin(1,h);
    h=reversell(h);
    traverse(h);
    /*rn=getKthnodefromtheend(h,rand()%6);
    while(k!=NULL)
    {
        k=k->next;
    }
    k=rn;
    b=hascycle(h);
    if(b==1)
        printf("\n cycle found");
    else
        printf("\n no cycle");
    //printf("\n data in kth=%d",k->data);*/
    return 0;
}
