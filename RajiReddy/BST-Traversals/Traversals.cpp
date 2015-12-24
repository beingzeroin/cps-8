#include <stack>
#include<stdio.h>
#include "BST.h"
using namespace std;

void iterativePreorder(BSTNode *r)
{
    if(r==NULL)
        return;
    stack<BSTNode*> mystack;
    while(1)
    {
        while(r!=NULL)
        {
            mystack.push(r);
            printf("%d ",r->data);
            r=r->left;
        }
        r=mystack.top();
        if(mystack.empty())
            break;
        mystack.pop();
        r=r->right;
    }
}

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
        r=mystack.top();
        if(mystack.empty())
            break;
         printf("%d ",r->data);
        mystack.pop();
        r=r->right;
    }
}
