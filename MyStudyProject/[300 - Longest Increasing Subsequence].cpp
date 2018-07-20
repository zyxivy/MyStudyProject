//Given an unsorted array of integers, find the length of longest increasing subsequence.
//For example,
//Given[10, 9, 2, 5, 3, 7, 101, 18],
//The longest increasing subsequence is[2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
//Your algorithm should run in O(n2) complexity.
//Follow up : Could you improve it to O(n log n) time complexity ?


//http://www.cnblogs.com/grandyang/p/4938187.html
#include "Header.h";
int Solution::lengthOfLIS(vector<int>& nums) {

	//下面我们来看一种优化时间复杂度到O(nlgn)的解法，这里用到了二分查找法，所以才能加快运行时间哇。
	//思路是，我们先建立一个数组ends，把首元素放进去，然后比较之后的元素，
	//如果遍历到的新元素比ends数组中的首元素小的话，替换首元素为此新元素，
	//如果遍历到的新元素比ends数组中的末尾元素还大的话，将此新元素添加到ends数组末尾(注意不覆盖原末尾元素)。
	//如果遍历到的新元素比ends数组首元素大，比尾元素小时，此时用二分查找法找到第一个不小于此新元素的位置，覆盖掉位置的原来的数字，
	//以此类推直至遍历完整个nums数组，此时ends数组的长度就是我们要求的LIS的长度，\
	//特别注意的是ends数组的值可能不是一个真实的LIS，
	//比如若输入数组nums为 { 4, 2， 4， 5， 3， 7 }，那么算完后的ends数组为{ 2， 3， 5， 7 }，可以发现它不是一个原数组的LIS，只是长度相等而已
	
	if (nums.empty()) return 0;
    vector<int> ends{ nums[0] };
    for (auto a : nums) {
        if (a < ends[0]) 
            ends[0] = a;
        else if (a > ends.back())
            ends.push_back(a);
        else {
            int left = 0, right = ends.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (ends[mid] < a) left = mid + 1;
                else right = mid;
            }
            ends[right] = a;
        }
    }
    return ends.size();


	//DP
	if (nums.empty()) return 0;
	vector<int> dp(nums.size(), 1);
	for (int i = 1; i < nums.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int maxDP = dp[0];
	for (int i = 1; i < dp.size(); i++) {
		maxDP = max(maxDP, dp[i]);
	}
	return maxDP;
}