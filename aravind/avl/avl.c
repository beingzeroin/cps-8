#include <stdlib.h>
#include "avl.h"
avlNode *createAVLNode (int data)
{
    avlNode *temp = malloc(sizeof(avlNode));
    temp->bf = 0;
    temp->height = 1;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
avlNode *insertAVL(avlNode *root, int data)
{
    if(root==NULL)
        return createAVLNode(data);
    if(data < root->data)
        root->left = insertAVL(root->left, data);
    else
        root->right = insertAVL(root->right, data);

    root->bf = height(root->left - height(root->right);

    if(bf>1)
    {

    }
    else if(bf<-1)
    {

    }

}
avlNode *deleteAVL(avlNode *root, int data);
avlNode *inorder(avlNode *root, int data);
int height (avlNode *node);
