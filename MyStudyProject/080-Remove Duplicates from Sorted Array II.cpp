//Follow up for "Remove Duplicates":
//What if duplicates are allowed at most twice ?
//
//For example,
//Given sorted array nums = [1, 1, 1, 2, 2, 3],
//
//Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
//
//Subscribe to see which companies asked this question

#include "Header.h";

int Solution::removeDuplicatesII(vector<int>& nums) {
    int wall = 0;
    int cur = 1;
    int count = 1;
    if (nums.size() <= 2) {
        return nums.size();
    }
    while (cur < nums.size()) {
        if (nums[cur] == nums[wall]) {
            if (count-- > 0) {
                wall++;
                nums[wall] = nums[cur];
            }
        }
        else {
            wall++;
            count = 1;
            nums[wall] = nums[cur];
        }
        cur++;
    }
    return wall + 1;
}