//Implement a trie with insert, search, and startsWith methods.
//Note:
//You may assume that all inputs are consist of lowercase letters a - z.

#include "Header.h";
Trie::Trie() {
    root = new TrieNode();
}

/** Inserts a word into the trie. */
void Trie::insert(string word) {
    map<char, TrieNode*> children = root->children;
    for (int i = 0; i < word.length(); i++) {
        TrieNode* node;
        char c = word[i];
        if (children.find(c) != children.end()) {
            node = children[c];
        }
        else {
            node = new TrieNode(c);
            children[c] = node;
        }
        children = node->children;
        if (i == word.length() - 1) {
            node->isLeaf = true;
        }
    }
}

/** Returns if the word is in the trie. */
bool Trie::search(string word) {
    TrieNode* node = searchNode(word);
    if (node == NULL || node->isLeaf == false) {
        return false;
    }
    return true;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool Trie::startsWith(string prefix) {
    TrieNode* node = searchNode(prefix);
    if (node == NULL) {
        return false;
    }
    return true;
}

TrieNode* Trie::searchNode(string word) {
    TrieNode* node = root;   
    for (int i = 0; i < word.length(); i++) {
        char c = word[i];
        map<char, TrieNode*> children = node->children;
        if (children.find(c) != children.end()) {
            node = children[c];
        }
        else {
            return NULL;
        }
    }
}