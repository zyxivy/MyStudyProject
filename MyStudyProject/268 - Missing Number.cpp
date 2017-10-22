//Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
//For example,
//Given nums = [0, 1, 3] return 2.
//Note:
//Your algorithm should run in linear runtime complexity.Could you implement it using only constant extra space complexity ?

#include "Header.h";

//http://yucoding.blogspot.com/2016/12/leetcode-question-missing-number.html
int Solution::missingNumber(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
        result ^= nums[i];
        result ^= i;
    }
    return result ^ nums.size();

    //Method 2

    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    return n * (n + 1) / 2 - sum;
}