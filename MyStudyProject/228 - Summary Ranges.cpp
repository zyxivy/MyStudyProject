//Given a sorted integer array without duplicates, return the summary of its ranges.
//Example 1:
//Input: [0, 1, 2, 4, 5, 7]
//    Output : ["0->2", "4->5", "7"]
//
//    Example 2 :
//    Input : [0, 2, 3, 4, 6, 8, 9]
//    Output : ["0", "2->4", "6", "8->9"]

#include "Header.h";
vector<string> Solution::summaryRanges(vector<int>& nums) {
    vector<string> ranges;
    if (nums.empty()) {
        return ranges;
    }
    if (nums.size() == 1) {
        ranges.push_back(to_string(nums[0]));
        return ranges;
    }

    int start = 0;
    for (int i = 0; i < nums.size()-1; i++) {
        if (nums[i + 1] != nums[i] + 1) {
            if (i == start) {
                ranges.push_back(to_string(nums[start]));
            }
            else {
                ranges.push_back(to_string(nums[start]) + "->"+ to_string(nums[i]));
            }
            start = i + 1;
        }
    }
    if (nums[nums.size() - 1] != nums[nums.size() - 2] + 1) {
        ranges.push_back(to_string(nums[nums.size() - 1]));
    }
    else {
        ranges.push_back(to_string(nums[start]) + "->" + to_string(nums[nums.size() - 1]));
    }

    return ranges;
}