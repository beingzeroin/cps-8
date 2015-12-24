#include "BST.h"
#include <stdlib.h>

BSTNode *createBSTNode(ElementType data)
{
<<<<<<< HEAD
    BSTNode *newNode=malloc(sizeof(BSTNode));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
=======
    return NULL;
>>>>>>> a7e39fa389f29ca80e4f80145d2b79261ecf40bd
}

BSTNode *searchBSTNode(BSTNode *root,ElementType data)
{
    if(root==NULL || data==root->data)
        return root;
    if(data<root->data)
        return searchBSTNode(root->left,data);
    if(data>root->data)
        return searchBSTNode(root->right,data);
    return NULL;
}
BSTNode *rinsertBSTNode(BSTNode *root, ElementType data)
{
    if(root==NULL)
        return createBSTNode(data);
    if(data<root->data)
        root->left=rinsertBSTNode(root->left,data);
    if(data>root->data)
        root->right=rinsertBSTNode(root->right,data);
    return root;
}

BSTNode *insertBSTNode(BSTNode *root, ElementType data)
{
    BSTNode *newNode=createBSTNode(data);
    if(root==NULL)
        return newNode;
    BSTNode *temp=root,*prev=NULL;
    while(temp!=NULL)
    {
        if(data==temp->data)
            return root;
        if(data<temp->data)
        {
            prev=temp;
            temp=temp->left;
        }
        else
        {
            prev=temp;
            temp=temp->right;
        }
    }
    if(data<prev->data)
        prev->left=newNode;
    if(data>prev->data)
        prev->right=newNode;
    return root;
}

BSTNode *delteBSTNode(BSTNode *root, ElementType data)
{
    if(root==NULL)
        return root;
    if(data<root->data)
        root->left=delteBSTNode(root->left,data);
    else if(data>root->data)
        root->right=delteBSTNode(root->right,data);
    else if(data==root->data)
    {
        if(root->left==NULL && root->right!=NULL)
        {
            BSTNode *temp=root->right;
            //root->right==NULL;
            free(root);
            return temp;
        }
        else if(root->left!=NULL && root->right==NULL)
        {
            BSTNode *temp=root->left;
            //root->left==NULL;
            free(root);
            return temp;
        }
        else if(root->left!=NULL)
        {
            BSTNode *temp=root->left;
            while(temp->right!=NULL)
                temp=temp->right;
            root->data=temp->data;
            return delteBSTNode(root->left,temp->data);
        }
        else if(root->right==NULL && root->left==NULL)
        {
            free(root);
            return NULL;
        }
    }
    return root;
}
