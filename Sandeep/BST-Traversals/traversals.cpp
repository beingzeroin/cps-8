#include <stack>
#include"BST.h"
#include <cstdlib>
#include <cstdio>
using namespace std;

void iterativePreOrder(BSTNode *r)
{
    stack<BSTNode*> mystack;
    while(1)
    {
        while(r!=NULL)
        {
            printf("%d", r->data);
            mystack.push(r);
            r=r->left;
        }
        if(mystack.empty())
            break;
        r = mystack.top();
        mystack.pop();
        r = r->right;
    }
}

void iterativeInOrder(BSTNode *r)
{
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
        r = mystack.top();
        printf("%d", r->data);
        mystack.pop();
        r = r->right;
    }
}

void iterativePostOrder(BSTNode *r)
{

}

