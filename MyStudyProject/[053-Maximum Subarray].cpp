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

    //Clear DP way
    //To calculate sum(0, i), you have 2 choices: either adding sum(0, i - 1) to a[i], or not.
    //If sum(0, i - 1) is negative, adding it to a[i] will only make a smaller sum, so we add only if it's non-negative.
    int len = nums.size();
    vector<int>max(len, 0);
    max[0] = nums[0];
    int maxSum = max[0];
    for (int i = 1; i < len; i++) {
        max[i] = nums[i] + (max[i - 1] > 0 ? max[i - 1] : 0);
        maxSum = maxSum < max[i] ? max[i] : maxSum;
    }
    return maxSum;

    //Optimized space

    //int max_ending = nums[0];
    //int max_so_far = nums[0];
    //for (int i = 1;i < nums.size();i++) {
    //    max_ending = nums[i] < max_ending + nums[i] ? max_ending + nums[i] : nums[i];
    //    max_so_far = max_so_far < max_ending ? max_ending : max_so_far;
    //}
    //return max_so_far;
}