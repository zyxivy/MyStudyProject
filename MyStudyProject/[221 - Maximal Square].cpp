//Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
//For example, given the following matrix :
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//Return 4.

#include "Header.h";

//http://yucoding.blogspot.com/2015/10/leetcode-question-maximal-square.html
int Solution::maximalSquare(vector<vector<int>>& matrix) {
	int row = matrix.size();
	if (row == 0) { return 0; }
	int col = matrix[0].size();

	vector<vector<int> > state(row, vector<int>(col));

	int res = 0;
	for (int i = 0; i<row; i++) {
		for (int j = 0; j<col; j++) {
			if (matrix[i][j] == '1') {
				state[i][j] = 1;
				res = 1;
			}
		}
	}
	for (int i = 1; i<row; i++) {
		for (int j = 1; j<col; j++) {
			if (state[i][j] != 0) {
				state[i][j] = 1 + min(state[i - 1][j], min(state[i][j - 1], state[i - 1][j - 1]));
				if (res<state[i][j]) { res = state[i][j]; }
			}
		}
	}
	return res*res;
}