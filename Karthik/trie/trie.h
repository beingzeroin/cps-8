#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#define ALPHABET_SIZE 26
#incluse <stdlib.h>
typedef struct trien TNode;
struct trien
{
    bool isEOW;
    TNode *next[ALPHABET_SIZE];
};



#endif // TRIE_H_INCLUDED
