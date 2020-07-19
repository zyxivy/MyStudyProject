//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit.You may complete as many transactions as you like(ie, buy one and sell one share of the stock multiple times) with the following restrictions :
//
//You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).
//After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
//Example :
//
//	Input : [1, 2, 3, 0, 2]
//	Output : 3
//	Explanation : transactions = [buy, sell, cooldown, buy, sell]

#include "pch.h";

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
// coolDown[i] = max(coolDown[i-1], sell[i-1])
// buy[i]= max(coolDown[i-1] - price[i], buy[i-1])
// coolDown, sell[i] = buy[i-1] + price[i]

int maxProfitWithCoolDown(vector<int>& prices) {
	if (prices.empty()) {
		return 0;
	}
	int n = prices.size();
	vector<int> coolDown(n, 0);
	vector<int> buy(n, 0);
	vector<int> sell(n, 0);
	coolDown[0] = 0;
	buy[0] = -prices[0];
	sell[0] = INT_MIN;

	for (int i = 1; i < n; i++) {
		coolDown[i] = max(coolDown[i - 1], sell[i - 1]);
		buy[i] = max(coolDown[i - 1] - prices[i], buy[i - 1]);
		sell[i] = buy[i - 1] + prices[i];
	}
	return max(coolDown[n - 1], sell[n - 1]);
}

int maxProfitWithCoolDownSimplified(vector<int>& prices) {
	if (prices.empty()) {
		return 0;
	}
	int n = prices.size();
	int preCoolDown = 0;
	int preBuy = -prices[0];
	int preSell = INT_MIN;

	for (int i = 1; i < n; i++) {
		int tmp = preSell;
		preSell = preBuy + prices[i];
		preBuy = max(preCoolDown - prices[i], preBuy);
		preCoolDown = max(preCoolDown, tmp);
	}
	return max(preCoolDown, preSell);
}