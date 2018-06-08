//Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory.
//
//For example,
//Given input array nums = [1, 1, 2],
//
//Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.It doesn't matter what you leave beyond the new length
#include "Header.h";

int Solution::removeDuplicates(vector<int>& nums) {
    int i = 0;
    int j = 1;
    if (nums.size() < 2) {
        return nums.size();
    }
    for (j = 1; j < nums.size(); j++) {
        if (nums[i] != nums[j]) {
            nums[++i] = nums[j];
        }
    }
    return i+1;
}