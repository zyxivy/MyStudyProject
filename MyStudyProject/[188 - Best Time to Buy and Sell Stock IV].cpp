//Say you have an array for which the ith element is the price of a given stock on day i.
//Design an algorithm to find the maximum profit.You may complete at most k transactions.
//Note:
//You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).

#include "Header.h";
//http://www.cnblogs.com/grandyang/p/4295761.html
//http://www.programcreek.com/2014/03/leetcode-best-time-to-buy-and-sell-stock-iv-java/
int solveMaxProfit(vector<int> &prices) {
    int res = 0;
    for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] - prices[i - 1] > 0) {
            res += prices[i] - prices[i - 1];
        }
    }
    return res;
}
int Solution::maxProfit(int k, vector<int>& prices) {
    if (prices.empty()) return 0;
    if (k >= prices.size()) return solveMaxProfit(prices);
    vector<int> g(k + 1, 0);
    vector<int> l(k + 1, 0);
    for (int i = 0; i < prices.size() - 1; ++i) {
        int diff = prices[i + 1] - prices[i];
        for (int j = k; j >= 1; --j) {
            l[j] = g[j - 1] + (diff > 0 ? diff : 0) > l[j] + diff ? g[j - 1] + (diff > 0 ? diff : 0) : l[j] + diff;
            g[j] = g[j] > l[j] ? g[j] : l[j];
        }
    }
    return g[k];
}