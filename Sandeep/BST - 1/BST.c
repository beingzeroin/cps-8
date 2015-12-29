#include "BST.h"
#include <stdlib.h>

BSTNode *createBSTNode(ElementType data)
{
    BSTNode *temp= malloc(sizeof(BSTNode));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

BSTNode *rinsertBSTNode(BSTNode *root, ElementType data)
{
    if(root==NULL)
        return createBSTNode(data);
    if(root->data>data)
        root->left=rinsertBSTNode(root->left,data);
    if(root->data<data)
        root->right=rinsertBSTNode(root->right,data);
    return root;

}

BSTNode *insertBSTNode(BSTNode *root, ElementType data)
{
    BSTNode *temp=createBSTNode(data),*t=root,*tt;
    if(root==NULL)
        return temp;
    else
    {
        while(root!=NULL)
        {
            tt=root;
        if(root->data>data)
            root=root->left;
        else
            root=root->right;
        }
        if(tt->data>data)
            tt->left=temp;
        else
            tt->right=temp;
    }
    return t;

}


BSTNode *delteBSTNode(BSTNode *root, ElementType data)
{
    BSTNode *i;
    BSTNode *t=searchBSTNode(root,data);
    i=t;
    if(t==NULL)
        return NULL;
    else
    {
        if(i->left==NULL&&i->right==NULL)
        {
            free(t);
        }
        if(i->left==NULL&&i->right!=NULL)
        {

        }
    }
    return NULL;
}

BSTNode *searchBSTNode(BSTNode *root,ElementType data)
{
    if(root->data==data||root==NULL)
        return root;
    if(root->data>data)
        return searchBSTNode(root->left,data);
    if(root->data<data)
        return searchBSTNode(root->right,data);

}




