//Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right.You can only see the k numbers in the window.Each time the sliding window moves right by one position.Return the max sliding window.
//
//Follow up :
//Could you solve it in linear time ?
//
//Example :
//
//	Input : nums = [1, 3, -1, -3, 5, 3, 6, 7], and k = 3
//	Output : [3, 3, 5, 5, 6, 7]
//	Explanation :
//
//	Window position                Max
//	-------------- - ---- -
//	[1  3 - 1] - 3  5  3  6  7       3
//	1[3 - 1 - 3] 5  3  6  7       3
//	1  3[-1 - 3  5] 3  6  7       5
//	1  3 - 1[-3  5  3] 6  7       5
//	1  3 - 1 - 3[5  3  6] 7       6
//	1  3 - 1 - 3  5[3  6  7]      7
//
//
//	Constraints:
//
//1 <= nums.length <= 10 ^ 5
//- 10 ^ 4 <= nums[i] <= 10 ^ 4
//1 <= k <= nums.length

#include "pch.h";
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	if (k == 1 || nums.empty()) {
		return nums;
	}

	deque<int> q;
	vector<int> result;

	for (int i = 0; i < nums.size(); i++) {
		while (!q.empty() && q.back() < nums[i]) {
			q.pop_back();
		}

		q.push_back(nums[i]);
		if (i >= k && q.front() == nums[i - k]) {
				q.pop_front();
		}
		if (i>=k-1) {
			result.push_back(q.front());
		}
	}
	return result;
}