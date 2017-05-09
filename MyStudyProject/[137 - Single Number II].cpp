//Given an array of integers, every element appears three times except for one, which appears exactly once.Find that single one.
//Note:
//Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory ?

//https://www.careercup.com/question?id=15066700

#include "Header.h";
int Solution::singleNumberII(vector<int>& nums) {
    int ones = 0, twos = 0, threes = 0;
    for (int i = 0; i < nums.size(); i++) {
        twos |= ones & nums[i];
        ones ^= nums[i];
        threes = ones & twos;
        ones &= ~threes;
        twos &= ~threes;
    }
    return ones;
}