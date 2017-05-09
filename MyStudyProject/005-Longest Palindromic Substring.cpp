//Given a string S, find the longest palindromic substring in S.You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring..

#include "Header.h"

string expandCenter(string s, int pos1, int pos2)
{
    int l = pos1;
    int r = pos2;
    while (pos1 >= 0 && pos2<=s.length() && s[pos1]==s[pos2]) {
        pos1--;
        pos2++;
        }
    return s.substr(pos1 + 1, pos2 - pos1 - 1);
}

string Solution::longestPalindrome(string s) {
    if (s.length() == 0 || s.length() == 1) {
        return s;
    }
    string str;
    for (int i = 0;i < s.length();i++) {
        string tmp= expandCenter(s, i, i);
        if (str.length() < tmp.length()) {
            str=tmp;
        }
        tmp = expandCenter(s, i, i+1);
        if (str.length() < tmp.length()) {
            str = tmp;
        }
    }

    
    return str;
}