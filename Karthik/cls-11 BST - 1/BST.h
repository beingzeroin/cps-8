#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

typedef int ElementType;
typedef struct bstNode BSTNode;
struct bstNode
{
    ElementType data;
    BSTNode *left;
    BSTNode *right;
};

BSTNode *createBSTNode(ElementType data);
BSTNode *insertBSTNode(BSTNode *root, ElementType data);
BSTNode *rinsertBSTNode(BSTNode *root, ElementType data);
BSTNode *searchBSTNode(BSTNode *root, ElementType data);
<<<<<<< HEAD
BSTNode *deleteBSTNode(BSTNode *root, ElementType data);
=======
BSTNode *delteBSTNode(BSTNode *root, ElementType data);
BSTNode *delteBSTNode2(BSTNode *root, ElementType data);
>>>>>>> 0ca016ec24f51ba2268fe2a0d407019a5c3452ec


#endif // BST_H_INCLUDED
