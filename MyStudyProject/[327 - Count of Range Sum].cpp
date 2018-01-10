//Given an integer array nums, return the number of range sums that lie in[lower, upper] inclusive.
//Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j(i ≤ j), inclusive.
//Note:
//A naive algorithm of O(n2) is trivial.You MUST do better than that.
//Example :
//    Given nums = [-2, 5, -1], lower = -2, upper = 2,
//    Return 3.
//    The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are : -2, -1, 2.

#include "Header.h";

int mergeSortcountRangeSum(vector<long>& sum, int lower, int upper, int low, int high)
{
    if (high - low <= 1) return 0;
    int mid = (low + high) / 2, m = mid, n = mid, count = 0;
    int s1 = mergeSortcountRangeSum(sum, lower, upper, low, mid);
    int s2 = mergeSortcountRangeSum(sum, lower, upper, mid, high);
    count = s1 + s2;
    for (int i = low; i< mid; i++)
    {
        while (m < high && sum[m] - sum[i] < lower) m++;
        while (n < high && sum[n] - sum[i] <= upper) n++;
        count += n - m;
    }
    inplace_merge(sum.begin() + low, sum.begin() + mid, sum.begin() + high);
    return count;
}
int Solution::countRangeSum(vector<int> nums, int lower, int upper) {
    int len = nums.size();
    vector<long> sum(len + 1, 0);
    for (int i = 0; i< len; i++) sum[i + 1] = sum[i] + nums[i];
    return mergeSortcountRangeSum(sum, lower, upper, 0, len + 1);
}