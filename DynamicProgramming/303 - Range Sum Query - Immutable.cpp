//Share
//Given an integer array nums, find the sum of the elements between indices iand j(i ≤ j), inclusive.
//
//Example:
//Given nums = [-2, 0, 3, -5, 2, -1]
//
//sumRange(0, 2) -> 1
//sumRange(2, 5) -> - 1
//sumRange(0, 5) -> - 3
//Note :
//	You may assume that the array does not change.
//	There are many calls to sumRange function.
#include "pch.h";

class NumArray {
public:
    vector<int> dp; // dp[i] contains the sum of num[0]...nums[i]
    NumArray(vector<int>& nums) {
        dp.push_back(0); // avoid if (i == 0) in sumRange
        int tempSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            dp.push_back(tempSum + nums[i]);
            tempSum += nums[i];
        }
    }

    int sumRange(int i, int j) {
        //if (i == 0) {
        //    return dp[j];
        //}
        //else {
        //    return dp[j] - dp[i - 1];
        //}
        return dp[j + 1] - dp[i];
    }
};