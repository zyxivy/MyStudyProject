//According to the Wikipedia's article: "The Game of Life, also known simply as Life, 
//is a cellular automaton devised by the British mathematician John Horton Conway in 1970." 
//Given a board with m by n cells, each cell has an initial state live(1) or dead(0).
//Each cell interacts with its eight neighbors(horizontal, vertical, diagonal) 
//using the following four rules(taken from the above Wikipedia article) :
//
//    Any live cell with fewer than two live neighbors dies, as if caused by under - population.
//    Any live cell with two or three live neighbors lives on to the next generation.
//    Any live cell with more than three live neighbors dies, as if by over - population..
//    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
//
//    Write a function to compute the next state(after one update) of the board given its current state.
//    Follow up :
//Could you solve it in - place ? Remember that the board needs to be updated at the same time : 
//You cannot update some cells first and then use their updated values to update other cells.
//In this question, we represent the board using a 2D array.In principle, the board is infinite, 
//which would cause problems when the active area encroaches the border of the array.How would you address these problems ?

#include "Header.h";
int countNeighbor(vector<vector<int>> board, int i, int j, int m, int n) {
    vector<int> is = { -1, 0, 1, -1, 1, -1, 0, 1 };
    vector<int> js = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int cnt = 0;
    for (int k = 0; k < 8;k++) {
        int nx = i + is[k];
        int ny = j + js[k];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
            continue;
        }
        if (board[nx][ny] & 1) {
            cnt += 1;
        }
    }
    return cnt;
}

//cnt:
//bit 0: initial state;
//bit 1: final state;
void Solution::gameOfLife(vector<vector<int>>& board) {
    int m = board.size();
    if (m == 0) {
        return;
    }
    int n = board[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int cnt = countNeighbor(board, i, j, m, n);
            if (board[i][j]) {
                if (cnt == 2 || cnt == 3) {
                    board[i][j]=board[i][j]|2;
                }
            }
            else {
                if (cnt == 3) {
                    board[i][j] = 2;
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = ((board[i][j] & 2) == 2);
        }
    }
}