#include "pch.h";
bool searchMatrixII(vector<vector<int>>& matrix, int target) {
	if (matrix.empty() || matrix[0].empty()) {
		return false;
	}

	int m = matrix.size();
	int n = matrix[0].size();
	int row = m - 1, col = 0;//left bottom corner
	while (row >= 0 && col < n) {
		if (target < matrix[row][col]) {
			row--;
		}
		else if (target > matrix[row][col]) {
			col++;
		}
		else {
			return true;
		}
	}
	return false;
}