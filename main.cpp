#include "trie.h"
#include <iostream>

int main(int argc, char *args[]){
    Trie *trie = new Trie;
    char *word = new char[256];
    for(int i = 0; i < argc; i++){
        trie->addWord(args[i]);
    }
    trie->printTrie();
    delete trie;
    delete word;
    std::cout << "finished\n";
    return 0;
}