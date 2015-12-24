#include <cstdio>
#include <stack>
#include "BST.h"
using namespace std;

void iterativePreorder(BSTNode *r)
{
    stack<BSTNode*> myStack;
    while(1)
    {
        while(r!=NULL){
        printf("%d ",r->data);
        myStack.push(r);
        r=r->left;
        }
        if(myStack.empty())
            break;
        r=myStack.top();
        myStack.pop();
        r=r->right;
    }
}

void recursivePreorder(BSTNode *r)
{
    if(r!=NULL)
    {
        printf("%d ",r->data);
        recursivePreorder(r->left);
        recursivePreorder(r->right);
    }
}

void iterativeInorder(BSTNode *r)
{
    stack<BSTNode*> myStack;
    while(1)
    {
        while(r!=NULL){
        myStack.push(r);
        r=r->left;
        }
        if(myStack.empty())
            break;
        r=myStack.top();
        printf("%d ",r->data);
        myStack.pop();
        r=r->right;
    }
}
/*
void iterativePostorder(BSTNode *r)
{
    stack<BSTNode*> myStack1;
    stack<BSTNode*> notVisited;
    while(1){
    while(r!=NULL)
    {
        myStack1.push(r);
        notVisited.push(r);
        r=r->left;
    }
    if(myStack1.empty())
        break;
    if(myStack1.top() == notVisited.top())
    {
        r=myStack1.top();
        r=r->right;
        notVisited.pop();
    }
    else
    {
        r=myStack1.top();
        printf("%d ",r->data);
        myStack1.pop();
        r=NULL;
    }
    }
}
*/

void iterativePostorder(BSTNode *r)
{
    stack<BSTNode*> myStack;
    BSTNode *rc;
    while(1)
    {
        while(r!=NULL)
        {
            if(r->right!=NULL)
                myStack.push(r->right);
            myStack.push(r);
            r=r->left;
        }
        if(myStack.empty())
            break;
        r=myStack.top();
        myStack.pop();
        if(myStack.empty())
        {
            printf("%d ",r->data);
            break;
        }
        else
        {
            rc=myStack.top();
            if(r->right==rc)
            {
                myStack.pop();
                myStack.push(r);
                r=r->right;
            }
            else
            {
                printf("%d ",r->data);
                r=NULL;
            }
        }
    }
}
