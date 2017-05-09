//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
//For example, given the following matrix :
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//Return 6.



#include "Header.h";
int Solution::maximalRectangle(vector<vector<char>>& matrix) {

    int maxArea = 0;
    //http://yucoding.blogspot.com/2013/01/incomplete-leetcode-question-47-maximal.html
    {
        int m = matrix.size();
        if (m > 0) {
            int n = matrix[0].size();
            vector<vector<int>> ones(m, vector<int>(n, 0));
            for (int i = 0;i < m;i++) {
                for (int j = 0;j < n;j++) {
                    if (matrix[i][j] == '1') {
                        ones[i][j] = (j == 0 ? 1 : ones[i][j - 1] + 1);
                    }
                }
            }
            for (int i = 0;i < m;i++) {
                for (int j = 0;j < n;j++) {
                    if (ones[i][j]>0) {
                        int min = ones[i][j];
                        if (maxArea < ones[i][j]) {
                            maxArea = ones[i][j];
                        }
                        int h = i - 1;
                        while (h >= 0) {
                            if (ones[h][j] < min) {
                                min = ones[h][j];
                            }
                            if (maxArea < (i - h + 1)*min) {
                                maxArea = (i - h + 1)*min;
                            }
                            h--;
                        }
                    }
                }
            }
        }
    }

    //http://www.programcreek.com/2014/05/leetcode-maximal-rectangle-java/
    {
        int m = matrix.size();
        if (m > 0) {
            int n = matrix[0].size();
            vector<vector<int>> heights(m, vector<int>(n + 1, 0));
            for (int i = 0;i < m;i++) {
                for (int j = 0;j < n;j++) {
                    if (matrix[i][j] == '1') {
                        heights[i][j] = (i == 0 ? 1 : heights[i - 1][j] + 1);
                    }
                }
            }
            for (int i = 0;i < m;i++) {
                int tmp = largestRectangleArea(heights[i]);
                if (maxArea < tmp) {
                    maxArea = tmp;
                }
            }
        }
    }

    return maxArea;
}