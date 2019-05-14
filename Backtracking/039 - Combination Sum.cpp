
#include "pch.h"

void combinationSumHelper(vector<int> candidates, vector<vector<int>>& ret, vector<int> item, int target, int start) {
	if (target == 0) {
		ret.push_back(item);
		return;
	}
	if (target < 0) {
		return;
	}
	for (int i = start; i < candidates.size(); i++) {
		item.push_back(candidates[i]);
		combinationSumHelper(candidates, ret, item, target - candidates[i], i);
		item.pop_back();
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> ret;
	vector<int> item;
	combinationSumHelper(candidates, ret, item, target, 0);
	return ret;
}