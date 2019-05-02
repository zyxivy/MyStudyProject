

#include "pch.h";
int Solution::removeDuplicates(vector<int>& nums) {
	int i = 0;
	int j = 0;
	int sz = nums.size();
	while (j < sz) {
		while(j < sz && i < sz && nums[i] == nums[j] ) {
			j++;
		}
		if (i < sz - 1) {
			nums[i + 1] = nums[j];
			i++;
		}
	}
	return i;
}