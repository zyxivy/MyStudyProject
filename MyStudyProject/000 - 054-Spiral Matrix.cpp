//Given a matrix of m x n elements(m rows, n columns), return all elements of the matrix in spiral order.
//
//For example,
//Given the following matrix :
//
//[
//    [1, 2, 3],
//    [4, 5, 6],
//    [7, 8, 9]
//]
//You should return[1, 2, 3, 6, 9, 8, 7, 4, 5].

#include "Header.h";
vector<int> Solution::spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ret;
    int n = matrix.size();
    //if (n == 1) {
    //    for (int i = 0;i < matrix[0].size();i++) {
    //        ret.push_back(matrix[0][i]);
    //        return ret;
    //    }
    //}
    for (int k = 0;k < n / 2 + n % 2;k++) {
        int i = k;
        int j = k;
        
        for (j = k;(int)matrix[k].size() - k - 1>=0 && j <= matrix[k].size() - k - 1;j++) {
            ret.push_back(matrix[i][j]);
        }
        j = matrix[k].size() - k - 1;
        if (j >= 0) {
            for (i = k + 1;n - k - 1 >= 0 && i <= n - k - 1;i++) {
                ret.push_back(matrix[i][j]);
            }
        }

        i = n - k - 1;
        if (n - k - 1 > 0) {
            for (j = matrix[n-k-1].size() - k - 2;j >= k;j--) {
                ret.push_back(matrix[i][j]);
            }
        }
        if (matrix[0].size() > 1) {
            j = k;
            if (n - k - 2 > k) {
                for (i = n - k - 2;i >= k + 1;i--) {
                    ret.push_back(matrix[i][j]);
                }
            }
        }
    }
    return ret;
}