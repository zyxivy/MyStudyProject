//Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
//
//Example:
//
//nums = [1, 2, 3]
//target = 4
//
//The possible combination ways are :
//(1, 1, 1, 1)
//(1, 1, 2)
//(1, 2, 1)
//(1, 3)
//(2, 1, 1)
//(2, 2)
//(3, 1)
//
//Note that different sequences are counted as different combinations.
//
//Therefore the output is 7.
//Follow up :
//What if negative numbers are allowed in the given array ?
//How does it change the problem ?
//What limitation we need to add to the question to allow negative numbers ?

#include "Header.h";
int combinationSum4DP(vector<int> nums, vector<int> &combinations, int target) {
    if (combinations[target] != -1) {
        return combinations[target];
    }
    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (target >= nums[i]) {
            result = combinationSum4DP(nums, combinations, target - nums[i]);
        }
    }
    combinations[target] = result;
    return result;

}

int Solution::combinationSum4(vector<int>& nums, int target) {
    vector<int> combinations(nums.size() + 1, -1);
    combinations[0] = 1;
    return combinationSum4DP(nums, combinations, target);
}