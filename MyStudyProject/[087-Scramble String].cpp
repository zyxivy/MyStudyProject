//Given a string s1, we may represent it as a binary tree by partitioning it to two non - empty substrings recursively.
//
//Below is one possible representation of s1 = "great":
//
//great
/// \
//gr    eat
/// \ / \
//g   r  e   at
/// \
//a   t
//To scramble the string, we may choose any non - leaf node and swap its two children.
//
//For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
//
//rgeat
/// \
//rg    eat
/// \ / \
//r   g  e   at
/// \
//a   t
//We say that "rgeat" is a scrambled string of "great".
//
//Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
//
//rgtae
/// \
//rg    tae
/// \ / \
//r   g  ta  e
/// \
//t   a
//We say that "rgtae" is a scrambled string of "great".
//
//Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

#include "Header.h";

bool checkScramble(string s1, string s2) {
    if (s1 == s2) {
        return true;
    }
    if (s1.length() != s2.length()) {
        return false;
    }
    int l = s1.length();
    int v1 = 0, v2 = 0;
    for (int i = 0;i < l;i++) {
        v2 += s2[i];
        v1 += s1[i];
    }
    if (v1 != v2) {
        return false;
    }

    for (int i = 1;i < s1.length();i++) {
        if (checkScramble(s1.substr(0,i), s2.substr(0,i)) && checkScramble(s1.substr(i), s2.substr(i))) {
            return true;
        }
        if (checkScramble(s1.substr(0, i), s2.substr(l - i)) && checkScramble(s1.substr(i), s2.substr(0, l - i))) {
            return true;
        }
    }
    return false;
}
bool Solution::isScramble(string s1, string s2) {
    bool ret = checkScramble(s1, s2);
    return ret;
}