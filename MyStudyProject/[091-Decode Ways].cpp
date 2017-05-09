//A message containing letters from A - Z is being encoded to numbers using the following mapping :
//
//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
//Given an encoded message containing digits, determine the total number of ways to decode it.
//
//For example,
//Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
//
//The number of ways decoding "12" is 2.

#include "Header.h";

int Solution::numDecodings(string s) {
    //http://bangbingsyb.blogspot.com/2014/11/leetcode-decode-ways.html
    //{
    //    if (s.empty() || s[0]<'1' || s[0]>'9') return 0;
    //    vector<int> dp(s.size() + 1, 0);
    //    dp[0] = dp[1] = 1;

    //    for (int i = 1; i<s.size(); i++) {
    //        if (!isdigit(s[i])) return 0;
    //        int v = (s[i - 1] - '0') * 10 + (s[i] - '0');
    //        if (v <= 26 && v>9) dp[i + 1] += dp[i - 1];
    //        if (s[i] != '0') dp[i + 1] += dp[i];
    //        if (dp[i + 1] == 0) return 0;
    //    }
    //    return dp[s.size()];
    //}

    {
        vector<int> ways(s.length(), 0);
        if (s.length() == 0 || s[0] == '0') {
            return 0;
        }
        if (s.length() == 1) {
            return 1;
        }
        ways[0] = 1;
        if (s[0] == '1' || (s[0] == '2' && s[1] >= '0' && s[1] <= '6')) {
            ways[1]++;
        }
        if (s[1] != '0') {
            ways[1]++;
        }
        for (int i = 2;i < s.length();i++) {
            if (s[i] != '0') {
                ways[i] += ways[i - 1];
            }
            if (s[i-1] == '1' || (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6')) {
                ways[i] += ways[i - 2];
            }
        }
        return ways[s.length() - 1];
    }
}