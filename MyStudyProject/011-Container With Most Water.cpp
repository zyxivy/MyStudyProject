//Given n non - negative integers a1, a2, ..., an, where each represents a point at coordinate(i, ai).n vertical lines are drawn such that the two endpoints of line i is at(i, ai) and (i, 0).Find two lines, which together with x - axis forms a container, such that the container contains the most water.
//
//Note: You may not slant the container.

#include "Header.h"

int Solution::maxArea(vector<int>& height) {
    int curArea = 0;
    int i = 0;
    int j = height.size() - 1;
    while (i < j) {
        int area = (height[i]>height[j] ? height[j] : height[i])*(j - i);
        curArea = curArea > area ? curArea : area;
        if (height[i] > height[j]) {
            j--;
        }
        else {
            i++;
        }
    }
    return curArea;
}