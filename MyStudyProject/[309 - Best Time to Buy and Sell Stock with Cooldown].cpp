
//Say you have an array for which the ith element is the price of a given stock on day i.
//Design an algorithm to find the maximum profit.You may complete as many transactions as you like(ie, buy one and sell one share of the stock multiple times) with the following restrictions :
//You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).
//After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
//Example :
//    prices = [1, 2, 3, 0, 2]
//    maxProfit = 3
//    transactions = [buy, sell, cooldown, buy, sell]

#include "Header.h";
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/

//Define Recursion
//buy[i]: Max profit till index i.The series of transaction is ending with a buy.
//sell[i] : Max profit till index i.The series of transaction is ending with a sell.
//buy[i]: To make a decision whether to buy at i, we either take a rest, by just using the old decision at i - 1, or sell at / before i - 2, then buy at i, We cannot sell at i - 1, then buy at i, because of cooldown.
//sell[i] : To make a decision whether to sell at i, we either take a rest, by just using the old decision at i - 1, or buy at / before i - 1, then sell at i.
//So we get the following formula :
//buy[i] = Math.max(buy[i - 1], sell[i - 2] - prices[i]);
//sell[i] = Math.max(sell[i - 1], buy[i - 1] + prices[i]);
int Solution::maxProfitCoolDown(vector<int>& prices) {
    int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;
    for (int price : prices) {
        prev_buy = buy;
        buy = max(prev_sell - price, buy);
        prev_sell = sell;
        sell = max(prev_buy + price, sell);
    }
    return sell;
}