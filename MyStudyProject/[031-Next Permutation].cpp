//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
//If such arrangement is not possible, it must rearrange it as the lowest possible order(ie, sorted in ascending order).
//
//The replacement must be in - place, do not allocate extra memory.
//
//Here are some examples.Inputs are in the left - hand column and its corresponding outputs are in the right - hand column.
//1, 2, 3 → 1, 3, 2
//3, 2, 1 → 1, 2, 3
//1, 1, 5 → 1, 5, 1

#include "Header.h";

/*
https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
2.Find the largest index l greater than k such that a[k] < a[l].
3.Swap the value of a[k] with that of a[l].
4.Reverse the sequence from a[k + 1] up to and including the final element a[n].
*/

void Solution::nextPermutation(vector<int>& nums) {
    int k = nums.size() - 2;
    for (k = nums.size() - 2;k >= 0;k--) {
        if (nums[k] < nums[k+1]) {
            break;
        }
    }
    if (k >= 0){
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
    int i = k + 1;
    int j = nums.size() - 1;
    while(i<j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }

}