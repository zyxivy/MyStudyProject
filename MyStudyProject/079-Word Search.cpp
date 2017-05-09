//Given a 2D board and a word, find if the word exists in the grid.
//
//The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.The same letter cell may not be used more than once.
//
//For example,
//Given board =
//
//[
//    ['A', 'B', 'C', 'E'],
//    ['S', 'F', 'C', 'S'],
//    ['A', 'D', 'E', 'E']
//]
//word = "ABCCED", ->returns true,
//word = "SEE", ->returns true,
//word = "ABCB", ->returns false.

#include "Header.h";

bool dfs(vector<vector<char>>& board, vector<vector<bool>>& flag, string word, int boardi, int boardj, int wordk) {
    if ((boardi < 0 || boardi >= board.size()) || (boardj < 0 || boardj >= board[0].size()) || board[boardi][boardj]!= word[wordk] || flag[boardi][boardj]) {
        return false;
    }
    if (wordk == word.length() - 1) {
        return true;
    }
    flag[boardi][boardj] = true;
    if (dfs(board, flag, word, boardi + 1, boardj, wordk + 1)) {
        return true;
    }
    if (dfs(board, flag, word, boardi, boardj + 1, wordk + 1)) {
        return true;
    }
    if (dfs(board, flag, word, boardi - 1, boardj, wordk + 1)) {
        return true;
    }
    if (dfs(board, flag, word, boardi, boardj - 1, wordk + 1)) {
        return true;
    }

    flag[boardi][boardj] = false;
    return false;
}
bool Solution::exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    if (m > 0) {
        int n = board[0].size();
        int i = 0, j = 0;
        vector<vector<bool>> flag(m, vector<bool>(n, false));
        for (i = 0;i < m;i++) {
            for (j = 0;j < n;j++) {
                if (dfs(board, flag, word, i, j, 0)) {
                    return true;
                }
            }
        }
    }
    
    return false;
}