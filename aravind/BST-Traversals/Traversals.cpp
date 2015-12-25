#include <stack>
#include <cstdlib>
#include <iostream>
#include <queue>
#include "BST.h"
using namespace std;

void iterativePreorder(BSTNode *r)
{
    stack<BSTNode*> mystack;

    if(r==NULL)
        return;
    while(1)
    {
        while(r!=NULL)
        {

            cout<<r->data<<" ";
            mystack.push(r);
            r = r->left;
        }

        if(mystack.empty())
        {
            break;
        }
        r = mystack.top();
        mystack.pop();
        r = r->right;
    }
}

void iterativeInorder(BSTNode *r)
{
    stack<BSTNode*> mystack;
    if(r==NULL)
        return;
    while(1)
    {
        while(r!=NULL)
        {
            mystack.push(r);
            r = r->left;
        }

        if(mystack.empty())
        {
            break;
        }
        r = mystack.top();
        cout<<r->data<<" ";
        mystack.pop();
        r = r->right;
    }
}

void iterativePostorder(BSTNode *r)
{
   /* stack<BSTNode*> mystack;
    if(r==NULL)
        return;
    while(1)
    {
        while(r!=NULL)
        {
            mystack.push(r);
            r = r->left;
        }

        if(mystack.empty())
        {
            break;
        }
        r = mystack.top();
        if(r->right==NULL)
        {
            cout<<r->data<<" ";
            mystack.pop();
        }
        else
            r = r->right;
    }
    */

}

void levelOrderTraversal(BSTNode *r)
{
    queue<BSTNode*> myqueue;
    if(r==NULL)
        return;
    myqueue.push(r);
    BSTNode *c=r;
    while(!myqueue.empty())
    {
        c = myqueue.front();
        myqueue.pop();
        if(c->left!=NULL)
            myqueue.push(c->left);
        if(c->right!=NULL)
            myqueue.push(c->right);

    }
}
void rlevelOrderTraversal(BSTNode *r)
{
    queue<BSTNode*> myqueue;
    if(r==NULL)
        return;
    myqueue.push(r);
    levelOrderTraversal(r->left);
    levelOrderTraversal(r->right);

    }
}

