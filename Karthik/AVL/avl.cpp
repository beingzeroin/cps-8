#include"avl.h"
#include<stdlib.h>
#include<stdio.h>
AVLNode *createNode(int data)
{
    AVLNode *newNode=(AVLNode *)malloc(sizeof(AVLNode));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    //newNode->bf=0;
    newNode->height=1;
    return newNode;
}
int MAX(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int getHeight(AVLNode *root)
{
    if(root==NULL)
        return 0;
    return root->height;
}
int getBF(AVLNode *root)
{
    if(root==NULL)
        return 0;
    return getHeight(root->left)-getHeight(root->right);
}
void rotateLeft(AVLNode *r)
{
    AVLNode *n=createNode(r->data);
    r->data=r->right->data;
    n->left=r->left;
    n->right=r->right->left;
    n->height=1+MAX(getHeight(n->left),getHeight(n->right));
    r->left=n;
    AVLNode *del=r->right;
    r->right=r->right->right;
    free(del);
    r->height=1+MAX(getHeight(r->left),getHeight(r->right));
}
void rotateRight(AVLNode *r)
{
    AVLNode *n=createNode(r->data);
    r->data=r->left->data;
    n->right=r->right;
    n->left=r->left->right;
    n->height=1+MAX(getHeight(n->left),getHeight(n->right));
    r->right=n;
    AVLNode *del=r->left;
    r->left=r->left->left;
    free(del);
    r->height=1+MAX(getHeight(r->left),getHeight(r->right));
}

AVLNode *decideAndRotate(AVLNode *root)
{
    if(getBF(root)==-2)
    {
        if(getBF(root->right)==-1)
            rotateLeft(root);
        else if(getBF(root->right)==1)
        {
            rotateRight(root->right);
            rotateLeft(root);
        }
    }
    if(getBF(root)==2)
    {
        if(getBF(root->left)==1)
            rotateRight(root);
        else if(getBF(root->left)==-1)
        {
            rotateLeft(root->left);
            rotateRight(root);
        }
    }
    root->height=1+MAX(getHeight(root->left),getHeight(root->right));
    return root;
}
AVLNode *insertAVL(AVLNode *root,int data)
{
    if(root==NULL)
        return createNode(data);
    if(data<root->data)
        root->left=insertAVL(root->left,data);
    if(data>root->data)
        root->right=insertAVL(root->right,data);
    root=decideAndRotate(root);
    return root;
}
AVLNode *deleteAVL(AVLNode *root,int data)
{
    if(root==NULL)
        return root;
    if(data<root->data)
        root->left=deleteAVL(root->left,data);
    else if(data>root->data)
        root->right=deleteAVL(root->right,data);
    else
    {

    }

}
void inorder(AVLNode *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d(%d) ",root->data,getBF(root));
    inorder(root->right);
}
