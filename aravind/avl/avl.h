#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

typedef struct avlnode avlNode;
struct avlnode
{
    int data;
    int bf;
    int height;
    avlNode *left, *right;
};

avlNode *createAVLNode (int data);
avlNode *insertAVL(avlNode *root, int data);
avlNode *deleteAVL(avlNode *root, int data);
avlNode *inorder(avlNode *root, int data);
int height (avlNode *node);

#endif // AVL_H_INCLUDED
