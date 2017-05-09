//Given a sorted array and a target value, return the index if the target is found.If not, return the index where it would be if it were inserted in order.
//
//You may assume no duplicates in the array.
//
//Here are few examples.
//[1, 3, 5, 6], 5 → 2
//[1, 3, 5, 6], 2 → 1
//[1, 3, 5, 6], 7 → 4
//[1, 3, 5, 6], 0 → 0

#include "Header.h";

int binaryInsert(vector<int>& nums, int target, int l, int r) {
    if (l == r) {
        if (nums[l] < target) {
            return ++l;
        }
        else{
            return l;
        }
    }
    if (l > r) {
        if (target<=nums[r]) {
            return r;
        }
        else if(nums[r]<target && target<=nums[l]){
            return l;
        }
        else {
            return ++l;
        }
    }
    int ret = 0;
    int m = (l + r) / 2;
    if (nums[m] == target) {
        ret= m;
    }
    else if (nums[m] < target) {
        ret = binaryInsert(nums, target, m + 1, r);
    }
    else {
        ret = binaryInsert(nums, target, l, m-1);
    }
    return ret;
}

int Solution::searchInsert(vector<int>& nums, int target) {
    int ret;
    if (nums[0] > target) {
        ret= 0;
    }
    else if (nums[nums.size() - 1] < target) {
        ret= nums.size();
    }
    else {
        ret = binaryInsert(nums, target, 0, nums.size() - 1);
    }
    return ret;
}