﻿//Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right.You can only see the k numbers in the window.Each time the sliding window moves right by one position.
//For example,
//Given nums = [1, 3, -1, -3, 5, 3, 6, 7], and k = 3.
//Window position                Max
//-------------- - ---- -
//[1  3 - 1] - 3  5  3  6  7       3
//1[3 - 1 - 3] 5  3  6  7       3
//1  3[-1 - 3  5] 3  6  7       5
//1  3 - 1[-3  5  3] 6  7       5
//1  3 - 1 - 3[5  3  6] 7       6
//1  3 - 1 - 3  5[3  6  7]      7
//Therefore, return the max sliding window as[3, 3, 5, 5, 6, 7].
//Note:
//You may assume k is always valid, ie : 1 ≤ k ≤ input array's size for non-empty array.
//Follow up :
//Could you solve it in linear time ?

#include "Header.h";
//https://lefttree.gitbooks.io/leetcode-categories/Heap/slidingWindowMax.html
//http://www.jianshu.com/p/7662caf4f39c
vector<int> Solution::maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> queue;
    vector<int> result;
    if (nums.empty()) {
        return result;
    }
    for (int i = 0; i < nums.size(); i++) {
        while (!queue.empty() && queue.back()<nums[i]){
            queue.pop_back();
        }
        queue.push_back(nums[i]);
        if (i >= k && nums[i - k] == queue[0]) {
            queue.pop_front();
        }
        if (i >= k - 1) {
            result.push_back(queue[0]);
        }
    }

    return result;
}