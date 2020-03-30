//Given an integer n, return all distinct solutions to the n - queens puzzle.
//
//Each solution contains a distinct board configuration of the n - queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
//
//Example:
//
//Input: 4
//Output : [
//    [".Q..",  // Solution 1
//        "...Q",
//        "Q...",
//        "..Q."],
//
//        ["..Q.",  // Solution 2
//        "Q...",
//        "...Q",
//        ".Q.."]
//]
//Explanation: There exist two distinct solutions to the 4 - queens puzzle as shown above.

#include "pch.h";
bool isSafe(vector<int> board, int k) {
	for (int i = 0; i < k; i++) {
		if (board[i] == board[k] // placed in the same column
			|| abs(board[i] - board[k]) == k - i)// placed in diagiagnal
			return false;
	}
	return true;
}
void printResult(vector<vector<string>>& result, vector<int> board) {
	vector<string> currentSolution;
	for (int i = 0; i < board.size(); i++) {
		string line(board.size(), '.');
		line[board[i]] = 'Q';
		currentSolution.push_back(line);
	}
	result.push_back(currentSolution);
}
void buildNQueenBoard(vector<vector<string>> & result, vector<int> &board, int k, int n) {
	if (k == n) {
		printResult(result, board);
		return;
	}
	for (int i = 0; i < n; i++) {
		board[k] = i;
		if (isSafe(board, k)) {
			buildNQueenBoard(result, board, k + 1, n);
		}
	}
}
vector<vector<string>> Solution::solveNQueens(int n) {
	vector<vector<string>> result;
	vector<int> board(n, 0); // board[i] contains the index where board row i is chosen.
	buildNQueenBoard(result, board, 0, n);
	return result;
}