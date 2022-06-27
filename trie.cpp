#include "trie.h"

Trie::Trie(){
    root = new TrieNode;
}

Trie::~Trie(){
    delete root;
}

TrieNode* Trie::createNode(){
    return new TrieNode;
}

void Trie::addWord(char *word){
    TrieNode *node = root;
    size_t word_len = strlen(word);
    char ch;
    for(size_t index = 0; index < word_len; index++){
        ch = word[index];
        if(node->nodes[word[index]] == nullptr){
            node->nodes[word[index]] = createNode();
        }
        node = node->nodes[word[index]];
    }
    if(node != root){
        node->terminal = true;
    }
}

bool Trie::searchWord(TrieNode *node, char *word, size_t word_len, int index){
    if(node == nullptr){
        return false;
    }
    if(node->terminal && index == word_len-1){
        return true;
    }
    return searchWord(node->nodes[word[index+1]], word, word_len, index+1);
}

bool Trie::searchWord(char *word){
    return searchWord(root, word, strlen(word), -1);
}

void Trie::printTrie(TrieNode *node, char *buffer, int index){
    for(int ch = 0; ch < N_CHARS; ch++){
        if(node->nodes[ch] != nullptr){
            buffer[index] = ch;
            if(node->nodes[ch]->terminal){
                std::cout << buffer << std::endl;
            }
            printTrie(node->nodes[ch], buffer, index+1);
            buffer[index] = '\0';
        }
    }
}

void Trie::printTrie(){
    char *buffer = new char[N_CHARS];
    printTrie(root, buffer, 0);
    delete buffer;
}

