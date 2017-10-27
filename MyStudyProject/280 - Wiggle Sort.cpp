//iven an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
//For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is[1, 6, 2, 5, 3, 4].

#include "Header.h";

void Solution::wiggleSort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (size_t i = 1; i + 1 < nums.size(); i += 2) {
        swap(nums[i], nums[i + 1]);
    }
}