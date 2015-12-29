#include "BST.h"
#include <stdlib.h>

BSTNode *createBSTNode(ElementType data)
{
    BSTNode *temp = malloc(sizeof(BSTNode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

BSTNode *rinsertBSTNode(BSTNode *root, ElementType data)
{
    if(root==NULL)
        return createBSTNode(data);
    if(data < root->data)
    {
        root->left = rinsertBSTNode(root->left, data);
    }
    else
    {
        root->right = rinsertBSTNode(root->right, data);
    }
    return root;
}
BSTNode *last(BSTNode *root)
{
    while(1)
    {
        if(root->left!=NULL)
            root = root->left;
        else
            return root;
    }
}
BSTNode *insertBSTNode(BSTNode *root, ElementType data)
{
    BSTNode *node = createBSTNode(data);
    BSTNode *temp = root;
    if(root==NULL)
        return node;
    while(1)
    {
        if(data < root->data)
        {

            if(root->left==NULL)
            {
                root->left = node;
                return temp;
            }
            root = root->left;
        }
        else
        {

            if(root->right==NULL)
            {
                root->right = node;
                return temp;
            }
            root = root->right;
        }
    }

}
BSTNode *searchBSTNode(BSTNode *root, ElementType data)
{
    if(root==NULL||root->data==data)
        return root;
    if(data < root->data)
        return searchBSTNode(root->left,data);
    else
        return searchBSTNode(root->right,data);
}


BSTNode *deleteBSTNode(BSTNode *root, ElementType data)
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

bool isBST(BSTNode *h)
{
    if(h==NULL)
        return true;
    if(h->left == NULL&&h->right==NULL)
        return true;
    if(h->left == NULL && h->data < h->right)
        isBST(h->right);
    else
        return false;
    if(h->right == NULL && h->data > h->left)
        isBST(h->left);
    else
        return false;
    if(h->data>h->left->data && h->data<h->right->data)
    {
        return isBST(h->left) && isBST(h->right);
    }
    else
        return false;
}
int count(BSTNode *h)
{
    if(h==NULL)
        return 0;
    return 1+count(h->left)+count(h->right);
}
