//Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//A region is captured by flipping all 'O's into 'X's in that surrounded region.
//For example,
//X X X X
//X O O X
//X X O X
//X O X X
//
//After running your function, the board should be :
//X X X X
//X X X X
//X X X X
//X O X X

#include "Header.h";

//DFS solution.Find all the ‘O’ connect to edge and change them to ‘#’.Then, change all the ‘O’ to ‘X’ and all the ‘#’ to ‘O’.

void dfsSearchRegion(vector<vector<char>> &board, int i, int j) {
    board[i][j] = '#';

    if (i + 1 < board.size() && board[i + 1][j] == 'O') {
        dfsSearchRegion(board, i + 1, j);
    }
    if (i - 1 > 0 && board[i - 1][j] == 'O') {
        dfsSearchRegion(board, i - 1, j);
    }
    if (j + 1 < board[i].size() && board[i][j + 1] == 'O') {
        dfsSearchRegion(board, i, j + 1);
    }
    if (j - 1 >0 && board[i][j - 1] == 'O') {
        dfsSearchRegion(board, i, j - 1);
    }
}

void Solution::SurroundedRegions(vector<vector<char>>& board) {
    if (board.size() == 0) {
        return;
    }
    int row = board.size();
    int col = board[0].size();

    for (int j = 0;j < col;j++) {
        if (board[0][j] == 'O') {
            dfsSearchRegion(board, 0, j);
        }
        if (row>1 && board[row - 1][j] == 'O') {
            dfsSearchRegion(board, row - 1, j);
        }
    }
    for (int i = 0;i < row;i++) {
        if (board[i][0] == 'O') {
            dfsSearchRegion(board, i, 0);
        }
        if (board[i].size() >1 && board[i][board[i].size() - 1] == 'O') {
            dfsSearchRegion(board, i, board[i].size() - 1);
        }
    }
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < board[i].size();j++) {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < board[i].size();j++) {
            if (board[i][j] == '#')
                board[i][j] = 'O';
        }
    }
}