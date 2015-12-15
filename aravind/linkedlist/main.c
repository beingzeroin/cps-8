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
    LLNode *temp = malloc(sizeof(LLNode));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
LLNode *insertInBegin(LLNode *h,int data)
{
    LLNode *temp;
    temp = createLLNode(data);
    temp->next = h;
    return temp;
}
LLNode *insertInEnd(LLNode *h,int data)
{
    LLNode *l;
    LLNode *temp = createLLNode(data);
    if(h==NULL)
        return temp;
    l = findLastNode(data);
    l->next= temp;
    return h;
}
/*LLNode *findLastNode(LLNode *h)
{
    if(h==NULL)
        return h;
    while(h->next!=NULL)
    {
        h=h->next;
    }
    return h;
}*/
LLNode *deleteLLNodeWithValue(LLNode *h,int data)
{
    LLNode *previous, *current;
    if(h==NULL)
        return h;
    previous = current = h;
    if(current->data==data)
    {
        h=h->next;
        free(current);
        return h;
    }
    current = current->next;
    while(current->next!=NULL)
    {
        if(current->data==data)
        {
            previous->next = current->next;
            free(current);
            return h;
        }
        else
        {
            current = current->next;
            previous = previous->next;
        }
    }
    if(current->next==NULL&&current->data==data)
    {
        previous->next=NULL;
        free(current);
        return h;
    }
    return h;
}
LLNode *createSerialList(int n)
{
    LLNode *h = NULL;
    int i;
    for(i=1;i<=n;i++)
        h = insertInEnd(h, i);
    return h;
}
void traverse(LLNode *h)
{
    LLNode *t = h;
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t = t->next;
    }
}
int main()
{

    LLNode *head = createSerialList(10);
    /*
    head = insertInBegin(head, 5);
    head = insertInBegin(head, 4);
    head = insertInBegin(head, 3);
    head = insertInBegin(head, 2);
    head = insertInBegin(head, 1);*/
    traverse(head);
    return 0;
}

