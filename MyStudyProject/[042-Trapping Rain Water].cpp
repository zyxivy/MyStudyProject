//Given n non - negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//For example,
//Given[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1], return 6.

#include "Header.h";
#include <algorithm>;

int Solution::trap(vector<int>& height) {
    //https://leetcode.com/problems/trapping-rain-water/discuss/17414/A-stack-based-solution-for-reference-inspired-by-Histogram
	int water = 0;
	stack<int> st;
	queue<int> q;
	int i = 0;
	while (i < height.size()) {
		if (st.empty() || height[i] < height[st.top()]) {
			st.push(i);
			i++;
		}
		else {
			int top = height[st.top()];
			st.pop();
			water += st.empty() ? 0 : (min(height[i], height[st.top()]) - top) * (i - st.top() - 1);
		}
	}

	return water;


	
	int maxLeft = 0, maxRight = 0;
	int left = 0, right = height.size() - 1;
	while (left < right) {
		if (height[left] <= height[right]) {
			if (height[left] < maxLeft) {
				water += maxLeft - height[left];
			}
			else {
				maxLeft = height[left];
			}
			left++;
		}
		else {
			if (height[right] < maxRight) {
				water += maxRight - height[right];
			}
			else {
				maxRight = height[right];
			}
			right--;
		}
	}
	return water;
}