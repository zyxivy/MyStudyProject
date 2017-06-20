//Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it.Find and return the shortest palindrome you can find by performing this transformation.
//For example :
//Given "aacecaaa", return "aaacecaaa".
//Given "abcd", return "dcbabcd".

#include "Header.h";

//http://yucoding.blogspot.com/2015/10/leetcode-question-shortest-palindrome.html
//http://blog.csdn.net/v_july_v/article/details/7041827
string Solution::shortestPalindrome(string s) {
    string r = s;
    reverse(r.begin(), r.end());
    string t = s + "#" + r;
    vector<int> next(t.size(), 0);
    for (int i = 1; i < t.size(); ++i) {
        int j = next[i - 1];
        while (j > 0 && t[i] != t[j]) j = next[j - 1];
        next[i] = (j += t[i] == t[j]);
    }
    return r.substr(0, s.size() - next.back()) + s;
}