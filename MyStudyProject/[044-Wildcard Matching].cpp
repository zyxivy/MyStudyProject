//Implement wildcard pattern matching with support for '?' and '*'.
//
//'?' Matches any single character.
//'*' Matches any sequence of characters(including the empty sequence).
//
//The matching should cover the entire input string(not partial).
//
//The function prototype should be :
//bool isMatch(const char *s, const char *p)
//
//Some examples :
//isMatch("aa", "a") → false
//isMatch("aa", "aa") → true
//isMatch("aaa", "aa") → false
//isMatch("aa", "*") → true
//isMatch("aa", "a*") → true
//isMatch("ab", "?*") → true
//isMatch("aab", "c*a*b") → false

#include "Header.h";

bool Solution::WildcardMatching(string s, string p) {
    int startI = -1;
    int startJ = -1;
    int i = 0;
    int j = 0;
    while (i < s.length()) {
        if (j < p.length() && (s[i]==p[j] || p[j] == '?')) {
            i++;
            j++;
        }
        else if (j < p.length() && (p[j] == '*')) {
            startJ = j;
            startI = i;
            j++;
        }
        else if (startJ != -1) {
            j = startJ;
            i = ++startI;
        }
        else {
            return false;
        }
    }
    while (j < p.length()) {
        if (p[j] != '*') {
            return false;
        }
        j++;
    }
    return true;
}