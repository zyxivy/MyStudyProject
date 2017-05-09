//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
//For example,
//If n = 4 and k = 2, a solution is :
//
//[
//    [2, 4],
//    [3, 4],
//    [2, 3],
//    [1, 2],
//    [1, 3],
//    [1, 4],
//]

#include "Header.h";

void dfs(int n, int k, int start, vector<int>& item, vector<vector<int>>& res) {
    if (item.size() == k) {
        res.push_back(item);
        return;
    }

    for (int i = start; i <= n; i++) {
        item.push_back(i);
        dfs(n, k, i + 1, item, res);
        item.pop_back();
    }
}
vector<vector<int>> Solution::combine(int n, int k) {
    vector<vector<int>> ret;
    vector<int> item;
    dfs(n, k, 1, item, ret);
    return ret;
}