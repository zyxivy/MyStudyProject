#include "pch.h";
int jump(vector<int>& nums) {
	int lastReach = 0, curReach = 0, count = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (lastReach < i) { // increase count when we absolutely must have to
			lastReach = curReach;
			count++;
		}
		curReach = max(nums[i] + i, curReach);
	}
	return count;
}