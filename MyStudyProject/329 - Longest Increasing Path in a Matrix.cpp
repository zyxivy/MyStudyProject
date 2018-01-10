//Given an integer matrix, find the length of the longest increasing path.
//From each cell, you can either move to four directions : left, right, up or down.You may NOT move diagonally or move outside of the boundary(i.e.wrap - around is not allowed).
//Example 1 :
//    nums = [
//        [9, 9, 4],
//            [6, 6, 8],
//            [2, 1, 1]
//    ]
//
//    Return 4
//        The longest increasing path is[1, 2, 6, 9].
//        Example 2:
//    nums = [
//        [3, 4, 5],
//            [3, 2, 6],
//            [2, 2, 1]
//    ]
//
//        Return 4
//        The longest increasing path is[3, 4, 5, 6].Moving diagonally is not allowed.
#include "Header.h";

vector<vector<int>> dir = { { 0, 1 },{ 1, 0 },{ 0, -1 },{ -1, 0 } };
int DFSlongestIncreasingPath(vector<vector<int>>& matrix, vector<vector<int>>& cache, int i, int j, int m, int n) {
    if (cache[i][j] != 0) {
        return cache[i][j];
    }
    int maxLen = 1;
    for (int k = 0; k < dir.size(); k++) {
        int x = i + dir[k][0];
        int y = j + dir[k][1];
        if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j])
            continue;
        int len = 1 + DFSlongestIncreasingPath(matrix, cache, x, y, m, n);
        maxLen = max(maxLen, len);
    }
    cache[i][j] = maxLen;
    return maxLen;
}

int Solution::longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> cache(m, vector<int>(n, 0));
    int maxLen = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int curMax = DFSlongestIncreasingPath(matrix, cache, i, j, m, n);
            maxLen = max(maxLen, curMax);
        }
    }
    return maxLen;
}