
#include "pch.h"

int Solution::removeElement(vector<int>& nums, int val) {
	int i = 0; int j = 0;
	while (j < nums.size()) {
		if (nums[j] != val) {
			nums[i] = nums[j];
			i++;
		}
		j++;
	}
	return i;
}