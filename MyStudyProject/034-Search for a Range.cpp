//Given a sorted array of integers, find the starting and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return[-1, -1].
//
//For example,
//Given[5, 7, 7, 8, 8, 10] and target value 8,
//return[3, 4].

#include "Header.h";

enum Direction {
Both = 0,
Left = 1,
Right = 2,
Invalid = 3
};

int binarySearch(vector<int>& nums, int begin, int end, int target)
{
    int i = begin;
    int j = end;
    while (i <= j)
    {
        int mid = (j + i) / 2;
        if (target == nums[mid])
        {
            return mid;
        }
        else if (target > nums[mid])
        {
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }
    return -1;
}
int searchInRange(vector<int>& nums, int target, int l, int r, int direction) {
    if (l == r) {
        if (nums[l] == target) {
            return l;
        }
        return -1;
    }
    if (l > r) {
        if (nums[l] == target) {
            return l;
        }
        else if (nums[r] == target) {
            return r;
        }
        return -1;
    }
    int m = (l + r) / 2;

    if (nums[m] == target) {
        int i = -1;
        if (direction == Left) {
            i=searchInRange(nums, target, l, m-1, Left);
        }
        else if (direction == Right) {
            i=searchInRange(nums, target, m+1 , r, Right);
        }
        return i == -1 ? m : i;
    }
    else if (nums[m] < target) {
            return searchInRange(nums, target, m + 1, r, Left);
    }
    else {
            return searchInRange(nums, target, l, m-1, Right);
    }
}

vector<int> Solution::searchRange(vector<int>& nums, int target) {
    vector<int> ret;
    int pos = binarySearch(nums, 0, nums.size() - 1, target);
    if (pos == -1) {
        ret.push_back(-1);
        ret.push_back(-1);
    }
    else if (pos == 0) {
        ret.push_back(0);
        int right = searchInRange(nums, target, 1, nums.size() - 1, Right);
        ret.push_back(right == -1 ? pos:right);
    }
    else if (pos == nums.size() - 1) {
        int left = searchInRange(nums, target, 1, nums.size() - 1, Left);      
        ret.push_back(left == -1 ? pos: left);
        ret.push_back(nums.size() - 1);
    }
    else {
        int left=searchInRange(nums, target, 0, pos-1, Left);
        int right=searchInRange(nums, target, pos+1, nums.size()- 1, Right);
        ret.push_back(left == -1 ? pos : left);
        ret.push_back(right == -1 ? pos : right);
    }
    return ret;
}