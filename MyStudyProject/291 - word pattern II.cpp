//This is the extension problem of Word Pattern I.
//Given a pattern and a string str, find if str follows the same pattern.
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non - empty substring in str.
//Examples:
//pattern = "abab", str = "redblueredblue" should return true.
//pattern = "aaaa", str = "asdasdasdasd" should return true.
//pattern = "aabb", str = "xyzabcxzyabc" should return false.

#include "Header.h";

bool wordPatternMatchDFS(string pattern, int i, string str, int j, map<char, string>& mp, set<string>& st) {
    int n = pattern.length();
    int m = str.length();
    if (i == n && j == m) {
        return true;
    }
    if (i == n || j == m) {
        return false;
    }

    char c = pattern[i];
    if (mp.find(c) != mp.end()) {
        int l = mp[c].length();
        string s = str.substr(j, l);
        if (s != mp[c]) {
            return false;
        }
        wordPatternMatchDFS(pattern, i + 1, str, j + l, mp, st);
    }
    else {
        for (int k = j; k < m; k++) {
            string s = str.substr(j, k - j + 1);
            st.insert(s);
            mp[c] = s;
            if (wordPatternMatchDFS(pattern, i + 1, str, k + 1, mp, st)) {
                return true;
            }
            st.erase(s);
            mp.erase(c);
        }
    }
    return false;
}
bool Solution::wordPatternMatch(string pattern, string str) {
    map<char, string> mp;
    set<string> st;
    return wordPatternMatchDFS(pattern, 0, str, 0, mp, st);
}