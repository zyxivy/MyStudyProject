//Design a Tic - tac - toe game that is played between two players on a n x n grid.
//You may assume the following rules :
//A move is guaranteed to be valid and is placed on an empty block.
//Once a winning condition is reached, no more moves is allowed.
//A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
//Follow up :
//Could you do better than O(n2) per move() operation ?

#include "Header.h";
class TicTacToe {
    vector<int> rows;
    vector<int> cols;
    int diag;
    int rdiag;
    int n;
public:
    TicTacToe(int n) {
        rows.resize(n);
        cols.resize(n);
        diag = 0;
        rdiag = 0;
        n = n;
    }

    /** Player {player} makes a move at ({row}, {col}).
    @param row The row of the board.
    @param col The column of the board.
    @param player The player, can be either 1 or 2.
    @return The current winning condition, can be either:
    0: No one wins.
    1: Player 1 wins.
    2: Player 2 wins. */
    int move(int row, int col, int player) {
        int v = player == 1 ? 1 : -1;

        rows[row] += v;
        cols[col] += v;

        if (row == col) {
            diag += v;
        }
        if (row == n - col - 1) {
            rdiag += v;
        }

        if (abs(rows[row]) == n || abs(cols[col]) == n || abs(diag) == n || abs(rdiag) == n) {
            return player;
        }
        return 0;
    }
};

