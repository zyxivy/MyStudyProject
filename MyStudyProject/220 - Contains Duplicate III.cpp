//Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
#include "Header.h";

//http://yucoding.blogspot.com/2015/10/leetcode-question-contains-duplicate-iii.html

static bool compar220(pair<int, int> a, pair<int, int> b) {
	
	return a.first<b.first;
}
bool Solution::containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
	int diff = t;
	int dist = k;
	vector<pair<int, int>> vec;

	if (nums.empty()) {
		return false;
	}
	for (int i = 0; i < nums.size(); i++) {
		pair<int, int > p(nums[i], i);
		vec.push_back(p);
	}
	sort(vec.begin(),vec.end(), compar220);

	int pos = 0;
	while (pos < vec.size()) {
		int i = pos + 1;
		while (i < vec.size()) {
			if ((abs(long(vec[i].first) - long(vec[pos].first)) <= t) && (abs(vec[i].second - vec[pos].second) <= k)) {
				return true;
			}
			else {
				if (abs(long(vec[i].first) - long(vec[pos].first)) > t) {
					break;
				}
				else {
					i += 1;
				}
			}
		}
		pos += 1;
	}
	return false;
}