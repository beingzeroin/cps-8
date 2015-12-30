#include <stack>
#include "BST.h"
#include <cstdlib>
#include <cstdio>
#include <queue>

using namespace std;

void levelOrderSpiral(BSTNode *r)
{
    printf("\nSPIRAL : ");
    if(r==NULL)
        return ;
    queue<BSTNode *> q;

    q.push(r);
    q.push(NULL);
    bool rtl = true;
    BSTNode *c ;
    while(!q.empty())
    {
        c = q.front();
        q.pop();
        if(c==NULL)
        {
            rtl = !rtl;
            q.push(NULL);
        }
        else
        {
            printf("%d ", c->data);
            if(rtl)
            {
                if(c->right)
                    q.push(c->right);
                if(c->left)
                    q.push(c->left);
            }
            else
            {
                 if(c->left)
                    q.push(c->left);
                 if(c->right)
                    q.push(c->right);
            }
        }
    }
}


void iterativeInorder(BSTNode *r)
{

    stack<BSTNode*> mystack;
    while(1)
    {
        while(r!=NULL)
        {
            /*            if(r->right!=NULL)
                            mystack.push(r->right);
                            */
            mystack.push(r);
            r= r->left;

        }
        if(mystack.empty())
            break;
        r = mystack.top();
        printf(" %d",r->data);
        mystack.pop();


        r = r->right;
    }

}
void iterativePostrder(BSTNode *r)
{
    stack<BSTNode*> mystack;
    BSTNode *p, *rc;
    while(1)
    {
        while(r!=NULL)
        {
            if(r->right!=NULL)
                mystack.push(r->right);

            mystack.push(r);
            r = r->left;
        }

        if(mystack.empty())
            break;
        p = mystack.top();
        mystack.pop();

        if(mystack.empty())
        {
            printf("%d ", p->data);
            break;
        }
        rc = mystack.top();
        mystack.pop();


        if(rc == p->right)
        {
            mystack.push(p);
            r = rc;
        }
        else
        {
            printf("%d ", p->data);
            mystack.push(rc);
            r = NULL; // IMPORTANT THING
        }
    }
}
void iterativePreorder(BSTNode *r)
{
    stack<BSTNode*> mystack;
<<<<<<< HEAD
     Stack *s=createStack();
     while(1)
     {
         while(r!=NULL)
         {

             printf("%d",r->data);
             mystack.push(r);
             r=r->left;
         }
         if(myStack.empty())
            break;
         r=myStack.top();
         myStack.pop();
         r=r->right;
     }

}
void iterativeInorder(BSTNode *r)
{
    stack<BSTNode*> mystack;
    Stack *s=createStack();
    while(1)
    {
       while(r!=NULL)
       {
        mystack.push(r);


       }

    }


=======
//    stack *s=createstack;

    while(1)
    {
        while(r!=NULL)
        {
            printf("%d ", r->data);
            mystack.push(r);
            r = r->left;
        }
>>>>>>> bf5bc6a76138e45f4e664e0f39b947f32f920989

        if(mystack.empty())
            break;
        r = mystack.top();
        mystack.pop();

        r = r->right;

        if(mystack.empty())
            break;
        r=mystack.top();
        mystack.pop();
    }

}

