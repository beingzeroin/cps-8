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
<<<<<<< HEAD
    root = rinsertBSTNode(root, 5);

    root = rinsertBSTNode(root, 3);
    root = rinsertBSTNode(root, 1);
    root = rinsertBSTNode(root, 4);
=======
    BSTNode *t=searchBSTNode(root,5);
    if(t==NULL)
        printf("\n data not found");
    else
        printf("\n data found is %d",t->data);
    // Delete Root
<<<<<<< HEAD

=======
    root = delteBSTNode(root, 5);
    printf("\nAfter deletion");
>>>>>>> cc18206aa627d8a76700b20568b8271e4b17958e
>>>>>>> bf5bc6a76138e45f4e664e0f39b947f32f920989

    root = rinsertBSTNode(root, 7);
    root = rinsertBSTNode(root, 6);
    root = rinsertBSTNode(root, 9);
    print_ascii_tree(root);

<<<<<<< HEAD
    BSTNode *temp=searchBSTNode(root,3);
    assert(temp!=NULL&&temp->data==3);
    if(temp==NULL)
    {

    }
    else
        printf("%d",temp->data);

        root = rdelteBSTNode(root, 5);
        print_ascii_tree(root);
=======
    //BSTNode *t=searchBSTNode(root,10);
    // Delete Root
    // root = delteBSTNode(root, 5);

>>>>>>> bf5bc6a76138e45f4e664e0f39b947f32f920989


    return 0;
}
