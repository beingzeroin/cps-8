#include <stdio.h>
#include <cstdlib>
#include "BST.h"
#include<assert.h>
#include <queue>
using namespace std;

// Forward Declaration


int unitTests()
{
    BSTNode *root = NULL;
    root = insertBSTNode(root, 5);
    root = insertBSTNode(root, 3);
    root = insertBSTNode(root, 1);
    root = insertBSTNode(root, 4);

    root = insertBSTNode(root, 7);
    root = insertBSTNode(root, 6);
    root = insertBSTNode(root, 9);
    //assert(searchBSTNode(root,3)!=NULL);

    print_ascii_tree(root);

    // Delete Root
   /* root = rdeleteBSTNode(root, 5);
    print_ascii_tree(root);
    root = rdeleteBSTNode(root, 7);
    print_ascii_tree(root);
    root = deleteBSTNode(root, 3);
    print_ascii_tree(root);
    root = rdeleteBSTNode(root, 100);

    print_ascii_tree(root);
*/
    iterativePreOrder(root);
    printf("\n");
    iterativeInOrder(root);
    printf("\n");
    iterativePostOrder(root);


    return 0;
}


int main()
{
    BSTNode *r = createRandomBST(11, 100);
    print_ascii_tree(r);
    //iterativePreorder(r);
    //iterativeInorder(r);
    iterativePostrder(r);

    assert(hasSum(r, 292)==true);
    assert(hasSum(r, 67)==false);

    levelOrderSpiral(r);

    return 0;
}

