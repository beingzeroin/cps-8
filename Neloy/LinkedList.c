#include <stdio.h>
#include <stdlib.h>

typedef struct n LLNode;

struct n{
    int data;
    LLNode *next;
};

LLNode* createNode(int d)
{
    LLNode *temp = malloc(sizeof(LLNode));
    temp->data = d;
    temp->next = NULL;
    return temp;
}

LLNode* insertInBegin(LLNode *h,int d)
{
    LLNode *temp = createNode(d);
    temp->next = h;
    return temp;
}

void traverse(LLNode *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
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

LLNode* insertAtEnd(LLNode *h,int d)
{
    LLNode *temp = createNode(d);
    if(h==NULL)
        return temp;
    else{
        LLNode *t = findLastNode(h);
        t->next = temp;
    return h;
    }
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
        h=insertAtEnd(h,i);
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

int main()
{
    /*
    LLNode *head = createSerialList(10);
    traverse(head);
    printf("\n");

    head = deleteNodeWithValue(head,1);
    traverse(head);
    printf("\n");

    head = deleteNodeWithValue(head,5);
    traverse(head);
    printf("\n");

    head = deleteNodeWithValue(head,15);
    traverse(head);
    printf("\n");


    head = deleteNodeWithValue(head,10);
    traverse(head);
    printf("\n");

    deleteNodeWithValue(NULL,5);
*/

    LLNode *h1 = createSerialList(7);
    LLNode *h2 = NULL;
    h2 = insertAtEnd(h2,8);
    h2 = insertAtEnd(h2,9);
    LLNode *t1,*t2;
    t1 = h1;
    t2 = h2;
    while(t1->data != 5)
        t1=t1->next;
    while(t2->next!=NULL)
        t2=t2->next;
    t2->next=t1;

    traverse(h1);
    printf("\n");
    traverse(h2);
    printf("\n");
    printf("%x %d",findIntersection(h1,h2),findIntersection(h1,h2)->data);
    return 0;
}
