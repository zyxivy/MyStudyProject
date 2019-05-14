#include "pch.h";
vector<vector<int>> Solution::threeSum(vector<int>& nums) {
	vector<vector<int>> ret;
	if (nums.size() < 3) {
		return ret;
	}
	std::sort(nums.begin(), nums.end());

	for (int i = 0; i <= nums.size() - 3; i++) {
		if (i == 0 || nums[i] != nums[i - 1]) {
			int target = 0 - nums[i];
			int low = i + 1;
			int high = nums.size() - 1;
			while (low < high) {
				if (nums[low] + nums[high] < target) {
					low++;
				}
				else if (nums[low] + nums[high] > target) {
					high--;
				}
				else {
					vector<int> item(3, 0);
					item[0] = nums[i];
					item[1] = nums[low];
					item[2] = nums[high];
					ret.push_back(item);
					//escape duplicate nums[low]
					while (low < high && item[1] == nums[low]) {
						low++;
					}
					//escape duplicate nums[high]
					while (low < high && item[2] == nums[high]) {
						high--;
					}
				}
			}
		}
	}
	return ret;
}
