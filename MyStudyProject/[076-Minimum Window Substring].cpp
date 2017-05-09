//Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
//For example,
//S = "ADOBECODEBANC"
//T = "ABC"
//Minimum window is "BANC".
//
//Note:
//If there is no such window in S that covers all characters in T, return the empty string "".
//
//If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
#include "Header.h";
string Solution::minWindow(string s, string t) {
    vector<bool> dict(128, false);
    vector<int> cnt(128, 0);
    int count = t.length();

    int start = 0, end = 0;
    int minWin = INT_MAX;

    string ret = "";

    if (s == t) {
        return s;
    }
    for (int i = 0;i < t.length();i++) {
        dict[t[i]] = true;
        cnt[t[i]] ++;
    }

    while (end < s.length()) {
        if (dict[s[end]]) {
            if (cnt[s[end]]-->0) {
                count--;
            }
            if (count == 0) {
                while (start < end) {
                    if (dict[s[start]]) {
                        if (cnt[s[start]] < 0) {
                            cnt[s[start]]++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    start++;
                }
                if (minWin > end - start + 1) {
                    minWin = end - start + 1;
                    ret = s.substr(start, minWin);
                }
            }
        }
        end++;
    }

    return ret;
}