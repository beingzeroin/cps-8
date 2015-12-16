#include <stdio.h>
#include <stdlib.h>

typedef struct n LLNode;
struct n
{
    int data;
    LLNode *next;
};

LLNode *head = NULL;

LLNode *createLLNode(int data)
{
    LLNode *t = malloc(sizeof(LLNode));
    t->data = data;
    t->next = NULL;
    return t;
}

LLNode *insertInBegin(LLNode *h, int data)
{
    LLNode *t = createLLNode(data);
    t->next = h;
    return t;
}

void traverse(LLNode *h)
{
    LLNode *t = h;
    while(t != NULL)
    {
        printf("%d\n",t->data);
        t = t->next;
    }
}

LLNode *insertInEnd(LLNode *h, int data)
{
    if(h==NULL)
        h=createLLNode(data);
    else
    {
        LLNode *temp = h;
        while(temp->next != NULL)
            temp = temp->next;
        LLNode *t = createLLNode(data);
        temp->next = t;
    }
    return h;
}

LLNode* findLastNode(LLNode *h)
{
    if(h==NULL)
        return h;
    while(h->next!=NULL)
    {
        h=h->next;
    }
    return h;

}

LLNode* deleteNodeWithValue(LLNode *h, int d)
{
    LLNode *p,*t = h;
    if(h==NULL)
    {
        return h;
    }
    else
    {
        while(t!=NULL && t->data != d)
        {
            p=t;
            t = t->next;
        }
        if(t==h)
        {
            h=t->next;
            free(t);
        }
        else if(t==NULL)
            return h;
        else if(t->next == NULL)
        {
            p->next = NULL;
            free(t);
        }
        else
        {
            p->next=t->next;
            free(t);
        }
    }
    return h;
}

LLNode *createSerialList(int n)
{
    int i;
    LLNode *h = NULL;
    for(i=1;i<=n;i++)
    {
        h=insertInEnd(h,i);
    }
    return h;
}

int findLengthOfList(LLNode *h)
{
    int c=0;
    while(h!=NULL)
    {
        c++;
        h=h->next;
    }
return c;
}

LLNode* findIntersection(LLNode *h1,LLNode *h2)
{
    int l1,l2;
    l1=findLengthOfList(h1);
    l2=findLengthOfList(h2);

    if(findLastNode(h1)!=findLastNode(h2))
        return NULL;

    if(l1>l2)
    {
        l1=l1-l2;
        for(l2=0;l2<l1;l2++)
            h1 = h1->next;
    }
    else
    {
        l2=l2-l1;
        for(l1=0;l1<l2;l1++)
            h2 = h2->next;
    }

    while(h1!=h2)
    {
        h1=h1->next;
        h2=h2->next;
    }
return h1;
}

LLNode *reverseLinkedList(LLNode *h)
{
    LLNode *c, *p ,*n;
    c=h;
    p=NULL;
    n=c->next;
    while(c!=NULL)
    {
        n=c->next;
        c->next = p;
        p=c;
        c = n;
    }
    return p;
}

