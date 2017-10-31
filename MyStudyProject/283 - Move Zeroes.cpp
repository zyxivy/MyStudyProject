//Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements. 
//For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be[1, 3, 12, 0, 0].
//Note:
//You must do this in - place without making a copy of the array.
//Minimize the total number of operations.

#include "Header.h";
void Solution::moveZeroes(vector<int>& nums) {
    //int i = 0;
    //int j = 0;
    //while (i <nums.size()){
    //    if (nums[i]==0) {
    //        j = i + 1;
    //        while (j <nums.size()) {
    //            if (nums[j] == 0) {
    //                j++;
    //            }
    //            else {
    //                int val = nums[j];
    //                nums.erase(nums.begin() + j);
    //                nums.insert(nums.begin() + i, val);
    //                break;
    //            }
    //        }
    //    }
    //    i++;
    //}

    int j = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}