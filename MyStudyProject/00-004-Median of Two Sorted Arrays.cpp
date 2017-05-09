//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
//Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
//
//Example 1:
//nums1 = [1, 3]
//nums2 = [2]
//
//The median is 2.0
//Example 2 :
//    nums1 = [1, 2]
//    nums2 = [3, 4]
//
//    The median is(2 + 3) / 2 = 2.5

#include "Header.h"

double median(vector<int>& num, int start, int end) {
    int n = num.size();
    return n % 2 == 0 ? (num[n / 2] + num[(n / 2) - 1]) / 2 : num[n / 2];
}

double findMedian(vector<int>& nums1, int p1start, int p1end, vector<int>& nums2, int p2start, int p2end) {
    int n1 = p1end - p1start + 1;
    int n2 = p2end - p2start + 1;
    double m1 = 0;
    double m2 = 0;

    if (n1 == 1 && n2 == 1) {
        return (nums1[p1start] + nums2[p2start]) / 2;
    }
    if (n1 > 1) {
        m1 = median(nums1, p1start, p1end);
    }
    m2 = median(nums2, p2start, p2end);

    if (m1 == m2)
    {
        return m1;
    }
    else if (m1 < m2) {
        findMedian(nums1, p1start + 1, p1end, nums2, p2start, p2end - 1);
    }
}

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    return 0;
}