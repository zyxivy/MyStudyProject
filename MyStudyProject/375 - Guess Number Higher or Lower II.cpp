//We are playing the Guess Game.The game is as follows :
//
//I pick a number from 1 to n.You have to guess which number I picked.
//
//Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
//
//However, when you guess a particular number x, and you guess wrong, you pay $x.You win the game when you guess the number I picked.
//
//Example:
//
//n = 10, I pick 8.
//
//First round : You guess 5, I tell you that it's higher. You pay $5.
//Second round : You guess 7, I tell you that it's higher. You pay $7.
//Third round : You guess 9, I tell you that it's lower. You pay $9.
//
//Game over. 8 is the number I picked.
//
//You end up paying $5 + $7 + $9 = $21.
//Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.

#include "Header.h";

//Definition of dp[i][j]: minimum number of money to guarantee win for subproblem[i, j].
//
//Target : dp[1][n]
//
//    Corner case: dp[i][i] = 0 (because the only element must be correct)

//Equation : we can choose k(i <= k <= j) as our guess, and pay price k.
//After our guess, the problem is divided into two subproblems.
//Notice we do not need to pay the money for both subproblems.
//We only need to pay the worst case (because the system will tell us which side we should go) to guarantee win.
//So dp[i][j] = min(i <= k <= j) { k + max(dp[i][k - 1], dp[k + 1][j]) }

int getMoneyAmountDP(vector<vector<int>>& table, int start, int end) {
    if (start >= end) {
        return 0;
    }
    if (table[start][end] != 0) {
        return table[start][end];
    }

    int ret = INT_MAX;
    for (int x = start; x < end; x++) {
        int tmp = x + max(getMoneyAmountDP(table, start, x - 1), getMoneyAmountDP(table, x + 1, end));
        ret = min(ret, tmp);
    }
    table[start][end] = ret;
    return ret;
}
int Solution::getMoneyAmount(int n) {
    vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));
    return getMoneyAmountDP(table, 1, n);
}