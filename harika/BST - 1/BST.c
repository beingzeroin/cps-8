#include "BST.h"
#include <stdlib.h>

BSTNode *createBSTNode(ElementType data)
{
    BSTNode *temp=(BSTNode*)malloc(sizeof(BSTNode));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

BSTNode *rinsertBSTNode(BSTNode *root, ElementType data)
{
    BSTNode *temp=(BSTNode*)malloc(sizeof(BSTNode));
    temp=root;
    if(temp==NULL)
        createBSTNode(data);
    else if(data<temp->data)
        temp->left=rinsertBSTNode(temp->left,data);
    else
        temp->right=rinsertBSTNode(temp->right,data);
    return temp;
}

BSTNode *insertBSTNode(BSTNode *root, ElementType data)
{
    BSTNode *temp=(BSTNode*)malloc(sizeof(BSTNode));
    temp=root;
    if(temp==NULL)
        return createBSTNode(data);
    while(1)
    {

        if(data<temp->data)
        {
            if(temp->left==NULL)
            {
                temp->left=createBSTNode(data);
                return root;
            }
            temp=temp->left;
        }
        if(data>temp->data)
        {
            if(temp->right==NULL)
            {
                temp->right=createBSTNode(data);
                return root;
            }
            temp=temp->right;
        }

    }
}

BSTNode *deleteBSTNode(BSTNode *root, ElementType data)
{
    BSTNode *temp=(BSTNode*)malloc(sizeof(BSTNode));
    temp=root;
    BSTNode *c=(BSTNode*)malloc(sizeof(BSTNode));
    c=root;
    if(temp==NULL)
        return temp;
    else if(data<temp->data)
        return deleteBSTNode(root->left,data);
    else if(data>temp->data)
        return deleteBSTNode(root->right,data);
    else
        if(temp->left==NULL)//one right child
        {
            c=root->right;
            free(temp);
            return c;
        }
        else if(temp->right==NULL)//one left child
        {
            c=root->left;
            free(temp);
            return c;
        }
        else                    //two children
        {
            c=temp->right;      //right subtree
            while(c->left!=NULL)
                c=c->left;
            temp->data=c->data;
            free(temp);
            return c;
            /*
            c=temp->left;       //left subtree
            while(c->right!=NULL)
                c=c->right;
            temp->data=c->data;
            free(temp);
            */
        }
}

BSTNode *searchBSTNode(BSTNode *root, ElementType data)
{
    BSTNode *temp=(BSTNode*)malloc(sizeof(BSTNode));
    temp=root;
    if(temp==NULL||temp->data==data)
        return temp;
    else if(root->data=data)
        return temp;
    else if(root->data>data)
        return searchBSTNode(root->left,data);
    else
        return searchBSTNode(root->right,data);
}


