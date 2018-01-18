//Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers.Return the maximum product you can get.
//For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
//Note: You may assume that n is not less than 2 and not larger than 58.

#include "Header.h";
int Solution::integerBreak(int n) {
    // 1.Init except dp[n], since it cannot be itself and must break into two positive
    vector<int> maxProd(n+1, 0);
    for (int i = 1; i < n; i++) {
        maxProd[i] = i;
    }

    // 2.Compute max product
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i - j; j++) { // Note: only check j <= i - j
            maxProd[i] = max(maxProd[i], maxProd[j] * maxProd[i - j]);
        }
    }
    return maxProd[n];
}