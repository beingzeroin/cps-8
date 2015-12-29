#include "BST.h"
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include "myList.h"

using namespace std;

void iterativePreorder(BSTNode *root){
    stack<BSTNode*> myStack;
    while(true){
        while(root != NULL){
            printf("%d ",root->data);
            myStack.push(root);
            root = root->left;
        }
        if(myStack.empty())
            break;
        root = myStack.top();
        myStack.pop();
        root = root->right;
    }
}
void iterativePostorder(BSTNode *root){
    stack<BSTNode*> myStack;
    BSTNode *parent, *rightChild;
    while(true){
        while(root != NULL){
            if(root->right != NULL)
                myStack.push(root->right);
            myStack.push(root);
            root = root->left;
        }
        parent = myStack.top();
        myStack.pop();
        if(myStack.empty()){
            printf("%d ",parent->data);
            break;
        }
        rightChild = myStack.top();
        myStack.pop();
        if(parent->right == rightChild){

        }
        else{

        }
    }
}
void iterativeInorder(BSTNode *root){
    stack<BSTNode*> myStack;
    while(true){
        while(root != NULL){
            myStack.push(root);
            root = root->left;
        }
        if(myStack.empty())
            break;
        root = myStack.top();
        printf("%d ",root->data);
        myStack.pop();
        root = root->right;
    }
}
void recursivePreorder(BSTNode *root){
    if(root!=NULL){
        printf("%d ",root->data);
        recursivePreorder(root->left);
        recursivePreorder(root->right);
    }
}
void recursivePostorder(BSTNode *root){
    if(root!=NULL){
        recursivePostorder(root->left);
        recursivePostorder(root->right);
        printf("%d ",root->data);
    }
}
void recursiveInorder(BSTNode *root){
    if(root!=NULL){
        recursiveInorder(root->left);
        printf("%d ",root->data);
        recursiveInorder(root->right);
    }
}
void levelOrder(BSTNode *root){
    queue<BSTNode*> myQueue;
    if(root == NULL)
        return;
    myQueue.push(root);
    while(true){
        root = myQueue.front();
        printf("%d ",root->data);
        myQueue.pop();
        if(root->left != NULL)
            myQueue.push(root->left);
        if(root->right != NULL)
            myQueue.push(root->right);
        if(myQueue.empty())
            break;
    }
}
void spiralLevelOrder(BSTNode *root){
    if(root == NULL)
        return;
    node *myList = NULL;
    myList = insertInEnding(myList,root);
    bool leftToRight = true;
    while(true){
        if(leftToRight){
            traverse(myList);
            leftToRight = false;
        }
        else{
            printReverseList(myList);
            leftToRight = true;
        }
        int temp = countNodes(myList);
        while(temp != 0){
            root = myList->data;
            myList = myList->next;
            if(root->left != NULL)
                myList = insertInEnding(myList,root->left);
            if(root->right != NULL)
                myList = insertInEnding(myList,root->right);
            temp--;
        }
        if(myList == NULL)
            break;
    }
}
