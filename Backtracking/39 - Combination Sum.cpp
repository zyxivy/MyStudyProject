//Given a set of candidate numbers(candidates) (without duplicates) and a target number(target), find all unique combinations in candidates where the candidate numbers sums to target.
//
//The same repeated number may be chosen from candidates unlimited number of times.
//
//Note:
//
//All numbers(including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//Example 1 :
//
//	Input : candidates = [2, 3, 6, 7], target = 7,
//	A solution set is :
//[
//	[7],
//	[2, 2, 3]
//]
//Example 2 :
//
//	Input : candidates = [2, 3, 5], target = 8,
//	A solution set is :
//[
//	[2, 2, 2, 2],
//	[2, 3, 3],
//	[3, 5]
//]

#include "pch.h";
void buildResult(vector<int>& candidates, vector<vector<int>>& result, vector<int> cur, int startPos, int target)
{
	if (target == 0) {
		result.push_back(cur);
		return;
	}
	if (target < 0) {
		return;
	}
	for (int i = startPos; i < candidates.size() && target >= candidates[i]; i++) {
		cur.push_back(candidates[i]);
		buildResult(candidates, result, cur, i, target - candidates[i]);
		cur.pop_back();
	}

}
vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> result;
	if (candidates.empty()) {
		return result;
	}
	vector<int> cur;
	sort(candidates.begin(), candidates.end());// sort input so we can skip with target > candidates[i]
	buildResult(candidates, result, cur, 0, target );
	return result;
}