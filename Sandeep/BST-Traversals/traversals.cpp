#include <stack>
#include "BST.h"
#include<queue>
using namespace std;

void levelorder(BSTNode *r)
{
    BSTNode *t;
    queue<BSTNode*> myq;
    if(root==NULL)
        return ;
    else
    {
        myq.push(root);
        if(r->left!=NULL)
            myq.push(r->left);
        if(r->right!=NULL)
            myq.push(r->right);

    }
    if(myq.empty())
        return ;
    t=myq.front();
    myq.pop();
    printf("%d ",t->data);
    levelorder(myq.front());

}
