#include <stack>
#include "BST.h"
#include<cstdlib>
#include<cstdio>
using namespace std;
void iterativeInorder(BSTNode *root)
{
    stack<BSTNode*> mystack;
    while(1)
    {
        while(root->left!=NULL)
        {

            mystack.push(root->left);
            root=root->left;
        }
        printf("%d",root->data);
        while(mystack.empty())
        {
            mystack.pop();
            printf("%d",mystack.top());
        }
        while(root->right!=NULL)
        {

            mystack.push(root->right);
            root=root->right;
        }
        printf("%d",root->data);
        while(mystack.empty())
        {

            printf("%d",mystack.top());
            mystack.pop();
        }

    }



}

void iterativePreorder(BSTNode *root)
{
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
        while(root!=NULL)
        {
            printf("%d \t",root->data);
            root=root->right;
        }
        if(mystack.empty())
                break;

    }


}



