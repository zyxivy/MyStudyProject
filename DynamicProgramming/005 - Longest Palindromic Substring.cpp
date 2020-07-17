//Given a string s, find the longest palindromic substring in s.You may assume that the maximum length of s is 1000.
//
//Example 1:
//
//Input: "babad"
//Output : "bab"
//Note : "aba" is also a valid answer.
//Example 2 :
//
//	Input : "cbbd"
//	Output : "bb"

#include "pch.h";
string longestPalindrome(string s) {
	int len = s.size();
	int maxLen = 0;
	int start = 0;
	int end = 0;

	//dp(i, j) represents whether s(i ... j) can form a palindromic substring, dp(i, j) is true when s(i) equals to s(j) and s(i + 1 ... j - 1) is a palindromic substring
	vector<vector<bool>> dp(len, vector<bool>(len, false));

	for (int j = 0; j < len; j++) 
	{
		for (int i = 0; i <= j; i++)
		{
			dp[i][j] = (i == j) || (s[i] == s[j] && (i == (j - 1) || dp[i + 1][j - 1]));
			if (dp[i][j] && maxLen < j - i + 1)
			{
				maxLen = j - i + 1;
				start = i;
				end = j;
			}
		}
	}
	return s.substr(start, end - start + 1);
}