//Given a collection of candidate numbers(candidates) and a target number(target), find all unique combinations in candidates where the candidate numbers sums to target.
//
//Each number in candidates may only be used once in the combination.
//
//Note:
//
//All numbers(including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//Example 1 :
//
//	Input : candidates = [10, 1, 2, 7, 6, 1, 5], target = 8,
//	A solution set is :
//[
//	[1, 7],
//	[1, 2, 5],
//	[2, 6],
//	[1, 1, 6]
//]
//Example 2:
//
//Input: candidates = [2, 5, 2, 1, 2], target = 5,
//	A solution set is :
//	   [
//		   [1, 2, 2],
//		   [5]
//	   ]

#include "Header.h";
void combinationSumHelper2(vector<int> candidates, int target, vector<int>& item, vector<vector<int>>& ret, int start) {
	if (target < 0) {
		return;
	}
	if (target == 0) {
		ret.push_back(item);
		return;
	}
	for (int i = start; i < candidates.size(); i++) {
		if (i > start && candidates[i - 1] == candidates[i])
			continue;
		item.push_back(candidates[i]);
		combinationSumHelper2(candidates, target - candidates[i], item, ret, i+1);
		item.pop_back();
	}
}
vector<vector<int>> Solution::combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> ret;
	vector<int> item;
	sort(candidates.begin(), candidates.end());
	combinationSumHelper2(candidates, target, item, ret, 0);
	return ret;
}