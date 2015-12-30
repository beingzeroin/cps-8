#include "BST.h"
#include <stdlib.h>

BSTNode *createBSTNode(ElementType data)
{
    BSTNode *t = malloc(sizeof(BSTNode));
    t->data = data;
    t->right = t->left = NULL;
    return t;
}

BSTNode *searchBSTNode(BSTNode *root, ElementType data)
{
    if(root==NULL)
        return NULL;
    else if(root->data == data)
        return root;
    else if(data > root->data)
        return searchBSTNode(root->right,data);
    else
        return searchBSTNode(root->left,data);
}

BSTNode *rinsertBSTNode(BSTNode *root, ElementType data)
{
    if(root == NULL)
    {
        return createBSTNode(data);
    }
    else if(root->data > data)
    {
        root->left = rinsertBSTNode(root->left, data);
    }
    else if(root->data < data)
    {
        root->right = rinsertBSTNode(root->right, data);
    }
    else
    {
        return root;
    }
    return root;
}

BSTNode *insertBSTNode(BSTNode *root, ElementType data)
{
    BSTNode *t = root;
    BSTNode *p;
    if(root==NULL)
    {
        p=createBSTNode(data);
        return p;
    }
    while(t!=NULL)
    {
        p=t;
        if(t->data == data)
            return root;
        else if(t->data > data)
            t=t->left;
        else if(t->data < data)
            t=t->right;
    }
    if(p->data > data)
        p->left = createBSTNode(data);
    else
        p->right = createBSTNode(data);
    return root;
}
/*  delete without recursion
BSTNode *delteBSTNode(BSTNode *root, ElementType data)
{
    BSTNode *t,*p;
    t=root;
    while(t!=NULL)
    {
        p=t;
        if(t->data == data)
        {
            if(t->right==NULL && t->left==NULL){
                if(p->data > data)
                    p->left=NULL;
                else
                    p->right=NULL;
                free(t);
            }
            else if(t->right==NULL || t->left==NULL)
            {
            }
        }
        else if(t->data > data)
            t=t->left;
        else if(t->data < data)
            t=t->right;
    }
}
*/

ElementType minValue(BSTNode *root)
{
    while(root->left!=NULL)
        root=root->left;
    return root->data;
}

BSTNode *delteBSTNode(BSTNode *root, ElementType data)
{
    if(root == NULL)
    {
        return NULL;
    }
    else if(root->data==data)
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left==NULL || root->right==NULL)
        {
            if(root->left!=NULL)
                return root->left;
            else
                return root->right;

        }
        else
        {
            root->data=minValue(root->right);
            root->right=delteBSTNode(root->right,root->data);
        }
    }
    else if(root->data > data)
    {
        root->left = delteBSTNode(root->left, data);
    }
    else if(root->data < data)
    {
        root->right = delteBSTNode(root->right, data);
    }
    return root;
}
