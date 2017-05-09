//The n - queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
//
//
//
//Given an integer n, return all distinct solutions to the n - queens puzzle.
//
//Each solution contains a distinct board configuration of the n - queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
//
//For example,
//There exist two distinct solutions to the 4 - queens puzzle :
//
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

#include "Header.h";


bool isSafe(vector<int>& A, int k) {
    for (int i = 0;i < k;i++) {
        if (A[i] == A[k] || (abs(A[i] - A[k]) == k - i)) {
            return false;
        }
    }
    return true;
}

void print(vector<vector<string>>& record, vector<int> A) {
    vector<string> rec;
    for (int i = 0;i < A.size();i++) {
        string str (A.size(), '.');        
        str[A[i]] = 'Q';
        rec.push_back(str);
    }
    record.push_back(rec);
}

void NQueens(vector<vector<string>>& record, vector<int>& A, int k, int n) {
    if (k == n) {
        print(record, A);
        return;
    }
    for (int i = 0;i < n;i++) {
        A[k] = i;
        if (isSafe(A,k)) {
            NQueens(record, A, k + 1, n);
        }
    }
}

vector<vector<string>> Solution::solveNQueens(int n) {
    vector<vector<string>> record;
    vector<int> A(n,0);
    NQueens(record, A, 0, n);
    return record;
}