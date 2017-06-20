//Note: This is an extension of House Robber.
//    After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention.This time, all houses at this place are arranged in a circle.That means the first house is the neighbor of the last one.Meanwhile, the security system for these houses remain the same as for those in the previous street.
//    Given a list of non - negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
#include "Header.h";
int Solution::robII(vector<int>& nums) {
    if (nums.empty())
        return 0;

    if (nums.size() == 1)
        return nums[0];

    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];

    for (int i = 2; i<nums.size()-1; i++) {
        dp[i] = dp[i - 2] + nums[i] > dp[i - 1] ? dp[i - 2] + nums[i] : dp[i - 1];
    }

    int max = dp[nums.size() - 2];

    dp[1] = nums[1];
    dp[2] = nums[1] > nums[2] ? nums[1] : nums[2];
    for (int i = 3; i<nums.size(); i++) {
        dp[i] = dp[i - 2] + nums[i] > dp[i - 1] ? dp[i - 2] + nums[i] : dp[i - 1];
    }

    max = max > dp[nums.size() - 1] ? max : dp[nums.size() - 1];

    return max;
}