//Follow up for "Unique Paths":
//
//Now consider if some obstacles are added to the grids.How many unique paths would there be ?
//
//An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
//For example,
//There is one obstacle in the middle of a 3x3 grid as illustrated below.
//
//[
//    [0, 0, 0],
//    [0, 1, 0],
//    [0, 0, 0]
//]
//The total number of unique paths is 2.
//
//Note: m and n will be at most 100.

#include "Header.h";

int Solution::uniquePathsWithObstacles(vector<vector<int>>& A) {
    int m = A.size();
    if (m == 0) {
        return 0;
    }
    int n = A[0].size();
    if (A[0][0]) {
        return false;
    }
    bool flag = false;
    for (int i = 0;i < m;i++) {
        if (A[i][0] == 1) {
            flag = true;
            A[i][0] = 0;
        }
        if (!flag) {
            A[i][0] = 1;
        }
        else {
            A[i][0] = 0;
        }
    }
    flag = false;
    for (int j = 1;j < n;j++) {
        if (A[0][j] == 1) {
            flag = true;
            A[0][j] = 0;
        }
        if (!flag) {
            A[0][j] = 1;
        }
        else {
            A[0][j] = 0;
        }
    }
    for (int i = 1;i < m;i++) {
        for (int j = 1;j < n;j++) {
            if (A[i][j] == 1) {
                A[i][j] = 0;
            }
            else {
                A[i][j] = A[i - 1][j] + A[i][j - 1];
            }
        }
    }
    return A[m - 1][n - 1];
}