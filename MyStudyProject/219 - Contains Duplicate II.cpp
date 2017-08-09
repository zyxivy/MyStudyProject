//Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
#include "Header.h";
bool Solution::containsNearbyDuplicate(vector<int>& nums, int k) {
	map<int, int> mp;
	for (int i = 0; i < nums.size(); i++) {
		if (mp.find(nums[i]) != mp.end()) {
			if (k >= (i- mp[nums[i]])) {
				return true;
			}
		}
		mp[nums[i]] = i;
	}
	return false;
}