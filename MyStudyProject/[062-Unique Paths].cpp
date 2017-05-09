//A robot is located at the top - left corner of a m x n grid(marked 'Start' in the diagram below).
//
//The robot can only move either down or right at any point in time.The robot is trying to reach the bottom - right corner of the grid(marked 'Finish' in the diagram below).
//
//How many possible unique paths are there ?
//
//
//Above is a 3 x 7 grid.How many possible unique paths are there ?
//
//Note : m and n will be at most 100.


//http://yucoding.blogspot.com/2013/04/leetcode-question-116-unique-path-i.html

#include "Header.h";

int Solution::uniquePaths(int m, int n) {
    vector<vector<int>> A;
    for (int i = 0;i < m;i++) {
        vector<int> row(n, 0);
        A.push_back(row);
    }
    for (int i = 0;i < m;i++) {
        A[i][0] = 1;
    }
    for (int i = 0;i < n;i++) {
        A[0][i] = 1;
    }
    for (int i = 1;i < m;i++) {
        for (int j = 1;j < n;j++) {
            A[i][j] = A[i - 1][j] + A[i][j - 1];
        }
    }
    return A[m - 1][n - 1];
}