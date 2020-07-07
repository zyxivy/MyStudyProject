//Given an input string(s) and a pattern(p), implement regular expression matching with support for '.' and '*'.
//
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
//The matching should cover the entire input string(not partial).
//
//Note:
//
//s could be empty and contains only lowercase letters a - z.
//p could be empty and contains only lowercase letters a - z, and characters like . or *.
//Example 1 :
//
//	Input :
//	s = "aa"
//	p = "a"
//	Output : false
//	Explanation : "a" does not match the entire string "aa".
//	Example 2 :
//
//	Input :
//	s = "aa"
//	p = "a*"
//	Output : true
//	Explanation : '*' means zero or more of the preceding element, 'a'.Therefore, by repeating 'a' once, it becomes "aa".
//	Example 3 :
//
//	Input :
//	s = "ab"
//	p = ".*"
//	Output : true
//	Explanation : ".*" means "zero or more (*) of any character (.)".
//	Example 4 :
//
//	Input :
//	s = "aab"
//	p = "c*a*b"
//	Output : true
//	Explanation : c can be repeated 0 times, a can be repeated 1 time.Therefore, it matches "aab".
//	Example 5 :
//
//	Input :
//	s = "mississippi"
//	p = "mis*is*p*."
//	Output : false

#include "pch.h";
bool Solution::isMatch(string s, string p) {

    //1, If p.charAt(j) == s.charAt(i) : dp[i][j] = dp[i - 1][j - 1];
    //2, If p.charAt(j) == '.' : dp[i][j] = dp[i - 1][j - 1];
    //3, If p.charAt(j) == '*':
    //here are two sub conditions :
    //1   if p.charAt(j - 1) != s.charAt(i) and p.charAt(j - 1) != '.'  : dp[i][j] = dp[i][j - 2]  //in this case, a* only counts as empty
    //2   if p.charAt(j - 1) == s.charAt(i) or p.charAt(i - 1) == '.' :
    //    dp[i][j] = dp[i - 1][j]    //in this case, a* counts as multiple a 
    //    or dp[i][j] = dp[i][j - 1]   // in this case, a* counts as single a
    //    or dp[i][j] = dp[i][j - 2]   // in this case, a* counts as empty

    int m = s.length(), n = p.length();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true; // empty string matches empty pattern

    // if pattern starts with a*a*a*, it matches empty string
    for (int j = 2; j < n+1; j++) {
        if (p[j - 1] == '*' && dp[0][j - 2])
        {
            dp[0][j] = true;
        }
    }

    for (int i = 1; i < m+1; i++) {
        for (int j = 1; j < n+1; j++)
        {
            if (p[j] == s[i] || p[j] == '.')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }

            if (p[j] == '*')
            {
                if (p[j - 1] != s[i - 1] && p[j - 1] != '.')
                {
                    dp[i][j] = dp[i][j - 2];
                }
                else
                {
                    dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];
                }
            }
        }
    }

    return dp[m][n];
}