//Find the contiguous subarray within an array(containing at least one number) which has the largest sum.
//
//For example, given the array[-2, 1, -3, 4, -1, 2, 1, -5, 4],
//the contiguous subarray[4, -1, 2, 1] has the largest sum = 6.
//
//click to show more practice.
//
//More practice :
//If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

//https://en.wikipedia.org/wiki/Maximum_subarray_problem

#include "Header.h";

int Solution::maxSubArray(vector<int>& nums) {
    int max_ending = nums[0];
    int max_so_far = nums[0];
    for (int i = 1;i < nums.size();i++) {
        max_ending = nums[i] < max_ending + nums[i] ? max_ending + nums[i] : nums[i];
        max_so_far = max_so_far < max_ending ? max_ending : max_so_far;
    }
    return max_so_far;
}