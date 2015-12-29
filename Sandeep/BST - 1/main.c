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

    // Delete Root


    print_ascii_tree(root);

    BSTNode *temp=searchBSTNode(root,3);
    assert(temp!=NULL&&temp->data==3);
    if(temp==NULL)
    {

    }
    else
        printf("%d",temp->data);

        root = rdelteBSTNode(root, 5);
        print_ascii_tree(root);


    return 0;
}
