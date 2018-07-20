//Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
//Example:
//
//Input: [1, 1, 2]
//	Output :
//	[
//		[1, 1, 2],
//		[1, 2, 1],
//		[2, 1, 1]
//	]

#include "Header.h";

	void permuteBackTrackingII(vector<int> nums, vector<vector<int>>& results, vector<int>& curr, vector<bool>& used) {
		if (curr.size() == nums.size()) {
			results.push_back(curr);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (used[i] || (i>0 && nums[i-1]==nums[i] && !used[i-1]))//important step
				continue;
			curr.push_back(nums[i]);
			used[i] = true;
			permuteBackTrackingII(nums, results, curr, used);
			curr.pop_back();
			used[i] = false;
		}
	}
vector<vector<int>> Solution::permuteUnique(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> results;
	vector<int> curr;
	vector<bool> used(nums.size(), false);
	permuteBackTrackingII(nums, results, curr, used);
	return results;
}