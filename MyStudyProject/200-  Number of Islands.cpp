//Given a 2d grid map of '1's(land) and '0's(water), count the number of islands.An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.You may assume all four edges of the grid are all surrounded by water.
//Example 1:
//11110
//11010
//11000
//00000
//Answer : 1
//    Example 2 :
//    11000
//    11000
//    00100
//    00011
//    Answer : 3

#include "Header.h";

void searchIslands(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& mark) {
    mark[i][j] = false;

    if (i + 1<grid.size() && grid[i + 1][j] == '1' && mark[i + 1][j] == true) {
        searchIslands(i + 1, j, grid, mark);
    }
    if (j + 1<grid[0].size() && grid[i][j + 1] == '1' && mark[i][j + 1] == true) {
        searchIslands(i, j + 1, grid, mark);
    }
    if (i - 1 >= 0 && grid[i - 1][j] == '1' && mark[i - 1][j] == true) {
        searchIslands(i - 1, j, grid, mark);
    }
    if (j - 1 >= 0 && grid[i][j - 1] == '1' && mark[i][j - 1] == true) {
        searchIslands(i, j - 1, grid, mark);
    }
}

int Solution::  numIslands(vector<vector<char>>& grid) {
    int row = grid.size();
    if (row == 0) return 0;
    int col = grid[0].size();

    int res = 0;

    vector<vector<bool> > mark(row, vector<bool>(col, true));

    for (int i = 0; i<row; i++) {
        for (int j = 0; j<col; j++) {
            if (grid[i][j] == '1' && mark[i][j] == true) {
                searchIslands(i, j, grid, mark);
                res += 1;
            }
        }
    }
    return res;
}