#include <stack>
#include "BST.h"
#include<cstdlib>
#include<cstdio>
#include<queue>
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

            mystack.push(root); // It may push null
            root=root->left;
        }
        if(mystack.empty())
            break;
        root=mystack.top();
        printf("%d ",root->data);
        mystack.pop();

        root=root->right; // Begin the same steps with Root->right.
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
            printf("%d ",root->data);
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
void iterativelevelorder(BSTNode *root)
{
    queue<int> myqueue;
    BSTNode *temp=root->left;
    BSTNode *temp1=root->left;
    BSTNode *temp2=root->right;
    BSTNode *temp3=root->right;

    if(root==NULL)
        return;
    else
    {
       printf("%d",root->data);
       if(root->left!=NULL)
       {
            printf("%d",root->left->data);

            if(temp->left!=NULL)
                myqueue.push(temp->data);
            else if(temp1->right!=NULL)
                myqueue.push(temp1->data);
            else
                return;


       }
       if(root->right!=NULL)
       {
            printf("%d",root->right->data);

            if(temp2->left!=NULL)
                myqueue.push(temp->data);
            else if(temp3->right!=NULL)
                myqueue.push(temp1->data);
            else
                return;


       }
       while(myqueue.front()!=NULL)
        {
                printf("%d \t",myqueue.front());
                myqueue.pop();
        }
        iterativelevelorder(temp);
        iterativelevelorder(temp1);
        iterativelevelorder(temp2);
        iterativelevelorder(temp3);


    }

}



