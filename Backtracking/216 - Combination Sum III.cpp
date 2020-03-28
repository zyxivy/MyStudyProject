//Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//
//Note:
//
//All numbers will be positive integers.
//The solution set must not contain duplicate combinations.
//Example 1 :
//
//	Input : k = 3, n = 7
//	Output : [[1, 2, 4]]
//	Example 2 :
//
//	Input : k = 3, n = 9
//	Output : [[1, 2, 6], [1, 3, 5], [2, 3, 4]]

#include "pch.h";

void buildResultCombinationSum3(int k, int n, vector<vector<int>>& result, vector<int> cur, int startNum)
{
	if (n == 0 && cur.size() == k) {
		result.push_back(cur);
		return;
	}
	if (cur.size() >= k) {
		return;
	}
	for (int i = startNum; i <= 9 && n >= i; i++) {
		cur.push_back(i);
		buildResultCombinationSum3(k, n - i, result, cur, i + 1);
		cur.pop_back();
	}
}
vector<vector<int>> Solution::combinationSum3(int k, int n)
{
	vector<vector<int>> result;
	if (k == 0 || n == 0) {
		return result;
	}
	vector<int> cur;
	buildResultCombinationSum3(k, n, result, cur, 1);
	return result;
}