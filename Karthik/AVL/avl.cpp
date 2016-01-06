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
void rotateLeft(AVLNode *r)
{
    AVLNode *n=createNode(r->data);
    r->data=r->right->data;
    n->left=r->left;
    n->right=r->right->left;
    r->left=n;
    AVLNode *del=r->right;
    r->right=r->right->right;
    free(del);
}
void roatateRight(AVLNode *r)
{
    AVLNode *n=createNode(r->data);
    r->data=r->left->data;
    n->right=r->right;
    n->left=r->left->right;
    r->right=n;
    AVLNode *del=r->left;
    r->left=r->left->left;
    free(del);
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
AVLNode *insertAVL(AVLNode *root,int data)
{
    if(root==NULL)
        return createNode(data);
    if(data<root->data)
        root->left=insertAVL(root->left,data);
    if(data>root->data)
        root->right=insertAVL(root->right,data);
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
    root->height=1+MAX(root->left->height,root->right->height);
    return root;
}
AVLNode *deleteAVL(AVLNode *root,int data)
{
    if(root==NULL)
        return root;
    if(data<root->data)
        root->left=deleteAVL(root->left,data);
    if(data>root->data)
        root->right=deleteAVL(root->right,data);
    if(data==root->data)
    {

    }

}
void inorder(AVLNode *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
