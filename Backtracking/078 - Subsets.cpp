//Given a set of distinct integers, nums, return all possible subsets(the power set).
//
//Note: The solution set must not contain duplicate subsets.
//
//Example :
//
//    Input : nums = [1, 2, 3]
//    Output :
//    [
//        [3],
//        [1],
//        [2],
//        [1, 2, 3],
//        [1, 3],
//        [2, 3],
//        [1, 2],
//        []
//    ]

#include "pch.h";
void buildSubsets(vector<int> nums, vector<vector<int>>& result, vector<int> item, int startPos) {
	result.push_back(item);
	for (int i = startPos; i < nums.size(); i++) {
		item.push_back(nums[i]);
		buildSubsets(nums, result, item, i + 1);
		item.pop_back();
	}
}

vector<vector<int>> Solution::subsets(vector<int>& nums) {
	vector<vector<int>> result;
	vector<int> item;
	buildSubsets(nums, result, item, 0);
	return result;
}