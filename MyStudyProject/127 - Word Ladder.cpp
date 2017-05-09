//Given two words(beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that: 
//Only one letter can be changed at a time.
//Each transformed word must exist in the word list.Note that beginWord is not a transformed word.
//For example,
//Given:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
//As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//return its length 5.
//Note :
//    Return 0 if there is no such transformation sequence.
//    All words have the same length.
//    All words contain only lowercase alphabetic characters.
//    You may assume no duplicates in the word list.
//    You may assume beginWord and endWord are non - empty and are not the same.

#include "Header.h";
int Solution::ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int level = 1;
    int wordLen = beginWord.length();
    if (beginWord == endWord) {
        return 1;
    }
    if (wordList.size() == 0) {
        return 0;
    }
    set<string> list;
    for (int i = 0;i < wordList.size();i++) {
        list.insert(wordList[i]);
    }
    if (list.find(endWord) == list.end()) {
        return 0;
    }

    map<string, bool> mark;
    for (int i = 0; i < wordList.size(); i++) {
        mark[wordList[i]] = false;
    }
    mark[beginWord] = true;
    vector<string> q;
    q.push_back(beginWord);
    while (!q.empty()) {
        vector<string> qt;
        for (int i = 0;i < q.size();i++) {
            string cur = q[i];
            for (int j = 0;j < wordLen;j++) {
                string s = cur;
                for (char k = 'a';k <= 'z';k++) {
                    if (s[j] != k) {
                        s[j] = k;
                        if (s == endWord) {
                            return level+1;
                        }
                        if (list.find(s) != list.end() && mark[s] == false) {
                            mark[s] = true;
                            qt.push_back(s);
                        }
                    }
                }
            }
        }
        q = qt;
        level++;
    }

    return 0;
}
