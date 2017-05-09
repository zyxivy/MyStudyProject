//Given a m x n grid filled with non - negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
//Note: You can only move either down or right at any point in time

#include "Header.h";
int Solution::minPathSum(vector<vector<int>>& A) {
    int m = A.size();
    if (m == 0) {
        return 0;
    }
    int n = A[0].size();
    for (int i = 1;i < m;i++) {
        A[i][0] = A[i-1][0] + A[i][0];
    }
    for (int j = 1;j < n;j++) {
        A[0][j] = A[0][j-1] + A[0][j];
    }

    for (int i = 1;i < m;i++) {
        for (int j = 1;j < n;j++) {
            A[i][j] = (A[i - 1][j]+A[i][j]) < (A[i][j - 1] + A[i][j])? (A[i - 1][j] + A[i][j]): (A[i][j - 1] + A[i][j]);
        }
    }
    return A[m - 1][n - 1];
}