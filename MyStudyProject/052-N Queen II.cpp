//Follow up for N - Queens problem.
//
//Now, instead outputting board configurations, return the total number of distinct solutions.

#include "Header.h";


bool isSafeII(vector<int>& A, int k) {
    for (int i = 0;i < k;i++) {
        if (A[i] == A[k] || (abs(A[i] - A[k]) == k - i)) {
            return false;
        }
    }
    return true;
}

void printII(vector<vector<string>>& record, vector<int> A) {
    vector<string> rec;
    for (int i = 0;i < A.size();i++) {
        string str(A.size(), '.');
        str[A[i]] = 'Q';
        rec.push_back(str);
    }
    record.push_back(rec);
}

void NQueensII(vector<vector<string>>& record, vector<int>& A, int k, int n) {
    if (k == n) {
        printII(record, A);
        return;
    }
    for (int i = 0;i < n;i++) {
        A[k] = i;
        if (isSafeII(A, k)) {
            NQueensII(record, A, k + 1, n);
        }
    }
}

int Solution::solveNQueensII(int n) {
    vector<vector<string>> record;
    vector<int> A(n, 0);
    NQueensII(record, A, 0, n);
    return record.size();
}