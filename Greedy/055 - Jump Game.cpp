#include "pch.h";

bool canJump(vector<int>& nums) {
	int maxReach = 0;
	int i = 0;
	for (; i < nums.size() && i <= maxReach;i++) {
		maxReach = max(maxReach, nums[i]+i);
	}
	return i == nums.size();
}