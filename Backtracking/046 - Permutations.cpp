//Given a collection of distinct integers, return all possible permutations.
//
//Example:
//
//Input: [1, 2, 3]
//Output :
//    [
//        [1, 2, 3],
//        [1, 3, 2],
//        [2, 1, 3],
//        [2, 3, 1],
//        [3, 1, 2],
//        [3, 2, 1]
//    ]

#include "pch.h";
void buildPermute(vector<int> nums, vector<vector<int>>& result, vector<int> item, unordered_set<int>& st){
	if (item.size() == nums.size()) {
		result.push_back(item);
		return;
	}
	for (int i = 0; i < nums.size(); i++) {
		if (st.count(nums[i]))
			continue;
		item.push_back(nums[i]);
		st.insert(nums[i]);
		buildPermute(nums, result, item, st);
		item.pop_back();
		st.erase(nums[i]);
	}
}
vector<vector<int>> Solution::permute(vector<int>& nums) {
	vector<vector<int>> result;
	if (nums.empty()) {
		return result;
	}
	unordered_set<int> st;
	vector<int> item;
	buildPermute(nums, result, item,  st);
	return result;
}
