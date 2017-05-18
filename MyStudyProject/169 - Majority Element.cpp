//Given an array of size n, find the majority element.The majority element is the element that appears more than ⌊ n / 2 ⌋ times.
//You may assume that the array is non - empty and the majority element always exist in the array.

#include "Header.h";
int Solution::majorityElement(vector<int>& nums) {
    map<int, int> mp;
    if (nums.size() < 2) {
        return nums[0];
    }
    int i = 0;
    for (i = 0; i < nums.size(); i++) {
        if (mp.find(nums[i]) != mp.end()) {
            mp[nums[i]] = mp[nums[i]] + 1;
            if (mp[nums[i]] > nums.size() / 2) {
                break;
            }
        }
        else {
            mp[nums[i]] = 1;
        }
    }
    return nums[i];
}