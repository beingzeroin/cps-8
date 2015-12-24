#include<stack>
#include<stdlib.h>
#include<stdio.h>
#include"BST.h"
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

void iterativeInorder(BSTNode *r)
{
    if(r==NULL)
        return;
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

