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
BSTNode *deleteBSTNode(BSTNode *root, ElementType data);
BSTNode *rdeleteBSTNode(BSTNode *root,ElementType data);
BSTNode *createRandomBST(int nodeCount, int maxVal);
bool isBST(BSTNode *h);
void print_ascii_tree(BSTNode *t);
bool hasSum(BSTNode *r,int sum);


void iterativePreorder(BSTNode *r);
void iterativeInorder(BSTNode *r);
void iterativePostorder(BSTNode *r);
void levelOrderTraversal(BSTNode *r);
void rlevelOrderTraversal(BSTNode *r);
void recursivPreorder(BSTNode *r);

#endif // BST_H_INCLUDED
