#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include <assert.h>
int main()
{
    BSTNode *root = NULL;
    /*root = rinsertBSTNode(root, 5);

    root = rinsertBSTNode(root, 3);
    root = rinsertBSTNode(root, 1);
    root = rinsertBSTNode(root, 4);

    root = rinsertBSTNode(root, 7);
    root = rinsertBSTNode(root, 6);
    root = rinsertBSTNode(root, 9);*/

    root = insertBSTNode(root, 5);

    root = insertBSTNode(root, 3);
    root = insertBSTNode(root, 1);
    root = insertBSTNode(root, 4);

    root = insertBSTNode(root, 7);
    root = insertBSTNode(root, 6);
    root = insertBSTNode(root, 9);

        print_ascii_tree(root);
    printf("\n%d",root->data);
   // root = rinsertBSTNode(root, 10);
    printf("\n%d",root->data);
    print_ascii_tree(root);

    BSTNode *t=searchBSTNode(root,5);
    if(t==NULL)
        printf("\n data not found");
    else
        printf("\n data found is %d",t->data);
    // Delete Root
    root = delteBSTNode(root, 5);
    printf("\nAfter deletion");

    root = rinsertBSTNode(root, 7);
    root = rinsertBSTNode(root, 6);
    root = rinsertBSTNode(root, 9);
    print_ascii_tree(root);


    //BSTNode *t=searchBSTNode(root,10);
    // Delete Root
    // root = delteBSTNode(root, 5);


    return 0;
}
