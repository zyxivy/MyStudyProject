#include "pch.h";
int Solution::maxArea(vector<int>& height) {
	int area = 0;
	int i = 0;
	int j = height.size() - 1;
	while (i < j) {
		int curArea = (height[i] < height[j] ? height[i] : height[j]) * (j - i);
		area = curArea > area ? curArea : area;
		if (height[i] > height[j]) {
			j--;
		}
		else {
			i++;
		}
	}
	return area;
}