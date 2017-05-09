//Given a collection of distinct numbers, return all possible permutations.
//
//For example,
//[1, 2, 3] have the following permutations :
//[
//    [1, 2, 3],
//    [1, 3, 2],
//    [2, 1, 3],
//    [2, 3, 1],
//    [3, 1, 2],
//    [3, 2, 1]
//]


#include "Header.h";

int partition(vector<int>& nums, int l, int r) {
    int wall = l;
    int pivot = nums[r];
    while (l < r) {
        if (nums[l]<pivot) {
            int tmp = nums[l];
            nums[l] = nums[wall];
            nums[wall] = tmp;
            wall++;
        }
        l++;
    }
    int tmp = nums[r];
    nums[r] = nums[wall];
    nums[wall] = tmp;
    return wall;
}
void quicksort(vector<int>& nums, int l, int r) {
    if (l < r) {
        int p = partition(nums, l, r);
        quicksort(nums, l, p - 1);
        quicksort(nums, p + 1, r);
    }
}


bool nextPermutationL(vector<int>& nums) {
    int k = nums.size() - 2;
    for (k = nums.size() - 2;k >= 0;k--) {
        if (nums[k] < nums[k + 1]) {
            break;
        }
    }
    if (k >= 0) {
        int l = nums.size() - 1;
        for (l = nums.size() - 1;l > k;l--) {
            if (nums[l] > nums[k]) {
                break;
            }
        }
        int tmp = nums[k];
        nums[k] = nums[l];
        nums[l] = tmp;
    }
    else {
        return false;
    }
    int i = k + 1;
    int j = nums.size() - 1;
    while (i < j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }
    return true;
}


vector<vector<int>> Solution::permute(vector<int>& nums) {
    quicksort(nums, 0, nums.size() - 1);
    vector<vector<int>> ret;
    ret.push_back(nums);
    while (nextPermutationL(nums)) {
        ret.push_back(nums);
    }
    return ret;
}