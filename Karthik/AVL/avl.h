#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

typedef struct avlNode AVLNode;
struct avlNode
{
    int data;
    AVLNode *left;
    AVLNode *right;
    //int bf;
    int height;
};
AVLNode *createNode(int data);
AVLNode *insertAVL(AVLNode *root,int data);
void inorder(AVLNode *root);
#endif // AVL_H_INCLUDED
