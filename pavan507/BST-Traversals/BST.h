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
int height(BSTNode *r);
BSTNode *minNode(BSTNode *r);
 bool isBST(BSTNode *r);
 void printGivenLevel(BSTNode *r,int level);
 void printLevelOrder(BSTNode *r);
 void printSpiralLevel(BSTNode *r,int level,int flag);
void spiralOrderTraversal(BSTNode *r);
void printSpiralOrder(BSTNode *r);
int nodeCount(BSTNode *r);
BSTNode *createBSTNode(ElementType data);
BSTNode *insertBSTNode(BSTNode *root, ElementType data);
BSTNode *rinsertBSTNode(BSTNode *root, ElementType data);
BSTNode *searchBSTNode(BSTNode *root, ElementType data);
BSTNode *deleteBSTNode(BSTNode *root, ElementType data);
BSTNode *rdeleteBSTNode(BSTNode *root,ElementType data);
void print_ascii_tree(BSTNode * t);
void iterativeInorder(BSTNode *r);
void recursiveInorder(BSTNode* r);
void levelOrderTraversal(BSTNode *r);
void iterativePostorder(BSTNode *r);
void iterativePreorder(BSTNode *r);
void recursivPreorder(BSTNode *r);
void printPath(BSTNode *r);
void printRecursively(BSTNode *r,int path[],int pathlen);
void printPathArray(int path[],int pathlen);
bool hasSum(BSTNode *r,int sum);
void iterativePreorder(BSTNode *r);


#endif // BST_H_INCLUDED