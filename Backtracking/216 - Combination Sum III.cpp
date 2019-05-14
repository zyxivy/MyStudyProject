#include "pch.h";

void combinationSumHelper(int k, int n, vector<vector<int>>& ret, vector<int> item, int start) {
	if (item.size() == k && n == 0) {
		ret.push_back(item);
		return;
	}
	for (int i = start; i <= 9 && n >= i; i++) {
		item.push_back(i);
		combinationSumHelper(k,n-i, ret, item,  i + 1);
		item.pop_back();
	}
}
vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>> ret;
	vector<int> item;
	combinationSumHelper(k, n, ret, item, 1);
	return ret;
}