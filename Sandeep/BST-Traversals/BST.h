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



void levelorder(BSTNode *r);
BSTNode *createBSTNode(ElementType data);
BSTNode *insertBSTNode(BSTNode *root, ElementType data);
BSTNode *rinsertBSTNode(BSTNode *root, ElementType data);
BSTNode *searchBSTNode(BSTNode *root, ElementType data);
BSTNode *deleteBSTNode(BSTNode *root, ElementType data);
BSTNode *rdeleteBSTNode(BSTNode *root,ElementType data);
void print_ascii_tree(BSTNode * t);
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

void iterativePreorder(BSTNode *r);
void recursivPreorder(BSTNode *r);

>>>>>>> fe043da394043d1e9fd8d5058ed0e4e03257dc63
#endif // BST_H_INCLUDED
