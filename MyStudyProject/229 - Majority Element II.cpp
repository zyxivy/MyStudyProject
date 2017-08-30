//Given an integer array of size n, find all elements that appear more than ⌊ n / 3 ⌋ times.The algorithm should run in linear time and in O(1) space.

#include "Header.h";
int compareMajorElement(const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}
int binarySearchDiff(vector<int> nums, int start, int end, int target) {
    if (start == end) {
        return start;
    }
    else if (start + 1 == end) {
        return nums[start] == target ? end : start;
    }
    int m = (start + end) / 2;
    if (nums[m] == target) {
        return binarySearchDiff(nums, m + 1, end, target);
    }
    else {
        return binarySearchDiff(nums, start, m - 1, target);
    }
}
vector<int> Solution::majorElement(vector<int>& nums) {
    vector<int> result;
    if (nums.empty()) {
        return result;
    }

    if (nums.size() <= 2) {
        result.push_back(nums[0]);
        if (nums.size() == 2 && nums[0] != nums[1]){
            result.push_back(nums[1]);
        }
        return result;
    }

    qsort(&nums[0], nums.size(), sizeof(int), compareMajorElement);
    
    int n3 = nums.size() / 3;
    int i = 0;
    while (i < nums.size()-n3) {
        if (nums[i] == nums[i + n3]) {
            result.push_back(nums[i]);
            i = binarySearchDiff(nums, i + n3, nums.size() - 1, nums[i]);
        }
        else {
            i++;
        }
    }
    return result;
}