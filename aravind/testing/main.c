#include <stdio.h>
#include <stdlib.h>

typedef struct n LLNode;
struct n
{
    int data;
    LLNode *next;
};

LLNode *createNode(int data)
{
    LLNode *temp = malloc(sizeof(LLNode));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
LLNode *insertInBegining(LLNode *h,int data)
{
    LLNode *temp = createNode(data);
    if(h==NULL)
        return temp;
    else
    {
        temp->next=h;
        return temp;
    }
}
LLNode *findLastNode(LLNode *h)
{
    if(h==NULL)
        return h;
    while(h->next!=NULL)
        h=h->next;
    return h;
}
LLNode *insertInEnd(LLNode *h,int data)
{
    LLNode *temp = createNode(data);
    if(h==NULL)
        return temp;
    else
    {
        while(h->next!=NULL)
        {
            h=h->next;
        }
        h->next = temp;
        return h;
    }
}
LLNode *createSeriesList(int n)
{
    int i;
    LLNode *h = NULL;
    for(i=1;i<=n;i++)
    {
        insertInEnd(h,i);
    }
    return h;
}
LLNode *deleteNodeWithValue(LLNode *h,int data)
{
    LLNode *current, *previous;
    if(h==NULL)
        return h;
    current = previous = h;
    if(current->data==data)
    {
        h=current->next;
        free(current);
        return h;
    }
    current = current->next;
    while(current!=NULL)
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
    return h;
}
void traversal(LLNode *h)
{
    printf("\n");
    while(h!=NULL)
    {
        printf("%d ",h->data);
        h = h->next;
    }
}
int main()
{
    LLNode *head = NULL;
    head = createSeriesList(10);
    traversal(head);
    return 0;
}
