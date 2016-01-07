#include "avl.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

AVLNode *createAVLNode(int data)
{
    AVLNode *n = malloc(sizeof(AVLNode));
    n->left = n->right = NULL;
    n->data = data;
    n->balanceFactor = 0;
    n->height = 1;
    return n;
}
int getHeight(AVLNode *r)
{
    if(r==NULL)
        return 0;
    return r->height;
}
int getBF(AVLNode *r)
{
    if(r==NULL)
        return 0;
    return r->balanceFactor;
}
AVLNode *insertAVL(AVLNode *root, int data)
{
    if(root==NULL)
        return createAVLNode(data);
    if(data < root->data)
        root->left = insertAVL(root->left, data);
    else
        root->right = insertAVL(root->right, data);

    root->height = 1 + MAX(getHeight(root->left), getHeight(root->right));
    root->balanceFactor = height(root->left) - height(root->right);

    if(root->balanceFactor<-11)
    {
        if(root->right->balanceFactor == -1)
            rotateleft(root);
        else
            rotateright(root->right);
            rotateleft(root);
    }
    else if(root->balanceFactor>1)
    {

    }
    return root;
}
AVLNode *searchAVL(AVLNode *root, int data)
{

    assert(false);
    return NULL;
}
AVLNode *deleteAVL(AVLNode *root, int data)
{
    assert(false);
    return NULL;
}
void inorderAVL(AVLNode *root)
{
    if(root)
    {
        inorderAVL(root->left);
        printf("%d (h: %d, bf: %d) ", root->data, getHeight(root), getBF(root));
        inorderAVL(root->right);
    }
}

AVLNode *createRandomAVLTree(int nodeCount)
{
    AVLNode *root = NULL;
    int i;
    for(i=1; i<=nodeCount; i++)
        root = insertAVL(root, rand());
    return root;
}
