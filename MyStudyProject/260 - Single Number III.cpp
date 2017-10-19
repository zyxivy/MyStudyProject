//Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice.Find the two elements that appear only once.
//For example :
//Given nums = [1, 2, 1, 3, 2, 5], return[3, 5].
//Note :
//    The order of the result is not important.So in the above example, [5, 3] is also correct.
//    Your algorithm should run in linear runtime complexity.Could you implement it using only constant space complexity ?


//http://fisherlei.blogspot.com/2015/10/leetcode-single-number-iii-solution.html
#include "Header.h";
vector<int> Solution::singleNumberIII(vector<int>& nums) {
    int len = nums.size();

    //xor whole array
    int xor_result = 0;
    for (int i = 0; i < len; i++) {
        xor_result ^= nums[i];
    }

    //find the fist index in xor result that is 1
    int first_one_index = 0;
    for (first_one_index = 0; first_one_index < 32; first_one_index++) {
        if ((xor_result >> first_one_index) & 1 == 1) {
            break;
        }
    }

    //split the array into two sets based on whether nums[i]'s first_one_index is 1
    int xor_single_num_1 = 0;
    for (int i = 0; i < len; i++) {
        if ((nums[i] >> first_one_index) & 1 == 1) {
            xor_single_num_1 ^= nums[i];
        }
    }

    //get result by xor one splited set into the xor result
    vector<int> result = { xor_single_num_1, xor_result ^ xor_single_num_1 };
    return result;
}