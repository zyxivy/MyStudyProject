//Determine if a Sudoku is valid, according to : Sudoku Puzzles - The Rules.
//
//The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

#include "Header.h";

//Rules:
//1. Each row must have the numbers 1 - 9 occuring just once.
//2. Each column must have the numbers 1 - 9 occuring just once.
//3.And the numbers 1 - 9 must occur just once in each of the 9 sub - boxes of the grid.

bool checkRuleOne(vector<vector<char>>& board) {
    for (int i = 0;i < 9;i++) {
        int table[] = { 0,0,0,0,0,0,0,0,0 };
        for (int j = 0;j <9;j++) {
            if (board[i][j] != '.' && table[(board[i][j]-'1')] == 0) {
                table[(board[i][j] - '1')] = 1;
            }
            else if(board[i][j] != '.' && table[(board[i][j] - '1')] == 1){
                return false;
            }
        }
    }
    return true;
}

bool checkRuleTwo(vector<vector<char>>& board) {
    for (int i = 0;i < 9;i++) {
        int table[] = { 0,0,0,0,0,0,0,0,0 };

        for (int j = 0;j < 9;j++) {
            if (board[j][i] != '.' && table[(board[j][i] - '1')] == 0) {
                table[(board[j][i] - '1')] = 1;
            }
            else if (board[j][i] != '.' && table[(board[j][i] - '1')] == 1) {
                return false;
            }
        }
    }
    return true;
}

bool checkRuleThree(vector<vector<char>>& board) {

    int stepi = 2;
    int stepj = 2;
    for (stepi = 2;stepi >= 0;stepi--) {
        for (stepj = 2;stepj >= 0;stepj--) {
            int table[] = { 0,0,0,0,0,0,0,0,0 };
            for (int i = stepi * 3;i < stepi * 3 + 3;i++) {
                for (int j = stepj * 3;j < stepj * 3+3;j++) {
                    if (board[i][j] != '.' && table[(board[i][j] - '1')] == 0) {
                        table[(board[i][j] - '1')] = 1;
                    }
                    else if (board[i][j] != '.' && table[(board[i][j] - '1')] == 1) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

bool Solution::isValidSudoku(vector<vector<char>>& board) {
    if (board.size() != 9) {
        return false;
    }
    for (int i = 0;i < board.size();i++) {
        if (board[i].size() != 9) {
            return false;
        }
    }
    return checkRuleOne(board) && checkRuleTwo(board) && checkRuleThree(board);
}