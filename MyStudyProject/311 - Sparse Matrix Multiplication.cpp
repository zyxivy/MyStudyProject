//Given two sparse matrices A and B, return the result of AB.
//You may assume that A's column number is equal to B's row number.
//Example:
//A = [
//    [1, 0, 0],
//        [-1, 0, 3]
//]
//
//B = [
//    [7, 0, 0],
//        [0, 0, 0],
//        [0, 0, 1]
//]
//
//
//| 1 0 0 |   | 7 0 0 |   |  7 0 0 |
//AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
//| 0 0 1 |

#include "Header.h";
vector<vector<int>> Solution::multiplySparseMatrix(vector<vector<int>>& A, vector<vector<int>>& B) {
    int m = A.size();
    int n = B.size();   
    if (m == 0 || n == 0) {
        vector<vector<int>> re;
        return re;
    }
    int l = B[0].size();

    vector<vector<int>> res(m, vector<int>(l,0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; n++) {
            if (A[i][j] != 0) {
                for (int k = 0; k < l; k++) {
                    if (B[j][k] != 0) {
                        res[i][k] += A[i][j] * B[j][k];
                    }
                }
            }

        }
    }

    return res;
}