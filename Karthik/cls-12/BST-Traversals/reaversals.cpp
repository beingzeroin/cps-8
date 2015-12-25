#include <stack>
#include <iostream>
#include "BST.h"
using namespace std;
void iterativePreorder(BSTNode *root)
{
    stack<BSTNode*> mystack;
    while(1)
    {
        while(root!=NULL)
        {
            cout<<root->data<<" ";
            mystack.push(root);
            root=root->left;
        }
        if(mystack.empty())
            break;
        root=mystack.top();
        mystack.pop();
        root=root->right;
    }
}

void riterativePreorder(BSTNode *root)
{
    if(root==NULL)
        return ;
    cout<<root->data<<" ";
    riterativePreorder(root->left);
    riterativePreorder(root->right);
}

void iterativeInorder(BSTNode *root)
{
    stack<BSTNode*> mystack;
    while(1)
    {
        while(root!=NULL)
        {
            mystack.push(root);
            root=root->left;
        }
        if(mystack.empty())
            break;
        root=mystack.top();
        cout<<root->data<<" ";
        mystack.pop();
        root=root->right;
    }
}

void iterativePostorder(BSTNode *root)
{
    stack<BSTNode*> mystack;
    BSTNode *r,*rc;
    while(1)
    {
        while(root!=NULL)
        {
            if(root->right!=NULL)
                mystack.push(root->right);
            mystack.push(root);
            root=root->left;
        }
        if(mystack.empty())
            break;
        r=mystack.top();
        mystack.pop();
        if(mystack.empty())
        {
            cout<<r->data<<" ";
            break;
        }
        rc=mystack.top();
        mystack.pop();
        if(r->right==rc)
        {
            mystack.push(r);
            root=rc;
        }
        else
        {
            cout<<r->data<<" ";
            mystack.push(rc);
            r=NULL;
        }
        //root=root->right;
    }
}
