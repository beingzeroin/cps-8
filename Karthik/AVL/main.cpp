#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
int main()
{
    //cout << "Hello world!" << endl;
    //return 0;
    AVLNode *root=NULL;
    root=insertAVL(root,5);
    root=insertAVL(root,1);
    root=insertAVL(root,2);
    root=insertAVL(root,10);
    root=insertAVL(root,8);
//    prettyPrintAVL(root);
    inorder(root);
}
