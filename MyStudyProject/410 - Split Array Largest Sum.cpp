//Given an array which consists of non - negative integers and an integer m, you can split the array into m non - empty continuous subarrays.Write an algorithm to minimize the largest sum among these m subarrays.
//
//Note:
//If n is the length of array, assume the following constraints are satisfied :
//
//1 ≤ n ≤ 1000
//1 ≤ m ≤ min(50, n)
//Examples :
//
//	Input :
//	nums = [7, 2, 5, 10, 8]
//	m = 2
//
//	Output :
//	18
//
//	Explanation :
//	There are four ways to split nums into two subarrays.
//	The best way is to split it into[7, 2, 5] and [10, 8],
//where the largest sum among the two subarrays is only 18.

#include "Header.h";
//http://www.cnblogs.com/grandyang/p/5933787.html

bool splitArrayBinarySearch(vector<int> nums, int m, int mid) {
	int cnt = 0;
	int curSum = 0;
	for (int i = 0; i < nums.size(); i++) {
		curSum += nums[i];
		if (curSum > mid) {
			curSum = nums[i];
			cnt++;
			if (cnt > m) {
				return false;
			}
		}
	}
	return true;
}
int Solution::splitArray(vector<int>& nums, int m) {

	//二分法
	int n = nums.size();
	int left = 0, right = 0;
	for (int i = 0; i < n; i++) {
		left = max(nums[i], left);
		right = right + nums[i];
	}
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (splitArrayBinarySearch(nums, m, mid)) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}


	// The method, in DP idea, costs lots of time, but the logic is very eary and clear.
	//用时蛮长的，但思路比较清晰 
	// f[m][i] means if we could split the array [0, i] in m subarray, the minimal value of the largest sum among these m subarrays we could get.
	//f[m][i]表示m刀，在[0, i]的最小化subarray的最大值
	// Then, f[m][i] = min (maxf[m-1][j], sum(nums[from j + 1 to i])), where j = [0, i - 1];
	//递归式子：f[m][i] = min(max(f[m-1][j], sum(nums[j+1 - i])) 其中，j = [0, i - 1];
	// The complexity is O(n^3)
	//这样处理的话，就是三重循环了

	//int n = nums.size();
	//vector<vector<long>> dp(m, vector<long>(n, 0));
	//dp[0][0] = nums[0];

	//for (int i = 1; i < n; i++) {
	//	dp[0][i] = dp[0][i - 1] + nums[i]; //dp[0][i] is the sum of nums[0]~nums[i]
	//}
	//for (int k = 1; k < m; k++) {
	//	for (int i = 0; i < n; i++) {
	//		long minVal = dp[0][i];
	//		for (int j = 0; j < i; j++) {
	//			long tempVal = max(dp[k - 1][j], dp[0][i] - dp[0][j]);
	//			minVal = min(minVal, tempVal);
	//		}
	//		dp[k][i] = minVal;
	//	}
	//}
	//return dp[m - 1][n - 1];
}