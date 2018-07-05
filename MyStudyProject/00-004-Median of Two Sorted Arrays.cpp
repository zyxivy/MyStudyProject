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


//https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O(log(min(mn))-solution-with-explanation
double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    double ans = 0;
    int len = nums1.size() + nums2.size();
    int cnt = len / 2;
    if (len % 2 == 0) {
        cnt--;
    }

    int i = 0;
    int j = 0;
    int c = 0;
    while (i < nums1.size() && j < nums2.size() && c<cnt) {
        if (nums1[i] < nums2[j]) {
            if (c == cnt) {
                ans += nums1[i];
                break;
            }
            i++;
            c++;
        }
        else {
            if (c == cnt) {
                ans += nums2[j];
                break;
            }
            j++;
            c++;
        }
    }
    while (i < nums1.size() && c < cnt) {
        i++;
        c++;
    }
    while (j < nums2.size() && c < cnt) {
        j++;
        c++;
    }

    if (len % 2 == 1) {
        
    }
    return 0;
}