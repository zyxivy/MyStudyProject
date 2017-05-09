//Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
//For example,
//Given n = 3,
//
//You should return the following matrix :
//[
//    [1, 2, 3],
//    [8, 9, 4],
//    [7, 6, 5]
//]

#include "Header.h";

vector<vector<int>> Solution::generateSpiralMatrix(int n) {
    vector<vector<int>> matrix;
    if (n == 0) {
        return matrix;
    }
    for (int i = 0;i < n;i++) {
        vector<int> row(n,0);
        matrix.push_back(row);
    }
    int count = 1;
    for (int k = 0;k < n / 2 + n % 2;k++) {
        int i = k;
        int j = k;
        for (j = k;j <= n - k - 1;j++) {
            matrix[i][j] = count++;
        }
        j = n - k - 1;
        for (i = k + 1;i <= n - k - 1;i++) {
            matrix[i][j] = count++;
        }
        i = n - k - 1;
        for (j = n - k - 2;j >= k;j--) {
            matrix[i][j] = count++;
        }
        j = k;
        for (i = n - k - 2;i >= k+1;i--) {
            matrix[i][j] = count++;
        }
    }
    return matrix;
}