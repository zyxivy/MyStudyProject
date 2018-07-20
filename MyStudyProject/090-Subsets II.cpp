//Given a collection of integers that might contain duplicates, nums, return all possible subsets.
//
//Note: The solution set must not contain duplicate subsets.
//
//    For example,
//    If nums = [1, 2, 2], a solution is :
//
//[
//    [2],
//    [1],
//    [1, 2, 2],
//    [2, 2],
//    [1, 2],
//    []
//]

#include "Header.h";

void dfssubsetsWithDup(vector<int> nums, int start, vector<int>& item, vector<vector<int>>& res) {
    res.push_back(item);
    for (int i = start; i <= nums.size() - 1; i++) {
		if (i > start && nums[i - 1] == nums[i])//i>start
			continue;
        item.push_back(nums[i]);
        dfssubsetsWithDup(nums, i + 1, item, res);
        item.pop_back();
    }
}
vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums) {
	//recursive
	sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
	vector<int> item;
	dfssubsetsWithDup(nums, 0, item, ret);
	return ret;

	//iterative
	sort(nums.begin(), nums.end());
	vector<vector<int>> ret;
	vector<int> item;
	if (nums.size() > 0) {
		vector<vector<int>> newly;
		item.push_back(nums[0]);
		newly.push_back(item);
		ret.push_back(item);
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == nums[i - 1]) {
				vector<vector<int>> newnewly;
				for (int j = 0; j < newly.size(); j++) {
					vector<int> item = newly[j];
					item.push_back(nums[i]);
					ret.push_back(item);
					newnewly.push_back(item);
				}
				newly.clear();
				newly = newnewly;
			}
			else
			{
				vector<vector<int>> newnewly;
				newly = ret;
				for (int j = 0; j < newly.size(); j++) {
					vector<int> item = ret[j];
					item.push_back(nums[i]);
					ret.push_back(item);
					newnewly.push_back(item);
				}
				vector<int> item;
				item.push_back(nums[i]);
				ret.push_back(item);
				newly.clear();
				newly = newnewly;
				newly.push_back(item);
			}
		}
	}
	item.clear();
	ret.push_back(item);
	return ret;
}