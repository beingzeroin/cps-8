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
BSTNode *createRandomBST(int nodeCount, int maxVal);
BSTNode *insertBSTNode(BSTNode *root, ElementType data);
BSTNode *rinsertBSTNode(BSTNode *root, ElementType data);
BSTNode *searchBSTNode(BSTNode *root, ElementType data);
BSTNode *deleteBSTNode(BSTNode *root, ElementType data);
BSTNode *rdeleteBSTNode(BSTNode *root,ElementType data);
void print_ascii_tree(BSTNode * t);
<<<<<<< HEAD
void iterativePreorder(BSTNode *r);
void iterativeInorder(BSTNode *r)
=======

void iterativePreorder(BSTNode *r);
void recursivPreorder(BSTNode *r);
void iterativeInorder(BSTNode *r);
void iterativePostrder(BSTNode *r);

>>>>>>> fe043da394043d1e9fd8d5058ed0e4e03257dc63
#endif // BST_H_INCLUDED
