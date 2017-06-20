//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0 ? Find all unique triplets in the array which gives the sum of zero.
//
//Note : The solution set must not contain duplicate triplets.
//
//    For example, given array S = [-1, 0, 1, 2, -1, -4],
//
//    A solution set is :
//[
//    [-1, 0, 1],
//    [-1, -1, 2]
//]

#include "Header.h"

int quickSortcompr(const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}

vector<vector<int>> KSum(vector<int>& nums, int target, int begin, int K) {
    int i = begin;
    int j = nums.size() - 1;
    vector<vector<int>> ret;
    int prevI = INT_MAX;

    if (K == 2) {
        int prevJ = INT_MAX;
        while (i < j) {
            if (prevJ != INT_MAX && prevJ == nums[j]) {
                j--;
                continue;
            }
            if (prevI != INT_MAX && prevI == nums[i]) {
                i++;
                continue;
            }
            int sum = nums[i] + nums[j];
            if (sum == target) {
                vector<int> result;
                result.push_back(nums[i]);
                result.push_back(nums[j]);
                ret.push_back(result);
                prevI = i;
                prevJ = j;
                i++;
                j--;
            }
            else if (sum < target) {
                prevI = i;
                i++;
            }
            else {
                prevJ = j;
                j--;
            }
        }
    }
    else {
        for (i=begin;i<= nums.size() - K;i++) {
            if (prevI != INT_MAX && prevI == nums[i]) {
                i++;
                continue;
            }
            prevI = i;
            vector<vector<int>> values = KSum(nums, target - nums[i], i+1, K - 1);
            for (int j = 0;j < values.size();j++) {
                vector<int> result;
                result.push_back(nums[i]);
                for (int k = 0;k < values[j].size();k++) {
                    result.push_back(values[j][k]);
                }
                ret.push_back(result);
            }
        }
    }
    return ret;
}

vector<vector<int>> Solution::threeSum(vector<int>& nums) {
    qsort(&(nums[0]), nums.size(), sizeof(int), quickSortcompr);

    vector<vector<int>> ret = KSum(nums, 0, 0, 3);
    return ret;
}