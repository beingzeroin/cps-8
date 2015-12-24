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
        mystack.pop();
        cout<<root->data<<" ";
        root=mystack.top();
        mystack.pop();
        cout<<root->data<<" ";
        root
    }
}
