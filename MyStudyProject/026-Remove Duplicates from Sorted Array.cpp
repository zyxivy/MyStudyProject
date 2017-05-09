//Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory.
//
//For example,
//Given input array nums = [1, 1, 2],
//
//Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.It doesn't matter what you leave beyond the new length
#include "Header.h";

int Solution::removeDuplicates(vector<int>& nums) {
	int i = 0;
	int j = 1;
	if (nums.size() < 2) {
		return nums.size();
	}
	while (i < nums.size() && j < nums.size()) {
		if (nums[i] == nums[j]) {
			nums[j] = INT_MIN;
			j++;
		}
		else {
			i = j;
			j = i + 1;
		}
	}
	i = 0; j = 0;
	while (i < nums.size() && nums[i] != INT_MIN) {
		i++;
	}
	j = i + 1;
	while (i < nums.size() && j < nums.size()) {
		if (nums[j] != INT_MIN) {
			nums[i] = nums[j];
			i++;
			j++;
		}
		else {
			j++;
		}
	}
	return i;
}