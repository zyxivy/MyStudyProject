//Given n non - negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//For example,
//Given[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1], return 6.

#include "Header.h";

int Solution::trap(vector<int>& height) {
    int water = 0;
    if (height.size() == 0) {
        return water;
    }
    int i = 0;
    int j = height.size() - 1;
    int max = height[i] >= height[j] ? i : j;
    while (i < j) {
        if (height[i] >= height[j]) {
            j--;
        }
        else { 
            i++;
        }
        max = height[i] >= height[j] ? i : j;
    }
    i = 0;
    j = height.size() - 1;
    while (i < max) {
        int p = i + 1;
        while (height[p] < height[i]) {
            p++;
        }
        if (p != i + 1) {
            int k = i + 1;
            while (k < p) {
                water += abs(height[i] - height[k]);
                k++;
            }
        }
        i = p;
    }
    while (j > max) {
        int p = j-1;
        while (height[p] < height[j]) {
            p--;
        }
        if (p != j - 1) {
            int k = j - 1;
            while (k > p) {
                water += abs(height[j] - height[k]);
                k--;
            }
        }
        j = p;
    }
    return water;
}