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
    //if (s.length() == 0 || s.length() == 1) {
    //    return s;
    //}
    //string str;
    //for (int i = 0;i < s.length();i++) {
    //    string tmp= expandCenter(s, i, i);
    //    if (str.length() < tmp.length()) {
    //        str=tmp;
    //    }
    //    tmp = expandCenter(s, i, i+1);
    //    if (str.length() < tmp.length()) {
    //        str = tmp;
    //    }
    //}
    //    
    //return str;


    //DP
    //http://fisherlei.blogspot.com/2012/12/leetcode-longest-palindromic-substring.html
    //define DP[i,j] as if substring between index i and j is palindromic.
    //DP[i, j] = 1  if i == j
    //    = S[i] == S[j]   if j = i + 1
    //    = S[i] == S[j] && P[i + 1][j - 1]  if j>i + 1
    int len = s.size();
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    int maxLen = 0;
    int start = 0;
    int end = 0;
    for (int j = 0; j < len; j++) {
        for (int i = 0; i <= j; i++) {
            dp[i][j] = (i==j) || (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]));
            if (dp[i][j] && maxLen < j - i + 1) {
                maxLen = j - i + 1;
                start = i;
                end = j;
            }
        }
    }
    return s.substr(start, end - start + 1);
}