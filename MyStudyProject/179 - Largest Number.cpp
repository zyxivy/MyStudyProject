//Given a list of non negative integers, arrange them such that they form the largest number.
//For example, given[3, 30, 34, 5, 9], the largest formed number is 9534330.
//Note: The result may be very large, so you need to return a string instead of an integer.

#include "Header.h";

int qcomp(const void* a, const void* b) {
    string sa = to_string(*(int*)a);
    string sb = to_string(*(int*)b);
    string s1 = sa + sb;
    string s2 = sb + sa;

    if (s1 > s2) {
        return -1;
    }
    else if (s1 == s2) {
        return 0;
    }
    else {
        return 1;
    }
}

string Solution::largestNumber(vector<int>& nums) {
    string str = "";
    if (nums.empty()) {
        return str;
    }
    qsort(&(nums[0]), nums.size(), sizeof(int), qcomp);
    if (nums[0] == 0) {
        return "0";
    }
    for (int i = 0; i < nums.size(); i++) {
        str += to_string(nums[i]);
    }
    return str;
}