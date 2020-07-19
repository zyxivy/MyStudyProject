//Your are given an array of integers prices, for which the i - th element is the price of a given stock on day i;and a non - negative integer fee representing a transaction fee.
//
//You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.You may not buy more than 1 share of a stock at a time(ie.you must sell the stock share before you buy again.)
//
//Return the maximum profit you can make.
//
//Example 1:
//Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
//Output : 8
//Explanation : The maximum profit can be achieved by :
//Buying at prices[0] = 1
//Selling at prices[3] = 8
//Buying at prices[4] = 4
//Selling at prices[5] = 9
//The total profit is((8 - 1) - 2) + ((9 - 4) - 2) = 8.
//Note :
//
//	0 < prices.length <= 50000.
//	0 < prices[i] < 50000.
//	0 <= fee < 50000.

#include "pch.h";
int maxProfitWithFee(vector<int>& prices, int fee) {
	if (prices.empty()) {
		return 0;
	}
	size_t n = prices.size();
	vector<int> buy(n, 0);
	vector<int> sell(n, 0);
	buy[0] = -prices[0] - fee;
	sell[0] = 0;
	for (size_t i = 1; i < n; i++) {
		buy[i] = max(sell[i - 1] - prices[i] - fee, buy[i - 1]);
		sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
	}
	return sell[n - 1];
}

int maxProfitWithFeeSimplified(vector<int>& prices, int fee) {
	if (prices.empty()) {
		return 0;
	}
	size_t n = prices.size();
	int preBuy = -prices[0] - fee;
	int preSell = 0;
	for (size_t i = 1; i < n; i++) {
		int curBuy = max(preSell - prices[i] - fee, preBuy);
		int curSell = max(preBuy + prices[i], preSell);
		preBuy = curBuy;
		preSell = curSell;
	}
	return preSell;
}