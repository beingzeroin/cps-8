#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

typedef struct avlNode AVLNode;
struct avlNode
{
	int data;
	AVLNode *left, *right;
	int balanceFactor;
	int height;
};

AVLNode *createAVLNode(int data);
AVLNode *insertAVL(AVLNode *root, int data);
AVLNode *searchAVL(AVLNode *root, int data);
AVLNode *deleteAVL(AVLNode *root, int data);
void inorderAVL(AVLNode *root);

AVLNode *createRandomAVLTree(int nodeCount);
void prettyPrintAVL(AVLNode *root);


#endif // AVL_H_INCLUDED
