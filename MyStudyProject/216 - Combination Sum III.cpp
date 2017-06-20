//Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//
//Example 1:
//Input: k = 3, n = 7
//    Output :
//
//    [[1, 2, 4]]
//
//
//       Example 2 :
//           Input : k = 3, n = 9
//           Output :
//
//           [[1, 2, 6], [1, 3, 5], [2, 3, 4]]

#include "Header.h";
vector<vector<int>> KSum2(vector<int>& nums, int target, int begin, int K) {
    int i = begin;
    int j = nums.size() - 1;
    int prevI = INT_MAX;
    vector<vector<int>> ret;
    if (K == 2) {
        int prevJ = INT_MAX;
        while (i < j) {
            if (prevJ != INT_MAX && prevJ == nums[j]) {
                j--;
                continue;
            }
            if (prevI != INT_MAX && prevI == nums[i]) {
                i++;
                continue;
            }
            int sum = nums[i] + nums[j];
            if (sum == target) {
                vector<int> result;
                result.push_back(nums[i]);
                result.push_back(nums[j]);
                ret.push_back(result);
                prevI = i;
                prevJ = j;
                i++;
                j--;
            }
            else if (sum < target) {
                prevI = i;
                i++;
            }
            else {
                prevJ = j;
                j--;
            }
        }
    }
    else {
        for (i = begin; i <= nums.size() - K; i++) {
            if (prevI != INT_MAX && prevI == nums[i]) {
                i++;
                continue;
            }
            prevI = i;
            vector<vector<int>> values = KSum2(nums, target - nums[i], i + 1, K - 1);
            for (int j = 0; j < values.size(); j++) {
                vector<int> result;
                result.push_back(nums[i]);
                for (int k = 0; k < values[j].size(); k++) {
                    result.push_back(values[j][k]);
                }
                ret.push_back(result);
            }
        }
    }
    return ret;
}
vector<vector<int>> Solution::combinationSum3(int k, int n) {
    vector<int> nums;
    for (int i = 1; i <= 9; i++) {
        nums.push_back(i);
    }
    vector<vector<int>> ret = KSum2(nums, n, 0, k);
    return ret;
}