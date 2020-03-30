//Given a collection of integers that might contain duplicates, nums, return all possible subsets(the power set).
//
//Note: The solution set must not contain duplicate subsets.
//
//	Example :
//
//	Input : [1, 2, 2]
//	Output :
//	[
//		[2],
//		[1],
//		[1, 2, 2],
//		[2, 2],
//		[1, 2],
//		[]
//	]

#include "pch.h";
void buildSubsetsWithDup(vector<int> nums, vector<vector<int>>& result, vector<int> item, int startPos) {
	result.push_back(item);
	for (int i = startPos; i < nums.size(); i++) {
		if (i > startPos && nums[i - 1] == nums[i])//i>start
			continue;
		item.push_back(nums[i]);
		buildSubsetsWithDup(nums, result, item, i + 1);
		item.pop_back();
	}
}
vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums) {
	vector<vector<int>> result;
	vector<int> item;
	sort(nums.begin(), nums.end());
	buildSubsetsWithDup(nums, result, item, 0);
	return result;
}