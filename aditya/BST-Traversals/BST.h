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
BSTNode* createRandomTree(BSTNode *root,int n);
void print_ascii_tree(BSTNode * t);
void iterativePreorder(BSTNode *root);
void iterativePostorder(BSTNode *root);
void iterativeInorder(BSTNode *root);
void recursivePreorder(BSTNode *root);
void recursivePostorder(BSTNode *root);
void recursiveInorder(BSTNode *root);
void levelOrder(BSTNode *root);
void spiralLevelOrder(BSTNode *root);

#endif // BST_H_INCLUDED
