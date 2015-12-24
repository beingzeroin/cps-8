#include "BST.h"
#include <stdlib.h>

BSTNode *createBSTNode(ElementType data)
{
    BSTNode *t=malloc(sizeof(BSTNode));
    t->data=data;
    t->left=NULL;
    t->right=NULL;

    return t;
}

BSTNode *rinsertBSTNode(BSTNode *root, ElementType data)
{
    if(root==NULL)
    {

        BSTNode *t=createBSTNode( data);

        return t;
    }
    else if(data>root->data)
    {


        if(root->right==NULL)
        {
            BSTNode *t=createBSTNode( data);
            root->right=t;
            return root;
        }
        root= rinsertBSTNode(root->right,data);
    }
    else
    {
        if(root->left==NULL)
        {
            BSTNode *t=createBSTNode( data);
            root->left=t;
            return root;
        }


        root= rinsertBSTNode(root->left,data);
    }


    return root;
}

BSTNode *insertBSTNode(BSTNode *root, ElementType data)
{
    BSTNode *temp=NULL,*t=createBSTNode(data),*root2=root;
    if(root==NULL)

        return t;
    else
        while(root!=NULL)
        {
            temp=root;
            if(data>root->data)
                root=root->right;
            else
                root=root->left;

        }
    if(data>temp->data)
    {
        temp->right=t;

    }
    else
        temp->left=t;

    return root2;

}
BSTNode *searchBSTNode(BSTNode *root, ElementType data)
{
    while(root!=NULL)
    {
        if(data==root->data)
            return root;
        else if(data>root->data)
            root=root->right;
        else
            root=root->left;
    }
    return root;
}

BSTNode *delteBSTNode(BSTNode *root, ElementType data)
{
    BSTNode *t=root,*temp=NULL,*temp2;
    ElementType d;
    if(t==NULL)
        return NULL;
    while(t!=NULL)
    {

        if(data==t->data)
            break;
        else if(data>t->data)
        {
            temp=t;
            t=t->right;
        }
        else
        {
            temp=t;
            t=t->left;
        }
    }
    if(t==root)
    {
        if(temp==NULL)
        {
            free(root);
            return NULL;
        }
    }
    if(t->left==NULL&&t->right==NULL)
    {
        if(temp->left==t)
        {
            free(t);
            temp->left=NULL;
            return root;
        }
        else
        {
            free(t);
            temp->right=NULL;
            return root;
        }
    }
    else if(t->left!=NULL&&t->right==NULL)
    {
        if(temp->left==t)
        {
            temp->left=t->left;
            free(t);
            return root;
        }
    }
    else
    {

        if(temp->left==t)
        {
            temp2=t;
            t=t->right;
            if(t->left==NULL)
            {
                temp->left=t;
                t->left=temp2->left;
                free(temp2);
                return root;
            }
            else
            {
                while(t->left!=NULL)
                {
                    t=t->left;
                }
                d=t->data;
                root=delteBSTNode(root,d);
                temp2->data=d;
                return root;

            }
        }
        else
        {
            temp2=t;
            t=t->right;
            if(t->left==NULL)
            {
                temp->left=t;
                t->left=temp2->left;
                free(temp2);
                return root;
            }
            else
            {
                while(t->left!=NULL)
                {
                    t=t->left;
                }
                d=t->data;
                root=delteBSTNode(root,d);
                temp2->data=d;

            }

        }
    }
    return root;
}
