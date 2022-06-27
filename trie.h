#ifndef TRIE_H
#define TRIE_H
#include <cstring>
#include <iostream>
#define N_CHARS 256

typedef struct TrieNode{
    TrieNode *nodes[N_CHARS];
    bool terminal;
} TrieNode;

class Trie{

   private:
        TrieNode *root;
        bool searchWord(TrieNode *node, char *word, size_t word_len, int index);
        void printTrie(TrieNode *node, char *buffer, int index);
    public:
        Trie();
        ~Trie();
        TrieNode* createNode();
        void addWord(char *word);
        bool searchWord(char *word);
        void printTrie();
};
#endif