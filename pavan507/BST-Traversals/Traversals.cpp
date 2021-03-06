#include <stack>
#include "BST.h"
#include<stdlib.h>
#include<stdio.h>
#include<queue>
int c=0;
using namespace std;

/*void iterativeInorder(BSTNode *r)
{
    stack<BSTNode*> mystack;
    if(r==NULL)
        return;
//<<<<<<< HEAD
//=======
//    stack<BSTNode*> mystack;
//>>>>>>> 5ae402af7707870aa0c61f2f0c2eb497a5180003
    while(1)
    {
        while(r!=NULL)
        {
            mystack.push(r);
            r=r->left;

//<<<<<<< HEAD

//=======
//>>>>>>> 5ae402af7707870aa0c61f2f0c2eb497a5180003
        }
        if(mystack.empty())
            break;
        r=mystack.top();
//<<<<<<< HEAD
        mystack.pop();
        printf("%d ",r->data);
        r=r->right;


    }

}
void recursiveInorder(BSTNode* r)
{
    if(r==NULL)
        return;
    recursiveInorder(r->left);
    printf("%d ",r->data);
    recursiveInorder(r->right);
}
void iterativePostorder(BSTNode *r)
{
    BSTNode *p=NULL,*rc=NULL;
    if(r==NULL)
        return;
    stack<BSTNode*>mystack;
//=======
        printf("%d ",r->data);
        mystack.pop();
        r=r->right;

    }


/*void iterativePreorder(BSTNode *r)
{
    if(r==NULL)
        return;
    stack<BSTNode*> mystack;
//>>>>>>> 5ae402af7707870aa0c61f2f0c2eb497a5180003
    while(1)
    {
        while(r!=NULL)
        {
//<<<<<<< HEAD
            if(r->right!=NULL)
                mystack.push(r->right);
            mystack.push(r);
            r=r->left;
        }
        if(mystack.empty())
            break;
        p=mystack.top();
        mystack.pop();
        if(mystack.empty())
        {
            printf("%d ",p->data);
            break;

        }
        rc=mystack.top();
        mystack.pop();
        if(p->right==rc)
        {
            mystack.push(p);
            r=rc;
        }
        else
        {
            printf("%d ",p->data);
            mystack.push(rc);
            r=NULL;

        }

    }
//=======
            printf("%d ",r->data);
            mystack.push(r);
            r=r->left;
//>>>>>>> 5ae402af7707870aa0c61f2f0c2eb497a5180003

        }
        if(mystack.empty())
            break;
        r=mystack.top();
        mystack.pop();
        r=r->right;
    }
}
void levelOrderTraversal(BSTNode *r)
{
    queue<BSTNode*>myqueue;
    if(r==NULL)
        return;
    myqueue.push(r);
    while(!myqueue.empty())
    {
        r=myqueue.front();
        myqueue.pop();
        printf("%d ",r->data);
        if(r->left!=NULL)
            myqueue.push(r->left);
        if(r->right!=NULL)
            myqueue.push(r->right);

    }

}
int height(BSTNode *r)
{
    if(r==0)
        return 0;
    int lheight=height(r->left);
    int rheight=height(r->right);
    if(lheight>rheight)
        return 1+lheight;
    else
        return 1+rheight;

}

void printLevelOrder(BSTNode *r)
{
    int h=height(r);
    int i;
    for(i=1;i<=h;i++)
    {

        printGivenLevel(r,i);
    }

void iterativePostorder(BSTNode *r)
{
    if(r==NULL)
        return;
    stack<BSTNode*> mystack;
    while(1)
    {
        while(r!=NULL)
        {
            if(r->right!=NULL)
                mystack.push(r->right);
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
void printGivenLevel(BSTNode *r,int level)
{
    if(r==NULL)
        return;
    if(level==1)
        printf("%d ",r->data);
    else if(level>1)
    {

        printGivenLevel(r->left,level-1);
        printGivenLevel(r->right,level-1);
    }
}

void printSpiralOrder(BSTNode *r)
{
    int h=height(r);
    int i,flag=0;
    for(i=1;i<=h;i++)
    {

        printSpiralLevel(r,i,flag);
        if(flag==0)flag=1;
        else flag=0;
    }

}
void printSpiralLevel(BSTNode *r,int level,int flag)
{
    if(r==NULL)
        return;
    if(level==1)
        printf("%d ",r->data);
    else if(level>1)
    {
       if(flag==0)
       {
        printSpiralLevel(r->left,level-1,flag);
        printSpiralLevel(r->right,level-1,flag);
    }
    else{
        printSpiralLevel(r->right,level-1,flag);
        printSpiralLevel(r->left,level-1,flag);
    }
}
}
int nodeCount(BSTNode *r)
{
    if(r==NULL)
        return 0;
    return (1+nodeCount(r->left)+nodeCount(r->right));

}*/
void printPath(BSTNode *r)
{
    int path[100];
    printRecursively(r,path,0);

}
void printRecursively(BSTNode *r,int path[],int pathlen)
{
    if(r==NULL)
        return;
    path[pathlen]=r->data;
    pathlen++;
    if(r->left==NULL&&r->right==NULL)
        printPathArray(path,pathlen);
    else
    {
        printRecursively(r->left,path,pathlen);
        printRecursively(r->right,path,pathlen);
    }

}
void printPathArray(int path[],int pathlen)
{
    int i;
    for(i=0;i<pathlen;i++)
        printf("%d ",path[i]);
    printf("\n");
}
/*
void spiralOrderTraversal(BSTNode *r)
{
    int i,k=0;
    queue<BSTNode*>myqueue;
    if(r==NULL)
        return;
    myqueue.push(r);
    c++;
    i=1;
    while(!myqueue.empty())
    {
        while(c--)
        {
            r=myqueue.front();
            myqueue.pop();
            printf("%d ",r->data);
            if(i%2==0)
            {
                if(r->right!=NULL)
                {
                    myqueue.push(r->right);
                    k++;
                }
                if(r->left!=NULL)
                {
                    myqueue.push(r->left);
                    k++;
                }


            }
            else
            {
                if(r->left!=NULL)
                {
                    myqueue.push(r->left);
                    k++;
                }
                if(r->right!=NULL)
                {
                    myqueue.push(r->right);
                    k++;
                }
            }

        }
        c=k;
        k=0;
        i++;


    }

}*/
