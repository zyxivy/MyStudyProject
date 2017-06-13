//Given two strings s and t, determine if they are isomorphic.
//Two strings are isomorphic if the characters in s can be replaced to get t.
//All occurrences of a character must be replaced with another character while preserving the order of characters.No two characters may map to the same character but a character may map to itself.
//For example,
//Given "egg", "add", return true.
//Given "foo", "bar", return false.
//Given "paper", "title", return true.
//Note:
//You may assume both s and t have the same length.

#include "Header.h";
bool Solution::isIsomorphic(string s, string t) {

    if (s.length() != t.length()) {
        return false;
    }
    if (s.empty()) {
        return true;
    }
    map<char, char> mps;
    map<char, char> mpt;
    for (int i = 0; i < s.length(); i++) {
        if (mps.find(s[i]) == mps.end()) {
            mps[s[i]] = t[i];
        }
        if (mpt.find(t[i]) == mpt.end()) {
            mpt[t[i]] = s[i];
        }
        if (mps.find(s[i]) != mps.end() && mps[s[i]] != t[i]) {
            return false;
        }
        if (mpt.find(t[i]) != mpt.end() && mpt[t[i]] != s[i]) {
            return false;
        }
    }
    return true;
}