//Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
//The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.Please note that your returned answers(both index1 and index2) are not zero - based.
//You may assume that each input would have exactly one solution and you may not use the same element twice.
//Input: numbers = { 2, 7, 11, 15 }, target = 9
//    Output : index1 = 1, index2 = 2

#include "Header.h";

vector<int> Solution::twoSumII(vector<int>& numbers, int target) {
    vector<int> result;
    int low = 0;
    int high = numbers.size() - 1;
    while (low < high) {
        if (numbers[low] + numbers[high] < target) {
            low++;
        }
        else if (numbers[low] + numbers[high]>target)
        {
            high--;
        }
        else
        {
            break;
        }
    }
    result.push_back(low + 1);
    result.push_back(high + 1);
    return result;
}