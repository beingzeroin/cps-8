#include <stack>
#include <iostream>
#include "BST.h"
#include <queue>
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

void recursivePreorder(BSTNode *root)
{
    if(root==NULL)
        return ;
    cout<<root->data<<" ";
    recursivePreorder(root->left);
    recursivePreorder(root->right);
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

    }
}

bool isBST(BSTNode *root)
{
    stack<BSTNode*> mystack;
    //bool flag=true;
    while(1)
    {
        if(root->left->data > root->data || root->right->data < root->data)
            return false;
        while(root!=NULL)
        {
            mystack.push(root);
            root=root->left;
        }
        if(mystack.empty())
            break;
        root=mystack.top();
        //cout<<root->data<<" ";
        mystack.pop();
        root=root->right;
    }
    return true;
}

bool recursiveIsBST(BSTNode *root)
{
    bool flag=true;
    if(root==NULL)
        return true;
    if(root->left!=NULL)
        if(root->left->data > root->data)
            return false;
    if(root->right!=NULL)
        if(root->right->data <root->data)
            return false;
    flag=recursiveIsBST(root->left);
    if(flag==false)
        return false;
    flag=recursiveIsBST(root->right);
    return false;
}

void levelOrderTraversal(BSTNode *root)
{
    if(root==NULL)
        return;
    queue<BSTNode*> myqueue;
    BSTNode *t1;
    myqueue.push(root);
    while(!myqueue.empty())
    {
        t1=myqueue.front();
        myqueue.pop();
        cout<<t1->data<<" " ;
        if(t1->left!=NULL)
            myqueue.push(t1->left);
        if(t1->right!=NULL)
            myqueue.push(t1->right);
    }
}

void spiralLevelOrderTraversal(BSTNode *root)
{
    if(root==NULL)
        return;
    queue<BSTNode*> myQ;
    BSTNode *t1;
    int i,len,clock=-1;
    myQ.push(root);
    while(1)
    {
        if(len=myQ.size())
        {
            if(clock==-1)
            {
                for(i=0;i<len;i++)
                {
                    t1=myQ.front();
                    cout<t1->data<<" ";
                    myQ.push(t1->left);
                    myQ.push(t1->right);
                    myQ.pop();
                }
                clock=1;
            }
            else if(clock==1)
            {
                for(i=0;i<len;i++)
                {

                }
                clock=-1;
            }
        }
    }
}
