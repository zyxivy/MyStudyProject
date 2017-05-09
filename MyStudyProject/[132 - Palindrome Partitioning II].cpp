//Given a string s, partition s such that every substring of the partition is a palindrome.
//Return the minimum cuts needed for a palindrome partitioning of s.
//For example, given s = "aab",
//Return 1 since the palindrome partitioning["aa", "b"] could be produced using 1 cut.

#include "Header.h";

//http://yucoding.blogspot.com/2013/08/leetcode-question-133-palindrome.html

int Solution::PalindromePartitionII(string s) {
    vector<int>res(s.size(), 0);
    //vector<vector<bool>> mp(s.size(), new vector<bool>(s.size(), false));

    //for (int i = s.size() - 1; i >= 0; i--) {
    //    for (int j = i; j<s.size(); j++) {
    //        if ((s[i] == s[j]) && (j - i<2 || mp[i + 1][j - 1])) {
    //            mp[i][j] = true;
    //        }
    //        else {
    //            mp[i][j] = false;
    //        }
    //    }
    //}

    //for (int i = 0; i<s.size(); i++) {
    //    int ms = s.size();
    //    if (mp[0][i]) {
    //        res[i] = 0;
    //    }
    //    else {
    //        for (int j = 0; j<i; j++) {
    //            if (mp[j + 1][i] && ms>res[j] + 1) {
    //                ms = res[j] + 1;
    //            }
    //        }
    //        res[i] = ms;
    //    }
    //}
    return res[s.size() - 1];
}
