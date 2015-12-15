#ifndef LLNODE_H_INCLUDED
#define LLNODE_H_INCLUDED

typedef struct n llnode;
struct n
{
    int data;
    struct n *next;
};

llnode *createNode();
llnode *createSerialList(int s, int e);


#endif // LLNODE_H_INCLUDED
