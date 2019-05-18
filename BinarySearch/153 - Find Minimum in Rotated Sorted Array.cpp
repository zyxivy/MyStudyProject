#include "pch.h";
int findMin(vector<int>& nums) {
	if (nums.empty()) {
		return 0;
	}
	if (nums.size() == 1) {
		return nums[0];
	}

	int l = 0, r = nums.size() - 1;
	while (l < r) {
		int m = (l + r) / 2;
		if (nums[m] > nums[r]) {
			l = m + 1;
		}
		else {
			r = m;
		}
	}
	return nums[l];
}