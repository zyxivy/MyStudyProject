//Given a non - empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
//
//Note:
//Each of the array element will not exceed 100.
//The array size will not exceed 200.
//Example 1 :
//
//	Input : [1, 5, 11, 5]
//
//	Output : true
//
//	Explanation : The array can be partitioned as[1, 5, 5] and [11].
//	Example 2 :
//
//	Input : [1, 2, 3, 5]
//
//	Output : false
//
//	Explanation : The array cannot be partitioned into equal sum subsets.

#include "Header.h";
//http://www.cnblogs.com/grandyang/p/5951422.html
bool Solution::canPartition(vector<int>& nums) {
	if (nums.size() < 2) {
		return false;
	}
	int target = 0;
	for (int n : nums) {
		target += n;
	}
	if (target % 2 != 0) {
		return false;
	}
	target = target / 2;

    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int n : nums) {
        for (int i = target; i >= n; i--) {
            if (dp[i - n]) {
                dp[i] = true;
            }
        }
    }
    return dp[target];
}