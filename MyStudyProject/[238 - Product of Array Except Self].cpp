//Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
//Solve it without division and in O(n).
//For example, given[1, 2, 3, 4], return[24, 12, 8, 6].
//Follow up :
//Could you solve it with constant space complexity ? (Note : The output array does not count as extra space for the purpose of space complexity analysis.)

#include "Header.h";

//https://leetcode.com/problems/product-of-array-except-self/discuss/65627/O(n)-time-and-O(1)-space-C++-solution-with-explanation
vector<int> Solution::productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    int fromBegin = 1;
    int fromLast = 1;
    vector<int> res(n, 1);

    for (int i = 0; i<n; i++) {
        res[i] *= fromBegin;
        fromBegin *= nums[i];
        res[n - 1 - i] *= fromLast;
        fromLast *= nums[n - 1 - i];
    }
    return res;
}
