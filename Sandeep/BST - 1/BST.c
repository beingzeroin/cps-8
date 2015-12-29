#include "BST.h"
#include <stdlib.h>

BSTNode *createBSTNode(ElementType data)
{
<<<<<<< HEAD
<<<<<<< HEAD
   BSTNode *node=malloc(sizeof(BSTNode));
   node->data=data;
   node->left=NULL;
   node->right=NULL;
   return node;
=======
<<<<<<< HEAD
=======
>>>>>>> bf5bc6a76138e45f4e664e0f39b947f32f920989
<<<<<<< HEAD
    BSTNode *newNode=malloc(sizeof(BSTNode));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
=======
    return NULL;
>>>>>>> a7e39fa389f29ca80e4f80145d2b79261ecf40bd
=======
    BSTNode *t=malloc(sizeof(BSTNode));
    t->data=data;
    t->left=NULL;
    t->right=NULL;

    return t;
=======
    return NULL;
>>>>>>> fe043da394043d1e9fd8d5058ed0e4e03257dc63
>>>>>>> cc18206aa627d8a76700b20568b8271e4b17958e
<<<<<<< HEAD
>>>>>>> bf5bc6a76138e45f4e664e0f39b947f32f920989
=======
>>>>>>> bf5bc6a76138e45f4e664e0f39b947f32f920989
}

BSTNode *searchBSTNode(BSTNode *root,ElementType data)
{
<<<<<<< HEAD
<<<<<<< HEAD
    if(root==NULL)
        return createBSTNode(data);
    if(root->data>data)
        root->left = rinsertBSTNode(root->left,data);
    if(root->data<data)
=======
<<<<<<< HEAD
=======
>>>>>>> bf5bc6a76138e45f4e664e0f39b947f32f920989
    if(root==NULL || data==root->data)
        return root;
    if(data<root->data)
        return searchBSTNode(root->left,data);
    if(data>root->data)
        return searchBSTNode(root->right,data);
    return NULL;
=======
    if(root==NULL)
    {

        BSTNode *t=createBSTNode( data);

        return t;
    }
    else if(data>root->data)
    {


        if(root->right==NULL)
        {
            BSTNode *t=createBSTNode( data);
            root->right=t;
            return root;
        }
        root= rinsertBSTNode(root->right,data);
    }
    else
    {
        if(root->left==NULL)
        {
            BSTNode *t=createBSTNode( data);
            root->left=t;
            return root;
        }


        root= rinsertBSTNode(root->left,data);
    }


    return root;
>>>>>>> cc18206aa627d8a76700b20568b8271e4b17958e
}
BSTNode *rinsertBSTNode(BSTNode *root, ElementType data)
{
    if(root==NULL)
        return createBSTNode(data);
    if(data<root->data)
        root->left=rinsertBSTNode(root->left,data);
    if(data>root->data)
<<<<<<< HEAD
>>>>>>> bf5bc6a76138e45f4e664e0f39b947f32f920989
=======
>>>>>>> bf5bc6a76138e45f4e664e0f39b947f32f920989
        root->right=rinsertBSTNode(root->right,data);
    return root;
}

BSTNode *insertBSTNode(BSTNode *root, ElementType data)
{
<<<<<<< HEAD
<<<<<<< HEAD
    if(root==NULL)
        return createBSTNode(data);
        BSTNode *c=root;
    while(1)
    {
        if(c->data>data)
    {
        if(c->left==NULL)
        {
            c->left=createBSTNode(data);
            return root;
        }
        c=c->left;
    }
    if(c->data<data)
    {
        if(c->right==NULL)
        {
            c->right=createBSTNode(data);
            return root;
        }
        c=c->right;
    }
    }
    return NULL;
=======
<<<<<<< HEAD
=======
>>>>>>> bf5bc6a76138e45f4e664e0f39b947f32f920989
    BSTNode *newNode=createBSTNode(data);
    if(root==NULL)
        return newNode;
    BSTNode *temp=root,*prev=NULL;
    while(temp!=NULL)
    {
        if(data==temp->data)
            return root;
        if(data<temp->data)
        {
            prev=temp;
            temp=temp->left;
        }
        else
        {
            prev=temp;
            temp=temp->right;
        }
    }
    if(data<prev->data)
        prev->left=newNode;
    if(data>prev->data)
        prev->right=newNode;
=======
    BSTNode *temp=NULL,*t=createBSTNode(data),*root2=root;
    if(root==NULL)

        return t;
    else
        while(root!=NULL)
        {
            temp=root;
            if(data>root->data)
                root=root->right;
            else
                root=root->left;

        }
    if(data>temp->data)
    {
        temp->right=t;

    }
    else
        temp->left=t;

    return root2;

}
BSTNode *searchBSTNode(BSTNode *root, ElementType data)
{
    while(root!=NULL)
    {
        if(data==root->data)
            return root;
        else if(data>root->data)
            root=root->right;
        else
            root=root->left;
    }
>>>>>>> cc18206aa627d8a76700b20568b8271e4b17958e
    return root;
<<<<<<< HEAD
>>>>>>> bf5bc6a76138e45f4e664e0f39b947f32f920989
=======
>>>>>>> bf5bc6a76138e45f4e664e0f39b947f32f920989
}

