#ifndef PCH_H
#define PCH_H

using namespace std;
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <math.h>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>

class Solution
{
public:
	static vector<int> twoSum(vector<int>& nums, int target);
	static int maxArea(vector<int>& height);
	static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
	static int removeElement(vector<int>& nums, int val);
	static int removeDuplicates(vector<int>& nums);
};

#endif //PCH_H
