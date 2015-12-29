#include "BST.h"
#include <stdlib.h>
#include<time.h>
#include<stdbool.h>

BSTNode *createBSTNode(ElementType data)
{
    BSTNode *b=malloc(sizeof(BSTNode));
    b->right=NULL;
    b->left=NULL;
    b->data=data;
   return b;
}

BSTNode *rinsertBSTNode(BSTNode *root, ElementType data)
{
    if(root==NULL)
        return createBSTNode(data);
    if(data<root->data)
    {

       root->left=rinsertBSTNode(root->left,data);
    }
    else
        root->right=rinsertBSTNode(root->right,data);
    return root;

}


    //return NULL;

BSTNode *searchBSTNode(BSTNode *root,ElementType data)
{
    BSTNode *temp=root;
    if(temp==NULL)
        return NULL;
    if(data<temp->data)
        return searchBSTNode(temp->left,data);
        else if(data>temp->data)
        return searchBSTNode(temp->right,data);
        else
        return temp;

}

BSTNode *insertBSTNode(BSTNode *root, ElementType data)
{
    BSTNode *temp=root;
    if(temp==NULL)
        return createBSTNode(data);

    while(1)
    {
        if(data>=temp->data)
        {

            if(temp->right==NULL)
            {


                temp->right=createBSTNode(data);
                return root;
            }
            temp=temp->right;
        }
        else if(data<temp->data)
        {

        if(temp->left==NULL)
        {

        temp->left=createBSTNode(data);
        return root;
        }
            temp=temp->left;

    }
    }
    //return root;
}
BSTNode *minofRightSubtree(BSTNode *root)
{
    while(root->left!=NULL)
        root=root->left;
    return root;

}
bool isBST(BSTNode *root)
{
    if(root==NULL)
    return true;
    if((root->left!=NULL&&root->left->data<root->data)&&root->data<root->right->data)
    {

    isBST(root->left);
     isBST(root->right);
     return true;
    }
    else
        return false;
}
BSTNode *createRandomTree(BSTNode *root,int n)
{
     srand(time(NULL));
    int i;
    ElementType d;
    for(i=1;i<=n;i++)
    {

        d=rand()%20;
        root=insertBSTNode(root,d);

    }
    return root;

}

BSTNode *delteBSTNode(BSTNode *root, ElementType data)
{
    if(root==NULL)
        return NULL;
    if(root->data==data)
    {
        if(root->left==NULL&&root->right==NULL)
            {
                free(root);
                return NULL;

            }
            else if(root->right==NULL&&root->left!=NULL)
            {

                BSTNode *temp= root->left;
            free(root);
            return temp;
            }
            else if(root->right!=NULL&&root->left==NULL)
            {
                BSTNode *temp=root->right;
                free(root);
                return temp;
            }
            else if(root->right!=NULL&&root->left!=NULL)
            {
                BSTNode *min=minofRightSubtree(root->right);
               // printf("\n%d",min->data);
                root->data=min->data;
               root->right=delteBSTNode(root->right,min->data);
                return root;
            }
           // return root;

    }

    else if(data<root->data)
        root->left=delteBSTNode(root->left,data);
        else
        root->right=delteBSTNode(root->right,data);
    return root;
}
