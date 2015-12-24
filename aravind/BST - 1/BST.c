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
    return NULL;
}

BSTNode *insertBSTNode(BSTNode *root, ElementType data)
{
    BSTNode *node = createBSTNode(data);
    BSTNode *temp = root;
    if(root==NULL)
        return node;
    while(root->left != NULL||root->right != NULL)
    {
        if(root->data>data)
            root = root->left;
        else
            root = root->right;
    }

    if(root->data>data)
        root->left = node;
    else
        root->right = node;

    return temp;
}

BSTNode *delteBSTNode(BSTNode *root, ElementType data)
{
    return NULL;
}
