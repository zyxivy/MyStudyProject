//Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
//Solve it without division and in O(n).
//For example, given[1, 2, 3, 4], return[24, 12, 8, 6].
//Follow up :
//Could you solve it with constant space complexity ? (Note : The output array does not count as extra space for the purpose of space complexity analysis.)

#include "Header.h";

//http://yucoding.blogspot.com/2016/04/leetcode-question-product-of-array.html
vector<int> Solution::productExceptSelf(vector<int>& nums) {
    vector<int> res(1, 1);
    for (int i = 0; i<nums.size(); i++) {
        res.push_back(res.back()*nums[i]);
    }
    int b = 1;
    for (int i = 0; i<nums.size(); i++) {
        res[nums.size() - i - 1] = res[nums.size() - i - 1] * b;
        b = b* nums[nums.size() - i - 1];
    }
    res.pop_back();
    return res;
}
