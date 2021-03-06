#include "BST.h"
#include <stdlib.h>
#include <assert.h>

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

BSTNode *createRandomBST(int nodeCount, int maxVal)
{
    int i;
    BSTNode *r = NULL;
<<<<<<< HEAD
    for(i=0;i<=nodeCount;i++)
=======
    for(i=1; i<=nodeCount; i++)
>>>>>>> 0ca016ec24f51ba2268fe2a0d407019a5c3452ec
        r = insertBSTNode(r, rand()%maxVal);
    return r;
}

ElementType min(BSTNode *n)
{
    while(n->left!=NULL)
        n=n->left;
    /*if(n->left==NULL)
        return n->data;
    else
        n=n->left;*/
    return n->data;

}

BSTNode *rdeleteBSTNode(BSTNode *root,ElementType data)
{
    if(root==NULL)
        return root;

    if(root->data==data)
    {
        // 1. leaf node
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }

        //2. left or right child
        else if(root->left==NULL || root->right==NULL)
        {
            if(root->left==NULL)
                return root->right;
            else if(root->right==NULL)
                return root->left;
        }

        //3. has both children
        else
        {
            root->data=min(root->right);
            root->right=rdeleteBSTNode(root->right,root->data);

        }
    }
    else if(data < root->data)
        root->left=rdeleteBSTNode(root->left,data);
    else
        root->right=rdeleteBSTNode(root->right,data);
    return root;
}

BSTNode *deleteBSTNode(BSTNode *root, ElementType data)
{
    BSTNode *c;
    //BSTNode *temp=root;
    if(root==NULL)
        return root;
    else if(data<root->data)
        root->left = deleteBSTNode(root->left,data);
    else if(data>root->data)
        root->right = deleteBSTNode(root->right,data);
    else
    {
        if(root->left==NULL)//one right child
        {
            c=root->right;
            free(root);
            return c;
        }
        else if(root->right==NULL)//one left child
        {
            c=root->left;
            free(root);
            return c;
        }
        else                    //two children
        {
            c=root->right;      //right subtree
            while(c->left!=NULL)
                c=c->left;
            root->data=c->data;

            // Delete c->data
            root->right = deleteBSTNode(root->right, c->data);
        }
    }

    return root;
}

BSTNode *searchBSTNode(BSTNode *root, ElementType data)
{
    BSTNode *temp=(BSTNode*)malloc(sizeof(BSTNode));
    temp=root;
    if(temp==NULL||temp->data==data)
        return temp;
    else if(root->data==data)
        return temp;
    else if(root->data>data)
        return searchBSTNode(root->left,data);
    else
        return searchBSTNode(root->right,data);
}
bool isLeaf(BSTNode *r)
{
    if(r==NULL)
        return false;
    return r->left==NULL && r->right==NULL;
}

bool hasSum(BSTNode *r, int sum)
{
    /*
    assert(r!=NULL);
    if(isLeaf(r))
        return sum==r->data;

    int diff = sum - r->data;
    return (hasSum(r->left, diff) || hasSum(r->right, diff));
    */

    assert(r!=NULL);
    if(r->data == sum && r->left==NULL && r->right==NULL)
        return true;

    if(r->left)
    {
        bool lHasSum = hasSum(r->left, sum - r->data);
        if(lHasSum)
            return true;
    }
    if(r->right)
    {
        bool rHasSum = hasSum(r->right, sum - r->data);
        if(rHasSum)
            return true;
    }
    return false;
}
