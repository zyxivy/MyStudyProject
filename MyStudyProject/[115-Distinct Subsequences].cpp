//Given a string S and a string T, count the number of distinct subsequences of T in S.
//
//A subsequence of a string is a new string which is formed from the original string by deleting some(can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//
//Here is an example :
//S = "rabbbit", T = "rabbit"
//
//Return 3.

#include "Header.h";

//http://www.programcreek.com/2013/01/leetcode-distinct-subsequences-total-java/

int Solution::numDistinct(string S, string T) {
    vector<vector<int>> table(S.length() + 1, vector<int>(T.length() + 1, 0));

    for (int i = 0; i < S.length(); i++)
        table[i][0] = 1;

    for (int i = 1; i <= S.length(); i++) {
        for (int j = 1; j <= T.length(); j++) {
            if (S[i - 1] == T[j - 1]) {
                table[i][j] += table[i - 1][j] + table[i - 1][j - 1];
            }
            else {
                table[i][j] += table[i - 1][j];
            }
        }
    }

    return table[S.length()][T.length()];
}