//Given an integer n, return the number of distinct solutions to the n - queens puzzle.
//
//Example:
//
//Input: 4
//Output : 2
//Explanation : There are two distinct solutions to the 4 - queens puzzle as shown below.
//[
//    [".Q..",  // Solution 1
//    "...Q",
//    "Q...",
//    "..Q."],
//
//    ["..Q.",  // Solution 2
//    "Q...",
//    "...Q",
//    ".Q.."]
//]

#include "pch.h";

int totalNQueensCnt=0;

//用column标记此行之前的哪些column已经放置了queen.棋盘坐标(row, col)对应column的第col位(LSB-- > MSB, 下同).
//用diag标记此位置之前的哪些主对角线已经放置了queen.棋盘坐标(row, col)对应diag的第(n - 1 + row - col)位. 每条对角线row - col相同， 加n-1防止负数
//用antiDiag标记此位置之前的哪些副对角线已经放置了queen.棋盘坐标(row, col)对应antiDiag的第(row + col)位. 每条反对角线row+col相同。
void buildNQueenBoard(int row, int column, int diag, int antiDiag, int n) {
	if (row == n) {
		totalNQueensCnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		bool isColumnSafe = ((1 << i) & column) == 0;
		bool isDiagSafe = ((1 << (n - 1 + row - i)) & diag) == 0;
		bool isAntiDiagSafe = ((1 << (row + i)) & antiDiag) == 0;
		if (isColumnSafe && isDiagSafe && isAntiDiagSafe) {
			buildNQueenBoard(row+1, (1 << i) | column, (1 << (n - 1 + row - i)) | diag, (1 << (row + i)) | antiDiag, n);
		}
	}
}
int Solution::totalNQueens(int n) {
	vector<int> board(n, 0); // board[i] contains the index where board row i is chosen.
	buildNQueenBoard(0, 0, 0, 0, n);
	return totalNQueensCnt;
}