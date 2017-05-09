//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//
//Note:
//You may assume that nums1 has enough space(size that is greater or equal to m + n) to hold additional elements from nums2.The number of elements initialized in nums1 and nums2 are m and n respectively.
#include "Header.h";
void Solution::mergeArray(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = 0, j = 0;
    if (m < nums1.size()) {
        nums1.resize(m);
    }
    while (i < nums1.size() &&j < n) {
        if (nums1[i] < nums2[j]) {
            i++;
        }
        else {
            nums1.insert(nums1.begin() + i, nums2[j]);
            //i++;
            j++;
        }
    }
    while (j < n) {
        nums1.push_back(nums2[j]);
        j++;
    }
    i = 1;
}