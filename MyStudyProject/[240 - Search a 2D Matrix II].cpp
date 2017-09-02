//Write an efficient algorithm that searches for a value in an m x n matrix.This matrix has the following properties :
//
//Integers in each row are sorted in ascending from left to right.
//Integers in each column are sorted in ascending from top to bottom.
//
//For example,
//Consider the following matrix :
//[
//    [1, 4, 7, 11, 15],
//    [2, 5, 8, 12, 19],
//    [3, 6, 9, 16, 22],
//    [10, 13, 14, 17, 24],
//    [18, 21, 23, 26, 30]
//]
//Given target = 5, return true.
//Given target = 20, return false.

#include "Header.h";
//http://bangbingsyb.blogspot.com/2014/11/leetcode-search-2d-matrix.html
bool Solution::searchMatrix2D(vector<vector<int>>& matrix, int target) {
    if (!matrix.size() || !matrix[0].size()) return false;
    int m = matrix.size(), n = matrix[0].size();
    int row = m - 1, col = 0; //left bottom corner
    while (row >= 0 && col<n) {
        if (target<matrix[row][col])
            row--;
        else if (target>matrix[row][col])
            col++;
        else
            return true;
    }
    return false;
}
