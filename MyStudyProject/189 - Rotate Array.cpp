//Rotate an array of n elements to the right by k steps.
//For example, with n = 7 and k = 3, the array[1, 2, 3, 4, 5, 6, 7] is rotated to[5, 6, 7, 1, 2, 3, 4].
//Note:
//Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
//Hint:
//Could you do it in - place with O(1) extra space ?
//Related problem : Reverse Words in a String II

#include "Header.h";

//Assuming we are given{ 1,2,3,4,5,6 } and order 2. The basic idea is :
//1. Divide the array two parts : 1, 2, 3, 4 and 5, 6
//2. Reverse first part : 4, 3, 2, 1, 5, 6
//3. Reverse second part : 4, 3, 2, 1, 6, 5
//4. Reverse the whole array : 5, 6, 1, 2, 3, 4

void reverse(vector<int>& nums, int start, int end) {
    if (nums.size() < 2 || start >= nums.size() || end >= nums.size() || start < 0 || end < 0) {
        return;
    }
    int i = start;
    int j = end;
    while (i < j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }
}
void Solution::rotate(vector<int>& nums, int k) {
    if (nums.empty() || k%nums.size() == 0) {
        return;
    }

    k = k%nums.size();
    int a = nums.size() - k;
    reverse(nums, 0, a - 1);
    reverse(nums, a, nums.size() - 1);
    reverse(nums, 0, nums.size() - 1);
}