#include <iostream>
#include "trie.h"

using namespace std;

int main()
{
    TNode *root = createTrieNode();

    insertWordInTrie(root, "beingzero");
    insertWordInTrie(root, "apple");
    insertWordInTrie(root, "apple");
    insertWordInTrie(root, "banana");
    insertWordInTrie(root, "chiku");

    printWordsInTrie(root);
    return 0;
}
