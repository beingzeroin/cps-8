#include "BST.h"
#include <stdlib.h>

BSTNode *createBSTNode(ElementType data)
{
   BSTNode *node=malloc(sizeof(BSTNode));
   node->data=data;
   node->left=NULL;
   node->right=NULL;
   return node;
}

BSTNode *rinsertBSTNode(BSTNode *root, ElementType data)
{
    if(root==NULL)
        return createBSTNode(data);
    if(root->data>data)
        root->left = rinsertBSTNode(root->left,data);
    if(root->data<data)
        root->right=rinsertBSTNode(root->right,data);
    return root;
}

BSTNode *insertBSTNode(BSTNode *root, ElementType data)
{
    if(root==NULL)
        return createBSTNode(data);
        BSTNode *c=root;
    while(1)
    {
        if(c->data>data)
    {
        if(c->left==NULL)
        {
            c->left=createBSTNode(data);
            return root;
        }
        c=c->left;
    }
    if(c->data<data)
    {
        if(c->right==NULL)
        {
            c->right=createBSTNode(data);
            return root;
        }
        c=c->right;
    }
    }
    return NULL;
}

BSTNode *searchBSTNode(BSTNode *root,ElementType data)
{
        if(root==NULL)
            return NULL;
        if(root->data==data)
            return root;
        if(root->data>data)
            return searchBSTNode(root->left,data);
        if(root->data<data)
            return searchBSTNode(root->right,data);
            return NULL;
}
ElementType min(BSTNode *n)
{
    while(n->left!=NULL)
        n=n->left;
    return n->data;
}
BSTNode *rdeleteBSTNode(BSTNode *root,ElementType data)
{
    if(root->data == data)
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left!=NULL && root->right!=NULL)
        {
            BSTNode *c= root->right;
            while(c->left!=NULL)
                c=c->left;
            root->data = c->data;
            root->right = deleteBSTNode(root->right,c->data);


        }
        else
        {

            if(root->left!=NULL)
            {
                BSTNode *c;

                c = root->left;
                free(root);
                return c;
            }
            else
            {
                BSTNode *c;
                c = root->right;
                free(root);
                return c;
            }
        }
    }
    else if(data <root->data)
        root->left = deleteBSTNode(root->left, data);
    else
        root->right = deleteBSTNode(root->right, data);

    return root;
}