BSTNode *searchBSTNode(BSTNode *root,ElementType data)
{
<<<<<<< HEAD
<<<<<<< HEAD
        if(root==NULL)
            return NULL;
        if(root->data==data)
            return root;
        if(root->data>data)
            return searchBSTNode(root->left,data);
        if(root->data<data)
            return searchBSTNode(root->right,data);
            return NULL;
}
ElementType min(BSTNode *n)
{
    while(n->left!=NULL)
        n=n->left;
    return n->data;
}
BSTNode *rdeleteBSTNode(BSTNode *root,ElementType data)
{
    if(root->data == data)
    {
        if(root->left == NULL && root->right == NULL)
=======
<<<<<<< HEAD
=======
>>>>>>> bf5bc6a76138e45f4e664e0f39b947f32f920989
    if(root==NULL)
        return root;
    if(data<root->data)
        root->left=delteBSTNode(root->left,data);
    else if(data>root->data)
        root->right=delteBSTNode(root->right,data);
    else if(data==root->data)
    {
        if(root->left==NULL && root->right!=NULL)
        {
            BSTNode *temp=root->right;
            //root->right==NULL;
            free(root);
            return temp;
        }
        else if(root->left!=NULL && root->right==NULL)
        {
            BSTNode *temp=root->left;
            //root->left==NULL;
            free(root);
            return temp;
        }
        else if(root->left!=NULL)
        {
            BSTNode *temp=root->left;
            while(temp->right!=NULL)
                temp=temp->right;
            root->data=temp->data;
            return delteBSTNode(root->left,temp->data);
        }
        else if(root->right==NULL && root->left==NULL)
        {
            free(root);
            return NULL;
=======
    BSTNode *t=root,*temp=NULL,*temp2;
    ElementType d;
    if(t==NULL)
        return NULL;
    while(t!=NULL)
    {

        if(data==t->data)
            break;
        else if(data>t->data)
        {
            temp=t;
            t=t->right;
        }
        else
        {
            temp=t;
            t=t->left;
        }
    }
    if(t==root)
    {
        if(temp==NULL)
<<<<<<< HEAD
>>>>>>> bf5bc6a76138e45f4e664e0f39b947f32f920989
=======
>>>>>>> bf5bc6a76138e45f4e664e0f39b947f32f920989
        {
            free(root);
            return NULL;
        }
<<<<<<< HEAD
<<<<<<< HEAD
        else if(root->left!=NULL && root->right!=NULL)
        {
            BSTNode *c= root->right;
            while(c->left!=NULL)
                c=c->left;
            root->data = c->data;
            root->right = deleteBSTNode(root->right,c->data);


        }
        else
        {

            if(root->left!=NULL)
            {
                BSTNode *c;

                c = root->left;
                free(root);
                return c;
            }
            else
            {
                BSTNode *c;
                c = root->right;
                free(root);
                return c;
            }
        }
    }
    else if(data <root->data)
        root->left = deleteBSTNode(root->left, data);
    else
        root->right = deleteBSTNode(root->right, data);

=======
=======
>>>>>>> bf5bc6a76138e45f4e664e0f39b947f32f920989
    }
    if(t->left==NULL&&t->right==NULL)
    {
        if(temp->left==t)
        {
            free(t);
            temp->left=NULL;
            return root;
        }
        else
        {
            free(t);
            temp->right=NULL;
            return root;
        }
    }
    else if(t->left!=NULL&&t->right==NULL)
    {
        if(temp->left==t)
        {
            temp->left=t->left;
            free(t);
            return root;
        }
    }
    else
    {

        if(temp->left==t)
        {
            temp2=t;
            t=t->right;
            if(t->left==NULL)
            {
                temp->left=t;
                t->left=temp2->left;
                free(temp2);
                return root;
            }
            else
            {
                while(t->left!=NULL)
                {
                    t=t->left;
                }
                d=t->data;
                root=delteBSTNode(root,d);
                temp2->data=d;
                return root;

            }
        }
        else
        {
            temp2=t;
            t=t->right;
            if(t->left==NULL)
            {
                temp->left=t;
                t->left=temp2->left;
                free(temp2);
                return root;
            }
            else
            {
                while(t->left!=NULL)
                {
                    t=t->left;
                }
                d=t->data;
                root=delteBSTNode(root,d);
                temp2->data=d;

            }

>>>>>>> cc18206aa627d8a76700b20568b8271e4b17958e
        }
    }
<<<<<<< HEAD
>>>>>>> bf5bc6a76138e45f4e664e0f39b947f32f920989
=======
>>>>>>> bf5bc6a76138e45f4e664e0f39b947f32f920989
    return root;
}
