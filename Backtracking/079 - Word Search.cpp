//Given a 2D board and a word, find if the word exists in the grid.
//
//The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.The same letter cell may not be used more than once.
//
//Example:
//
//board =
//[
//	['A', 'B', 'C', 'E'],
//	['S', 'F', 'C', 'S'],
//	['A', 'D', 'E', 'E']
//]
//
//Given word = "ABCCED", return true.
//Given word = "SEE", return true.
//Given word = "ABCB", return false.
//
//
//Constraints:
//
//board and word consists only of lowercase and uppercase English letters.
//1 <= board.length <= 200
//1 <= board[i].length <= 200
//1 <= word.length <= 10 ^ 3

#include "pch.h";
bool findWord(vector<vector<char>>& board, string word, vector<vector<bool>> &used, int wordPos, int i, int j, int m, int n) {
	if (wordPos == word.length()) {
		return true;
	}
	if (i == m || j == n || m < 0 || n < 0) {
		return false;
	}
	if (board[i][j] != word[wordPos] || used[i][j] == true) {
		return false;
	}
	used[i][j] = true;
	if (findWord(board, word, used, wordPos + 1, i + 1, j, m, n))
		return true;
	if (findWord(board, word, used, wordPos + 1, i, j + 1, m, n))
		return true;
	if (findWord(board, word, used, wordPos + 1, i - 1, j, m, n))
		return true;
	if (findWord(board, word, used, wordPos + 1, i, j - 1, m, n))
		return true;

	used[i][j] = false;
	return false;
}
bool exist(vector<vector<char>>& board, string word) {
	int m = board.size();
	if (m > 0) {
		int n = board[0].size();
		vector<vector<bool>> used(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (findWord(board, word, used, 0, i, j, m, n)) {
					return true;
				}
			}
		}
	}
	return false;
}