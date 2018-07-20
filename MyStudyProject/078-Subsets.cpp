//Given a set of distinct integers, nums, return all possible subsets.
//
//Note: The solution set must not contain duplicate subsets.
//
//    For example,
//    If nums = [1, 2, 3], a solution is :
//
//[
//    [3],
//    [1],
//    [2],
//    [1, 2, 3],
//    [1, 3],
//    [2, 3],
//    [1, 2],
//    []
//]

#include "Header.h";

void dfs(vector<int> nums, int start, vector<int>& item, vector<vector<int>>& res) {
    res.push_back(item);
    for (int i = start; i <= nums.size()-1; i++) {
        item.push_back(nums[i]);
        dfs(nums, i + 1, item, res);
        item.pop_back();
    }
}
vector<vector<int>> Solution::subsets(vector<int>& nums) {
    vector<vector<int>> ret;
    vector<int> item;

    dfs(nums, 0, item, ret);
    return ret;
}