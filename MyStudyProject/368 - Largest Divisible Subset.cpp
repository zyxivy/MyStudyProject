//Discuss
//Pick One
//
//Given a set of distinct positive integers, find the largest subset such that every pair(Si, Sj) of elements in this subset satisfies : Si % Sj = 0 or Sj % Si = 0.
//If there are multiple solutions, return any subset is fine.
//Example 1 :
//    nums : [1, 2, 3]
//
//    Result : [1, 2](of course, [1, 3] will also be ok)
//
//    Example 2 :
//    nums : [1, 2, 4, 8]
//
//    Result : [1, 2, 4, 8]
#include "Header.h";
//Given a set of integers that satisfies the property that each pair of integers inside the set are mutually divisible, 
//for a new integer S, S can be placed into the set as long as it can divide the smallest number of the set or is divisible by the largest number of the set.
//For example, let’s say we have a set P = { 4, 8, 16 }, 
//P satisfies the divisible condition.Now consider a new number 2, 
//it can divide the smallest number 4, so it can be placed into the set; similarly, 
//32 can be divided by 16, the biggest number in P, it can also placed into P.

//https://www.hrwhisper.me/leetcode-largest-divisible-subset/
//思路：其实和求最大上升子序列LIS差不多，只不过这题要求输出序列而已。
//先把数组排好序。首先要明确，若a<b且b%a == 0, b <c 且 c%b == 0那么必然有c%a == 0
//    我们设dp[i] 为最大的子集长度，更新的时候保存上一个的下标即可。
vector<int> Solution::largestDivisibleSubset(vector<int>& nums) {
    vector<int> ans;
    if (nums.empty()) {
        return ans;
    }
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> index(n, -1); //index[i] is the index of the previous(j<i) nums[j] in the same set of nums[i]
    vector<int> dp(n, 1);
    int max_dp = 1;
    int max_index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                index[i] = j;
            }
        }
        if (max_dp < dp[i]) {
            max_dp = dp[i];
            max_index = i;
        }
    }

    int index_i = max_index;
    while (index_i != -1) {
        ans.push_back(nums[index_i]);
        index_i = index[index_i];
    }
    return ans;
}