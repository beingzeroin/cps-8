#include <stdio.h>
#include <cstdlib>
#include "BST.h"
#include<assert.h>

int unitTests()
{

    /*root = insertBSTNode(root, 5);
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
    root = rdeleteBSTNode(root, 100);*/


    return 0;
}

int main()
{
    BSTNode *root = createRandomBST(10,100);
    print_ascii_tree(root);
<<<<<<< HEAD
    //iterativePreorder(root);
    //iterativeInorder(root);
    iterativelevelorder(root);
=======
    iterativePreorder(root);
    //iterativeInorder(root);
>>>>>>> bf5bc6a76138e45f4e664e0f39b947f32f920989


    return 0;
}
