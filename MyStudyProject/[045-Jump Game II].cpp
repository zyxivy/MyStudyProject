//Given an array of non - negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Your goal is to reach the last index in the minimum number of jumps.
//
//For example :
//Given array A = [2, 3, 1, 1, 4]
//
//The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
//
//Note :
//    You can assume that you can always reach the last index.

#include "Header.h";

int Solution::jump2(vector<int>& nums) {
    int curReach = 0, lastReach = 0, cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (lastReach < i) {
            lastReach = curReach;
            cnt++;
        }
		curReach = max(curReach, nums[i] + i);
    }
    return cnt;
}