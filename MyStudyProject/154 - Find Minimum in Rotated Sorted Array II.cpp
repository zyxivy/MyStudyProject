//Follow up for "Find Minimum in Rotated Sorted Array":
//What if duplicates are allowed ?
//
//Would this affect the run - time complexity ? How and why ?
//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Find the minimum element.
//
//The array may contain duplicates.

#include "Header.h";

int Solution::findMinII(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }

    if (nums[0] == nums[nums.size() - 1]) {
        return nums[0];
    }

    int i = 0;
    int j = nums.size() - 1;
    while (i < j) {
        int mid = (i + j) / 2;
        if (nums[mid] > nums[j]) {
            i = mid + 1;
        }
        else if(nums[mid]<nums[j]){
            j = mid;
        }
        else {
            j--;
        }
    }
    return nums[i];
}