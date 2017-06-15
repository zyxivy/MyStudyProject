//Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s.If there isn't one, return 0 instead. 
//For example, given the array[2, 3, 1, 2, 4, 3] and s = 7,
//the subarray[4, 3] has the minimal length under the problem constraint.
//click to show more practice.
//More practice :
//If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

#include "Header.h";

//We can use 2 points to mark the left and right boundaries of the sliding window. 
//When the sum is greater than the target, shift the left pointer; when the sum is less than the target, shift the right pointer. 
int Solution::minSubArrayLen(int s, vector<int>& nums) {
    if (nums.empty() || nums.size() == 1)
        return 0;

    int result = nums.size();

    int start = 0;
    int sum = 0;
    int i = 0;
    bool exists = false;

    while (i <= nums.size()) {
        if (sum >= s) {
            exists = true; //mark if there exists such a subarray 
            if (start == i - 1) {
                return 1;
            }

            result = result < i - start ? result : i - start;
            sum = sum - nums[start];
            start++;

        }
        else {
            if (i == nums.size())
                break;
            sum = sum + nums[i];
            i++;
        }
    }

    if (exists)
        return result;
    else
        return 0;
}