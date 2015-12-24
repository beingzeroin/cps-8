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
