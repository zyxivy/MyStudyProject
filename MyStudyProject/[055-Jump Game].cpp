
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

bool Solution::canJump(vector<int>& nums) {
    if (nums.size() == 0) {
        return false;
    }
    int maxReach = nums[0];
    int start = 0;
    for (start = 0;start <= maxReach&&start < nums.size();start++) {
        if (nums[start] + start > maxReach) {
            maxReach = nums[start] + start;
        }
        if (maxReach >= nums.size() - 1) {
            return true;
        }
    }
    if (maxReach < nums.size() - 1) {
        return false;
    }
    return true;
}