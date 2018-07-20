//There is a new alien language which uses the latin alphabet.However, the order among letters are unknown to you.You receive a list of non - empty words from the dictionary, where words are sorted lexicographically by the rules of this new language.Derive the order of letters in this language.
//Example 1:
//Given the following words in dictionary,
//1
//2
//3
//4
//5
//6
//7
//[
//    "wrt",
//    "wrf",
//    "er",
//    "ett",
//    "rftt"
//]
//
//The correct order is : "wertf".
//Example 2 :
//    Given the following words in dictionary,
//    1
//    2
//    3
//    4
//    [
//        "z",
//        "x"
//    ]
//
//The correct order is : "zx".
//Example 3 :
//    Given the following words in dictionary,
//    1
//    2
//    3
//    4
//    5
//    [
//        "z",
//        "x",
//        "z"
//    ]
//
//The order is invalid, so return "".
//Note:
//You may assume all letters are in lowercase.
//You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
//If the order is invalid, return an empty string.
//There may be multiple valid order of letters, return any one of them is fine.

#include "Header.h";

//https://aquahillcf.wordpress.com/2015/09/07/leetcode-alien-dictionary/
//https://en.wikipedia.org/wiki/Topological_sorting
string alienOrderTopSortKahn(map<char, set<char>> mp) {
    queue<char> q;
    map<char, int> inDegrees;
    string s;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        for (auto c : it->second) {
            if (inDegrees.find(c) != inDegrees.end()) {
                inDegrees[c] = inDegrees[c] + 1;
            }
            else {
                inDegrees[c] = 1;
            }
        }
    }

    //find char with no incoming edge
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (inDegrees.find(it->first) == inDegrees.end()) {
            q.push(it->first);
        }
    }

    while (!q.empty()) {
        char c = q.back();
        q.pop();
        s.push_back(c);
        set<char> conNodes = mp[c];
        for (char a : conNodes) {
            inDegrees[a] = inDegrees[a] - 1;
            if (inDegrees[a] == 0) {
                q.push(a);
            }
        }
    }

    for (auto it = inDegrees.begin(); it != inDegrees.end(); it++) {
        if (it->second != 0) {
            return "";
        }
    }
    return s;
}

void alienOrderTopSortDFS(string &s, char c, map<char, int>& visited, map<char, set<char>> mp) {
    if (visited[c] == -1) {
        return;
    }
    if (visited[c] == 1) {
        s = "";
        return;
    }
    visited[c] = 1;
    set<char> conNodes = mp[c];
    for (char a : conNodes) {
        alienOrderTopSortDFS(s, a, visited, mp);
    }
    visited[c] = -1;
    s.insert(s.begin(), c);
}

string Solution::alienOrder(vector<string> words) {
    //construct graph
    map<char, set<char>> mp;
    string prev;
    string curr;
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words[i].length(); j++) {
            char c = words[i][j];
            if (mp.find(c) != mp.end()) {
                set<char> st;
                mp[c] = st;
            }
        }
        if (i > 0) {
            //order graph
            prev = words[i - 1];
            curr = words[i];
            int minLen = min(prev.length(), curr.length());
            for (int k = 0; k < minLen; k++) {
                if (prev[k] != curr[k]) {
                    mp[prev[k]].insert(curr[k]);
                    break;
                }
            }
        }
    }

    string s;
    //topology sort Kahn
    s = alienOrderTopSortKahn(mp);

    //topology sort DFS
    map<char, int> visited;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (visited.find(it->first) != visited.end()){
            visited[it->first] = 0;
            //0:unmakred;
            //1:temporarily marked;
            //-1:permanently marked
        }
    }
    for (auto it = visited.begin(); it != visited.end(); it++) {
        if (it->second == 0) {
            alienOrderTopSortDFS(s, it->first, visited, mp);
        }
    }


    return s;
}