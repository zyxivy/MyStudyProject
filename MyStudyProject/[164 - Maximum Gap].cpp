//Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//Try to solve it in linear time / space.
//Return 0 if the array contains less than 2 elements.
//You may assume all elements in the array are non - negative integers and fit in the 32 - bit signed integer range.

#include "Header.h";

//The key part is to get the interval :
//From: interval * (num[i] - min) = 0 and interval * (max - num[i]) = n
//    interval = num.length / (max - min)

//TODO: question: why max gap won't fall within a bucket.

struct bucket {
    int low = -1;
    int high = -1;
};
int Solution::maximumGap(vector<int>& nums) {
    if (nums.size() <= 1) {
        return 0;
    }

    int max = nums[0];
    int min = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        max = max > nums[i] ? max : nums[i];
        min = min < nums[i] ? min : nums[i];
    }
    if (min == max) {
        return 0;
    }
    double interval = (double)nums.size() / (max - min);
    vector<bucket> buckets;

    for (int i = 0; i < nums.size() + 1; i++) {
        bucket bk;
        buckets.push_back(bk);
    }
    for (int i = 0; i < nums.size(); i++) {
        int index = (int)(nums[i] - min)*interval;
        if (buckets[index].low == -1) {
            buckets[index].low = nums[i];
            buckets[index].high = nums[i];
        }
        else {
            buckets[index].low = buckets[index].low < nums[i] ? buckets[index].low : nums[i];
            buckets[index].high = buckets[index].high > nums[i] ? buckets[index].high : nums[i];
        }
    }
    int maxGap = 0;
    int pre = buckets[0].high;
    for (int i = 1; i < buckets.size(); i++) {
        if (buckets[i].low != -1) {
            maxGap = maxGap > buckets[i].low - pre ? maxGap : buckets[i].low - pre;
            pre = buckets[i].high;
        }
    }

    return maxGap;
}