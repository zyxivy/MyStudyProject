//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Find the minimum element.
//
//You may assume no duplicate exists in the array

#include "Header.h";

int Solution::findMin(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }
    //for (int i = 0; i < nums.size() - 1; i++) {
    //    if (nums[i] > nums[i + 1]) {
    //        return nums[i + 1];
    //    }
    //}
    //return nums[0];

    int i = 0;
    int j = nums.size() - 1;
    while (i < j) {
        int mid = (i + j) / 2;
        if (nums[mid] > nums[j]) {
            i = mid + 1;
        }
        else {
            j=mid;
        }
    }
    return nums[i];
}