#include <stdio.h>
#include <cstdlib>
#include "BST.h"
#include<assert.h>

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
    root = rdeleteBSTNode(root, 5);
    print_ascii_tree(root);
    root = rdeleteBSTNode(root, 7);
    print_ascii_tree(root);
    root = deleteBSTNode(root, 3);
    print_ascii_tree(root);
    root = rdeleteBSTNode(root, 100);

    print_ascii_tree(root);

    return 0;
}
<<<<<<< HEAD
int main()
{
    BSTNode *r=NULL;
    r=insertBSTNode(r,5);
    r=insertBSTNode(r,6);
    r=insertBSTNode(r,4);
    r=insertBSTNode(r,9);
    r=insertBSTNode(r,7);
    print_ascii_tree(r);
   // iterativePreorder(r);
    iterativeInorder(r);
return 0;

=======

int main()
{
    BSTNode *r = createRandomBST(11, 100);
    print_ascii_tree(r);
    //iterativePreorder(r);
    //iterativeInorder(r);
    iterativePostrder(r);
    return 0;
>>>>>>> fe043da394043d1e9fd8d5058ed0e4e03257dc63
}
