//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit.You may complete at most two transactions.
//
//Note:
//You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).



//Comparing to I and II, III limits the number of transactions to 2. 
//This can be solve by "devide and conquer".We use left[i] to track the maximum profit for transactions before i, and use right[i] to track the maximum profit for transactions after i.
//You can use the following example to understand the Java solution :
//
//Prices : 1 4 5 7 6 3 2 9
//    left = [0, 3, 4, 6, 6, 6, 6, 8]
//    right = [8, 7, 7, 7, 7, 7, 7, 0]
//    The maximum profit = 13
#include "Header.h";
int Solution::maxProfitIII(vector<int>& prices) {
    if (prices.size() == 0) {
        return 0;
    }
    vector<int> left(prices.size(), 0);
    vector<int> right(prices.size(), 0);
    int min = prices[0];
    for (int i = 1;i < prices.size();i++) {
        min = min <= prices[i] ? min : prices[i];
        left[i] = prices[i] - min > left[i - 1] ? prices[i] - min : left[i - 1];
    }
    int max = prices[prices.size()-1];
    for (int i = prices.size() - 2;i>=0;i--) {
        max = max >= prices[i] ? max : prices[i];
        right[i] = max - prices[i] > right[i + 1] ? max-prices[i] : right[i+ 1];
    }

    int profit = 0;
    for (int i = 0;i < prices.size();i++) {
        profit = profit > left[i] + right[i] ? profit : left[i] + right[i];
    }
    return profit;
}