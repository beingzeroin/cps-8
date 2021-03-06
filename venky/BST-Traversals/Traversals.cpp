#include <stack>
#include<stdlib.h>
#include<stdio.h>
#include "BST.h"
using namespace std;

void iterativeInorder(BSTNode *r)
{
    if(r==NULL)
        return;
    stack<BSTNode*> mystack;
    while(1)
    {
        while(r!=NULL)
        {
            mystack.push(r);
            r=r->left;

        }
        if(mystack.empty())
            break;
        r=mystack.top();
        printf("%d ",r->data);
        mystack.pop();
        r=r->right;

    }
}

void iterativePreorder(BSTNode *r)
{
    if(r==NULL)
        return;
    stack<BSTNode*> mystack;
    while(1)
    {
        while(r!=NULL)
        {
            printf("%d ",r->data);
            mystack.push(r);
            r=r->left;

        }
        if(mystack.empty())
            break;
        r=mystack.top();
        mystack.pop();
        r=r->right;
    }
}

void iterativePostorder(BSTNode *r)
{
    if(r==NULL)
        return;
    stack<BSTNode*> mystack;
    BSTNode *p, *rc;
    while(1)
    {
        while(r!=NULL)
        {
            if(r->right!=NULL)
                mystack.push(r->right);
            mystack.push(r);
            r=r->left;

        }
        if(mystack.empty())
            break;
        p=mystack.top();
        mystack.pop();
        if(mystack.empty())
        {
            printf("%d ",p->data);
            break;
        }
        rc=mystack.top();
        mystack.pop();

        if(rc == p->right)
        {
            mystack.push(p);
            r=rc;
        }
        else
        {
            printf("%d ",p->data);
            mystack.push(rc);
            r = NULL;
        }
    }
}
