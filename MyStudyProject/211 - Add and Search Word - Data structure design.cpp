//Design a data structure that supports the following two operations :
//void addWord(word)
//bool search(word)
//search(word) can search a literal word or a regular expression string containing only letters a - z or ..A.means it can represent any one letter.
//For example :
//addWord("bad")
//addWord("dad")
//addWord("mad")
//search("pad") -> false
//search("bad") -> true
//search(".ad") -> true
//search("b..") -> true
//Note:
//You may assume that all words are consist of lowercase letters a - z.
//click to show hint.
//You should be familiar with how a Trie works.If not, please work on this problem : Implement Trie(Prefix Tree) first.

#include "Header.h";
WordDictionary::WordDictionary() {
    root = new TrieNode();
}

/** Adds a word into the data structure. */
void WordDictionary::addWord(string word) {
    map<char, TrieNode*> children = root->children;
    TrieNode* node;
    for (int i = 0; i < word.length(); i++) {
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

bool dfsSearch(map<char, TrieNode*> children, string word, int start) {
    if (start == word.length()) {
        if (children.size() == 0)
            return true;
        else
            return false;
    }

    char c = word[start];

    if (children.find(c)!=children.end()) {
        if (start == word.length() - 1 && children[c]->isLeaf) {
            return true;
        }

        return dfsSearch(children[c]->children, word, start + 1);
    }
    else if (c == '.') {
        bool result = false;
        for (map<char, TrieNode*>::iterator it = children.begin(); it != children.end();it++) {
            if (start == word.length() - 1 && it->second->isLeaf) {
                return true;
            }

            //if any path is true, set result to be true; 
            if (dfsSearch(it->second->children, word, start + 1)) {
                result = true;
            }
        }

        return result;
    }
    else {
        return false;
    }
}
/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool WordDictionary::search(string word) {
    return dfsSearch(root->children, word, 0);
}