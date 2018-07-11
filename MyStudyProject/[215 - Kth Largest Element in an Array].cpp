//Find the kth largest element in an unsorted array.Note that it is the kth largest element in the sorted order, not the kth distinct element.
//For example,
//Given[3, 2, 1, 5, 6, 4] and k = 2, return 5.
//Note:
//You may assume k is always valid, 1 ¡Ü k ¡Ü array's length.

#include "Header.h";

//quick select: http://www.cs.yale.edu/homes/aspnes/pinewiki/QuickSelect.html
//https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/4-C++-Solutions-using-Partition-Max-Heap-priority_queue-and-multiset-respectively
int quickSelectpartition(vector<int>& nums, int l, int r) {
    int wall = l;
    int pivot = nums[r];
    while (l < r) {
        if (nums[l]<pivot) {
            swap(nums[wall], nums[l]);
            wall++;
        }
        l++;
    }
    swap(nums[wall], nums[r]);
    return wall;
}
int quickSelect(vector<int>& nums, int k, int l, int r) {
    if (l < r) {
        int p = quickSelectpartition(nums, l, r);
        if (p == nums.size()-k) {
            return nums[p];
        }
        if (p < nums.size() - k) {
            return quickSelect(nums, k, p + 1, r);
        }
        else {
            return quickSelect(nums, k, l, p - 1);
        }
    }
    else return nums[l];

}
int Solution::findKthLargest(vector<int>& nums, int k) {
    int ret = quickSelect(nums, k, 0, nums.size() - 1);
    return ret;
}
