//There is a fence with n posts, each post can be painted with one of the k colors.
//You have to paint all the posts such that no more than two adjacent fence posts have the same color.
//Return the total number of ways you can paint the fence.
//Note:
//n and k are non - negative integers.

#include "Header.h";

//https://www.programcreek.com/2014/05/leetcode-pain-fence-java/
int Solution::numWays(int n, int k) {
    int dp[] = { 0, k , k*k, 0 };

    if (n <= 2)
        return dp[n];

    for (int i = 2; i < n; i++) {
        dp[3] = (k - 1) * (dp[1] + dp[2]);
        dp[1] = dp[2];
        dp[2] = dp[3];
    }

    return dp[3];
}