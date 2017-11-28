﻿//Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner(row1, col1) and lower right corner(row2, col2).
//
//The above rectangle(with the red border) is defined by(row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.
//Example:
//Given matrix = [
//    [3, 0, 1, 4, 2],
//        [5, 6, 3, 2, 1],
//        [1, 2, 0, 1, 5],
//        [4, 1, 0, 1, 7],
//        [1, 0, 3, 0, 5]
//]
//
//sumRegion(2, 1, 4, 3) -> 8
//sumRegion(1, 1, 2, 2) -> 11
//sumRegion(1, 2, 2, 4) -> 12
//
//Note:
//You may assume that the matrix does not change.
//There are many calls to sumRegion function.
//You may assume that row1 ≤ row2 and col1 ≤ col2.

#include "Header.h";

class NumMatrix {
private:
    vector<vector<int>> sums;
    int m = 0;
    int n = 0;
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty()) {
            return;
        }
        m = matrix.size();
        n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            vector<int> line;
            if (i == 0) {
                line.push_back(matrix[0][0]);
                for (int j = 1; j < n; j++) {
                    line.push_back(line[j - 1] + matrix[i][j]);
                }
            }
            else {
                line.push_back(matrix[i][0] + sums[i - 1][0]);
                for (int j = 1; j < n; j++) {
                    line.push_back(sums[i - 1][j] + line[j - 1] - sums[i - 1][j - 1] + matrix[i][j]);
                }
            }
            sums.push_back(line);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row2 == 0 && col2 == 0) {
            return sums[0][0];
        }
        if (row1 == 0 && col1 == 0 && row2 == m - 1 && col2 == n - 1) {
            return sums[m - 1][n - 1];
        }
        if (row1 == 0) {
            return sums[row2][col2] - sums[row2][col1 - 1];
        }
        if (col1 == 0) {
            return sums[row2][col2] - sums[row1 - 1][col2];
        }

        return sums[row2][col2] - sums[row1 - 1][col2] - sums[row2][col1 - 1] + sums[row1 - 1][col1 - 1];
    }
};
//int main() {
//    vector<vector<int>> matrix2 = {
//        { 1, 0, 0, 1 },
//        { 1, 1, 0, 1 },
//        { 1, 1, 0, 1 },
//        { 0, 1, 1, 1 } };
//    NumMatrix n(matrix2);
//}
