//Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
//
//Example:
//
//nums = [1, 2, 3]
//target = 4
//
//The possible combination ways are :
//(1, 1, 1, 1)
//(1, 1, 2)
//(1, 2, 1)
//(1, 3)
//(2, 1, 1)
//(2, 2)
//(3, 1)
//
//Note that different sequences are counted as different combinations.
//
//Therefore the output is 7.
//
//
//Follow up :
//What if negative numbers are allowed in the given array ?
//How does it change the problem ?
//What limitation we need to add to the question to allow negative numbers 

#include "pch.h";
void buildResultCombinationSum4(vector<int> nums, vector<vector<int>>& result, vector<int> item, int target) {
	if (target == 0) {
		result.push_back(item);
		return;
	}
	for (int i = 0; i < nums.size() && target >= nums[i]; i++) {
		item.push_back(nums[i]);
		buildResultCombinationSum4(nums, result, item, target - nums[i]);
		item.pop_back();
	}
}
int combinationSum4(vector<int>& nums, int target) {
	vector<vector<int>> result;
	vector<int> item;
	sort(nums.begin(), nums.end());
	buildResultCombinationSum4(nums, result, item, target);
	return result.size();
}