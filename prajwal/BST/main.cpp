#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include<time.h>
typedef int elementtype;
typedef struct bstnode bst;
struct bstnode
{
    elementtype data;
    bst *left;
    bst *right;
};
void spiralorder(bst *node,int level,int i);
void levelorder(bst *node,int level);

bst *createnode(elementtype data)
{
    bst *n=(struct bstnode*)malloc(sizeof(struct bstnode));
    n->data =data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
bst *rinsertnode(bst *rt,elementtype data)
{
    bst *n,*t;
    if(rt==NULL)
    {
        n=createnode(data);
        //root=n;
        return n;
    }
    if(rt==NULL)
    {
        n=createnode(data);

        //SANDEEP: t isn't initialized ... How are you using it?
        if(t->data>data)
        {
            //printf(" %d %d",n->data,t->data);
            t->left=n;
        }

        else if(t->data <data)
        {
            //printf("%d %d",n->data,t->data);
            t->right=n;
        }
    }

    else if(rt->data>data)
    {
        t=rt;
        rt->left = rinsertnode(rt->left,data);
    }
    else if(rt->data<data)
    {
        t=rt;
        rt->right = rinsertnode(rt->right,data);
    }


    return rt;
}
bst *dltnode(bst *rt,elementtype data)
{
    bst *t;
    if(rt==NULL)
        return NULL;
    if(rt->data==data)
    {
        printf("\n %d\n",rt->data);
        if(rt->left==NULL && rt->right==NULL)
        {
            if(t->data > rt->data)
                t->left=NULL;
            else
                t->right=NULL;
            free(rt);
        }
        if(rt->left==NULL && rt->right!=NULL)
        {
            if(t->data > rt->data)
            {
                t->left=rt->right;
            }
            else if(t->data <rt->data)
            {
                t->right=rt->right;
            }
            free(rt);
        }
        if(rt->left!=NULL && rt->right==NULL)
        {


            if(t->data > rt->data)
            {
                t->left=rt->left;
            }
            else if(t->data <rt->data)
            {
                t->right=rt->left;
            }
            free(rt);
        }
        if(rt->left!=NULL && rt->right!=NULL)
        {
            bst *temp,*prev=NULL;
            temp=rt->right;
            while(temp->left!=NULL)
            {
                prev=temp;
                temp=temp->left;
            }
            if(prev==NULL)
            {
                if(temp->right!=NULL)
                {
                    rt->right=temp->right;
                }
                else
                {
                    rt->right=NULL;
                }
            }
            //printf("%d",temp->data);
            rt->data=temp->data;
            if(temp->right==NULL)
            {
                prev->left=NULL;
            }
            else if(temp->right!=NULL)
            {
                prev->left=temp->right;
            }
            if(rt->data==data)
            {
                rt=temp;
                return rt;
            }
            free(rt);
        }
    }

    else if(rt->data>data)
    {
        t=rt;
        rt->left= dltnode(rt->left,data);
    }
    else if(rt->data<data)
    {
        t=rt;
        rt->right = dltnode(rt->right,data);
    }

    return rt;
}
void preorder(bst *root)
{
    if(root==NULL)
        return;
    else
    {

        printf(" %d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(bst *root)
{
    if(root==NULL)
        return;
    else
    {
        inorder(root->left);
        printf(" %d ",root->data);
        inorder(root->right);
    }
}
void postorder(bst *root)
{
    if(root==NULL)
        return;
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d ",root->data);
    }
}
int height(bst *rt)
{
    int lheight,rheight;
    if(rt==NULL)
        return 0;
    else
    {
        lheight=height(rt->left);
        rheight=height(rt->right);
        if(lheight>=rheight)
            return (1+lheight);
        else
            return (1+rheight);
    }
}
void printlevelorder(bst *rt)
{
    int i,n;
    int h=height(rt);
    printf("1=level order 2=spiral order\n");
    scanf("%d",&n);
    if(rt==NULL)
        return;
    else
        for(i=1; i<=h; i++)
        {
            if(n==1)
                levelorder(rt,i);
            else
                spiralorder(rt,i,i);
        }
}
void levelorder(bst *rt,int level)
{
    if(rt==NULL)
        return;
    else if(level==1)
        printf("%d ",rt->data);
    else
    {
        levelorder(rt->left,level-1);
        levelorder(rt->right,level-1);
    }
}
void spiralorder(bst *rt,int level,int i)
{
    if(rt==NULL)
        return;
    else if(level==1)
        printf("%d ",rt->data);
    else
    {
        if((i%2)!=0)
        {
            spiralorder(rt->left,level-1,i);
            spiralorder(rt->right,level-1,i);
        }
        else
        {
            spiralorder(rt->right,level-1,i);
            spiralorder(rt->left,level-1,i);
        }
    }
}
int max(bst *rt)
{
    bst *temp=rt;
    if(temp==NULL || temp->left==NULL)
        return 0;
    while(temp->right!=NULL)
    {
        temp=temp->right;
        printf("%d ",temp->data);
    }
    return temp->data;
}
int min(bst *rt)
{
    bst *temp=rt;
    if(temp==NULL || temp->left==NULL)
        return 0;
    while(temp->left!=NULL)
    {
        temp=temp->left;
        printf("\n%d ",temp->data);
    }

    return temp->data;
}
int bstcheck(bst *rt)
{
    if(rt==NULL)
        return 1;
    else if(rt->left!=NULL && max(rt->left)>rt->data)
        return 0;
    else if(rt->right!=NULL && min(rt->right)<rt->data)
        return 0;
    if((!(bstcheck(rt->left)))|| (!(bstcheck(rt->right))))
        return 0;
    return 1;
}
int count(bst *rt)
{
    if(rt==NULL)
        return 0;
    else
        return 1+count(rt->left)+count(rt->right);
}
bst *randominsertnodes(bst *root,int max)
{
    int n,i;
    srand(time(NULL));
    printf("no of nodes :");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        root=rinsertnode(root,rand()%(max-1));
//printf("%d",root->data);
    }
    return root;
}
bst *searchnode(bst *rt,elementtype data)
{
    if(rt==NULL)
        return NULL;
    if(rt->data==data)
        return rt;
    else
    {
        if(rt->data>data)
            return searchnode(rt->left,data);
        else if(rt->data<data)
            return searchnode(rt->right,data);
    }
    return rt;
}

int main()
{
    bst* root=NULL;
    bst *s=NULL;
    int i;

    root = rinsertnode(root, 5);

    root = rinsertnode(root, 3);
    root = rinsertnode(root, 1);
    root = rinsertnode(root, 4);

    root = rinsertnode(root, 7);
    root = rinsertnode(root, 6);
    root = rinsertnode(root, 9);
    // root = dltnode(root,9);
    i=bstcheck(root);
    printf("%d",i);
    printlevelorder(root);
    printf("\nPRE: ");
    preorder(root);
    printf("\nIN: ");
    inorder(root);

    return 0;
}
