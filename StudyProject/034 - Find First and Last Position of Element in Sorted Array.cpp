#include "pch.h";

//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/discuss/14699/Clean-iterative-solution-with-two-binary-searches-(with-explanation)
vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> ret(2, -1);
	if (nums.empty()) {
		return ret;
	}
	int low = 0;
	int high = nums.size() - 1;

	//find low
	while (low < high) {
		int m = (low + high) / 2;
		if (nums[m] < target) {
			low = m + 1;
		}
		else {
			high = m;
		}
	}
	if (nums[low] != target)
		return ret;
	ret[0] = low;

	//find high
	high = nums.size() - 1;
	while (low < high) {
		int m = (low + high) / 2 + 1;//Important: need to make middle biased to the right;
		if (nums[m] > target) {
			high = m - 1;
		}
		else {
			low = m;
		}
	}
	ret[1] = high;

	return ret;
}