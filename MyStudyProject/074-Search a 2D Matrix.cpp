//Write an efficient algorithm that searches for a value in an m x n matrix.This matrix has the following properties :
//
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row.
//For example,
//
//Consider the following matrix :
//
//[
//    [1, 3, 5, 7],
//    [10, 11, 16, 20],
//    [23, 30, 34, 50]
//]
//Given target = 3, return true.
#include "Header.h";
bool Solution::searchMatrix(vector<vector<int>>& matrix, int target) {
    bool ret = false;

    //1
    {
        int m = matrix.size();
        if (m > 0) {
            int n = matrix[0].size();
            if (matrix[0][0] > target || matrix[m - 1][n - 1] < target) {
                return false;
            }

            int i = 0;int j = m - 1;
            while (i <= j) {
                if (matrix[i][0] == target || matrix[j][0] == target) {
                    return true;
                }
                if (matrix[i][0] < target) {
                    i++;
                }
                if (matrix[j][0] > target) {
                    j--;
                }
            }
            if (j < 0) {
                return false;
            }
            int row = j;
            i = 0;j = n - 1;
            while (i <= j) {
                if (matrix[row][i] == target || matrix[row][j] == target) {
                    return true;
                }
                if (matrix[row][i] < target) {
                    i++;
                }
                if (matrix[row][j] > target) {
                    j--;
                }
            }
        }
        return false;
    }

    //2
    {
        int m = matrix.size();
        if (m > 0) {
            int n = matrix[0].size();

            int start = 0;
            int end = m*n - 1;

            while (start <= end) {
                int mid = (start + end) / 2;
                int midX = mid / n;
                int midY = mid%n;

                if (matrix[midX][midY] == target)
                    return true;

                if (matrix[midX][midY]<target) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }

            return false;
        }

    }
}