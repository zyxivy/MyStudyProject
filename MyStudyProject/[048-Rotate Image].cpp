//You are given an n x n 2D matrix representing an image.
//
//Rotate the image by 90 degrees(clockwise).
//
//Follow up :
//Could you do this in - place ?

#include "Header.h";

/*
* clockwise rotate
* first reverse up to down, then swap the symmetry
* 1 2 3     7 8 9     7 4 1
* 4 5 6  => 4 5 6  => 8 5 2
* 7 8 9     1 2 3     9 6 3
*/
/*
* anticlockwise rotate
* first reverse left to right, then swap the symmetry
* 1 2 3     3 2 1     3 6 9
* 4 5 6  => 6 5 4  => 2 5 8
* 7 8 9     9 8 7     1 4 7
*/

void  Solution::rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> ret;
    for (int i = 0;i < n / 2;i++) {
        for (int j = i;j < n - i - 1;j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = tmp;
        }
    }
    return;
}