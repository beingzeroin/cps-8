#include "avl.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

AVLNode *createAVLNode(int data)
{
    AVLNode *n = malloc(sizeof(AVLNode));
    n->left =NULL;
     n->right = NULL;
    n->data = data;
    n->balanceFactor = 0;
    n->height=1;
    return n;
}

void rotateLeft(AVLNode *root)
{
    AVLNode *n=createAVLNode(root->data);
    root->data=root->right->data;
    n->left=root->left;
    n->right=root->right->left;
root->height=1+MAX(getHeight(root->right),getHeight(root->left));
    AVLNode *c=root->right;
    root->left=n;
    root->right=c->right;
root->height=1+MAX(getHeight(root->right),getHeight(root->left));
    free(c);

}
void rotateRight(AVLNode *root)
{
    AVLNode *n=createAVLNode(root->data);
    root->data=root->left->data;
    n->right=root->right;
    n->left=root->left->right;
    root->height=1+MAX(getHeight(root->right),getHeight(root->left));
    AVLNode *c=root->left;
    root->right=n;
    root->left=c->right;
    root->height=1+MAX(getHeight(root->right),getHeight(root->left));
    free(c);

}
int getHeight(AVLNode *root)
{
    if(root==NULL)
        return 0;
    return root->height;
}
AVLNode *insertAVL(AVLNode *root, int data)
{
    if(root==NULL)
        return createAVLNode(data);
    if(data<root->data)
        root->left=insertAVL(root->left,data);
    else
        root->right=insertAVL(root->right,data);
        root->height=1+MAX(getHeight(root->right),getHeight(root->left));
        root->balanceFactor=getHeight(root->left)-getHeight(root->right);
        if(root->balanceFactor<-1)
        {
            if(root->right->balanceFactor==-1)
            {
               // printf("\nleft rotation");
             rotateLeft(root);

            }
            else
            {
                rotateRight(root->right);
                rotateLeft(root);
            }

        }
        else if(root->balanceFactor>1)
        {
            if(root->left->balanceFactor==1)
            {

                rotateRight(root);
            }
            else
                {
                rotateLeft(root->left);
                rotateRight(root);
            }
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
    if(root==NULL)
        return;
    inorderAVL(root->left);
    printf("%d (%d:%d) ",root->data,root->height,root->balanceFactor);
    inorderAVL(root->right);
   // assert(false);
 }

AVLNode *createRandomAVLTree(int nodeCount)
{
    AVLNode *root = NULL;
    int i;
    for(i=1;i<=nodeCount;i++)
        root = insertAVL(root, rand());
    return root;
}
