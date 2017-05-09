//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution.

#include "Header.h"

void quickSort(vector<int>& arr, int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

vector<int> Solution::twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        if (nums.size() == 0) {
            return ret;
        }

        vector<int> copy(nums.size());
        for (int i = 0;i < nums.size();i++) {
            copy[i] = nums[i];
        }

        quickSort(copy, 0, copy.size() - 1);
        int low = 0;
        int high = copy.size()-1;
        while (low < high) {       
            if (copy[low] + copy[high] < target) {
                low++;
            }
            else if (copy[low] + copy[high]>target)
            {
                high--;
            }
            else
            {
                break;
            }
        }

        for (int i = 0;i < nums.size();i++) {
            if (nums[i] == copy[low] || nums[i]==copy[high]) {
                ret.push_back(i);
            }
        }

        return ret;
    }

//int main()
//{
//    vector<int> nums;
//    nums.push_back(1);
//    nums.push_back(0);
//    nums.push_back(4);
//    nums.push_back(-2);
//    nums.push_back(7);
//    nums.push_back(9);
//    nums.push_back(10);
//    nums.push_back(12);
//    nums.push_back(18);
//
//    int target = 2;
//    Solution::twoSum(nums, target);
//}