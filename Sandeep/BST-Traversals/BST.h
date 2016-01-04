#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include <stdbool.h>

typedef int ElementType;
typedef struct bstNode BSTNode;
struct bstNode
{
    ElementType data;
    BSTNode *left;
    BSTNode *right;
};



void levelorder(BSTNode *r);
BSTNode *createBSTNode(ElementType data);
BSTNode *createRandomBST(int nodeCount, int maxVal);
BSTNode *insertBSTNode(BSTNode *root, ElementType data);
BSTNode *rinsertBSTNode(BSTNode *root, ElementType data);
BSTNode *searchBSTNode(BSTNode *root, ElementType data);
BSTNode *deleteBSTNode(BSTNode *root, ElementType data);
BSTNode *rdeleteBSTNode(BSTNode *root,ElementType data);
void print_ascii_tree(BSTNode * t);
<<<<<<< HEAD
<<<<<<< HEAD
BSTNode *createRandomBST(int nodeCount, int maxVal);

void iterativePreOrder(BSTNode *r);
void RecursivePreOrder(BSTNode *r);
void iterativeInOrder(BSTNode *r);
void iterativePostOrder(BSTNode *r);

=======
<<<<<<< HEAD
void iterativePreorder(BSTNode *r);
void iterativeInorder(BSTNode *r)
=======
>>>>>>> 976743db0544a685597f1a1cf5ec5b09fd15ee2e

=======
>>>>>>> 0ca016ec24f51ba2268fe2a0d407019a5c3452ec
void iterativePreorder(BSTNode *r);
void recursivPreorder(BSTNode *r);
void iterativeInorder(BSTNode *r);
void iterativePostrder(BSTNode *r);
bool hasSum(BSTNode *r, int sum);
void levelOrderSpiral(BSTNode *r);

#endif // BST_H_INCLUDED
