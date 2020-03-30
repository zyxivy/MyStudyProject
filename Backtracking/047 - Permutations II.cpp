//Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
//Example:
//
//Input: [1, 1, 2]
//Output :
//    [
//        [1, 1, 2],
//        [1, 2, 1],
//        [2, 1, 1]
//    ]

#include "pch.h";
void buildPermuteUnique(vector<int> nums, vector<vector<int>>& result, vector<int> item, vector<bool>& used) {
	if (item.size() == nums.size()) {
		result.push_back(item);
		return;
	}
	for (int i = 0; i < nums.size(); i++) {
		if (used[i] || (i > 0 && nums[i - 1] == nums[i] && !used[i - 1])) //when a number has the same value with its previous, we can use this number only if his previous is used
			continue;
		item.push_back(nums[i]);
		used[i] = true;
		buildPermuteUnique(nums, result, item, used);
		item.pop_back();
		used[i] = false;
	}
}
vector<vector<int>> Solution::permuteUnique(vector<int>& nums) {
	vector<vector<int>> result;
	if (nums.empty()) {
		return result;
	}
	vector<bool> used(nums.size(), false);
	vector<int> item;
	sort(nums.begin(), nums.end());
	buildPermuteUnique(nums, result, item, used);
	return result;
}