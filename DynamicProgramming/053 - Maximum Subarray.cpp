//Given an integer array nums, find the contiguous subarray(containing at least one number) which has the largest sumand return its sum.
//
//Example:
//
//Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4] ,
//Output : 6
//Explanation : [4, -1, 2, 1] has the largest sum = 6.
//Follow up :
//
//If you have figured out the O(n) solution, try coding another solution using the divideand conquer approach, which is more subtle.
#include "pch.h";
int maxSubArray(vector<int>& nums) {
	// dp[i] = max(num[i], num[i]+dp[i-1]);

	if (nums.empty()) {
		return 0;
	}
	if (nums.size() == 1) {
		return nums[0];
	}

	int curMax = nums[0]; // dp[i-1]
	int overallMax = curMax;

	for (int i = 1; i < nums.size();i++) {
		curMax = max(nums[i], nums[i] + curMax);
		overallMax = max(curMax, overallMax);
	}
	return overallMax;
}