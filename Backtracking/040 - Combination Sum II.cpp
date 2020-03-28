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
#include "pch.h";
void buildResultCombinationSumII(vector<int>& candidates, vector<vector<int>>& result, vector<int> cur, int startPos, int target)
{
	if (target == 0) {
		result.push_back(cur);
		return;
	}
	for (int i = startPos; i < candidates.size() && target >= candidates[i]; i++) {
		if (i > startPos && candidates[i] == candidates[i - 1])
			continue;
		cur.push_back(candidates[i]);
		buildResultCombinationSumII(candidates, result, cur, i + 1, target - candidates[i]);
		cur.pop_back();
	}

}

vector<vector<int>> Solution::combinationSumII(vector<int>& candidates, int target) {
	vector<vector<int>> result;
	if (candidates.empty()) {
		return result;
	}
	vector<int> cur;
	sort(candidates.begin(), candidates.end());// sort input so we can skip with target > candidates[i]
	buildResultCombinationSumII(candidates, result, cur, 0, target);
	return result;
}