#include<stdio.h>
#include <string.h>
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
void print_ascii_tree(bst *root);
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

    print_ascii_tree(root);

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





// -----------------

typedef bst* BinaryTreeNodePtr;

//printing tree in ascii
typedef struct asciinode_struct asciinode;
struct asciinode_struct
{
    asciinode * left, * right;
//length of the edge from this node to its children
    int edge_length;


    int height;
    int lablen;
//-1=I am left, 0=I am root, 1=right
    int parent_dir;
//max supported unit32 in dec, 10 digits max
    char label[11];
};
#define MAX_HEIGHT 1000
int lprofile[MAX_HEIGHT];
int rprofile[MAX_HEIGHT];
#define INFINITY (1<<20)
//adjust gap between left and right nodes
int gap = 3;
//used for printing next node in the same level,
//this is the x coordinate of the next char printed
int print_next;
int MIN (int X, int Y)
{
    return ((X) < (Y)) ? (X) : (Y);
}
int MAX (int X, int Y)
{
    return ((X) > (Y)) ? (X) : (Y);
}
asciinode * build_ascii_tree_recursive(bst * t)
{
    asciinode * node;
    if (t == NULL) return NULL;
    node = (asciinode*)malloc(sizeof(asciinode));
    node->left = build_ascii_tree_recursive(t->left);
    node->right = build_ascii_tree_recursive(t->right);
    if (node->left != NULL)
    {
        node->left->parent_dir = -1;
    }
    if (node->right != NULL)
    {


        node->right->parent_dir = 1;
    }
    sprintf(node->label, "%d", t->data);
    node->lablen = strlen(node->label);
    return node;
}
//Copy the tree into the ascii node structre
asciinode * build_ascii_tree(bst * t)
{
    asciinode *node;
    if (t == NULL) return NULL;
    node = build_ascii_tree_recursive(t);
    node->parent_dir = 0;
    return node;
}
//Free all the nodes of the given tree
void free_ascii_tree(asciinode *node)
{
    if (node == NULL) return;
    free_ascii_tree(node->left);
    free_ascii_tree(node->right);
    free(node);
}
//The following function fills in the lprofile array for the given tree.
//It assumes that the center of the label of the root of this tree
//is located at a position (x,y). It assumes that the edge_length
//fields have been computed for this tree.
void compute_lprofile(asciinode *node, int x, int y)
{
    int i, isleft;
    if (node == NULL) return;
    isleft = (node->parent_dir == -1);
    lprofile[y] = MIN(lprofile[y], x-((node->lablen-isleft)/2));
    if (node->left != NULL)
    {
        for (i=1; i <= node->edge_length && y+i < MAX_HEIGHT; i++)
        {
            lprofile[y+i] = MIN(lprofile[y+i], x-i);
        }
    }
    compute_lprofile(node->left, x-node->edge_length-1, y+node->edge_length+1);
    compute_lprofile(node->right, x+node->edge_length+1, y+node->edge_length+1);


}
void compute_rprofile(asciinode *node, int x, int y)
{
    int i, notleft;
    if (node == NULL) return;
    notleft = (node->parent_dir != -1);
    rprofile[y] = MAX(rprofile[y], x+((node->lablen-notleft)/2));
    if (node->right != NULL)
    {
        for (i=1; i <= node->edge_length && y+i < MAX_HEIGHT; i++)
        {
            rprofile[y+i] = MAX(rprofile[y+i], x+i);
        }
    }
    compute_rprofile(node->left, x-node->edge_length-1, y+node->edge_length+1);
    compute_rprofile(node->right, x+node->edge_length+1, y+node->edge_length+1);
}
//This function fills in the edge_length and
//height fields of the specified tree
void compute_edge_lengths(asciinode *node)
{
    int h, hmin, i, delta;
    if (node == NULL) return;
    compute_edge_lengths(node->left);
    compute_edge_lengths(node->right);
    /* first fill in the edge_length of node */
    if (node->right == NULL && node->left == NULL)
    {
        node->edge_length = 0;
    }
    else
    {
        if (node->left != NULL)
        {
            for (i=0; i<node->left->height && i < MAX_HEIGHT; i++)
            {
                rprofile[i] = -INFINITY;
            }
            compute_rprofile(node->left, 0, 0);
            hmin = node->left->height;
        }
        else
        {
            hmin = 0;
        }
        if (node->right != NULL)


        {
            for (i=0; i<node->right->height && i < MAX_HEIGHT; i++)
            {
                lprofile[i] = INFINITY;
            }
            compute_lprofile(node->right, 0, 0);
            hmin = MIN(node->right->height, hmin);
        }
        else
        {
            hmin = 0;
        }
        delta = 4;
        for (i=0; i<hmin; i++)
        {
            delta = MAX(delta, gap + 1 + rprofile[i] - lprofile[i]);
        }
//If the node has two children of height 1, then we allow the
//two leaves to be within 1, instead of 2
        if (((node->left != NULL && node->left->height == 1) ||
                (node->right != NULL && node->right->height == 1))&&delta>4)
        {
            delta--;
        }
        node->edge_length = ((delta+1)/2) - 1;
    }
//now fill in the height of node
    h = 1;
    if (node->left != NULL)
    {
        h = MAX(node->left->height + node->edge_length + 1, h);
    }
    if (node->right != NULL)
    {
        h = MAX(node->right->height + node->edge_length + 1, h);
    }
    node->height = h;
}
//This function prints the given level of the given tree, assuming
//that the node has the given x cordinate.
void print_level(asciinode *node, int x, int level)
{
    int i, isleft;
    if (node == NULL) return;
    isleft = (node->parent_dir == -1);
    if (level == 0)


    {
        for (i=0; i<(x-print_next-((node->lablen-isleft)/2)); i++)
        {
            printf(" ");
        }
        print_next += i;
        printf("%s", node->label);
        print_next += node->lablen;
    }
    else if (node->edge_length >= level)
    {
        if (node->left != NULL)
        {
            for (i=0; i<(x-print_next-(level)); i++)
            {
                printf(" ");
            }
            print_next += i;
            printf("/");
            print_next++;
        }
        if (node->right != NULL)
        {
            for (i=0; i<(x-print_next+(level)); i++)
            {
                printf(" ");
            }
            print_next += i;
            printf("\\");
            print_next++;
        }
    }
    else
    {
        print_level(node->left,
                    x-node->edge_length-1,
                    level-node->edge_length-1);
        print_level(node->right,
                    x+node->edge_length+1,
                    level-node->edge_length-1);
    }
}
void print_ascii_tree(bst * t)
{
    printf("\n");
    asciinode *proot;
    int xmin, i;
    if (t == NULL) return;
    proot = build_ascii_tree(t);


    compute_edge_lengths(proot);
    for (i=0; i<proot->height && i < MAX_HEIGHT; i++)
    {
        lprofile[i] = INFINITY;
    }
    compute_lprofile(proot, 0, 0);
    xmin = 0;
    for (i = 0; i < proot->height && i < MAX_HEIGHT; i++)
    {
        xmin = MIN(xmin, lprofile[i]);
    }
    for (i = 0; i < proot->height; i++)
    {
        print_next = 0;
        print_level(proot, -xmin, i);
        printf("\n");
    }
    if (proot->height >= MAX_HEIGHT)
    {
        printf("(This tree is taller than %d, and may be drawn incorrectly.)\n", MAX_HEIGHT);
    }
    free_ascii_tree(proot);
}
