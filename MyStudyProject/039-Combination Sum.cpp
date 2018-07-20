//Given a set of candidate numbers(C) and a target number(T), find all unique combinations in C where the candidate numbers sums to T.
//
//The same repeated number may be chosen from C unlimited number of times.
//
//Note:
//All numbers(including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//For example, given candidate set[2, 3, 6, 7] and target 7,
//A solution set is :
//[
//    [7],
//    [2, 2, 3]
//]

#include "Header.h";

void combinationSumHelper(vector<int> candidates, int target, vector<int>& item, vector<vector<int>>& ret, int start) {
	if (target < 0) {
		return;
	}
	if (target == 0) {
		ret.push_back(item);
		return;
	}
	for (int i = start; i < candidates.size(); i++) {
		item.push_back(candidates[i]);
		combinationSumHelper(candidates, target - candidates[i], item, ret, i);
		item.pop_back();
	}
}
vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ret;
	vector<int> item;
	combinationSumHelper(candidates, target, item, ret, 0);
    return ret;
}