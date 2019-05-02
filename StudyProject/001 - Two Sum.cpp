#include "pch.h";
vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> ret(2, 0);
	unordered_map<int, int> mp;
	for (int i = 0; i < nums.size(); i++) {
		int find = target - nums[i];
		if (mp.count(find)) {
			ret[0] = mp[find];
			ret[1] = i;
			return ret;
		}
		mp[nums[i]] = i;
	}
	return ret;
}