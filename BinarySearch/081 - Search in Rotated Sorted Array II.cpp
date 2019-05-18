#include "pch.h";
bool search(vector<int>& nums, int target) {
	if (nums.empty()) {
		return false;
	}
	int lo = 0;
	int hi = nums.size() - 1;
	while (lo <= hi) {
		int mi = (lo + hi) / 2;
		if (nums[mi] == target) {
			return true;
		}
		
		if (nums[lo] < nums[mi]) {
			if (nums[lo] <= target && target < nums[mi]) {
				hi = mi - 1;
			}
			else {
				lo = mi + 1;
			}
		}
		else if (nums[mi] < nums[lo]) {
			if (nums[mi] < target && target <= nums[hi]) {
				lo = mi + 1;
			}
			else {
				hi = mi - 1;
			}
		}
		else
		{
			lo++;//skip duplicates
		}
	}
	return false;
}