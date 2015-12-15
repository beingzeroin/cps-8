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
        while(t->data != d)
        {
            p=t;
            t = t->next;
        }
        if(t==h)
        {
            h=t->next;
            free(t);
        }
        else if(t->next == NULL)
        {
            p->next = NULL;
            free(t);
        }
        else if(t==NULL)
            return h;
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

int main()
{
    LLNode *head = createSerialList(10);
    traverse(head);
    printf("\n");

    head = deleteNodeWithValue(head,1);
    traverse(head);
    printf("\n");

    head = deleteNodeWithValue(head,5);
    traverse(head);
    printf("\n");

    head = deleteNodeWithValue(head,10);
    traverse(head);
    printf("\n");

    head = deleteNodeWithValue(head,15);
    traverse(head);
    printf("\n");

    deleteNodeWithValue(NULL,5);



    traverse(head);
    return 0;
}
