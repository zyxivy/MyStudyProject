//Given two words(beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
//
//Only one letter can be changed at a time
//Each intermediate word must exist in the word list
//For example,
//
//Given:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot", "dot", "dog", "lot", "log"]
//Return
//[
//    ["hit", "hot", "dot", "dog", "cog"],
//    ["hit", "hot", "lot", "log", "cog"]
//]
//Note:
//    All words have the same length.
//        All words contain only lowercase alphabetic characters.

#include "Header.h";

vector<vector<string>> Solution::findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> result;
    map<string, vector<string>> ladder;
    map<string, string> preList;
    bool found = false;

    int wordLen = beginWord.length();
    if (beginWord == endWord) {
        return result;
    }
    if (wordList.size() == 0) {
        return result;
    }
    set<string> list;
    for (int i = 0;i < wordList.size();i++) {
        list.insert(wordList[i]);
    }
    if (list.find(endWord) == list.end()) {
        return result;
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
            vector<string> kids;
            for (int j = 0;j < wordLen;j++) {
                string s = cur;
                for (char k = 'a';k <= 'z';k++) {
                    if (s[j] != k) {
                        s[j] = k;
                        if (s == endWord) {
                            found = true;
                            vector<string> strings;
                            strings.push_back(cur);
                            strings.push_back(s);
                            std::vector<string>::iterator it;
                            string pre = cur;
                            while (preList.find(pre) != preList.end()) {
                                pre = preList[pre];
                                it = strings.begin();
                                strings.insert(it, pre);
                                it = strings.begin();
                            }
                            result.push_back(strings);
                            continue;
                        }
                        if (list.find(s) != list.end() && mark[s] == false) {
                            mark[s] = true;
                            qt.push_back(s);
                            preList[s] = cur;
                            kids.push_back(s);
                        }
                    }
                }
            }        
            ladder[cur] = kids;
        }
        if (found) {
            break;
        }
        q = qt;
    }

    return result;
}
