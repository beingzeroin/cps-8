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
bool isLeaf(BSTNode *r)
{
    if(r==NULL)
        return false;
    return r->left==NULL && r->left==NULL;
}
bool hasSum(BSTNode *r,int sum)
{
    if(r==NULL&&sum==0)
    {
        return true;
    }
    if(r==NULL||sum==0)
    {
        return false;
    }
    else
    {
        return hasSum(r->left, sum - r->data);
        return hasSum(r->right, sum - r->data);
    }
}

void levelOrderSpiral(BSTNode *r)
{
    if(r==NULL)
        return;
    queue<BSTNode *> q;
    q.push(r);
    q.push(NULL);
    bool rtl = true;
    BSTNode *c;
    while(!q.empty())
    {
        c = q.front();
        q.pop();
        if(c==NULL)
        {
            rtl = !rtf;
            q.push(NULL);
        }
        else
        {
            printf("%d ",c->data);
            if(rtl)
            {
                if(c->right)
                    q.push(c->right);
                if(c->left)
                    q.push(c->left);
            }
            else
            {
                if(c->left)
                    q.push(c->left);
                if(c->right)
                    q.push(c->right);
            }
        }
    }
}
