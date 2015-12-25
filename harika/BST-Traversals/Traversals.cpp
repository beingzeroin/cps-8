#include <stack>
#include "BST.h"
#include<cstdlib>
#include<cstdio>
using namespace std;
void iterativeInorder(BSTNode *root)
{
    if(root==NULL)
        return;
    stack<BSTNode*> mystack;
    while(1)
    {
        while(root!=NULL)
        {

            mystack.push(root->left);
            root=root->left;
        }
        if(mystack.empty())
            break;
        root=mystack.top();
        printf("%d",root->data);
        mystack.pop();
        root=root->right;
    }



}

void iterativePreorder(BSTNode *root)
{
    if(root==NULL)
        return;
    stack<BSTNode*> mystack;
    while(1)
    {
        while(root!=NULL)
        {
            printf("%d \t",root->data);
            mystack.push(root);
            root=root->left;
        }
        if(mystack.empty())
            break;
        root=mystack.top();
        mystack.pop();
        root=root->right;
       /* while(root!=NULL)
        {
            printf("%d \t",root->data);
            root=root->right;
        }
        if(mystack.empty())
                break;*/

    }


}



