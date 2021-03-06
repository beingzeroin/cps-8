#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int factorial(int n)
{
    int i;
    int ans = 1;
    for(i=1; i<=n; i++)
        ans = ans * i;
    return ans;
}
int memDiscussion()
{

    auto int a=5;
    auto int b=10;
    factorial(5);
    printf("%d %d", a, b);


    return 0;
}

typedef struct n LLNode;
struct n
{
    int data;
    LLNode *next;
};

LLNode *createLLNode(int data)// Allocate - put data and null
{
    // Allocate Node on Heap
    LLNode *t = malloc(sizeof(LLNode));

    // Init Memory
    t->data = data;
    t->next = NULL;


    // Return the address
    return t;
}
// NULL
LLNode *insertInBegin(LLNode *h, int data)
{
    LLNode *t = createLLNode(data);
    t->next = h;
    return t;

}
void traverse(LLNode *h)
{
    printf("\nTRAVERSE: ");
    LLNode *c = h;

    while(c!=NULL)
    {
        printf("%d ", c->data);
        c = c->next;
    }

}
LLNode *findLastNode(LLNode *h)
{

	while(h->next!=NULL)
	{
		h = h->next;
	}
	return h;
}
LLNode *insertInEnd(LLNode *h, int data)
{
	LLNode *t = createLLNode(data);
	// TODO:  Empty List
	if(h==NULL)
		return t;
	LLNode *l = findLastNode(h);

	l->next = t;

	return h;
}

LLNode *deleteNodeWithValue(LLNode *h, int data)
{
    LLNode* c=h, *p=NULL;

    while(c!=NULL)
    {
        if(c->data==data)
        {
            if(p==NULL)
            {
                c = c->next;
                free(h);
                return c;
            }
            p->next = c->next;
            free(c);
            return h;
        }
        p = c;
        c = c->next;
    }
    return h;
}
/*
LLNode *deleteNodeWithValue(LLNode *h, int data)
{
    LLNode *current,*prev;
    current=h;
    prev=NULL;
    if(current==NULL)//empty list
        return current;
    else
    {
        while(current->data!=data)
        {
            prev=current;
            current=current->next;
        }
        if(current->data!=data)//Data not found
        {

            printf("Data not found");
        }
        else if(current->data==data&&current=h)//Delete head
        {
            h=h->next;
            delete(current);
        }
        else if(current->data==data &&current->next!=NULL)//Data found in between
        {
            prev->next=current->next;
            return h;
        }
        else//Delete last node
        {
            delete(current);
        }
    }


}

*/
LLNode *createSerialList(int n)
{
    int i;
    LLNode *h = NULL;
    for(i=1;i<=n;i++)
        h = insertInEnd(h, i);

    return h;
}
int countLinkedListNodes(LLNode *h)
{
    int c = 0;

    while(h!=NULL){
        c++;
        h = h->next;
    }

    return c;
}

LLNode *searchNodeWithValue(LLNode *h, int data)
{

}

LLNode *findIntersectionPoint(LLNode *h1, LLNode *h2)
{


}

int main()
{

    LLNode *h = createSerialList(10);
    traverse(h);
    assert(countLinkedListNodes(h)==10);

    // 1st Node Deletion
    assert(searchNodeWithValue(h, 1)!=NULL);
    h = deleteNodeWithValue(h, 1);
    traverse(h);
    assert(countLinkedListNodes(h)==9);
    assert(searchNodeWithValue(h, 1)==NULL);

    // Last Node
     h = deleteNodeWithValue(h, 10);
    traverse(h);
    assert(countLinkedListNodes(h)==8);

    // Middle Node
     h = deleteNodeWithValue(h, 5);
    traverse(h);
    assert(countLinkedListNodes(h)==7);

    // Empty Linked List
    deleteNodeWithValue(NULL, 7);

    // Data Not Found
     h = deleteNodeWithValue(h, 15);
    traverse(h);
    assert(countLinkedListNodes(h)==7);
    //findLastNode(NULL);

    LLNode *head = NULL;
    head = insertInBegin(head, 5);
    head = insertInBegin(head, 4);
    head = insertInBegin(head, 3);
    head = insertInBegin(head, 2);
    head = insertInBegin(head, 1);
    traverse(head);
    return 0;
}
