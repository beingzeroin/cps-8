#ifndef LLNode_H_INCLUDED
#define LLNode_H_INCLUDED

typedef int ElementType;
typedef struct LLNode LLNode;

// Define Structure LLNode
struct LLNode
{
    ElementType data;
    LLNode *next;
};

LLNode* createLLNode(ElementType data);
LLNode* insertInBegin(LLNode *head, ElementType data);
LLNode* deleteFirstNode(LLNode *head);
LLNode* destroyAllNodes(LLNode *head);
LLNode* insertInEnd(LLNode *head,ElementType data);
LLNode* deleteLastNode(LLNode *head);

#endif // LLNode_H_INCLUDED
