//Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//
//For example,
//Given n = 3, there are a total of 5 unique BST's.
//
//1         3     3      2      1
//\ / / / \      \
//3     2     1      1   3      2
/// / \                 \
//2     1         2                 3

//http://bangbingsyb.blogspot.com/2014/11/leetcode-unique-binary-search-trees-i-ii.html
#include "Header.h";
int Solution::numTrees(int n) {
    vector<int> f(n + 1, 0);
    f[0] = 1;
    f[1] = 1;
    for (int i = 2;i <= n;i++) {
        for (int j = 0;j < i;j++) {
            f[i] += f[j] * f[i - j - 1];
        }        
    }
    return f[n];
}