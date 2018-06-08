//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//You are given a target value to search.If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.

#include "Header.h";

//Find smallest value first Question 153
//binary search
int Solution::search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (nums[m] == target) {
            return m;
        }
        if (nums[l] <= nums[m]) {
            if (nums[l] <= target && target < nums[m]) {
                r = m-1;
            }
            else {
                l = m+1;
            }
        }
        else {
            if (nums[m] < target&& target <= nums[r]) {
                l = m+1;
            }
            else {
                r = m-1;
            }
        }
    }
    return -1;
}