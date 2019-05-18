#include "pch.h";
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int m = matrix.size();
	if (m == 0) {
		return false;
	}
	int n = matrix[0].size();
	int lo = 0;
	int hi = m * n - 1;
	while (lo <= hi) {
		int mi = (lo + hi) / 2;
		int i = mi / n;
		int j = mi % n;
		if (target == matrix[i][j]) {
			return true;
		}
		else if(target < matrix[i][j]){
			hi = mi - 1;
		}
		else {
			lo = mi + 1;
		}
	}
	return false;
}