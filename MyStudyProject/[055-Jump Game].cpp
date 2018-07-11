
//Given an array of non - negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Determine if you are able to reach the last index.
//
//For example :
//A = [2, 3, 1, 1, 4], return true.
//
//A = [3, 2, 1, 0, 4], return false.

#include "Header.h";
////
//1. 能跳到位置i的条件：i <= maxIndex。
//2. 一旦跳到i，则maxIndex = max(maxIndex, i + A[i])。
//3. 能跳到最后一个位置n - 1的条件是：maxIndex >= n - 1

bool Solution::canJump(vector<int>& nums) {
    if (nums.size() == 0) {
        return false;
    }
    int maxReach = nums[0];
    int i = 0;
    for (i = 0; i <= maxReach && i < nums.size(); i++) {
		maxReach = max(maxReach, nums[i] + i);
    }
	return i == nums.size();
}