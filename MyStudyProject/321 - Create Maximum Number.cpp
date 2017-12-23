//Given two arrays of length m and n with digits 0 - 9 representing two numbers.Create the maximum number of length k <= m + n from digits of the two.The relative order of the digits from the same array must be preserved.Return an array of the k digits.You should try to optimize your time and space complexity.
//Example 1:
//nums1 = [3, 4, 6, 5]
//nums2 = [9, 1, 2, 5, 8, 3]
//k = 5
//return[9, 8, 6, 5, 3]
//Example 2 :
//    nums1 = [6, 7]
//    nums2 = [6, 0, 4]
//    k = 5
//    return[6, 7, 6, 0, 4]
//    Example 3 :
//    nums1 = [3, 9]
//    nums2 = [8, 9]
//    k = 3
//    return[9, 8, 9]
#include "Header.h";
//https://discuss.leetcode.com/topic/36805/c-16ms-fastest-beats-97

// create max number of length t from single non-empty vector
void getMax(vector<int> num, int len, vector<int>& result, int k, int& sortedLen)
{
    if (k <= 0) {
        return;
    }
    if (result.size() != k) {
        return;
    }
    if (len == k) {
        result = num;
    }
    int top = 0; // top of stack(result)
    result[0] = num[0];
    const int need2Drop = len - k; // number of numbers needs to drop
    for (int i = 1; i < len; i++) {
        int n = num[i];
        while (top >= 0 && result[top] < n && (i - top) <= need2Drop) {//numbers between i ~ top are already dropped.
            top--;
        }
        if (i - top > need2Drop) {//
            sortedLen = max(1, top);
            while (++top < k) result[top] = num[i++];
            return;
        }
        if (++top < k)
            result[top] = n;
        else
            top = k - 1;
    }
}

// create max number of different length from single vector
void getDP(vector<int> nums, int len, int minL, int maxL, vector<vector<int>>& vec, int& sortedLen, int k) {
    getMax(nums, len, vec[vec.size() - 1], vec[vec.size() - 1].size(), sortedLen); //get the max numbers with the longest possible k
    vector<int> prev = vec[vec.size() - 1];
    for (int i = vec.size()-2; i >= max(minL - 1, 0); i--) {
        vector<int> v = vec[i];
        if (v.size() == 0) {
            continue;
        }
        v[0] = prev[0];
        if (v.size() < 2) {
            prev = v;
            vec[i] = v;
            continue;
        }
        v[1] = prev[1];
        int j = sortedLen;
        for (; j < v.size() - 1; j++) {
            if (v[j] < prev[j + 1]) {
                sortedLen = max(1, j - 1);
                for (int p = j; p < v.size(); p++) {
                    v[p] = prev[p + 1];
                }
                break;
            }
        }
        if (j == v.size()) {
            for (int p = j; p < v.size(); p++) {
                v[p] = prev[p + 1];
            }
        }
        prev = v;
        vec[i] = v;
    }
}

vector<int> Solution::maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int len1 = nums1.size();
    int len2 = nums2.size();

    int minL1 = max(0, k - len2);
    int maxL1 = min(k, len1);
    int minL2 = k - maxL1; //same as max(0, k - len1);
    int maxL2 = k - minL1; //same as min(k, len2);

    vector<int> result(k, 0);
    int sortedLen1 = 1, sortedLen2 = 1;
    vector<vector<int>> vec1(maxL1 - minL1 + 1); //Stores the max numbers of different length from nums1. Length : minL1 ~ maxL1.
    vector<vector<int>> vec2(maxL2 - minL2 + 1); //Stores the max numbers of different length from nums2. Length : minL2 ~ maxL2.
    for (int l = minL1; l <= maxL1; l++) {
        vec1[l - minL1].resize(l);
    }
    for (int l = minL2; l <= maxL2; l++) {
        vec2[l - minL2].resize(l);
    }

    if (len1 == 0 && len2 > 0) {
        getMax(nums2, len2, result, k, sortedLen2);
    }
    else if (len1 > 0 && len2 == 0) {
        getMax(nums2, len2, result, k, sortedLen1);
    }
    else if (len1 > 0 && len2 > 0) {
        getDP(nums1, len1, minL1, maxL1, vec1, sortedLen1, k);
        getDP(nums2, len2, minL2, maxL2, vec2, sortedLen2, k);
    }
    return result;
}